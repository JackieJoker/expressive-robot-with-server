#ifndef VerticalServo_h
#define VerticalServo_h

#include "SmoothServoController.h"
// Needed for the struct
#include "HorizontalServo.h"

/// This class handles all the servomotors that make vertical movements
/// it provides up and down movements wrt the idle position.
/// 
/// To use this class you need to:
/// (1) Record the sequence of movements  
/// (2) Periodically call the updatePosition() method (i.e. put it in the loop() function of the .ino file)  
class VerticalServo {
  private:
    SmoothServoController servo;

    /// the default angle, when the robots turns on, it goes in this position
    /// all the angles are expressed relatively to the ilde position (ex. 30 degrees right)
    int idleAngle;

    // if the motor is upside down use reverse = true to invert all the movements
    bool reverse;

    /// the maximum angle the robot can move up
    int maxUpAngle;

    /// the maximum angle the robot can move down
    int maxDownAngle;

    // true if the servo can move of 360 degrees
    // this is obtained by using a gear 1:2
    bool is360 = false;

    // array of movements, NOTE: the maximum number of movements in a sequence is 100
    // it can be changed to dynamic vectors if needed
    Movement movementsSequence[100];
    // length of the sequence array (first free element in the array)
    int sequenceLength;
    // current index
    int sequenceIndex;
    
    bool isRunning; 

  public:
    VerticalServo(int pin, int idleAngle, bool reverse, int maxUpAngle, int maxDownAngle);
    
    void setup();

    int getAngle();

    /// this method has to be called before all the others
    /// to start the sequence of movements
    void startSequence();

    /// Move the servo up
    ///
    /// (input)   int angle: the relative angle wrt idle position
    /// (input)   unsigned long duration: the duration in milliseconds of the movement    
    void moveUp(int angle, unsigned long duration);

    /// Move the servo down
    ///
    /// (input)   int angle: the relative angle wrt idle position
    /// (input)   unsigned long duration: the duration in milliseconds of the movement    
    void moveDown(int angle, unsigned long duration);

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