#ifndef ServoController_h
#define ServoController_h

#include <ESP32Servo.h>

/// This class is just for backup
/// The class actually used is SmoothServoController
class ServoController {
  private:
    int pinServo;
    Servo servo;
    int currentAngle;

    unsigned long moveStartTime;
    int targetAngle;
    unsigned long movementDuration;

    bool isWaiting;

  public:
    ServoController(int pin, int angle);
    int getAngle();
    int getPin();
    
    /// This method set the target angle that the servo motor has to reach in a given time
    ///
    /// (input)   int targetAngle: the absolute angle to reach
    /// (input)   unsigned long movementDuration: the duration in milliseconds of the movement
    void setTarget(int targetAngle, unsigned long movementDuration);

    /// This method set a timer in which the servo motor will not move
    ///
    /// (input)   unsigned long duration: the duration in milliseconds of the waiting time
    void wait(unsigned long duration);
    
    /// This method is periodically called to update the position given the passed time
    ///
    /// (output)  bool targetReached: return true when the target is reached
    bool updatePosition();
};

#endif