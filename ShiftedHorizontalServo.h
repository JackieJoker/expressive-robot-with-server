#ifndef ShiftedHorizontalServo_h
#define ShiftedHorizontalServo_h

#include "HorizontalServo.h"

/// this class can be used only with horizontal servos, in particular in relationship with lowerBody, in order to be able to move our robot in the angular direction we want 
class ShiftedHorizontalServo {
  private:
    /// angular position of the robot we are talking to
    int shiftAngle; 

    HorizontalServo horizontalServo;
  
  public:
    ShiftedHorizontalServo(int pin, int idleAngle, bool reverse, int maxLeftAngle, int maxRightAngle);
    
    void setup();

    int getAngle();

    /// this method has to be called before all the others
    /// to start the sequence of movements
    void startSequence(int angle);

    /// Move the servo to the left
    ///
    /// (input)   int angle: the relative angle wrt shift angle
    /// (input)   unsigned long duration: the duration in milliseconds of the movement    
    void moveLeft(int angle, unsigned long duration);

    /// Move the servo to the right
    ///
    /// (input)   int angle: the relative angle wrt shift angle
    /// (input)   unsigned long duration: the duration in milliseconds of the movement    
    void moveRight(int angle, unsigned long duration);

    /// Move the servo back to the idle position (start position)
    ///
    /// (input)   unsigned long duration: the duration in milliseconds of the movement    
    void goIdle(unsigned long duration);

    /// Wait. The wait is non-blocking, other operations can be executed in the meanwhile
    ///
    /// (input)   unsigned long duration: the duration in milliseconds of the waiting time
    void wait(unsigned long duration);

    /// this method has to be called after all the others
    /// to end the sequence of movements. 
    /// After this instruction the sequence of movements starts playing
    void stopSequence();

    /// this method internally calculates the elapsed time and moves the servo motor
    void updatePosition();
};

#endif