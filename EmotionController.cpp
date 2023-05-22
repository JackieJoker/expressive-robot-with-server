#include "EmotionController.h"
#include <Arduino.h>

EmotionController::EmotionController(){
  for(int i = 0; i < nRobot; i++) {
    robotsState[i].emotion = 'A';
    robotsState[i].toRobot = 0;
    robotsState[i].intensity = 0;
  }

  state = (robotState){'A', 0, 1};
}

void EmotionController::received_GodMsg(char index) {
  switch (index) {
    case '1':
    robotsState[orderRobot[0]] = (robotState){'B', orderRobot[0], 1};
    break;
    case '2':
    robotsState[orderRobot[0]] = (robotState){'B', orderRobot[0], 1};
    break;
    case '3':
    robotsState[orderRobot[0]] = (robotState){'B', orderRobot[0], 1};
    break;
    case '4':
    robotsState[orderRobot[0]] = (robotState){'B', orderRobot[0], 1};
    break;
    case '5':
    robotsState[orderRobot[0]] = (robotState){'B', orderRobot[0], 1};
    break;
    case '6':
    robotsState[orderRobot[0]] = (robotState){'B', orderRobot[0], 1};
    break;
    case '7':
    robotsState[orderRobot[0]] = (robotState){'B', orderRobot[0], 1};
    break;
    case '8':
    robotsState[orderRobot[0]] = (robotState){'B', orderRobot[0], 1};
    break;
    case '9':
    robotsState[orderRobot[0]] = (robotState){'B', orderRobot[0], 1};
    break;
    case 'A':
    robotsState[orderRobot[0]] = (robotState){'B', orderRobot[0], 1};
    break;
    case 'B':
    robotsState[orderRobot[0]] = (robotState){'B', orderRobot[0], 1};
    break;
    case 'C':
    robotsState[orderRobot[0]] = (robotState){'B', orderRobot[0], 1};
    break;
    case 'D':
    robotsState[orderRobot[0]] = (robotState){'B', orderRobot[0], 1};
    break;
    case 'E':
    robotsState[orderRobot[0]] = (robotState){'B', orderRobot[0], 1};
    break;
    default: break;
  }
}

robotState *EmotionController::getRobotsState(){
  return robotsState;
}

void EmotionController::received_EmotionMsg(int fromWho, char emotion, int towardsWho, int intensity) {
  int index = robotOrder[fromWho - 1];
  robotsState[index].emotion = emotion;
  robotsState[index].toRobot = towardsWho;
  robotsState[index].intensity = intensity;
}

robotState EmotionController::nextEmotion(){
  if (flag_selected) {
    flag_selected = false;
    state = selectedState;
    return selectedState;
  }
  if (flag_active) {
  for (int i = 0; i < nRobot; i++) {
    int coin = random(0, 10);
    if (coin <= 2 && robotsState[i].emotion != 'A') {
      char new_emotion = responce_matrix[i][robotsState[i].emotion - 'A'];
      int intensity = random (1,3);
      state = (robotState){new_emotion, orderRobot[i], intensity};
      return state;
    }
  }}
  state = (robotState){'A', 0, 1};
  return state;
}

char *EmotionController::printRobotsState(){
  String str;
  for (int i=0; i < nRobot; i++){ 
    str += String("Robot" + String(orderRobot[i]) + " --- Emotion: " + robotsState[i].emotion + " Intensity: " + String(robotsState[i].intensity) + " toRobot: " + String(robotsState[i].toRobot) + "\n");
  }
  char *ret = (char*)malloc(1024);
  if (ret == NULL) return NULL;
  str.toCharArray(ret, 1024);
  return ret;
}
char EmotionController::getRobotEmotion(){
  return state.emotion;
}

void EmotionController::setRobotState(robotState newState){
  selectedState = newState;
  flag_selected = true;
}