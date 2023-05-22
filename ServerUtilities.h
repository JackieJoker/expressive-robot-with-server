#ifndef ServerUtilities_h
#define ServerUtilities_h

#include <ArduinoOTA.h>
#include <ESPmDNS.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <WebServer.h>
#include "RobotMovement.h"
#include "EmotionController.h"

class ServerUtilities {
  private:
    RobotMovement& robot;
    EmotionController& emotionController;

  public:
    ServerUtilities(RobotMovement& robot, EmotionController& emotionController);
    void setupRest();
    void setupOTA();
    void initConnection();
    void serverConnection(WiFiClient& client);
    void handleOTA();
    void handleClient();
    void print(String string);
};

#endif