#ifndef SmoothServoController_h
#define SmoothServoController_h

#include <Arduino.h>

// Must specify this before the include of "ServoEasing.hpp"
#define USE_PCA9685_SERVO_EXPANDER
//#define USE_LEIGHTWEIGHT_SERVO_LIB    // Makes the servo pulse generating immune to other libraries blocking interrupts for a longer time like SoftwareSerial, Adafruit_NeoPixel and DmxSimple.
//#define PROVIDE_ONLY_LINEAR_MOVEMENT  // Activating this disables all but LINEAR movement. Saves up to 1540 bytes program memory.
#define DISABLE_COMPLEX_FUNCTIONS     // Activating this disables the SINE, CIRCULAR, BACK, ELASTIC, BOUNCE and PRECISION easings. Saves up to 1850 bytes program memory.
#define MAX_EASING_SERVOS 5                       // Non è il numero di servo, ma di boards

#define ENABLE_EASE_QUADRATIC

#include "ServoEasing.h"

class SmoothServoController {
  private:
    int pinServo;
    int idleAngle;
    ServoEasing servo = ServoEasing(PCA9685_DEFAULT_ADDRESS);

    unsigned long moveStartTime;
    unsigned long waitingDuration;
    bool isWaiting;

  public:
    SmoothServoController(int pin, int angle);
    int getAngle();
    int getPin();

    void setup();
    
    /// This method set the target angle that the servo motor has to reach in a given time
    ///
    /// (input)   int targetAngle: the absolute angle to reach
    /// (input)   unsigned long movementDuration: the duration in milliseconds of the movement
    void setTarget(int targetAngle, unsigned long movementDuration);

    /// This method set the easing type (quadratic, cubic, linear, etc.)
    ///
    /// (input)   int easingType: the MACRO of the easing type.
    ///           an example of valid method call is: setEasingType(EASE_QUADRATIC_IN_OUT);
    void setEasingType(int easingType);

    /// This method set a timer in which the servo motor will not move
    ///
    /// (input)   unsigned long duration: the duration in milliseconds of the waiting time
    void wait(unsigned long duration);
    
    /// This method is periodically called to update the position given the passed time
    /// UPDATE: with the Smooth version this method does nothing actually but 
    /// simply returns true when the movement is finished
    ///
    /// (output)  bool targetReached: return true when the target is reached
    bool updatePosition();
};

#endif