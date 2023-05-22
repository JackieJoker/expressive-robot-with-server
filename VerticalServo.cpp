#include "VerticalServo.h"

VerticalServo::VerticalServo(int pin, int idleAngle, bool reverse, int maxUpAngle, int maxDownAngle) 
  : 
    idleAngle((maxUpAngle + maxDownAngle > 180) ? (idleAngle / 2) : idleAngle),
    reverse(reverse), 
    maxUpAngle(maxUpAngle), 
    maxDownAngle(maxDownAngle), 
    servo(SmoothServoController(pin, (maxUpAngle + maxDownAngle > 180) ? (idleAngle / 2) : idleAngle)) 
  {
    isRunning = false;
    if(maxUpAngle + maxDownAngle > 180) {
      is360 = true;
    }      
  }

void VerticalServo::setup() {
  servo.setup();
}

int VerticalServo::getAngle(){
  return servo.getAngle();
}

void VerticalServo::startSequence() {
  isRunning = false;
  sequenceIndex = 0;
  sequenceLength = 0;
}

void VerticalServo::stopSequence() {
  if(movementsSequence[sequenceIndex].wait) {
      servo.wait(movementsSequence[sequenceIndex].duration);
    } else {
      servo.setTarget(movementsSequence[sequenceIndex].angle, movementsSequence[sequenceIndex].duration);            
    }  
  sequenceIndex++;
  isRunning = true;
}


void VerticalServo::moveUp(int angle, unsigned long duration) {
  if(angle > maxUpAngle) {
    angle = maxUpAngle;
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

void VerticalServo::moveDown(int angle, unsigned long duration) {
  if(angle > maxDownAngle) {
    angle = maxDownAngle;
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

void VerticalServo::goIdle(unsigned long duration) {
  movementsSequence[sequenceLength].angle = idleAngle;
  movementsSequence[sequenceLength].duration = duration;
  movementsSequence[sequenceLength].wait = false;
  sequenceLength++;
}

void VerticalServo::wait(unsigned long duration) {
  movementsSequence[sequenceLength].wait = true;
  movementsSequence[sequenceLength].duration = duration;
  sequenceLength++;
}

void VerticalServo::updatePosition() {
  if(isRunning) {
    bool finished = servo.updatePosition();
    if(finished) {      
      if(sequenceIndex < sequenceLength) {
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