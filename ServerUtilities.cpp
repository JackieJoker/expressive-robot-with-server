#include "ServerUtilities.h"

String serialText = "";
/*
const char* ssid = "iPhone di Danilo";
const char* password = "danilo99";

const char* ssid = "LAPTOPANNA";
const char* password = "CIAOCIAO";
*/
const char* ssid = "iPhone";
const char* password = "LolloBello";

const char* server_ip = "172.20.10.5";
int server_port = 2048;

WebServer server(80);

ServerUtilities::ServerUtilities(RobotMovement& robot, EmotionController& emotionController) 
:
robot(robot),
emotionController(emotionController)
{  
}

void ServerUtilities::setupRest() {
  /***************** INIT MDNS ***************/
  // Activate mDNS this is used to be able to connect to the server
  // with local DNS hostmane robot.local
  if (MDNS.begin("robot")) {
    Serial.println("MDNS responder started");
  }
  /***************** INIT MDNS ****************/
  
  /***************** INIT Server REST ********/
  server.enableCORS();
  server.begin();
  Serial.println("HTTP server started");

  server.on("/hello", [this]() {
    server.send(200, "text/plain", "Hello from esp8266 server web!");
  });

  server.on("/debug", [this]() {    
    server.send(200, "text/plain", serialText);
  });

  server.on("/motor_position", [this]() {
    server.send(200, "text/plain", String(robot.getAngleLowerBody()) + "-" + String(robot.getAngleUpperBody()) + "-" + String(robot.getAngleHead()) + "-" + String(robot.getAngleLowerCap()) + "-" + String(robot.getAngleUpperCap()));
  });

  server.on("/set_emotion", HTTP_GET, [this]() {
    String emotion =  server.arg("emotion");
    server.send(200, "text/plain", "emotion selected: " + emotion);
    emotionController.setRobotState((robotState){emotion.charAt(0), 5, 1});
    Serial.println("Emotion selected: " + emotion);
  });

  server.on("/get_emotion", [this]() {
    char emotion = emotionController.getRobotEmotion();
    server.send(200, "text/plain", String(emotion));
  });
  /***************** INIT Server REST *********/
}

void ServerUtilities::setupOTA() {
/***************** INIT ArduinoOTA **********/
  // Port defaults to 3232
  ArduinoOTA.setPort(3232);

  ArduinoOTA.setPassword("admin");

  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

  ArduinoOTA.begin();
  Serial.println("OTA update service started");
  /***************** INIT ArduinoOTA **********/
}

void ServerUtilities::handleOTA() {
  ArduinoOTA.handle();
}

void ServerUtilities::handleClient() {
  server.handleClient();
}

void ServerUtilities::initConnection() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // WiFi connection
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void ServerUtilities::serverConnection(WiFiClient& client) {
  // Server connection
  Serial.println();
  Serial.println("Connecting to Server...");
  while (!client.connect(server_ip, server_port)) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Server connected");
  Serial.println();
}

void ServerUtilities::print(String string) {
  serialText.concat(string);
}