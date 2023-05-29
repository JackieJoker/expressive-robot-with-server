#ifndef EmotionController_h
#define EmotionController_h

struct robotState {
  char emotion;
  int toRobot;
  int intensity;
};

/// This class handles the emotion of our robot
/// it provides entry points to update the state of the table and the next emotion to perform
///  
class EmotionController {
  private:
  char responce_matrix[6][11] = {
  //  A    B    C    D    E    F    G    H    I    J    K
    {'B', 'C', 'D', 'E', 'B', 'E', 'E', 'D', 'E', 'K', 'I'},
    {'B', 'C', 'D', 'E', 'B', 'E', 'E', 'D', 'E', 'K', 'I'},
    {'B', 'C', 'D', 'E', 'B', 'E', 'E', 'D', 'E', 'K', 'I'},
    {'B', 'C', 'D', 'E', 'B', 'E', 'E', 'D', 'E', 'K', 'I'},
    {'B', 'C', 'D', 'E', 'B', 'E', 'E', 'D', 'E', 'K', 'I'},
    {'B', 'C', 'D', 'E', 'B', 'E', 'E', 'D', 'E', 'K', 'I'},
  };
  
  robotState robotsState[6];
  robotState state;
  int nRobot = 6;
  int robotOrder[7] = {2, 4, 0, 5, 6, 1, 3};
  int orderRobot[7] = {3, 6, 1, 7, 2, 4, 5};

  bool flag_selected = false;
  robotState selectedState;

  bool flag_active = true;


  public:
  EmotionController();

  void received_GodMsg(char index);

  robotState *getRobotsState();

  char *printRobotsState();
  
  void received_EmotionMsg(int fromWho, char emotion, int towardsWho, int intensity);

  robotState nextEmotion();

  void setRobotState(robotState newState);

  char getRobotEmotion();
};

#endif