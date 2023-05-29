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
  flag_selected = true;
  flag_active = false;
  switch (index) {
    case '1':
    selectedState = (robotState){'H', 1, 3};
    break;
    case '2':
    selectedState = (robotState){'K', 1, 3};
    break;
    case '3':
    selectedState = (robotState){'I', 2, 3};
    break;
    case '4':
    selectedState = (robotState){'K', 2, 3};
    break;
    case '5':
    selectedState = (robotState){'I', 3, 3};
    break;
    case '6':
    selectedState = (robotState){'K', 3, 3};
    break;
    case '7':
    selectedState = (robotState){'H', 4, 3};
    break;
    case '8':
    selectedState = (robotState){'K', 4, 3};
    break;
    case '9':
    selectedState = (robotState){'K', 0, 4};
    flag_active = true;
    break;
    case 'A':
    selectedState = (robotState){'K', 0, 3};
    flag_active = true;
    break;
    case 'B':
    selectedState = (robotState){'I', 6, 3};
    break;
    case 'C':
    selectedState = (robotState){'B', 6, 3};
    break;
    case 'D':
    selectedState = (robotState){'H', 7, 3};
    break;
    case 'E':
    selectedState = (robotState){'I', 7, 3};
    break;
    case 'F':  
    for(int i = 0; i < nRobot; i++) {
      robotsState[i].emotion = 'A';
      robotsState[i].toRobot = 0;
      robotsState[i].intensity = 0;
    }
    break;
    case 'G':
    flag_active = true;
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
  if (flag_active) {
    if (flag_selected) {
      flag_selected = false;
      state = selectedState;
      return selectedState;
    }
    for (int i = 0; i < nRobot; i++) {
      int coin = random(0, 10);
      if (coin <= 2 && robotsState[i].emotion != 'A') {
        char new_emotion = responce_matrix[i][robotsState[i].emotion - 'A'];
        int intensity = random (1,3);
        state = (robotState){new_emotion, orderRobot[i], intensity};
        return state;
      }
    }
  }
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