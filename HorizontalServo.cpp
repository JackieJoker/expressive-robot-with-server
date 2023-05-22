#include "HorizontalServo.h"

HorizontalServo::HorizontalServo(int pin, int idleAngle, bool reverse, int maxLeftAngle, int maxRightAngle) 
  : 
    idleAngle((maxRightAngle + maxLeftAngle > 180) ? (idleAngle / 2) : idleAngle),
    reverse(reverse),
    maxLeftAngle(maxLeftAngle), 
    maxRightAngle(maxRightAngle), 
    servo(SmoothServoController(pin, (maxRightAngle + maxLeftAngle > 180) ? (idleAngle / 2) : idleAngle)) 
  {
    isRunning = false;
    if(maxRightAngle + maxLeftAngle > 180) {
      is360 = true;
    }    
  }

void HorizontalServo::setup() {
  servo.setup();
}

int HorizontalServo::getAngle(){
  return servo.getAngle();
}

void HorizontalServo::startSequence() {
  isRunning = false;
  sequenceIndex = 0;
  sequenceLength = 0;
}

void HorizontalServo::stopSequence() {
    if(movementsSequence[sequenceIndex].wait) {
      servo.wait(movementsSequence[sequenceIndex].duration);
    } else {
      servo.setTarget(movementsSequence[sequenceIndex].angle, movementsSequence[sequenceIndex].duration);            
    }  
    sequenceIndex++;
    isRunning = true;
}

void HorizontalServo::moveLeft(int angle, unsigned long duration) {
  if(angle > maxLeftAngle) {
    angle = maxLeftAngle;
  }
  if(is360) {
    angle = angle / 2;
  }
  
  int absoluteAngle;
  if (reverse) {
    absoluteAngle = idleAngle - angle;
  } else {
    absoluteAngle = idleAngle + angle;
  }
  movementsSequence[sequenceLength].angle = absoluteAngle;
  movementsSequence[sequenceLength].duration = duration;
  movementsSequence[sequenceLength].wait = false;
  sequenceLength++;
}

void HorizontalServo::moveRight(int angle, unsigned long duration) {
  if(angle > maxRightAngle) {
    angle = maxRightAngle;
  }
  if(is360) {
    angle = angle / 2;
  }

  int absoluteAngle;
  if (reverse) {
    absoluteAngle = idleAngle + angle;
  } else {
    absoluteAngle = idleAngle - angle;
  }
  movementsSequence[sequenceLength].angle = absoluteAngle;
  movementsSequence[sequenceLength].duration = duration;
  movementsSequence[sequenceLength].wait = false;
  sequenceLength++;
}

void HorizontalServo::goIdle(unsigned long duration) {
  movementsSequence[sequenceLength].angle = idleAngle;
  movementsSequence[sequenceLength].duration = duration;
  movementsSequence[sequenceLength].wait = false;
  sequenceLength++;
}

void HorizontalServo::wait(unsigned long duration) {
  movementsSequence[sequenceLength].wait = true;
  movementsSequence[sequenceLength].duration = duration;
  sequenceLength++;
}

void HorizontalServo::updatePosition() {
  if(isRunning) {
    bool finished = servo.updatePosition();
    if(finished) {
      if (sequenceIndex < sequenceLength) {
        if(movementsSequence[sequenceIndex].wait) {
          servo.wait(movementsSequence[sequenceIndex].duration);
        } else {
          servo.setTarget(movementsSequence[sequenceIndex].angle, movementsSequence[sequenceIndex].duration);            
        }
        sequenceIndex++;
      } else {
        isRunning = false;        
      }
    }
  }
}