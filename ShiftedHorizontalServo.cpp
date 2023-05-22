#include "ShiftedHorizontalServo.h"

ShiftedHorizontalServo::ShiftedHorizontalServo(int pin, int idleAngle, bool reverse, int maxLeftAngle, int maxRightAngle) 
  :   
  shiftAngle(0),
  horizontalServo(HorizontalServo(pin, idleAngle, reverse, maxLeftAngle, maxRightAngle))
  {    
  }

void ShiftedHorizontalServo::setup() {
  horizontalServo.setup();
}

int ShiftedHorizontalServo::getAngle(){
  return horizontalServo.getAngle();
}

void ShiftedHorizontalServo::startSequence(int angle) {
  shiftAngle = angle;
  horizontalServo.startSequence();
}

void ShiftedHorizontalServo::stopSequence() {
  horizontalServo.stopSequence();
}

void ShiftedHorizontalServo::moveLeft(int angle, unsigned long duration) {
   if (shiftAngle - angle == 0){
    horizontalServo.goIdle(duration);
  } else if (shiftAngle - angle > 0){
    horizontalServo.moveRight(shiftAngle - angle, duration);
  } else if (shiftAngle - angle < 0){
    horizontalServo.moveLeft(-(shiftAngle - angle), duration);
  }
}

void ShiftedHorizontalServo::moveRight(int angle, unsigned long duration) {
   if (shiftAngle + angle == 0){
    horizontalServo.goIdle(duration);
  } else if (shiftAngle + angle > 0){
    horizontalServo.moveRight(shiftAngle + angle, duration);
  } else if (shiftAngle + angle < 0){
    horizontalServo.moveLeft(-(shiftAngle + angle), duration);
  }
}

void ShiftedHorizontalServo::goIdle(unsigned long duration) {
  if (shiftAngle == 0){
    horizontalServo.goIdle(duration);
  } else if (shiftAngle > 0){
    horizontalServo.moveRight(shiftAngle, duration);
  } else if (shiftAngle < 0){
    horizontalServo.moveLeft(-shiftAngle, duration);
  }
}

void ShiftedHorizontalServo::wait(unsigned long duration) {
  horizontalServo.wait(duration);  
}

void ShiftedHorizontalServo::updatePosition() {
  horizontalServo.updatePosition();  
}