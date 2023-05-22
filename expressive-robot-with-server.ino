#include <WiFiClient.h>
#include "RobotMovement.h"
#include "LedMatrixController.h"
#include "Mp3Controller.h"
#include "EmotionController.h"
#include "ServerUtilities.h"

RobotMovement robot;
LedMatrixController ledMatrixController;
Mp3Controller mp3Controller;
EmotionController emotionController;
ServerUtilities serverUtilities(robot, emotionController);

unsigned long timeStart = 0;
int timeMovement = 10000;
int timeMovementIdle = 1000;
int timeIdle = 3000;
bool emotionFinished = true;
bool goIdle = true;

int groupNumber = 6;
int intensity = 3;
bool shortMovement = true;

// if this variable is true the robot tries all the motors
bool initialization = false;
// if this variable is true the robot goes in the mounting position
// (all the motors in idle except from lower and upper cap that goes in the closed position)
bool calibration = false;

static WiFiClient client;

TaskHandle_t Task1;
TaskHandle_t Task2;

String serial_msg;

//variables for blinking a LED with Millis
const int led = 2; // ESP32 Pin to which onboard LED is connected

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);

  Serial.begin(115200);
  Serial.println("Booting");

  robot.setup();
  mp3Controller.setup();
  ledMatrixController.setup();

  ledMatrixController.showGif("0000_idle.gif");

  if(initialization) {
    robot.initialization(60000, 0); 
  }
  if(calibration) {
    robot.calibration(3000);
  }

  serverUtilities.initConnection();
  serverUtilities.setupOTA();
  serverUtilities.setupRest();  

  digitalWrite(led, LOW);

  // Create a task that will be executed in the main_loop() function,
  // with name "main", stack size 10000, NULL as parameter, priority 1,
  // handled by Task1 and executed on core 0
  xTaskCreatePinnedToCore(main_loop, "main", 10000, NULL, 1, &Task1, 0);                 
  delay(500); 

  xTaskCreatePinnedToCore(network_loop, "network", 10000, NULL, 1, &Task2, 1);
  delay(500);
}

void main_loop(void * pvParameters) {
  while(true) {
    serverUtilities.handleClient();
    serverUtilities.handleOTA();
    if(!initialization && !calibration) {
      if(emotionFinished) {
        emotionFinished = false;
        timeStart = millis();  
        robotState newState = emotionController.nextEmotion();
        
        String toPrint = "React to the robot " + String(newState.toRobot) + " with " + newState.emotion + " with intensity " + String(newState.intensity);
        serverUtilities.print(toPrint + '\n');
        Serial.println(toPrint);
        
        client.print("5" + newState.emotion + String(newState.toRobot) + String(newState.intensity));
        if(newState.emotion == 'A' && newState.emotion == 'F') {
          // idle
          ledMatrixController.showGif("0000_idle.gif");
          robot.neutral(timeMovement, groupNumber, intensity, shortMovement);
        } else if(newState.emotion == 'B') {
          // happy        
          ledMatrixController.showGif("0001_happy.gif");
          mp3Controller.play(1);  
          robot.happy(timeMovement, groupNumber, intensity, shortMovement);
        } else if(newState.emotion == 'C') {
          // angry   
          ledMatrixController.showGif("0003_angry.gif");
          mp3Controller.play(3);  
          robot.angry(timeMovement, groupNumber, intensity, shortMovement); 
        } else if(newState.emotion == 'D') {
          // surprised
          ledMatrixController.showGif("0007_surprised.gif");
          mp3Controller.play(7);  
          robot.surprised(timeMovement, groupNumber, intensity, shortMovement); 
        } else if(newState.emotion == 'E') {  
          // sad
          ledMatrixController.showGif("0002_sad.gif");
          mp3Controller.play(2);  
          robot.sad(timeMovement, groupNumber, intensity, shortMovement);   
        } else if(newState.emotion == 'H') {  
          // suspicious
          ledMatrixController.showGif("0006_suspicious.gif");
          mp3Controller.play(6);  
          robot.cautious(timeMovement, groupNumber, intensity, shortMovement);
        } else if(newState.emotion == 'I') {  
          // surprised
          ledMatrixController.showGif("0007_surprised.gif");
          mp3Controller.play(7);  
          robot.surprised(timeMovement, groupNumber, intensity, shortMovement); 
        } else if(newState.emotion == 'J') {  
          // disgusted
          ledMatrixController.showGif("0005_disgusted.gif");
          mp3Controller.play(5);  
          robot.annoyed(timeMovement, groupNumber, intensity, shortMovement); 
        } else if(newState.emotion == 'K') {  
          // embarrassed  
          ledMatrixController.showGif("0004_embarrassed.gif");
          mp3Controller.play(4);  
          robot.embarassed(timeMovement, groupNumber, intensity, shortMovement);
        } else {
          // idle
          ledMatrixController.showGif("0000_idle.gif");
          robot.neutral(timeMovement, groupNumber, intensity, shortMovement); 
        }
      }

      // Go to idle after "timeMovement" milliseconds
      if(millis() - timeStart > timeMovement + 200 && goIdle){
        goIdle = false;
        robot.idle(timeMovementIdle);
        ledMatrixController.showGif("0000_idle.gif");
      }

      // When idle is reached
      if(millis() - timeStart > timeMovement + timeMovementIdle + timeIdle + 400){
        emotionFinished = true;
        goIdle = true;
      }
    }      
    
    robot.updatePosition();
    ledMatrixController.updateGif();     
  } 
}

void network_loop(void * pvParameters) {
  serverUtilities.serverConnection(client);  
  String incomingData;
  // Handle connection and receive from WiFi (updating state)
  while(true) {
    if(client.available())  {
      incomingData = client.readStringUntil('\n');

      Serial.println(incomingData);
      serverUtilities.print(incomingData + '\n');

      serial_msg.concat(incomingData + "\n");
      
      Serial.println(incomingData.length());
      if (incomingData.length() == 4){
        if ((isdigit(incomingData.charAt(0)) && incomingData.charAt(0) != '5' )&& (incomingData.charAt(1) >= 'A' && incomingData.charAt(1) <= 'K') && isdigit(incomingData.charAt(2)) && isdigit(incomingData.charAt(3))){
          emotionController.received_EmotionMsg(incomingData.charAt(0) - '0', incomingData.charAt(1), incomingData.charAt(2) - '0', incomingData.charAt(3) - '0');
        }
      }

      if (incomingData.length() == 2){
        if (incomingData.charAt(0) == 'G'){
          emotionController.received_GodMsg(incomingData.charAt(1));
        }
      }

      char *tmp = emotionController.printRobotsState();
      Serial.println();
      free(tmp);
    }
    delay(10);  
  }
}

void loop() {}