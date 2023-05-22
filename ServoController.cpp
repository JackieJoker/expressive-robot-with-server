#include "ServoController.h"
#define MIN_MICROSECONDS 500
#define MAX_MICROSECONDS 2500

ServoController::ServoController(int pin, int angle) {
  pinServo = pin;
  currentAngle = angle;
  // Calibration for the servo motor to reach 180 degrees
  servo.attach(pinServo, MIN_MICROSECONDS, MAX_MICROSECONDS);
  //servo.attach(pinServo, Servo_ESP32::CHANNEL_NOT_ATTACHED, 0, 180, 540, 2520);
  isWaiting = false;
}

int ServoController::getAngle() {
  return currentAngle;
}

int ServoController::getPin() {
  return pinServo;
}

void ServoController::setTarget(int targetAngle, unsigned long movementDuration) {
  moveStartTime = millis();
  this->targetAngle = targetAngle;
  this->movementDuration = movementDuration;
  isWaiting = false;
}

void ServoController::wait(unsigned long duration) {
  moveStartTime = millis();
  this->targetAngle = currentAngle;
  isWaiting = true;
  this->movementDuration = duration;
}

bool ServoController::updatePosition() {
  unsigned long progress = millis() - moveStartTime;
  if (progress <= movementDuration) {
    // write on the servo only if there is a movement request
    if (!isWaiting) {      
      int currentAngleInMicroseconds = map(currentAngle, 0, 180, MIN_MICROSECONDS, MAX_MICROSECONDS);
      int targetAngleInMicroseconds = map(targetAngle, 0, 180, MIN_MICROSECONDS, MAX_MICROSECONDS);
      //int partialAngle = map(progress, 0, movementDuration, currentAngle, targetAngle);
      int partialAngleInMicroseconds = map(progress, 0, movementDuration, currentAngleInMicroseconds, targetAngleInMicroseconds);
//      Serial.println(String(pinServo) +  " | Previous angle: " + String(currentAngle) + " Target Angle: " + String(targetAngle));         
      //servo.write(partialAngle);
      servo.writeMicroseconds(partialAngleInMicroseconds);
      //Serial.println("partialAngleInMicroseconds: " + String(partialAngleInMicroseconds));
    }
  } else {
    currentAngle = targetAngle;
    isWaiting = false;
    return true;
  }
  return false;
}