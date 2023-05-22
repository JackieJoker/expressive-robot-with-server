#include "SmoothServoController.h"

#include "ServoEasing.hpp"
SmoothServoController::SmoothServoController(int pin, int angle) {
  pinServo = pin;
  idleAngle = angle;
}

void SmoothServoController::setup() {
  if (servo.attach(pinServo, idleAngle) == INVALID_SERVO) {
    Serial.println(F("Error attaching servo"));
  }
  servo.setEasingType(EASE_QUADRATIC_IN_OUT);
}

int SmoothServoController::getAngle() {
  return servo.getCurrentAngle();
}

int SmoothServoController::getPin() {
  return pinServo;
}

void SmoothServoController::setTarget(int targetAngle, unsigned long movementDuration) {
  // if(this->pinServo == 1)
  //   Serial.println("startEaseToD | angle: " + String(targetAngle) + " duration: " + String(movementDuration));
  servo.startEaseToD(targetAngle, movementDuration);
}

void SmoothServoController::setEasingType(int easingType) {
  servo.setEasingType(easingType);
}

void SmoothServoController::wait(unsigned long duration) {
  moveStartTime = millis();
  isWaiting = true;
  waitingDuration = duration;
}

bool SmoothServoController::updatePosition() {
  if(isWaiting) {
    unsigned long progress = millis() - moveStartTime;
    if(progress < waitingDuration) {
      return false;
    } else {
      isWaiting = false;
      return true;
    }
  } else {
    if(!servo.isMoving()) {
      delay(1);
    }
    return !servo.isMoving();
  }
}