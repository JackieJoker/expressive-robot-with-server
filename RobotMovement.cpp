#include "RobotMovement.h"

RobotMovement::RobotMovement() 
:
  // Parameters of the servomotors position in the robot
  lowerBody(ShiftedHorizontalServo(0, 180, false, 180, 180)), 
  upperBody(HorizontalServo(1, 180, false, 180, 180)),
  head(HorizontalServo(2, 180, false, 180, 180)),
  lowerCap(VerticalServo(3, 127, true, 45, 0)),
  upperCap(VerticalServo(4, 60, true, 0, 60))
{
  //constructor    
}

void RobotMovement::setup() {
  lowerBody.setup();
  upperBody.setup();
  head.setup();
  lowerCap.setup();
  upperCap.setup();   
}

bool RobotMovement::isRobotLeftOriented(int groupNumber) {
  if (groupPositions[groupNumber]>=0){
    return true;
    }
    else return false;
}

int RobotMovement::getRobotPosition(int groupNumber){
  return groupPositions[groupNumber]; 
}

int RobotMovement::getAngleLowerBody(){
  return lowerBody.getAngle();
}

int RobotMovement::getAngleUpperBody(){
  return upperBody.getAngle();
}

int RobotMovement::getAngleHead(){
  return head.getAngle();
}

int RobotMovement::getAngleLowerCap(){
  return lowerCap.getAngle();
}

int RobotMovement::getAngleUpperCap(){
  return upperCap.getAngle();
}

void RobotMovement::happy(unsigned long duration, int groupNumber, int intensity, bool shortMovement) {
  int robotAngularPosition = getRobotPosition(groupNumber);

  bool orientation = isRobotLeftOriented(groupNumber);
  if(orientation){
    if(shortMovement){
      if (intensity==1){
        beHappyShort1Left(duration, robotAngularPosition); 
      } else if (intensity==2){
        beHappyShort2Left(duration, robotAngularPosition);  
      } else if (intensity==3){
        beHappyShort3Left(duration, robotAngularPosition); 
      }
    } else {
      beHappyLeft(duration, robotAngularPosition);
    }
  } else if(shortMovement){
          if (intensity==1){
            beHappyShort1Right(duration, robotAngularPosition); 
          } else if (intensity==2){
            beHappyShort2Right(duration, robotAngularPosition); 
          } else if (intensity==3){
            beHappyShort3Right(duration, robotAngularPosition);
          }
        } else {
          beHappyRight(duration, robotAngularPosition); 
        }
}
void RobotMovement::sad(unsigned long duration, int groupNumber, int intensity, bool shortMovement) {
  int robotAngularPosition = getRobotPosition(groupNumber);
  bool orientation = isRobotLeftOriented(groupNumber);
  if(orientation){
    if(shortMovement){
      if (intensity==1){
        beSadShort1Left(duration, robotAngularPosition);
      } else if (intensity==2){
        beSadShort2Left(duration, robotAngularPosition);
      } else if (intensity==3){
          beSadShort3Left(duration, robotAngularPosition);
      }
    } else {
      beSadLeft(duration, robotAngularPosition);
    }
  } else if(shortMovement){
          if (intensity==1){
            beSadShort1Right(duration, robotAngularPosition); 
          } else if (intensity==2){
            beSadShort2Right(duration, robotAngularPosition); 
          } else if (intensity==3){
              beSadShort3Right(duration, robotAngularPosition);
          }
        } else {
          beSadRight(duration, robotAngularPosition); 
        }
}
void RobotMovement::angry(unsigned long duration, int groupNumber, int intensity, bool shortMovement) {
  int robotAngularPosition = getRobotPosition(groupNumber);
  bool orientation = isRobotLeftOriented(groupNumber);
  if(orientation){
    if(shortMovement){
      if (intensity==1){
        beAngryShort1Left(duration, robotAngularPosition);
      } else if (intensity==2){
        beAngryShort2Left(duration, robotAngularPosition);
      } else if (intensity==3){
        beAngryShort3Left(duration, robotAngularPosition);
      }
    } else {
      beAngryLeft(duration, robotAngularPosition);
    }
  } else if(shortMovement){
          if (intensity==1){
            beAngryShort1Right(duration, robotAngularPosition); 
          } else if (intensity==2){
              beAngryShort2Right(duration, robotAngularPosition); 
          } else if (intensity==3){
              beAngryShort3Right(duration, robotAngularPosition);
          }
        } else {
          beAngryRight(duration, robotAngularPosition); 
        }
}
void RobotMovement::surprised(unsigned long duration, int groupNumber, int intensity, bool shortMovement) {
  int robotAngularPosition = getRobotPosition(groupNumber);
  bool orientation = isRobotLeftOriented(groupNumber);
  if(orientation){
  if(shortMovement){
    if (intensity==1){
      beSurprisedShort1Left(duration, robotAngularPosition);
    } else if (intensity==2){
       beSurprisedShort2Left(duration, robotAngularPosition);
     } else if (intensity==3){
        beSurprisedShort3Left(duration, robotAngularPosition);
     }
  } else {
    beSurprisedLeft(duration, robotAngularPosition);
   }
  } else if(shortMovement){
            if (intensity==1){
              beSurprisedShort1Right(duration, robotAngularPosition); 
            } else if (intensity==2){
              beSurprisedShort2Right(duration, robotAngularPosition); 
            } else if (intensity==3){
              beSurprisedShort3Right(duration, robotAngularPosition);
            }
          } else {
            beSurprisedRight(duration, robotAngularPosition); 
          }
}
void RobotMovement::annoyed(unsigned long duration, int groupNumber, int intensity, bool shortMovement) {
  int robotAngularPosition = getRobotPosition(groupNumber);
  bool orientation = isRobotLeftOriented(groupNumber);
  if(orientation){
  if(shortMovement){
    if (intensity==1){
      beAnnoyedShort1Left(duration, robotAngularPosition);
    } else if (intensity==2){
       beAnnoyedShort2Left(duration, robotAngularPosition);
     } else if (intensity==3){
        beAnnoyedShort3Left(duration, robotAngularPosition);
     }
  } else {
    beAnnoyedLeft(duration, robotAngularPosition);
    }
  } else if(shortMovement){
            if (intensity==1){
              beAnnoyedShort1Right(duration, robotAngularPosition); 
            } else if (intensity==2){
              beAnnoyedShort2Right(duration, robotAngularPosition); 
            } else if (intensity==3){
                beAnnoyedShort3Right(duration, robotAngularPosition);
            }
          } else {
            beAnnoyedRight(duration, robotAngularPosition); 
          }
}
void RobotMovement::embarassed(unsigned long duration, int groupNumber, int intensity, bool shortMovement) {
  int robotAngularPosition = getRobotPosition(groupNumber);
  bool orientation = isRobotLeftOriented(groupNumber);
  if(orientation){
  if(shortMovement){
    if (intensity==1){
      beEmbarassedShort1Left(duration, robotAngularPosition);
    } else if (intensity==2){
       beEmbarassedShort2Left(duration, robotAngularPosition);
     } else if (intensity==3){
        beEmbarassedShort3Left(duration, robotAngularPosition);
     }
  } else {
    beEmbarassedLeft(duration, robotAngularPosition);
    }
  } else if(shortMovement){
            if (intensity==1){
              beEmbarassedShort1Right(duration, robotAngularPosition); 
            } else if (intensity==2){
              beEmbarassedShort2Right(duration, robotAngularPosition); 
            } else if (intensity==3){
                beEmbarassedShort3Right(duration, robotAngularPosition);
            } else if (intensity==4){
                beEmbarassedShort4Right(duration, robotAngularPosition);
            }
          } else {
            beEmbarassedRight(duration, robotAngularPosition); 
          }
}
void RobotMovement::cautious(unsigned long duration, int groupNumber, int intensity, bool shortMovement) {
  int robotAngularPosition = getRobotPosition(groupNumber);
  bool orientation = isRobotLeftOriented(groupNumber);
  if(orientation){
  if(shortMovement){
    if (intensity==1){
      beCautiousShort1Left(duration, robotAngularPosition);
    } else if (intensity==2){
       beCautiousShort2Left(duration, robotAngularPosition);
     } else if (intensity==3){
        beCautiousShort3Left(duration, robotAngularPosition);
     }
  } else {
    beCautiousLeft(duration, robotAngularPosition);
    }
  } else if(shortMovement){
            if (intensity==1){
              beCautiousShort1Right(duration, robotAngularPosition); 
            } else if (intensity==2){
              beCautiousShort2Right(duration, robotAngularPosition); 
            } else if (intensity==3){
                beCautiousShort3Right(duration, robotAngularPosition);
            }
          } else {
            beCautiousRight(duration, robotAngularPosition); 
          }
}
void RobotMovement::neutral(unsigned long duration, int groupNumber, int intensity, bool shortMovement) {
  int robotAngularPosition = getRobotPosition(groupNumber);
  bool orientation = isRobotLeftOriented(groupNumber);
  if(orientation){
  if(shortMovement){
    beNeutralShort3Left(duration, robotAngularPosition);
    } else {
    beNeutralLeft(duration, robotAngularPosition);
    }
  } else if(shortMovement){
            if (intensity==3){
              beNeutralShort3Right(duration, robotAngularPosition);
            }
          } else {
            beNeutralRight(duration, robotAngularPosition); 
          }
}




void RobotMovement::test(unsigned long duration, int groupNumber) { 
  int robotAngularPosition = getRobotPosition(groupNumber);
  float k = duration/10000.0;

  lowerBody.startSequence(robotAngularPosition);
  lowerBody.moveRight(90, 5000*k);
  lowerBody.moveLeft(90, 5000*k);
  lowerBody.stopSequence();

  /*upperBody.startSequence();
  upperBody.moveRight(30, 5000*k);
  upperBody.stopSequence();

  head.startSequence();
  head.wait(1000*k);
  head.moveLeft(90, 2000*k);
  //head.wait(1000*k);
  head.moveRight(90, 4000*k);

  head.moveLeft(90, 3000*k);
  //head.wait(3000*k);

  head.stopSequence();

  lowerCap.startSequence();
  lowerCap.moveDown(30, 5000*k);
  lowerCap.stopSequence();*/
}

void RobotMovement::initialization(unsigned long duration,  int robotAngularPosition){
  float k = duration/60000.0;

  lowerBody.startSequence(0); 
  lowerBody.moveLeft(180, 2000*k);
  lowerBody.wait(2000*k);
  lowerBody.moveRight(180, 4000*k);
  lowerBody.wait(2000*k);
  lowerBody.goIdle(2000*k);
  lowerBody.stopSequence();

  upperBody.startSequence(); 
  upperBody.wait(12000*k);
  upperBody.moveLeft(180, 2000*k);
  upperBody.wait(2000*k);
  upperBody.moveRight(180, 4000*k);
  upperBody.wait(2000*k);
  upperBody.goIdle(2000*k);
  upperBody.stopSequence();

  head.startSequence();
  head.wait(24000*k);
  head.moveLeft(180, 2000*k);
  head.wait(2000*k);
  head.moveRight(180, 4000*k);
  head.wait(2000*k);
  head.goIdle(2000*k);
  head.stopSequence();

  lowerCap.startSequence();
  lowerCap.wait(36000*k);
  lowerCap.moveUp(40, 3000*k);
  lowerCap.wait(2000*k);
  lowerCap.goIdle(3000*k);
  lowerCap.wait(4000*k);
  lowerCap.stopSequence();

  upperCap.startSequence(); 
  upperCap.wait(48000*k);
  upperCap.moveDown(60, 3000*k);
  upperCap.wait(2000*k);
  upperCap.goIdle(3000*k);
  upperCap.wait(4000*k);
  upperCap.stopSequence();
}


void RobotMovement::calibration(unsigned long duration){
  float k = duration/3000.0;

  lowerBody.startSequence(0);
  lowerBody.goIdle(3000*k);
  lowerBody.stopSequence();

  upperBody.startSequence();
  upperBody.goIdle(3000*k);
  upperBody.stopSequence();

  head.startSequence();
  head.goIdle(3000*k);
  head.stopSequence();

  lowerCap.startSequence(); 
  lowerCap.moveUp(40, 3000*k);
  lowerCap.stopSequence();

  upperCap.startSequence(); 
  upperCap.moveDown(60, 3000*k);
  upperCap.stopSequence();
}


void RobotMovement::idle(unsigned long duration) { 
  float k = duration/5000.0;

  lowerBody.startSequence(0);
  lowerBody.goIdle(5000*k);
  lowerBody.stopSequence();

  upperBody.startSequence();
  upperBody.goIdle(5000*k);
  upperBody.stopSequence();

  head.startSequence();
  head.goIdle(5000*k);
  head.stopSequence();

  lowerCap.startSequence(); 
  lowerCap.goIdle(5000*k);
  lowerCap.stopSequence();

  upperCap.startSequence(); 
  upperCap.goIdle(5000*k);
  upperCap.stopSequence();
}


/// CHIUDERE DEL TUTTO LA CALOTTA
void RobotMovement::beEmbarassedRight(unsigned long duration, int robotAngularPosition) { 
  float k = duration/82000.0;

  //UPPERBODY EMBARASSED
  upperBody.startSequence(); 
  upperBody.moveRight(75,2000*k);//mod da 90
  upperBody.wait(31000*k); //1             //dipende dalla durata della testa
  upperBody.moveRight(25,4000*k);//2
  upperBody.wait(45000*k);                 //dipende dalla testa+cap
  upperBody.stopSequence();

  //HEAD EMBARASSED
  head.startSequence(); 
  head.moveRight(20,4000*k);
  head.wait(2000*k);
  for (int i=0;i<2;i++){           //13500*2=27000
    head.moveLeft(20,6000*k);
    head.wait(3000*k);
    head.moveRight(20,1500*k);
    head.wait(3000*k);    
  } //1
  head.wait(2000*k);             //2000
  head.goIdle(2000*k);//2        //2000
  for (int i=0;i<3;i++){      //7000*3=21000
    head.moveRight(20,1000*k);
    head.wait(2000*k);
    head.goIdle(4000*k);  
  }
  head.wait(24000*k); // cap movement durata(24)
  head.stopSequence();

  //UPPERCAP EMBARASSED
  upperCap.startSequence(); 
  upperCap.wait(58000*k);
  for (int i=0;i<3;i++){    //8000*3=24000 cap move
    upperCap.moveDown(10,2000*k);
    upperCap.wait(2000*k);
    upperCap.goIdle(4000*k);
  }
  upperCap.stopSequence();

   //LOWERCAP EMBARASSED
  lowerCap.startSequence(); 
  lowerCap.wait(58000*k);
  for (int i=0;i<3;i++){    //8000*3=24000 cap move
    lowerCap.moveUp(10,2000*k);
    lowerCap.wait(2000*k);
    lowerCap.goIdle(4000*k);
  }
  lowerCap.stopSequence();
}
void RobotMovement::beEmbarassedShort4Right(unsigned long duration, int robotAngularPosition) { 
  float k = duration/10000.0;

  //LOWERBODY EMBARASSED (WORKOUT)
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(60,500*k);
  for (int i=0;i<4;i++){
    lowerBody.moveLeft(60, 1000*k);
    lowerBody.moveRight(60, 1000*k);
  }
  lowerBody.moveLeft(60, 1000*k);
  lowerBody.wait(500*k);         
  lowerBody.stopSequence();

  //HEAD EMBARASSED
  head.startSequence(); 
  head.wait(500*k);
  head.moveLeft(60,500*k);
  for (int i=0;i<4;i++){
    head.moveRight(60, 1000*k);
    head.moveLeft(60, 1000*k);
  }
  head.stopSequence();

  //UPPERCAP EMBARASSED
  upperCap.startSequence(); 
  upperCap.wait(1000*k);
  for (int i=0;i<2;i++){ 
    upperCap.moveDown(10,2000*k);
    upperCap.moveUp(10,2000*k);
  }
  upperCap.wait(1000*k);
  upperCap.stopSequence();

   //LOWERCAP EMBARASSED
  lowerCap.startSequence(); 
  lowerCap.wait(1000*k);
  for (int i=0;i<2;i++){   
    lowerCap.moveUp(10,2000*k);
    lowerCap.moveDown(10,2000*k);
  }
  lowerCap.wait(1000*k);
  lowerCap.stopSequence();
}
void RobotMovement::beEmbarassedShort3Right(unsigned long duration, int robotAngularPosition) { 
  float k = duration/10000.0;

  //UPPERBODY EMBARASSED
  upperBody.startSequence(); 
  upperBody.moveRight(75,2000*k);//mod da 90
  upperBody.wait(8000*k);              
  upperBody.stopSequence();

  //HEAD EMBARASSED
  head.startSequence(); 
  head.moveRight(20,2000*k);
  head.wait(8000*k);
  head.stopSequence();

  //UPPERCAP EMBARASSED
  upperCap.startSequence(); 
  upperCap.wait(2000*k);
  for (int i=0;i<2;i++){ 
    upperCap.moveDown(10,2000*k);
    upperCap.moveUp(10,2000*k);
  }
  upperCap.stopSequence();

   //LOWERCAP EMBARASSED
  lowerCap.startSequence(); 
  lowerCap.wait(2000*k);
  for (int i=0;i<2;i++){   
    lowerCap.moveUp(10,2000*k);
    lowerCap.moveDown(10,2000*k);
  }
  lowerCap.stopSequence();
}
void RobotMovement::beEmbarassedShort2Right(unsigned long duration, int robotAngularPosition) { 
  float k = duration/10000.0;

  //UPPERBODY EMBARASSED
  upperBody.startSequence(); 
  upperBody.moveRight(75,2000*k);
  upperBody.wait(8000*k);              
  upperBody.stopSequence();

  //HEAD EMBARASSED
  head.startSequence(); 
  head.moveRight(20,2000*k);
  head.wait(8000*k);
  head.stopSequence();

  //UPPERCAP EMBARASSED
  upperCap.startSequence(); 
  upperCap.wait(2000*k);
  for (int i=0;i<2;i++){ 
    upperCap.moveDown(10,2000*k);
    upperCap.goIdle(2000*k);
  }
  upperCap.stopSequence();

   //LOWERCAP EMBARASSED
  lowerCap.startSequence(); 
  lowerCap.wait(2000*k);
  for (int i=0;i<2;i++){   
    lowerCap.moveUp(10,2000*k);
    lowerCap.goIdle(2000*k);
  }
  lowerCap.stopSequence();
}
void RobotMovement::beEmbarassedShort1Right(unsigned long duration, int robotAngularPosition) { 
  float k = duration/10000.0;

  //UPPERBODY EMBARASSED
  upperBody.startSequence(); 
  upperBody.moveRight(75,2000*k);
  upperBody.wait(8000*k);              
  upperBody.stopSequence();

  //HEAD EMBARASSED
  head.startSequence(); 
  head.moveRight(20,2000*k);
  head.wait(8000*k);
  head.stopSequence();

  //UPPERCAP EMBARASSED
  upperCap.startSequence(); 
  upperCap.wait(2000*k);
  for (int i=0;i<2;i++){ 
    upperCap.moveDown(10,2000*k);
    upperCap.moveDown(5,2000*k);
  }
  upperCap.stopSequence();

   //LOWERCAP EMBARASSED
  lowerCap.startSequence(); 
  lowerCap.wait(2000*k);
  for (int i=0;i<2;i++){   
    lowerCap.moveUp(10,2000*k);
    lowerCap.moveUp(5,2000*k);
  }
  lowerCap.stopSequence();
}

void RobotMovement::beEmbarassedLeft(unsigned long duration, int robotAngularPosition) { 
  float k = duration/82000.0;

  //UPPERBODY EMBARASSED
  upperBody.startSequence(); 
  upperBody.moveLeft(75,2000*k);//mod da 90
  upperBody.wait(31000*k); //1             //dipende dalla durata della testa
  upperBody.moveLeft(25,4000*k);//2
  upperBody.wait(45000*k);                 //dipende dalla testa+cap
  upperBody.stopSequence();

  //HEAD EMBARASSED
  head.startSequence(); 
  head.moveLeft(20,4000*k);
  head.wait(2000*k);
  for (int i=0;i<2;i++){           //13500*2=27000
    head.moveRight(20,6000*k);
    head.wait(3000*k);
    head.moveLeft(20,1500*k);
    head.wait(3000*k);    
  } //1
  head.wait(2000*k);             //2000
  head.goIdle(2000*k);//2        //2000
  for (int i=0;i<3;i++){      //7000*3=21000
    head.moveLeft(20,1000*k);
    head.wait(2000*k);
    head.goIdle(4000*k);  
  }
  head.wait(24000*k); // cap movement durata(24)
  head.stopSequence();

  //UPPERCAP EMBARASSED
  upperCap.startSequence(); 
  upperCap.wait(58000*k);
  for (int i=0;i<3;i++){    //8000*3=24000 cap move
    upperCap.moveDown(10,2000*k);
    upperCap.wait(2000*k);
    upperCap.goIdle(4000*k);
  }
  upperCap.stopSequence();

   //LOWERCAP EMBARASSED
  lowerCap.startSequence(); 
  lowerCap.wait(58000*k);
  for (int i=0;i<3;i++){    //8000*3=24000 cap move
    lowerCap.moveUp(10,2000*k);
    lowerCap.wait(2000*k);
    lowerCap.goIdle(4000*k);
  }
  lowerCap.stopSequence();
}
void RobotMovement::beEmbarassedShort3Left(unsigned long duration, int robotAngularPosition) { 
  float k = duration/10000.0;

  //UPPERBODY EMBARASSED
  upperBody.startSequence(); 
  upperBody.moveLeft(75,2000*k);//mod da 90
  upperBody.wait(8000*k);              
  upperBody.stopSequence();

  //HEAD EMBARASSED
  head.startSequence(); 
  head.moveLeft(20,2000*k);
  head.wait(8000*k);
  head.stopSequence();

  //UPPERCAP EMBARASSED
  upperCap.startSequence(); 
  upperCap.wait(2000*k);
  for (int i=0;i<2;i++){ 
    upperCap.moveDown(10,2000*k);
    upperCap.moveUp(10,2000*k);
  }
  upperCap.stopSequence();

   //LOWERCAP EMBARASSED
  lowerCap.startSequence(); 
  lowerCap.wait(2000*k);
  for (int i=0;i<2;i++){   
    lowerCap.moveUp(10,2000*k);
    lowerCap.moveDown(10,2000*k);
  }
  lowerCap.stopSequence();
}
void RobotMovement::beEmbarassedShort2Left(unsigned long duration, int robotAngularPosition) { 
  float k = duration/10000.0;

  //UPPERBODY EMBARASSED
  upperBody.startSequence(); 
  upperBody.moveLeft(75,2000*k);
  upperBody.wait(8000*k);              
  upperBody.stopSequence();

  //HEAD EMBARASSED
  head.startSequence(); 
  head.moveLeft(20,2000*k);
  head.wait(8000*k);
  head.stopSequence();

  //UPPERCAP EMBARASSED
  upperCap.startSequence(); 
  upperCap.wait(2000*k);
  for (int i=0;i<2;i++){ 
    upperCap.moveDown(10,2000*k);
    upperCap.goIdle(2000*k);
  }
  upperCap.stopSequence();

   //LOWERCAP EMBARASSED
  lowerCap.startSequence(); 
  lowerCap.wait(2000*k);
  for (int i=0;i<2;i++){   
    lowerCap.moveUp(10,2000*k);
    lowerCap.goIdle(2000*k);
  }
  lowerCap.stopSequence();
}
void RobotMovement::beEmbarassedShort1Left(unsigned long duration, int robotAngularPosition) { 
  float k = duration/10000.0;

  //UPPERBODY EMBARASSED
  upperBody.startSequence(); 
  upperBody.moveLeft(75,2000*k);
  upperBody.wait(8000*k);              
  upperBody.stopSequence();

  //HEAD EMBARASSED
  head.startSequence(); 
  head.moveLeft(20,2000*k);
  head.wait(8000*k);
  head.stopSequence();

  //UPPERCAP EMBARASSED
  upperCap.startSequence(); 
  upperCap.wait(2000*k);
  for (int i=0;i<2;i++){ 
    upperCap.moveDown(10,2000*k);
    upperCap.moveDown(5,2000*k);
  }
  upperCap.stopSequence();

   //LOWERCAP EMBARASSED
  lowerCap.startSequence(); 
  lowerCap.wait(2000*k);
  for (int i=0;i<2;i++){   
    lowerCap.moveUp(10,2000*k);
    lowerCap.moveUp(5,2000*k);
  }
  lowerCap.stopSequence();
}




void RobotMovement::beNeutralShort3Left(unsigned long duration, int robotAngularPosition) { 
  float k = duration/10000.0;

  //LOWERBODY NEUTRAL SHORT
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(20,2000*k);
  lowerBody.wait(2000*k);
  lowerBody.moveRight(20,2000*k);
  lowerBody.wait(2000*k);
  lowerBody.moveLeft(15,2000*k);
 
  lowerBody.stopSequence();

  //HEAD NEUTRAL SHORT
  head.startSequence(); 
  head.wait(2000*k);
  head.moveRight(10,2000*k);
  head.wait(2000*k);
  head.moveLeft(15,2000*k);
  head.wait(2000*k);
 
  head.stopSequence();

  //UPPERCAP NEUTRAL SHORT
  upperCap.startSequence(); 
  upperCap.wait(2000*k);
  upperCap.moveUp(5,1000*k);
  upperCap.moveDown(5,1000*k);
  upperCap.wait(2000*k);
  upperCap.moveDown(5,1000*k);
  upperCap.moveUp(5,1000*k);
  upperCap.wait(2000*k);
  
  upperCap.stopSequence();

  //LOWERCAP NEUTRAL SHORT
  lowerCap.startSequence(); 
  lowerCap.wait(2000*k);
  lowerCap.moveDown(5,1000*k);
  lowerCap.moveUp(5,1000*k);
  lowerCap.wait(2000*k);
  lowerCap.moveUp(5,1000*k);
  lowerCap.moveDown(5,1000*k);
  lowerCap.wait(2000*k);
  lowerCap.stopSequence();
}
void RobotMovement::beNeutralLeft(unsigned long duration, int robotAngularPosition) { 
  float k = duration/117500.0;

  //LOWERBODY NEUTRAL
  lowerBody.startSequence(robotAngularPosition); 
  for (int i=0;i<2;i++){    //59000*2=118000
    lowerBody.moveLeft(20,4000*k);
    lowerBody.wait(3000*k);
    lowerBody.moveRight(20,8000*k);
    lowerBody.wait(5000*k);
    lowerBody.moveLeft(15,6000*k);
    lowerBody.wait(2000*k);
    lowerBody.moveRight(15,6000*k);
    lowerBody.wait(2000*k);
    lowerBody.moveRight(25,5000*k);
    lowerBody.wait(2000*k);
    lowerBody.moveRight(10,6000*k);
    lowerBody.wait(3000*k);
    lowerBody.moveLeft(15,5000*k);
    lowerBody.wait(2000*k);
  }
  lowerBody.stopSequence();

  //HEAD NEUTRAL
  head.startSequence(); 
  for (int i=0;i<2;i++){    //59000*2=118000
    head.wait(4000*k);
    head.moveRight(10,3000*k);
    head.wait(8000*k);
    head.moveLeft(15,5000*k);
    head.wait(6000*k);
    head.moveRight(5,2000*k);
    head.wait(6000*k);
    head.moveLeft(5,2000*k);
    head.wait(5000*k);
    head.moveLeft(5,2000*k);
    head.wait(6000*k);
    head.moveLeft(10,3000*k);
    head.wait(5000*k);
    head.moveRight(5,2000*k);
  }
  head.stopSequence();

  //UPPERCAP NEUTRAL
  upperCap.startSequence(); 
  for (int i=0;i<2;i++){    //59000*2=118000
    upperCap.wait(4000*k);
    upperCap.moveUp(5,1500*k);
    upperCap.moveDown(5,1500*k);
    upperCap.wait(8000*k);
    upperCap.moveDown(5,2500*k);
    upperCap.moveUp(5,2500*k);
    upperCap.wait(6000*k);
    upperCap.moveUp(5,1000*k);
    upperCap.moveDown(5,1000*k);
    upperCap.wait(6000*k);
    upperCap.moveDown(5,1000*k);
    upperCap.moveUp(5,1000*k);
    upperCap.wait(5000*k);
    upperCap.moveUp(5,1000*k);
    upperCap.moveDown(5,1000*k);
    upperCap.wait(6000*k);
    upperCap.moveDown(5,1500*k);
    upperCap.moveUp(5,1500*k);
    upperCap.wait(5000*k);
    upperCap.moveDown(5,1000*k);
    upperCap.moveUp(5,1000*k);
  }
  upperCap.stopSequence();

  //LOWERCAP NEUTRAL
  lowerCap.startSequence(); 
  for (int i=0;i<2;i++){    //59000*2=118000
    lowerCap.wait(4000*k);
    lowerCap.moveDown(5,1500*k);
    lowerCap.moveUp(5,1500*k);
    lowerCap.wait(8000*k);
    lowerCap.moveUp(5,2500*k);
    lowerCap.moveDown(5,2500*k);
    lowerCap.wait(6000*k);
    lowerCap.moveDown(5,1000*k);
    lowerCap.moveUp(5,1000*k);
    lowerCap.wait(6000*k);
    lowerCap.moveUp(5,1000*k);
    lowerCap.moveDown(5,1000*k);
    lowerCap.wait(5000*k);
    lowerCap.moveDown(5,1000*k);
    lowerCap.moveUp(5,1000*k);
    lowerCap.wait(6000*k);
    lowerCap.moveUp(5,1500*k);
    lowerCap.moveDown(5,1500*k);
    lowerCap.wait(5000*k);
    lowerCap.moveUp(5,1000*k);
    lowerCap.moveDown(5,1000*k);
  }
  lowerCap.stopSequence();
}

void RobotMovement::beNeutralShort3Right(unsigned long duration, int robotAngularPosition) { 
  float k = duration/10000.0;

  //LOWERBODY NEUTRAL SHORT
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(20,2000*k);
  lowerBody.wait(2000*k);
  lowerBody.moveLeft(20,2000*k);
  lowerBody.wait(2000*k);
  lowerBody.moveRight(15,2000*k);
 
  lowerBody.stopSequence();

  //HEAD NEUTRAL SHORT
  head.startSequence(); 
  head.wait(2000*k);
  head.moveLeft(10,2000*k);
  head.wait(2000*k);
  head.moveRight(15,2000*k);
  head.wait(2000*k);
 
  head.stopSequence();

  //UPPERCAP NEUTRAL SHORT
  upperCap.startSequence(); 
  upperCap.wait(2000*k);
  upperCap.moveUp(5,1000*k);
  upperCap.moveDown(5,1000*k);
  upperCap.wait(2000*k);
  upperCap.moveDown(5,1000*k);
  upperCap.moveUp(5,1000*k);
  upperCap.wait(2000*k);
  
  upperCap.stopSequence();

  //LOWERCAP NEUTRAL SHORT
  lowerCap.startSequence(); 
  lowerCap.wait(2000*k);
  lowerCap.moveDown(5,1000*k);
  lowerCap.moveUp(5,1000*k);
  lowerCap.wait(2000*k);
  lowerCap.moveUp(5,1000*k);
  lowerCap.moveDown(5,1000*k);
  lowerCap.wait(2000*k);
  lowerCap.stopSequence();
}  
void RobotMovement::beNeutralRight(unsigned long duration, int robotAngularPosition) { 
  float k = duration/117500.0;

  //LOWERBODY NEUTRAL
  lowerBody.startSequence(robotAngularPosition); 
  for (int i=0;i<2;i++){    //59000*2=118000
    lowerBody.moveRight(20,4000*k);
    lowerBody.wait(3000*k);
    lowerBody.moveLeft(20,8000*k);
    lowerBody.wait(5000*k);
    lowerBody.moveRight(15,6000*k);
    lowerBody.wait(2000*k);
    lowerBody.moveLeft(15,6000*k);
    lowerBody.wait(2000*k);
    lowerBody.moveLeft(25,5000*k);
    lowerBody.wait(2000*k);
    lowerBody.moveLeft(10,6000*k);
    lowerBody.wait(3000*k);
    lowerBody.moveRight(15,5000*k);
    lowerBody.wait(2000*k);
  }
  lowerBody.stopSequence();

  //HEAD NEUTRAL
  head.startSequence(); 
  for (int i=0;i<2;i++){    //59000*2=118000
    head.wait(4000*k);
    head.moveLeft(10,3000*k);
    head.wait(8000*k);
    head.moveRight(15,5000*k);
    head.wait(6000*k);
    head.moveLeft(5,2000*k);
    head.wait(6000*k);
    head.moveRight(5,2000*k);
    head.wait(5000*k);
    head.moveRight(5,2000*k);
    head.wait(6000*k);
    head.moveRight(10,3000*k);
    head.wait(5000*k);
    head.moveLeft(5,2000*k);
  }
  head.stopSequence();

  //UPPERCAP NEUTRAL
  upperCap.startSequence(); 
  for (int i=0;i<2;i++){    //59000*2=118000
    upperCap.wait(4000*k);
    upperCap.moveUp(5,1500*k);
    upperCap.moveDown(5,1500*k);
    upperCap.wait(8000*k);
    upperCap.moveDown(5,2500*k);
    upperCap.moveUp(5,2500*k);
    upperCap.wait(6000*k);
    upperCap.moveUp(5,1000*k);
    upperCap.moveDown(5,1000*k);
    upperCap.wait(6000*k);
    upperCap.moveDown(5,1000*k);
    upperCap.moveUp(5,1000*k);
    upperCap.wait(5000*k);
    upperCap.moveUp(5,1000*k);
    upperCap.moveDown(5,1000*k);
    upperCap.wait(6000*k);
    upperCap.moveDown(5,1500*k);
    upperCap.moveUp(5,1500*k);
    upperCap.wait(5000*k);
    upperCap.moveDown(5,1000*k);
    upperCap.moveUp(5,1000*k);
  }
  upperCap.stopSequence();

  //LOWERCAP NEUTRAL
  lowerCap.startSequence(); 
  for (int i=0;i<2;i++){    //59000*2=118000
    lowerCap.wait(4000*k);
    lowerCap.moveDown(5,1500*k);
    lowerCap.moveUp(5,1500*k);
    lowerCap.wait(8000*k);
    lowerCap.moveUp(5,2500*k);
    lowerCap.moveDown(5,2500*k);
    lowerCap.wait(6000*k);
    lowerCap.moveDown(5,1000*k);
    lowerCap.moveUp(5,1000*k);
    lowerCap.wait(6000*k);
    lowerCap.moveUp(5,1000*k);
    lowerCap.moveDown(5,1000*k);
    lowerCap.wait(5000*k);
    lowerCap.moveDown(5,1000*k);
    lowerCap.moveUp(5,1000*k);
    lowerCap.wait(6000*k);
    lowerCap.moveUp(5,1500*k);
    lowerCap.moveDown(5,1500*k);
    lowerCap.wait(5000*k);
    lowerCap.moveUp(5,1000*k);
    lowerCap.moveDown(5,1000*k);
  }
  lowerCap.stopSequence();
} 


void RobotMovement::sayNo(unsigned long duration, int robotAngularPosition) { 
  float k = duration/30500.0;
  head.startSequence(); 
  head.moveLeft(30,500*k);
  for (int i=0;i<6;i++){       //2000*6=12000
    head.moveRight(30,1000*k);
    head.moveLeft(30,1000*k);
  } 
  for (int i=0;i<4;i++){       //2000*4=8000
    head.moveRight(15,1000*k);
    head.moveLeft(15,1000*k);
  } 
  head.wait(2000*k);            //2000
  for (int i=0;i<5;i++){      //2000*5=10000
    head.moveRight(20,1000*k);
    head.moveLeft(20,1000*k);
  } 
  head.stopSequence();
}


void RobotMovement::beHappyLeft(unsigned long duration, int robotAngularPosition) {
  float k = duration/85500.0;
  //LOWERBODY HAPPY
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(25,500*k);
  for (int i=0;i<2;i++){          //16000*2=32000
    for (int j=0;j<4;j++){//2000*4=8000
      lowerBody.moveRight(25,1000*k);
      lowerBody.moveLeft(25,1000*k);
    } 
    for (int l=0;l<4;l++){//2000*4=8000
      lowerBody.moveRight(15,1000*k);
      lowerBody.moveLeft(15,1000*k);
    }
  }
  for (int i=0;i<2;i++){          //17000*2=34000
    for (int j=0;j<3;j++){//3000*3=9000
      lowerBody.moveRight(20,1500*k);
      lowerBody.moveLeft(20,1500*k);
    } 
    for (int l=0;l<2;l++){//4000*2=8000
      lowerBody.moveRight(10,2000*k);
      lowerBody.moveLeft(10,2000*k);
    }
  }
  for (int i=0;i<4;i++){           //2000*4=8000
      lowerBody.moveRight(5,1000*k);
      lowerBody.moveLeft(5,1000*k);
    }
  lowerBody.wait(3000*k);                //3000
  for (int i=0;i<4;i++){           //2000*4=8000
      lowerBody.moveRight(5,1000*k);
      lowerBody.moveLeft(5,1000*k);
    }
  lowerBody.stopSequence();


  //UPPERBODY HAPPY
  upperBody.startSequence(); 
  upperBody.moveRight(45,500*k);
  for (int i=0;i<2;i++){          //16000*2=32000
    for (int j=0;j<4;j++){//2000*4=8000
      upperBody.moveRight(45,1000*k);
      upperBody.moveLeft(45,1000*k);
    } 
    for (int l=0;l<4;l++){//2000*4=8000
      upperBody.moveRight(35,1000*k);
      upperBody.moveLeft(35,1000*k);
    }
  }
  for (int i=0;i<2;i++){          //17000*2=34000
    for (int j=0;j<3;j++){//3000*3=9000
      upperBody.moveRight(40,1500*k);
      upperBody.moveLeft(40,1500*k);
    } 
    for (int l=0;l<2;l++){//4000*2=8000
      upperBody.moveRight(30,2000*k);
      upperBody.moveLeft(30,2000*k);
    }
  }
  for (int i=0;i<4;i++){           //2000*4=8000
      upperBody.moveRight(20,1000*k);
      upperBody.moveLeft(20,1000*k);
    }
  upperBody.wait(3000*k);                //3000
  for (int i=0;i<4;i++){           //2000*4=8000
      upperBody.moveRight(10,1000*k);
      upperBody.moveLeft(10,1000*k);
    }
  upperBody.stopSequence();


  //HEAD HAPPY
  head.startSequence(); //horizontal
  head.moveRight(35,500*k);
  for (int i=0;i<2;i++){          //16000*2=32000
    for (int j=0;j<4;j++){//2000*4=8000
      head.moveRight(35,1000*k);
      head.moveLeft(35,1000*k);
    } 
    for (int l=0;l<4;l++){//2000*4=8000
      head.moveRight(25,1000*k);
      head.moveLeft(25,1000*k);                        
    }
  }
  for (int i=0;i<2;i++){          //17000*2=34000
    for (int j=0;j<3;j++){//3000*3=9000
      head.moveRight(30,1500*k);
      head.moveLeft(30,1500*k);
    } 
    for (int l=0;l<2;l++){//4000*2=8000
      head.moveRight(20,2000*k);
      head.moveLeft(20,2000*k);
    }
  }
  for (int i=0;i<4;i++){           //2000*4=8000
      head.moveRight(10,1000*k);
      head.moveLeft(10,1000*k);
    }
  head.wait(3000*k);                //3000
  for (int i=0;i<4;i++){           //2000*4=8000
      head.moveRight(10,1000*k);
      head.moveLeft(10,1000*k);
    }
  head.stopSequence();


  //UPPERCAP HAPPY
  upperCap.startSequence();
  upperCap.moveUp(20,500*k);
  for (int i=0;i<2;i++){          //16000*2=32000
    for (int j=0;j<4;j++){//2000*4=8000
      upperCap.moveDown(20,1000*k);
      upperCap.moveUp(20,1000*k);
    } 
    for (int l=0;l<4;l++){//2000*4=8000
      upperCap.moveDown(10,1000*k);
      upperCap.moveUp(10,1000*k);                        
    }
  }
  for (int i=0;i<2;i++){          //17000*2=34000
    for (int j=0;j<3;j++){//3000*3=9000
      upperCap.moveDown(15,1500*k);
      upperCap.moveUp(15,1500*k);
    } 
    for (int l=0;l<2;l++){//4000*2=8000
      upperCap.moveDown(10,2000*k);
      upperCap.moveUp(10,2000*k);
    }
  }
  for (int i=0;i<4;i++){           //2000*4=8000
      upperCap.moveDown(5,1000*k);
      upperCap.moveUp(5,1000*k);
    }
  upperCap.wait(3000);                //3000
  for (int i=0;i<4;i++){           //2000*4=8000
      upperCap.moveDown(5,1000*k);
      upperCap.moveUp(5,1000*k);
    }
  upperCap.stopSequence();


  //LOWERCAP HAPPY
  lowerCap.startSequence();
  lowerCap.moveDown(20,500*k);
  for (int i=0;i<2;i++){          //16000*2=32000
    for (int j=0;j<4;j++){//2000*4=8000
      lowerCap.moveUp(20,1000*k);
      lowerCap.moveDown(20,1000*k);      
    } 
    for (int l=0;l<4;l++){//2000*4=8000
      lowerCap.moveUp(10,1000*k);
      lowerCap.moveDown(10,1000*k);                              
    }
  }
  for (int i=0;i<2;i++){          //17000*2=34000
    for (int j=0;j<3;j++){//3000*3=9000
      lowerCap.moveUp(15,1500*k);
      lowerCap.moveDown(15,1500*k);      
    } 
    for (int l=0;l<2;l++){//4000*2=8000
      lowerCap.moveUp(10,2000*k);
      lowerCap.moveDown(10,2000*k);
    }
  }
  for (int i=0;i<4;i++){           //2000*4=8000
      lowerCap.moveUp(5,1000*k);
      lowerCap.moveDown(5,1000*k);      
    }
  lowerCap.wait(3000*k);                //3000
  for (int i=0;i<4;i++){           //2000*4=8000
      lowerCap.moveUp(5,1000*k);
      lowerCap.moveDown(5,1000*k);      
    }
  lowerCap.stopSequence();  
}
void RobotMovement::beHappyShort3Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  
  //LOWERBODY HAPPY
  lowerBody.startSequence(robotAngularPosition); // qui modificheremo inserendo angolo // questo di là diventa shiftAngle // metto zero quando faccio prove
  lowerBody.moveLeft(25, 500*k); // testare angolo e cambiarlo in modo che lo schermo sia frontale
  for (int i=0;i<2;i++){          //4000*2=8000
    lowerBody.moveRight(25,1000*k);
    lowerBody.moveLeft(25,1000*k);
    lowerBody.moveRight(15,1000*k);
    lowerBody.moveLeft(15,1000*k);
  }
  lowerBody.wait(1500*k);
  lowerBody.stopSequence();


  //UPPERBODY HAPPY
  upperBody.startSequence(); 
  upperBody.moveRight(45,500*k);
  for (int i=0;i<2;i++){          //4000*2=8000
    upperBody.moveRight(45,1000*k);
    upperBody.moveLeft(45,1000*k);
    upperBody.moveRight(35,1000*k);
    upperBody.moveLeft(35,1000*k);
  }
  upperBody.wait(1500*k);
  upperBody.stopSequence();


  //HEAD HAPPY
  head.startSequence(); //horizontal
  head.moveRight(35,500*k);
  for (int i=0;i<2;i++){          //4000*2=8000
      head.moveRight(35,1000*k);
      head.moveLeft(35,1000*k);
      head.moveRight(25,1000*k);
      head.moveLeft(25,1000*k);                         
  }
  head.wait(1500*k);
  head.stopSequence();


  //UPPERCAP HAPPY
  upperCap.startSequence();
  upperCap.moveUp(20,500*k);
  for (int i=0;i<2;i++){          //4000*2=8000
    upperCap.moveDown(20,1000*k);
    upperCap.moveUp(20,1000*k);
    upperCap.moveDown(10,1000*k);
    upperCap.moveUp(10,1000*k);                        
  }
  upperCap.wait(1500*k);
  upperCap.stopSequence();


  //LOWERCAP HAPPY
  lowerCap.startSequence();
  lowerCap.moveDown(20,500*k);
  for (int i=0;i<2;i++){          //4000*2=8000
    lowerCap.moveUp(20,1000*k);
    lowerCap.moveDown(20,1000*k);      
    lowerCap.moveUp(10,1000*k);
    lowerCap.moveDown(10,1000*k);                              
  }
  lowerCap.wait(1500*k);
  lowerCap.stopSequence();  
}
void RobotMovement::beHappyShort2Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;
  //LOWERBODY HAPPY
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(20,1000*k);
  lowerBody.moveRight(20,1500*k);
  lowerBody.moveLeft(20,1500*k);
  lowerBody.moveRight(10,2000*k);
  lowerBody.moveLeft(10,2000*k);
  lowerBody.moveRight(10,2000*k);
  lowerBody.stopSequence();


  //UPPERBODY HAPPY
  upperBody.startSequence(); 
  upperBody.moveLeft(40,1000*k);
  upperBody.moveRight(40,1500*k);
  upperBody.moveLeft(40,1500*k);
  upperBody.moveRight(30,2000*k);
  upperBody.moveLeft(30,2000*k);
  upperBody.moveRight(30,2000*k);
  upperBody.stopSequence();



  //HEAD HAPPY
  head.startSequence(); 
  head.moveLeft(30,1000*k);
  head.moveRight(30,1500*k);
  head.moveLeft(30,1500*k);
  head.moveRight(20,2000*k);
  head.moveLeft(20,2000*k);      
  head.moveRight(20,2000*k);                   
  head.stopSequence();


  //UPPERCAP HAPPY
  upperCap.startSequence();
  upperCap.moveUp(15,1000*k);
  upperCap.moveDown(15,1500*k);
  upperCap.moveUp(15,1500*k);
  upperCap.moveDown(10,2000*k);
  upperCap.moveUp(10,2000*k);   
  upperCap.moveDown(10,2000*k);                     
  upperCap.stopSequence();


  //LOWERCAP HAPPY
  lowerCap.startSequence();
  lowerCap.moveDown(15,1000*k);
  lowerCap.moveUp(15,1500*k);
  lowerCap.moveDown(15,1500*k);      
  lowerCap.moveUp(10,2000*k);
  lowerCap.moveDown(10,2000*k);     
  lowerCap.moveUp(10,2000*k);                         
  lowerCap.stopSequence();  
}
void RobotMovement::beHappyShort1Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;
  //LOWERBODY HAPPY
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(5,1000*k);
  lowerBody.moveRight(5,1500*k);
  lowerBody.moveLeft(5,1500*k);
  lowerBody.moveRight(10,2000*k);
  lowerBody.moveLeft(10,2000*k);
  lowerBody.moveRight(10,2000*k);
  lowerBody.stopSequence();


  //UPPERBODY HAPPY
  upperBody.startSequence(); 
  upperBody.moveLeft(20,1000*k);
  upperBody.moveRight(20,1500*k);
  upperBody.moveLeft(20,1500*k);
  upperBody.moveRight(10,2000*k);
  upperBody.moveLeft(10,2000*k);
  upperBody.moveRight(10,2000*k);
  upperBody.stopSequence();



  //HEAD HAPPY
  head.startSequence(); 
  head.moveLeft(20,1000*k);
  head.moveRight(20,1500*k);
  head.moveLeft(20,1500*k);
  head.moveRight(10,2000*k);
  head.moveLeft(10,2000*k);      
  head.moveRight(10,2000*k);                   
  head.stopSequence();


  //UPPERCAP HAPPY
  upperCap.startSequence();
  upperCap.moveUp(10,1000*k);
  upperCap.moveDown(10,1500*k);
  upperCap.moveUp(10,1500*k);
  upperCap.moveDown(5,2000*k);
  upperCap.moveUp(5,2000*k);   
  upperCap.moveDown(5,2000*k);                     
  upperCap.stopSequence();


  //LOWERCAP HAPPY
  lowerCap.startSequence();
  lowerCap.moveDown(10,1000*k);
  lowerCap.moveUp(10,1500*k);
  lowerCap.moveDown(10,1500*k);      
  lowerCap.moveUp(5,2000*k);
  lowerCap.moveDown(5,2000*k);        
  lowerCap.moveUp(5,2000*k);                      
  lowerCap.stopSequence();  
}
 
void RobotMovement::beHappyRight(unsigned long duration, int robotAngularPosition) {
  float k = duration/85500.0;
  //LOWERBODY HAPPY
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(25,500*k);
  for (int i=0;i<2;i++){          //16000*2=32000
    for (int j=0;j<4;j++){//2000*4=8000
      lowerBody.moveLeft(25,1000*k);
      lowerBody.moveRight(25,1000*k);
    } 
    for (int l=0;l<4;l++){//2000*4=8000
      lowerBody.moveLeft(15,1000*k);
      lowerBody.moveRight(15,1000*k);
    }
  }
  for (int i=0;i<2;i++){          //17000*2=34000
    for (int j=0;j<3;j++){//3000*3=9000
      lowerBody.moveLeft(20,1500*k);
      lowerBody.moveRight(20,1500*k);
    } 
    for (int l=0;l<2;l++){//4000*2=8000
      lowerBody.moveLeft(10,2000*k);
      lowerBody.moveRight(10,2000*k);
    }
  }
  for (int i=0;i<4;i++){           //2000*4=8000
      lowerBody.moveLeft(5,1000*k);
      lowerBody.moveRight(5,1000*k);
    }
  lowerBody.wait(3000*k);                //3000
  for (int i=0;i<4;i++){           //2000*4=8000
      lowerBody.moveLeft(5,1000*k);
      lowerBody.moveRight(5,1000*k);
    }
  lowerBody.stopSequence();


  //UPPERBODY HAPPY
  upperBody.startSequence(); 
  upperBody.moveLeft(45,500*k);
  for (int i=0;i<2;i++){          //16000*2=32000
    for (int j=0;j<4;j++){//2000*4=8000
      upperBody.moveLeft(45,1000*k);
      upperBody.moveRight(45,1000*k);
    } 
    for (int l=0;l<4;l++){//2000*4=8000
      upperBody.moveLeft(35,1000*k);
      upperBody.moveRight(35,1000*k);
    }
  }
  for (int i=0;i<2;i++){          //17000*2=34000
    for (int j=0;j<3;j++){//3000*3=9000
      upperBody.moveLeft(40,1500*k);
      upperBody.moveRight(40,1500*k);
    } 
    for (int l=0;l<2;l++){//4000*2=8000
      upperBody.moveLeft(30,2000*k);
      upperBody.moveRight(30,2000*k);
    }
  }
  for (int i=0;i<4;i++){           //2000*4=8000
      upperBody.moveLeft(20,1000*k);
      upperBody.moveRight(20,1000*k);
    }
  upperBody.wait(3000*k);                //3000
  for (int i=0;i<4;i++){           //2000*4=8000
      upperBody.moveLeft(10,1000*k);
      upperBody.moveRight(10,1000*k);
    }
  upperBody.stopSequence();


  //HEAD HAPPY
  head.startSequence(); //horizontal
  head.moveLeft(35,500*k);
  for (int i=0;i<2;i++){          //16000*2=32000
    for (int j=0;j<4;j++){//2000*4=8000
      head.moveLeft(35,1000*k);
      head.moveRight(35,1000*k);
    } 
    for (int l=0;l<4;l++){//2000*4=8000
      head.moveLeft(25,1000*k);
      head.moveRight(25,1000*k);                        
    }
  }
  for (int i=0;i<2;i++){          //17000*2=34000
    for (int j=0;j<3;j++){//3000*3=9000
      head.moveLeft(30,1500*k);
      head.moveRight(30,1500*k);
    } 
    for (int l=0;l<2;l++){//4000*2=8000
      head.moveLeft(20,2000*k);
      head.moveRight(20,2000*k);
    }
  }
  for (int i=0;i<4;i++){           //2000*4=8000
      head.moveLeft(10,1000*k);
      head.moveRight(10,1000*k);
    }
  head.wait(3000*k);                //3000
  for (int i=0;i<4;i++){           //2000*4=8000
      head.moveLeft(10,1000*k);
      head.moveRight(10,1000*k);
    }
  head.stopSequence();


  //UPPERCAP HAPPY
  upperCap.startSequence();
  upperCap.moveUp(20,500*k);
  for (int i=0;i<2;i++){          //16000*2=32000
    for (int j=0;j<4;j++){//2000*4=8000
      upperCap.moveDown(20,1000*k);
      upperCap.moveUp(20,1000*k);
    } 
    for (int l=0;l<4;l++){//2000*4=8000
      upperCap.moveDown(10,1000*k);
      upperCap.moveUp(10,1000*k);                        
    }
  }
  for (int i=0;i<2;i++){          //17000*2=34000
    for (int j=0;j<3;j++){//3000*3=9000
      upperCap.moveDown(15,1500*k);
      upperCap.moveUp(15,1500*k);
    } 
    for (int l=0;l<2;l++){//4000*2=8000
      upperCap.moveDown(10,2000*k);
      upperCap.moveUp(10,2000*k);
    }
  }
  for (int i=0;i<4;i++){           //2000*4=8000
      upperCap.moveDown(5,1000*k);
      upperCap.moveUp(5,1000*k);
    }
  upperCap.wait(3000);                //3000
  for (int i=0;i<4;i++){           //2000*4=8000
      upperCap.moveDown(5,1000*k);
      upperCap.moveUp(5,1000*k);
    }
  upperCap.stopSequence();


  //LOWERCAP HAPPY
  lowerCap.startSequence();
  lowerCap.moveDown(20,500*k);
  for (int i=0;i<2;i++){          //16000*2=32000
    for (int j=0;j<4;j++){//2000*4=8000
      lowerCap.moveUp(20,1000*k);
      lowerCap.moveDown(20,1000*k);      
    } 
    for (int l=0;l<4;l++){//2000*4=8000
      lowerCap.moveUp(10,1000*k);
      lowerCap.moveDown(10,1000*k);                              
    }
  }
  for (int i=0;i<2;i++){          //17000*2=34000
    for (int j=0;j<3;j++){//3000*3=9000
      lowerCap.moveUp(15,1500*k);
      lowerCap.moveDown(15,1500*k);      
    } 
    for (int l=0;l<2;l++){//4000*2=8000
      lowerCap.moveUp(10,2000*k);
      lowerCap.moveDown(10,2000*k);
    }
  }
  for (int i=0;i<4;i++){           //2000*4=8000
      lowerCap.moveUp(5,1000*k);
      lowerCap.moveDown(5,1000*k);      
    }
  lowerCap.wait(3000*k);                //3000
  for (int i=0;i<4;i++){           //2000*4=8000
      lowerCap.moveUp(5,1000*k);
      lowerCap.moveDown(5,1000*k);      
    }
  lowerCap.stopSequence();  
} 
void RobotMovement::beHappyShort3Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;
  
  //LOWERBODY HAPPY
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(25,500*k);
  for (int i=0;i<2;i++){          //4000*2=8000
    lowerBody.moveLeft(25,1000*k);
    lowerBody.moveRight(25,1000*k);
    lowerBody.moveLeft(15,1000*k);
    lowerBody.moveRight(15,1000*k);
  }
  lowerBody.wait(1500*k);
  lowerBody.stopSequence();


  //UPPERBODY HAPPY
  upperBody.startSequence(); 
  upperBody.moveLeft(45,500*k);
  for (int i=0;i<2;i++){          //4000*2=8000
    upperBody.moveLeft(45,1000*k);
    upperBody.moveRight(45,1000*k);
    upperBody.moveLeft(35,1000*k);
    upperBody.moveRight(35,1000*k);
  }
  upperBody.wait(1500*k);
  upperBody.stopSequence();


  //HEAD HAPPY
  head.startSequence(); //horizontal
  head.moveLeft(35,500*k);
  for (int i=0;i<2;i++){          //4000*2=8000
      head.moveLeft(35,1000*k);
      head.moveRight(35,1000*k);
      head.moveLeft(25,1000*k);
      head.moveRight(25,1000*k);                         
  }
  head.wait(1500*k);
  head.stopSequence();


  //UPPERCAP HAPPY
  upperCap.startSequence();
  upperCap.moveUp(20,500*k);
  for (int i=0;i<2;i++){          //4000*2=8000
    upperCap.moveDown(20,1000*k);
    upperCap.moveUp(20,1000*k);
    upperCap.moveDown(10,1000*k);
    upperCap.moveUp(10,1000*k);                        
  }
  upperCap.wait(1500*k);
  upperCap.stopSequence();


  //LOWERCAP HAPPY
  lowerCap.startSequence();
  lowerCap.moveDown(20,500*k);
  for (int i=0;i<2;i++){          //4000*2=8000
    lowerCap.moveUp(20,1000*k);
    lowerCap.moveDown(20,1000*k);      
    lowerCap.moveUp(10,1000*k);
    lowerCap.moveDown(10,1000*k);                              
  }
  lowerCap.wait(1500*k);
  lowerCap.stopSequence();  
}  
void RobotMovement::beHappyShort2Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;
  //LOWERBODY HAPPY
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(20,1000*k);
  lowerBody.moveLeft(20,1500*k);
  lowerBody.moveRight(20,1500*k);
  lowerBody.moveLeft(10,2000*k);
  lowerBody.moveRight(10,2000*k);
  lowerBody.moveLeft(10,2000*k);
  lowerBody.stopSequence();


  //UPPERBODY HAPPY
  upperBody.startSequence(); 
  upperBody.moveRight(40,1000*k);
  upperBody.moveLeft(40,1500*k);
  upperBody.moveRight(40,1500*k);
  upperBody.moveLeft(30,2000*k);
  upperBody.moveRight(30,2000*k);
  upperBody.moveLeft(30,2000*k);
  upperBody.stopSequence();



  //HEAD HAPPY
  head.startSequence(); 
  head.moveRight(30,1000*k);
  head.moveLeft(30,1500*k);
  head.moveRight(30,1500*k);
  head.moveLeft(20,2000*k);
  head.moveRight(20,2000*k);      
  head.moveLeft(20,2000*k);                   
  head.stopSequence();


  //UPPERCAP HAPPY
  upperCap.startSequence();
  upperCap.moveUp(15,1000*k);
  upperCap.moveDown(15,1500*k);
  upperCap.moveUp(15,1500*k);
  upperCap.moveDown(10,2000*k);
  upperCap.moveUp(10,2000*k);   
  upperCap.moveDown(10,2000*k);                     
  upperCap.stopSequence();


  //LOWERCAP HAPPY
  lowerCap.startSequence();
  lowerCap.moveDown(15,1000*k);
  lowerCap.moveUp(15,1500*k);
  lowerCap.moveDown(15,1500*k);      
  lowerCap.moveUp(10,2000*k);
  lowerCap.moveDown(10,2000*k);     
  lowerCap.moveUp(10,2000*k);                         
  lowerCap.stopSequence();  
} 
void RobotMovement::beHappyShort1Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;
  //LOWERBODY HAPPY
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(5,1000*k);
  lowerBody.moveLeft(5,1500*k);
  lowerBody.moveRight(5,1500*k);
  lowerBody.moveLeft(10,2000*k);
  lowerBody.moveRight(10,2000*k);
  lowerBody.moveLeft(10,2000*k);
  lowerBody.stopSequence();


  //UPPERBODY HAPPY
  upperBody.startSequence(); 
  upperBody.moveRight(20,1000*k);
  upperBody.moveLeft(20,1500*k);
  upperBody.moveRight(20,1500*k);
  upperBody.moveLeft(10,2000*k);
  upperBody.moveRight(10,2000*k);
  upperBody.moveLeft(10,2000*k);
  upperBody.stopSequence();



  //HEAD HAPPY
  head.startSequence(); 
  head.moveRight(20,1000*k);
  head.moveLeft(20,1500*k);
  head.moveRight(20,1500*k);
  head.moveLeft(10,2000*k);
  head.moveRight(10,2000*k);      
  head.moveLeft(10,2000*k);                   
  head.stopSequence();


  //UPPERCAP HAPPY
  upperCap.startSequence();
  upperCap.moveUp(10,1000*k);
  upperCap.moveDown(10,1500*k);
  upperCap.moveUp(10,1500*k);
  upperCap.moveDown(5,2000*k);
  upperCap.moveUp(5,2000*k);   
  upperCap.moveDown(5,2000*k);                     
  upperCap.stopSequence();


  //LOWERCAP HAPPY
  lowerCap.startSequence();
  lowerCap.moveDown(10,1000*k);
  lowerCap.moveUp(10,1500*k);
  lowerCap.moveDown(10,1500*k);      
  lowerCap.moveUp(5,2000*k);
  lowerCap.moveDown(5,2000*k);        
  lowerCap.moveUp(5,2000*k);                      
  lowerCap.stopSequence();  
} 


//CHIUDERE DEL TUTTO LA CALOTTA
void RobotMovement:: beSadRight(unsigned long duration, int robotAngularPosition) { 
  float k = duration/76500.0;

  //LOWERBODY SAD
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(90,4000*k);
  lowerBody.wait(56500*k); //// durata intero movimento
  lowerBody.stopSequence();

  //UPPERBODY SAD
  upperBody.startSequence(); 
  upperBody.moveLeft(130,4000*k);       //4000
  upperBody.wait(14500*k); //durata movimento head //1   //14500
  upperBody.moveLeft(120,1000*k);      //1000
  upperBody.wait(1000*k);              //1000
  for (int i=0;i<3;i++){          //8000*3=24000
    upperBody.moveLeft(130,2000*k);
    upperBody.wait(2000*k);
    upperBody.moveLeft(120,2000*k);
    upperBody.wait(2000*k);
  }  //2
  for (int i=0;i<2;i++){          //8000*2=16000
    upperBody.moveLeft(110,2000*k);
    upperBody.wait(2000*k);
    upperBody.moveLeft(115,2000*k);
    upperBody.wait(2000*k);
  }  //3
  upperBody.moveLeft(110,1000*k);//4      //1000
  upperBody.wait(15000*k);
  upperBody.stopSequence();

  //HEAD SAD
  head.startSequence(); 
  head.wait(4000*k); 
  head.moveLeft(15,500*k);
  for (int i=0;i<4;i++){       //2000*4=8000
    head.moveRight(15,1000*k);
    head.moveLeft(15,1000*k);
  } 
  for (int i=0;i<3;i++){       //2000*3=6000
    head.moveRight(10,1000*k);
    head.moveLeft(10,1000*k);
  } //1
  head.wait(500*k);           //500
  head.moveLeft(15,1500*k);   //1500
  for (int i=0;i<3;i++){       //8000*3=24000
    head.wait(1500*k);
    head.moveRight(15,2500*k);
    head.wait(1500*k);
    head.moveLeft(15,2500*k);
  } //2
  for (int i=0;i<2;i++){       //8000*2=16000
    head.wait(1500*k);
    head.moveRight(10,2500*k);
    head.wait(1500*k);
    head.moveLeft(10,2500*k);
  } //3
  head.goIdle(1000*k); //4       //1000
  head.wait(15000*k);
  head.stopSequence();

  //UPPERCAP SAD
  upperCap.startSequence();
  upperCap.wait(61500*k);//4
  for (int i=0;i<3;i++){              //5000*3=15000
    upperCap.moveDown(20,2000*k); 
    upperCap.moveDown(10,1000*k);
    upperCap.moveDown(15,2000*k);    
  }
  upperCap.stopSequence();

  //LOWERCAP SAD
  lowerCap.startSequence();
  lowerCap.wait(61500*k);//4
  for (int i=0;i<3;i++){           //5000*4=15000
    lowerCap.moveUp(20,2000*k); 
    lowerCap.moveUp(10,1000*k);
    lowerCap.moveUp(15,2000*k);    
  }
  lowerCap.stopSequence();
}
void RobotMovement:: beSadShort3Right(unsigned long duration, int robotAngularPosition) { // guardo più o meno daa he parte è rivolto il robot, sottraggo quell'angolo per arrivare a zero e aggiungo posizione del robot a cui mi rivolgo
  float k = duration/10000.0;

  //LOWERBODY SAD
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(90,4000*k);
  lowerBody.wait(6000*k); //// durata intero movimento
  lowerBody.stopSequence();

  //UPPERBODY SAD
  upperBody.startSequence(); 
  upperBody.moveLeft(130,4000*k);       //4000
  upperBody.wait(6000*k); //durata movimento head //1   //14500
  upperBody.stopSequence();

  //HEAD SAD
  head.startSequence(); 
  head.wait(4000*k); 
  head.moveLeft(15,500*k);
  head.moveRight(15,1000*k);
  head.moveLeft(15,1000*k);
  head.moveRight(10,1000*k);
  head.wait(2500*k); 
  head.stopSequence();

  //UPPERCAP SAD
  upperCap.startSequence();
  upperCap.wait(7500*k);
  upperCap.moveDown(20,1500*k); 
  upperCap.moveDown(10,1000*k);   
  upperCap.stopSequence();

  //LOWERCAP SAD
  lowerCap.startSequence();
  lowerCap.wait(7500*k);
  lowerCap.moveUp(20,1500*k); 
  lowerCap.moveUp(10,1000*k);  
  lowerCap.stopSequence();
}
void RobotMovement:: beSadShort2Right(unsigned long duration, int robotAngularPosition) { 
  float k = duration/10000.0;

  //LOWERBODY SAD
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(90,4000*k);
  lowerBody.wait(6000*k); // durata intero movimento
  lowerBody.stopSequence();

  //UPPERBODY SAD
  upperBody.startSequence(); 
  upperBody.moveLeft(120,4000*k);     
  upperBody.wait(6000*k); //durata movimento head 
  upperBody.stopSequence();

  //HEAD SAD
  head.startSequence(); 
  head.wait(4000*k); 
  head.moveLeft(15,500*k);
  head.moveRight(15,1500*k);
  head.moveLeft(15,1500*k);
  head.wait(2500*k); 
  head.stopSequence();

  //UPPERCAP SAD
  upperCap.startSequence();
  upperCap.wait(7500*k);
  upperCap.moveDown(20,1500*k); 
  upperCap.moveDown(10,1000*k);   
  upperCap.stopSequence();

  //LOWERCAP SAD
  lowerCap.startSequence();
  lowerCap.wait(7500*k);
  lowerCap.moveUp(20,1500*k); 
  lowerCap.moveUp(10,1000*k);  
  lowerCap.stopSequence();
}
void RobotMovement:: beSadShort1Right(unsigned long duration, int robotAngularPosition) { 
  float k = duration/10000.0;

  //LOWERBODY SAD
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(90,4000*k);
  lowerBody.wait(6000*k); // durata intero movimento
  lowerBody.stopSequence();

  //UPPERBODY SAD
  upperBody.startSequence(); 
  upperBody.moveLeft(120,4000*k);     
  upperBody.wait(6000*k); //durata movimento head 
  upperBody.stopSequence();

  //HEAD SAD
  head.startSequence(); 
  head.wait(4000*k); 
  head.moveLeft(10,500*k);
  head.moveRight(10,1500*k);
  head.moveLeft(10,1500*k);
  head.wait(2500*k); 
  head.stopSequence();

  //UPPERCAP SAD
  upperCap.startSequence();
  upperCap.wait(7500*k);
  upperCap.moveDown(20,2500*k); 
  upperCap.stopSequence();

  //LOWERCAP SAD
  lowerCap.startSequence();
  lowerCap.wait(7500*k);
  lowerCap.moveUp(20,2500*k);  
  lowerCap.stopSequence();
}

void RobotMovement:: beSadLeft(unsigned long duration, int robotAngularPosition) { 
  float k = duration/76500.0;

  //LOWERBODY SAD
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(90,4000*k);
  lowerBody.wait(56500*k); //// durata intero movimento
  lowerBody.stopSequence();

  //UPPERBODY SAD
  upperBody.startSequence(); 
  upperBody.moveRight(130,4000*k);       //4000
  upperBody.wait(14500*k); //durata movimento head //1   //14500
  upperBody.moveRight(120,1000*k);      //1000
  upperBody.wait(1000*k);              //1000
  for (int i=0;i<3;i++){          //8000*3=24000
    upperBody.moveRight(130,2000*k);
    upperBody.wait(2000*k);
    upperBody.moveRight(120,2000*k);
    upperBody.wait(2000*k);
  }  //2
  for (int i=0;i<2;i++){          //8000*2=16000
    upperBody.moveRight(110,2000*k);
    upperBody.wait(2000*k);
    upperBody.moveRight(115,2000*k);
    upperBody.wait(2000*k);
  }  //3
  upperBody.moveRight(110,1000*k);//4      //1000
  upperBody.wait(15000*k);
  upperBody.stopSequence();

  //HEAD SAD
  head.startSequence(); 
  head.wait(4000*k); 
  head.moveRight(15,500*k);
  for (int i=0;i<4;i++){       //2000*4=8000
    head.moveLeft(15,1000*k);
    head.moveRight(15,1000*k);
  } 
  for (int i=0;i<3;i++){       //2000*3=6000
    head.moveLeft(10,1000*k);
    head.moveRight(10,1000*k);
  } //1
  head.wait(500*k);           //500
  head.moveRight(15,1500*k);   //1500
  for (int i=0;i<3;i++){       //8000*3=24000
    head.wait(1500*k);
    head.moveLeft(15,2500*k);
    head.wait(1500*k);
    head.moveRight(15,2500*k);
  } //2
  for (int i=0;i<2;i++){       //8000*2=16000
    head.wait(1500*k);
    head.moveLeft(10,2500*k);
    head.wait(1500*k);
    head.moveRight(10,2500*k);
  } //3
  head.goIdle(1000*k); //4       //1000
  head.wait(15000*k);
  head.stopSequence();

  //UPPERCAP SAD
  upperCap.startSequence();
  upperCap.wait(61500*k);//4
  for (int i=0;i<3;i++){              //5000*3=15000
    upperCap.moveDown(20,2000*k); 
    upperCap.moveDown(10,1000*k);
    upperCap.moveDown(15,2000*k);    
  }
  upperCap.stopSequence();

  //LOWERCAP SAD
  lowerCap.startSequence();
  lowerCap.wait(61500*k);//4
  for (int i=0;i<3;i++){           //5000*4=15000
    lowerCap.moveUp(20,2000*k); 
    lowerCap.moveUp(10,1000*k);
    lowerCap.moveUp(15,2000*k);    
  }
  lowerCap.stopSequence();
}
void RobotMovement:: beSadShort3Left(unsigned long duration, int robotAngularPosition) { 
  float k = duration/10000.0;

  //LOWERBODY SAD
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(90,4000*k);
  lowerBody.wait(6000*k); //// durata intero movimento
  lowerBody.stopSequence();

  //UPPERBODY SAD
  upperBody.startSequence(); 
  upperBody.moveRight(130,4000*k);       //4000
  upperBody.wait(6000*k); //durata movimento head //1   //14500
  upperBody.stopSequence();

  //HEAD SAD
  head.startSequence(); 
  head.wait(4000*k); 
  head.moveRight(15,500*k);
  head.moveLeft(15,1000*k);
  head.moveRight(15,1000*k);
  head.moveLeft(10,1000*k);
  head.wait(2500*k); 
  head.stopSequence();

  //UPPERCAP SAD
  upperCap.startSequence();
  upperCap.wait(7500*k);
  upperCap.moveDown(20,1500*k); 
  upperCap.moveDown(10,1000*k);   
  upperCap.stopSequence();

  //LOWERCAP SAD
  lowerCap.startSequence();
  lowerCap.wait(7500*k);
  lowerCap.moveUp(20,1500*k); 
  lowerCap.moveUp(10,1000*k);  
  lowerCap.stopSequence();
}
void RobotMovement:: beSadShort2Left(unsigned long duration, int robotAngularPosition) { 
  float k = duration/10000.0;

  //LOWERBODY SAD
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(90,4000*k);
  lowerBody.wait(6000*k); // durata intero movimento
  lowerBody.stopSequence();

  //UPPERBODY SAD
  upperBody.startSequence(); 
  upperBody.moveRight(120,4000*k);     
  upperBody.wait(6000*k); //durata movimento head 
  upperBody.stopSequence();

  //HEAD SAD
  head.startSequence(); 
  head.wait(4000*k); 
  head.moveRight(15,500*k);
  head.moveLeft(15,1500*k);
  head.moveRight(15,1500*k);
  head.wait(2500*k); 
  head.stopSequence();

  //UPPERCAP SAD
  upperCap.startSequence();
  upperCap.wait(7500*k);
  upperCap.moveDown(20,1500*k); 
  upperCap.moveDown(10,1000*k);   
  upperCap.stopSequence();

  //LOWERCAP SAD
  lowerCap.startSequence();
  lowerCap.wait(7500*k);
  lowerCap.moveUp(20,1500*k); 
  lowerCap.moveUp(10,1000*k);  
  lowerCap.stopSequence();
}
void RobotMovement:: beSadShort1Left(unsigned long duration, int robotAngularPosition) { 
  float k = duration/10000.0;

  //LOWERBODY SAD
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(90,4000*k);
  lowerBody.wait(6000*k); // durata intero movimento
  lowerBody.stopSequence();

  //UPPERBODY SAD
  upperBody.startSequence(); 
  upperBody.moveRight(120,4000*k);     
  upperBody.wait(6000*k); //durata movimento head 
  upperBody.stopSequence();

  //HEAD SAD
  head.startSequence(); 
  head.wait(4000*k); 
  head.moveRight(10,500*k);
  head.moveLeft(10,1500*k);
  head.moveRight(10,1500*k);
  head.wait(2500*k); 
  head.stopSequence();

  //UPPERCAP SAD
  upperCap.startSequence();
  upperCap.wait(7500*k);
  upperCap.moveDown(20,2500*k); 
  upperCap.stopSequence();

  //LOWERCAP SAD
  lowerCap.startSequence();
  lowerCap.wait(7500*k);
  lowerCap.moveUp(20,2500*k);  
  lowerCap.stopSequence();
}


void RobotMovement::beSurprisedLeft(unsigned long duration, int robotAngularPosition) {
  float k = duration/96000.0;

  //LOWERBODY SURPRISED
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(25,2000*k);
  for (int i=0;i<2;i++){             //34000*2=68000
    for (int j=0;j<4;j++){           //4000*4=16000
        lowerBody.moveLeft(20,1000*k); 
        lowerBody.moveLeft(35,2000*k);
        lowerBody.moveLeft(30,1000*k);    
    }
    lowerBody.moveRight(25,2000*k);       //2000
    for (int l=0;l<4;l++){           //4000*4=16000
        lowerBody.moveRight(20,1000*k); 
        lowerBody.moveRight(35,2000*k);
        lowerBody.moveRight(30,1000*k);    
    }
  }
  lowerBody.moveRight(5,3000*k);        //3000
  lowerBody.wait(2000*k);               //2000
  lowerBody.moveLeft(10,1000*k);        //1000
  for (int i=0;i<5;i++){           //4000*5=20000
      lowerBody.moveRight(10,2000*k);
      lowerBody.moveLeft(10,2000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY SURPRISED
  upperBody.startSequence(); 
  upperBody.moveRight(60,2000*k);
  for (int i=0;i<2;i++){             //34000*2=68000
    for (int j=0;j<4;j++){           //4000*4=16000
        upperBody.moveRight(55,1000*k); 
        upperBody.moveRight(70,2000*k);
        upperBody.moveRight(65,1000*k);    
    }
    upperBody.moveLeft(60,2000*k);       //2000
    for (int l=0;l<4;l++){           //4000*4=16000
        upperBody.moveLeft(55,1000*k); 
        upperBody.moveLeft(70,2000*k);
        upperBody.moveLeft(65,1000*k);    
    }
  }
  upperBody.moveLeft(15,3000*k);       //3000
  upperBody.wait(23000*k);              //23000
  upperBody.stopSequence();

  //HEAD SURPRISED
  head.startSequence(); 
  head.moveLeft(35,2000*k);
  for (int i=0;i<2;i++){             //34000*2=68000
    for (int j=0;j<4;j++){           //4000*4=16000
        head.moveLeft(30,1000*k); 
        head.moveLeft(40,2000*k);
        head.moveLeft(35,1000*k);    
    }
    head.moveRight(35,2000*k);       //2000
    for (int l=0;l<4;l++){           //4000*4=16000
        head.moveRight(30,1000*k); 
        head.moveRight(40,2000*k);
        head.moveRight(35,1000*k);    
    }
  }
  head.moveRight(10,3000*k);      //3000
  head.wait(23000*k);            //23000
  head.stopSequence();

  //UPPERCAP SURPRISED       
  upperCap.startSequence();
  upperCap.moveUp(40,4000*k);          //chiedo max angolo
  for (int i=0;i<2;i++){             //32000*2=64000
    for (int j=0;j<4;j++){           //3000*4=12000
        upperCap.moveUp(30,1000*k); 
        upperCap.moveUp(35,1000*k);
        upperCap.moveUp(20,1000*k);    
    }
    upperCap.moveDown(20,8000*k);
    for (int l=0;l<4;l++){           //3000*4=12000
        upperCap.moveDown(15,1000*k); 
        upperCap.moveDown(5,1000*k);
        upperCap.moveDown(10,1000*k);    
    }
  }
  upperCap.moveDown(5,5000*k);     //5000
  upperCap.moveUp(5,1000*k);       //1000
  for (int i=0;i<5;i++){           //4000*5=20000
      upperCap.moveDown(5,2000*k); 
      upperCap.moveUp(5,2000*k);  
  }
  upperCap.moveDown(5,2000*k);    //2000
  upperCap.stopSequence();

  //LOWERCAP SURPRISED
  lowerCap.startSequence();
  lowerCap.moveDown(20,1000*k);
  for (int i=0;i<2;i++){             //32000*2=64000
    for (int j=0;j<4;j++){           //3000*4=12000
        lowerCap.moveDown(5,1000*k); 
        lowerCap.moveDown(20,1000*k);
        lowerCap.moveDown(10,1000*k);    
    }
    lowerCap.moveUp(20,8000*k);
    for (int l=0;l<4;l++){           //3000*4=12000
        lowerCap.moveUp(15,1000*k); 
        lowerCap.moveUp(5,1000*k);
        lowerCap.moveUp(10,1000*k);    
    }
  }
  lowerCap.moveUp(5,5000*k);     //5000
  lowerCap.moveDown(5,1000*k);       //1000
  for (int i=0;i<5;i++){           //4000*5=20000
      lowerCap.moveUp(5,2000*k); 
      lowerCap.moveDown(5,2000*k);  
  }
  lowerCap.moveUp(5,2000*k);    //2000
  lowerCap.stopSequence();
}
void RobotMovement::beSurprisedShort3Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //LOWERBODY SURPRISED
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(25,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    lowerBody.moveLeft(20,1000*k); 
    lowerBody.moveLeft(35,2000*k);
    lowerBody.moveLeft(30,1000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY SURPRISED
  upperBody.startSequence(); 
  upperBody.moveRight(60,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    upperBody.moveRight(55,1000*k); 
    upperBody.moveRight(70,2000*k);
    upperBody.moveRight(65,1000*k);    
  }
  upperBody.stopSequence();

  //HEAD SURPRISED
  head.startSequence(); 
  head.moveLeft(35,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    head.moveLeft(30,1000*k); 
    head.moveLeft(40,2000*k);
    head.moveLeft(35,1000*k);    
  }
  head.stopSequence();

  //UPPERCAP SURPRISED       
  upperCap.startSequence();
  upperCap.moveUp(40,4000*k);          //chiedo max angolo
  for (int j=0;j<2;j++){           //3000*2=6000
    upperCap.moveUp(30,1000*k); 
    upperCap.moveUp(35,1000*k);
    upperCap.moveUp(20,1000*k);    
  }
  upperCap.stopSequence();

  //LOWERCAP SURPRISED
  lowerCap.startSequence();
  lowerCap.moveDown(20,4000*k);
  for (int j=0;j<2;j++){           //3000*2=6000
    lowerCap.moveDown(5,1000*k); 
    lowerCap.moveDown(20,1000*k);
    lowerCap.moveDown(10,1000*k);    
  }
  lowerCap.stopSequence();
}
void RobotMovement::beSurprisedShort2Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //LOWERBODY SURPRISED
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(20,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    lowerBody.moveLeft(15,1000*k); 
    lowerBody.moveLeft(30,2000*k);
    lowerBody.moveLeft(25,1000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY SURPRISED
  upperBody.startSequence(); 
  upperBody.moveRight(55,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    upperBody.moveRight(50,1000*k); 
    upperBody.moveRight(65,2000*k);
    upperBody.moveRight(60,1000*k);    
  }
  upperBody.stopSequence();

  //HEAD SURPRISED
  head.startSequence(); 
  head.moveLeft(30,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    head.moveLeft(25,1000*k); 
    head.moveLeft(35,2000*k);
    head.moveLeft(30,1000*k);    
  }
  head.stopSequence();

  //UPPERCAP SURPRISED       
  upperCap.startSequence();
  upperCap.moveUp(35,4000*k);          
  for (int j=0;j<2;j++){           //3000*2=6000
    upperCap.moveUp(25,1000*k); 
    upperCap.moveUp(30,1000*k);
    upperCap.moveUp(15,1000*k);    
  }
  upperCap.stopSequence();

  //LOWERCAP SURPRISED
  lowerCap.startSequence();
  lowerCap.moveDown(15,4000*k);
  for (int j=0;j<2;j++){           //3000*2=6000
    lowerCap.goIdle(1000*k); 
    lowerCap.moveDown(15,1000*k);
    lowerCap.moveDown(5,1000*k);    
  }
  lowerCap.stopSequence();
}
void RobotMovement::beSurprisedShort1Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //LOWERBODY SURPRISED
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(15,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    lowerBody.moveLeft(10,1000*k); 
    lowerBody.moveLeft(25,2000*k);
    lowerBody.moveLeft(20,1000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY SURPRISED
  upperBody.startSequence(); 
  upperBody.moveRight(50,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    upperBody.moveRight(45,1000*k); 
    upperBody.moveRight(60,2000*k);
    upperBody.moveRight(55,1000*k);    
  }
  upperBody.stopSequence();

  //HEAD SURPRISED
  head.startSequence(); 
  head.moveLeft(25,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    head.moveLeft(20,1000*k); 
    head.moveLeft(30,2000*k);
    head.moveLeft(25,1000*k);    
  }
  head.stopSequence();

  //UPPERCAP SURPRISED       
  upperCap.startSequence();
  upperCap.moveUp(30,4000*k);          
  for (int j=0;j<2;j++){           //3000*2=6000
    upperCap.moveUp(20,1000*k); 
    upperCap.moveUp(25,1000*k);
    upperCap.moveUp(10,1000*k);    
  }
  upperCap.stopSequence();

  //LOWERCAP SURPRISED
  lowerCap.startSequence();
  lowerCap.moveDown(10,4000*k);
  for (int j=0;j<3;j++){           //2000*3=6000
    lowerCap.goIdle(1000*k); 
    lowerCap.moveDown(10,1000*k);   
  }
  lowerCap.stopSequence();
}

void RobotMovement::beSurprisedRight(unsigned long duration, int robotAngularPosition) {
  float k = duration/96000.0;

  //LOWERBODY SURPRISED
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(25,2000*k);
  for (int i=0;i<2;i++){             //34000*2=68000
    for (int j=0;j<4;j++){           //4000*4=16000
        lowerBody.moveRight(20,1000*k); 
        lowerBody.moveRight(35,2000*k);
        lowerBody.moveRight(30,1000*k);    
    }
    lowerBody.moveLeft(25,2000*k);       //2000
    for (int l=0;l<4;l++){           //4000*4=16000
        lowerBody.moveLeft(20,1000*k); 
        lowerBody.moveLeft(35,2000*k);
        lowerBody.moveLeft(30,1000*k);    
    }
  }
  lowerBody.moveLeft(5,3000*k);        //3000
  lowerBody.wait(2000*k);               //2000
  lowerBody.moveRight(10,1000*k);        //1000
  for (int i=0;i<5;i++){           //4000*5=20000
      lowerBody.moveLeft(10,2000*k);
      lowerBody.moveRight(10,2000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY SURPRISED
  upperBody.startSequence(); 
  upperBody.moveLeft(60,2000*k);
  for (int i=0;i<2;i++){             //34000*2=68000
    for (int j=0;j<4;j++){           //4000*4=16000
        upperBody.moveLeft(55,1000*k); 
        upperBody.moveLeft(70,2000*k);
        upperBody.moveLeft(65,1000*k);    
    }
    upperBody.moveRight(60,2000*k);       //2000
    for (int l=0;l<4;l++){           //4000*4=16000
        upperBody.moveRight(55,1000*k); 
        upperBody.moveRight(70,2000*k);
        upperBody.moveRight(65,1000*k);    
    }
  }
  upperBody.moveRight(15,3000*k);       //3000
  upperBody.wait(23000*k);              //23000
  upperBody.stopSequence();

  //HEAD SURPRISED
  head.startSequence(); 
  head.moveRight(35,2000*k);
  for (int i=0;i<2;i++){             //34000*2=68000
    for (int j=0;j<4;j++){           //4000*4=16000
        head.moveRight(30,1000*k); 
        head.moveRight(40,2000*k);
        head.moveRight(35,1000*k);    
    }
    head.moveLeft(35,2000*k);       //2000
    for (int l=0;l<4;l++){           //4000*4=16000
        head.moveLeft(30,1000*k); 
        head.moveLeft(40,2000*k);
        head.moveLeft(35,1000*k);    
    }
  }
  head.moveLeft(10,3000*k);      //3000
  head.wait(23000*k);            //23000
  head.stopSequence();

  //UPPERCAP SURPRISED       
  upperCap.startSequence();
  upperCap.moveUp(40,4000*k);          //chiedo max angolo
  for (int i=0;i<2;i++){             //32000*2=64000
    for (int j=0;j<4;j++){           //3000*4=12000
        upperCap.moveUp(30,1000*k); 
        upperCap.moveUp(35,1000*k);
        upperCap.moveUp(20,1000*k);    
    }
    upperCap.moveDown(20,8000*k);
    for (int l=0;l<4;l++){           //3000*4=12000
        upperCap.moveDown(15,1000*k); 
        upperCap.moveDown(5,1000*k);
        upperCap.moveDown(10,1000*k);    
    }
  }
  upperCap.moveDown(5,5000*k);     //5000
  upperCap.moveUp(5,1000*k);       //1000
  for (int i=0;i<5;i++){           //4000*5=20000
      upperCap.moveDown(5,2000*k); 
      upperCap.moveUp(5,2000*k);  
  }
  upperCap.moveDown(5,2000*k);    //2000
  upperCap.stopSequence();

  //LOWERCAP SURPRISED
  lowerCap.startSequence();
  lowerCap.moveDown(20,1000*k);
  for (int i=0;i<2;i++){             //32000*2=64000
    for (int j=0;j<4;j++){           //3000*4=12000
        lowerCap.moveDown(5,1000*k); 
        lowerCap.moveDown(20,1000*k);
        lowerCap.moveDown(10,1000*k);    
    }
    lowerCap.moveUp(20,8000*k);
    for (int l=0;l<4;l++){           //3000*4=12000
        lowerCap.moveUp(15,1000*k); 
        lowerCap.moveUp(5,1000*k);
        lowerCap.moveUp(10,1000*k);    
    }
  }
  lowerCap.moveUp(5,5000*k);     //5000
  lowerCap.moveDown(5,1000*k);       //1000
  for (int i=0;i<5;i++){           //4000*5=20000
      lowerCap.moveUp(5,2000*k); 
      lowerCap.moveDown(5,2000*k);  
  }
  lowerCap.moveUp(5,2000*k);    //2000
  lowerCap.stopSequence();
}
void RobotMovement::beSurprisedShort3Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //LOWERBODY SURPRISED
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(25,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    lowerBody.moveRight(20,1000*k); 
    lowerBody.moveRight(35,2000*k);
    lowerBody.moveRight(30,1000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY SURPRISED
  upperBody.startSequence(); 
  upperBody.moveLeft(60,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    upperBody.moveLeft(55,1000*k); 
    upperBody.moveLeft(70,2000*k);
    upperBody.moveLeft(65,1000*k);    
  }
  upperBody.stopSequence();

  //HEAD SURPRISED
  head.startSequence(); 
  head.moveRight(35,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    head.moveRight(30,1000*k); 
    head.moveRight(40,2000*k);
    head.moveRight(35,1000*k);    
  }
  head.stopSequence();

  //UPPERCAP SURPRISED       
  upperCap.startSequence();
  upperCap.moveUp(40,4000*k);          //chiedo max angolo
  for (int j=0;j<2;j++){           //3000*2=6000
    upperCap.moveUp(30,1000*k); 
    upperCap.moveUp(35,1000*k);
    upperCap.moveUp(20,1000*k);    
  }
  upperCap.stopSequence();

  //LOWERCAP SURPRISED
  lowerCap.startSequence();
  lowerCap.moveDown(20,4000*k);
  for (int j=0;j<2;j++){           //3000*2=6000
    lowerCap.moveDown(5,1000*k); 
    lowerCap.moveDown(20,1000*k);
    lowerCap.moveDown(10,1000*k);    
  }
  lowerCap.stopSequence();
}
void RobotMovement::beSurprisedShort2Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //LOWERBODY SURPRISED
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(20,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    lowerBody.moveRight(15,1000*k); 
    lowerBody.moveRight(30,2000*k);
    lowerBody.moveRight(25,1000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY SURPRISED
  upperBody.startSequence(); 
  upperBody.moveLeft(55,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    upperBody.moveLeft(50,1000*k); 
    upperBody.moveLeft(65,2000*k);
    upperBody.moveLeft(60,1000*k);    
  }
  upperBody.stopSequence();

  //HEAD SURPRISED
  head.startSequence(); 
  head.moveRight(30,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    head.moveRight(25,1000*k); 
    head.moveRight(35,2000*k);
    head.moveRight(30,1000*k);    
  }
  head.stopSequence();

  //UPPERCAP SURPRISED       
  upperCap.startSequence();
  upperCap.moveUp(35,4000*k);          
  for (int j=0;j<2;j++){           //3000*2=6000
    upperCap.moveUp(25,1000*k); 
    upperCap.moveUp(30,1000*k);
    upperCap.moveUp(15,1000*k);    
  }
  upperCap.stopSequence();

  //LOWERCAP SURPRISED
  lowerCap.startSequence();
  lowerCap.moveDown(15,4000*k);
  for (int j=0;j<2;j++){           //3000*2=6000
    lowerCap.goIdle(1000*k); 
    lowerCap.moveDown(15,1000*k);
    lowerCap.moveDown(5,1000*k);    
  }
  lowerCap.stopSequence();
}
void RobotMovement::beSurprisedShort1Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //LOWERBODY SURPRISED
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(15,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    lowerBody.moveRight(10,1000*k); 
    lowerBody.moveRight(25,2000*k);
    lowerBody.moveRight(20,1000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY SURPRISED
  upperBody.startSequence(); 
  upperBody.moveLeft(50,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    upperBody.moveLeft(45,1000*k); 
    upperBody.moveLeft(60,2000*k);
    upperBody.moveLeft(55,1000*k);    
  }
  upperBody.stopSequence();

  //HEAD SURPRISED
  head.startSequence(); 
  head.moveRight(25,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    head.moveRight(20,1000*k); 
    head.moveRight(30,2000*k);
    head.moveRight(25,1000*k);    
  }
  head.stopSequence();

  //UPPERCAP SURPRISED       
  upperCap.startSequence();
  upperCap.moveUp(30,4000*k);          
  for (int j=0;j<2;j++){           //3000*2=6000
    upperCap.moveUp(20,1000*k); 
    upperCap.moveUp(25,1000*k);
    upperCap.moveUp(10,1000*k);    
  }
  upperCap.stopSequence();

  //LOWERCAP SURPRISED
  lowerCap.startSequence();
  lowerCap.moveDown(10,4000*k);
  for (int j=0;j<3;j++){           //2000*3=6000
    lowerCap.goIdle(1000*k); 
    lowerCap.moveDown(10,1000*k);   
  }
  lowerCap.stopSequence();
}



void RobotMovement::beCautiousLeft(unsigned long duration, int robotAngularPosition) {
  float k = duration/96000.0;

  //LOWERBODY CAUTIOUS
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(25,2000*k);
  for (int i=0;i<2;i++){             //34000*2=68000
    for (int j=0;j<4;j++){           //4000*4=16000
        lowerBody.moveLeft(20,1000*k); 
        lowerBody.moveLeft(35,2000*k);
        lowerBody.moveLeft(30,1000*k);    
    }
    lowerBody.moveRight(25,2000*k);       //2000
    for (int l=0;l<4;l++){           //4000*4=16000
        lowerBody.moveRight(20,1000*k); 
        lowerBody.moveRight(35,2000*k);
        lowerBody.moveRight(30,1000*k);    
    }
  }
  lowerBody.moveRight(5,3000*k);        //3000
  lowerBody.wait(2000*k);               //2000
  lowerBody.moveLeft(10,1000*k);        //1000
  for (int i=0;i<5;i++){           //4000*5=20000
      lowerBody.moveRight(10,2000*k);
      lowerBody.moveLeft(10,2000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY CAUTIOUS
  upperBody.startSequence(); 
  upperBody.moveRight(60,2000*k);
  for (int i=0;i<2;i++){             //34000*2=68000
    for (int j=0;j<4;j++){           //4000*4=16000
        upperBody.moveRight(55,1000*k); 
        upperBody.moveRight(70,2000*k);
        upperBody.moveRight(65,1000*k);    
    }
    upperBody.moveLeft(60,2000*k);       //2000
    for (int l=0;l<4;l++){           //4000*4=16000
        upperBody.moveLeft(55,1000*k); 
        upperBody.moveLeft(70,2000*k);
        upperBody.moveLeft(65,1000*k);    
    }
  }
  upperBody.moveLeft(15,3000*k);       //3000
  upperBody.wait(23000*k);              //23000
  upperBody.stopSequence();

  //HEAD CAUTIOUS
  head.startSequence(); 
  head.moveLeft(35,2000*k);
  for (int i=0;i<2;i++){             //34000*2=68000
    for (int j=0;j<4;j++){           //4000*4=16000
        head.moveLeft(30,1000*k); 
        head.moveLeft(40,2000*k);
        head.moveLeft(35,1000*k);    
    }
    head.moveRight(35,2000*k);       //2000
    for (int l=0;l<4;l++){           //4000*4=16000
        head.moveRight(30,1000*k); 
        head.moveRight(40,2000*k);
        head.moveRight(35,1000*k);    
    }
  }
  head.moveRight(10,3000*k);      //3000
  head.wait(23000*k);            //23000
  head.stopSequence();

  //UPPERCAP CAUTIOUS      
  upperCap.startSequence();
  upperCap.moveUp(40,4000*k);          //chiedo max angolo
  for (int i=0;i<2;i++){             //32000*2=64000
    for (int j=0;j<4;j++){           //3000*4=12000
        upperCap.moveUp(30,1000*k); 
        upperCap.moveUp(35,1000*k);
        upperCap.moveUp(20,1000*k);    
    }
    upperCap.moveDown(20,8000*k);
    for (int l=0;l<4;l++){           //3000*4=12000
        upperCap.moveDown(15,1000*k); 
        upperCap.moveDown(5,1000*k);
        upperCap.moveDown(10,1000*k);    
    }
  }
  upperCap.moveDown(5,5000*k);     //5000
  upperCap.moveUp(5,1000*k);       //1000
  for (int i=0;i<5;i++){           //4000*5=20000
      upperCap.moveDown(5,2000*k); 
      upperCap.moveUp(5,2000*k);  
  }
  upperCap.moveDown(5,2000*k);    //2000
  upperCap.stopSequence();

  //LOWERCAP CAUTIOUS
  lowerCap.startSequence();
  lowerCap.moveDown(20,1000*k);
  for (int i=0;i<2;i++){             //32000*2=64000
    for (int j=0;j<4;j++){           //3000*4=12000
        lowerCap.moveDown(5,1000*k); 
        lowerCap.moveDown(20,1000*k);
        lowerCap.moveDown(10,1000*k);    
    }
    lowerCap.moveUp(20,8000*k);
    for (int l=0;l<4;l++){           //3000*4=12000
        lowerCap.moveUp(15,1000*k); 
        lowerCap.moveUp(5,1000*k);
        lowerCap.moveUp(10,1000*k);    
    }
  }
  lowerCap.moveUp(5,5000*k);     //5000
  lowerCap.moveDown(5,1000*k);       //1000
  for (int i=0;i<5;i++){           //4000*5=20000
      lowerCap.moveUp(5,2000*k); 
      lowerCap.moveDown(5,2000*k);  
  }
  lowerCap.moveUp(5,2000*k);    //2000
  lowerCap.stopSequence();
}
void RobotMovement::beCautiousShort3Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //LOWERBODY CAUTIOUS
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(25,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    lowerBody.moveLeft(20,1000*k); 
    lowerBody.moveLeft(35,2000*k);
    lowerBody.moveLeft(30,1000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY CAUTIOUS
  upperBody.startSequence(); 
  upperBody.moveRight(60,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    upperBody.moveRight(55,1000*k); 
    upperBody.moveRight(70,2000*k);
    upperBody.moveRight(65,1000*k);    
  }
  upperBody.stopSequence();

  //HEAD CAUTIOUS
  head.startSequence(); 
  head.moveLeft(35,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    head.moveLeft(30,1000*k); 
    head.moveLeft(40,2000*k);
    head.moveLeft(35,1000*k);    
  }
  head.stopSequence();

  //UPPERCAP CAUTIOUS       
  upperCap.startSequence();
  upperCap.moveUp(40,4000*k);          //chiedo max angolo
  for (int j=0;j<2;j++){           //3000*2=6000
    upperCap.moveUp(30,1000*k); 
    upperCap.moveUp(35,1000*k);
    upperCap.moveUp(20,1000*k);    
  }
  upperCap.stopSequence();

  //LOWERCAP CAUTIOUS
  lowerCap.startSequence();
  lowerCap.moveDown(20,4000*k);
  for (int j=0;j<2;j++){           //3000*2=6000
    lowerCap.moveDown(5,1000*k); 
    lowerCap.moveDown(20,1000*k);
    lowerCap.moveDown(10,1000*k);    
  }
  lowerCap.stopSequence();
}
void RobotMovement::beCautiousShort2Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //LOWERBODY CAUTIOUS
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(20,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    lowerBody.moveLeft(15,1000*k); 
    lowerBody.moveLeft(30,2000*k);
    lowerBody.moveLeft(25,1000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY CAUTIOUS
  upperBody.startSequence(); 
  upperBody.moveRight(55,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    upperBody.moveRight(50,1000*k); 
    upperBody.moveRight(65,2000*k);
    upperBody.moveRight(60,1000*k);    
  }
  upperBody.stopSequence();

  //HEAD CAUTIOUS
  head.startSequence(); 
  head.moveLeft(30,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    head.moveLeft(25,1000*k); 
    head.moveLeft(35,2000*k);
    head.moveLeft(30,1000*k);    
  }
  head.stopSequence();

  //UPPERCAP CAUTIOUS       
  upperCap.startSequence();
  upperCap.moveUp(35,4000*k);          
  for (int j=0;j<2;j++){           //3000*2=6000
    upperCap.moveUp(25,1000*k); 
    upperCap.moveUp(30,1000*k);
    upperCap.moveUp(15,1000*k);    
  }
  upperCap.stopSequence();

  //LOWERCAP CAUTIOUS
  lowerCap.startSequence();
  lowerCap.moveDown(15,4000*k);
  for (int j=0;j<2;j++){           //3000*2=6000
    lowerCap.goIdle(1000*k); 
    lowerCap.moveDown(15,1000*k);
    lowerCap.moveDown(5,1000*k);    
  }
  lowerCap.stopSequence();
}
void RobotMovement::beCautiousShort1Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //LOWERBODY CAUTIOUS
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveLeft(15,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    lowerBody.moveLeft(10,1000*k); 
    lowerBody.moveLeft(25,2000*k);
    lowerBody.moveLeft(20,1000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY CAUTIOUS
  upperBody.startSequence(); 
  upperBody.moveRight(50,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    upperBody.moveRight(45,1000*k); 
    upperBody.moveRight(60,2000*k);
    upperBody.moveRight(55,1000*k);    
  }
  upperBody.stopSequence();

  //HEAD CAUTIOUS
  head.startSequence(); 
  head.moveLeft(25,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    head.moveLeft(20,1000*k); 
    head.moveLeft(30,2000*k);
    head.moveLeft(25,1000*k);    
  }
  head.stopSequence();

  //UPPERCAP CAUTIOUS      
  upperCap.startSequence();
  upperCap.moveUp(30,4000*k);          
  for (int j=0;j<2;j++){           //3000*2=6000
    upperCap.moveUp(20,1000*k); 
    upperCap.moveUp(25,1000*k);
    upperCap.moveUp(10,1000*k);    
  }
  upperCap.stopSequence();

  //LOWERCAP CAUTIOUS
  lowerCap.startSequence();
  lowerCap.moveDown(10,4000*k);
  for (int j=0;j<3;j++){           //2000*3=6000
    lowerCap.goIdle(1000*k); 
    lowerCap.moveDown(10,1000*k);   
  }
  lowerCap.stopSequence();
}

void RobotMovement::beCautiousRight(unsigned long duration, int robotAngularPosition) {
  float k = duration/96000.0;

  //LOWERBODY CAUTIOUS
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(25,2000*k);
  for (int i=0;i<2;i++){             //34000*2=68000
    for (int j=0;j<4;j++){           //4000*4=16000
        lowerBody.moveRight(20,1000*k); 
        lowerBody.moveRight(35,2000*k);
        lowerBody.moveRight(30,1000*k);    
    }
    lowerBody.moveLeft(25,2000*k);       //2000
    for (int l=0;l<4;l++){           //4000*4=16000
        lowerBody.moveLeft(20,1000*k); 
        lowerBody.moveLeft(35,2000*k);
        lowerBody.moveLeft(30,1000*k);    
    }
  }
  lowerBody.moveLeft(5,3000*k);        //3000
  lowerBody.wait(2000*k);               //2000
  lowerBody.moveRight(10,1000*k);        //1000
  for (int i=0;i<5;i++){           //4000*5=20000
      lowerBody.moveLeft(10,2000*k);
      lowerBody.moveRight(10,2000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY CAUTIOUS
  upperBody.startSequence(); 
  upperBody.moveLeft(60,2000*k);
  for (int i=0;i<2;i++){             //34000*2=68000
    for (int j=0;j<4;j++){           //4000*4=16000
        upperBody.moveLeft(55,1000*k); 
        upperBody.moveLeft(70,2000*k);
        upperBody.moveLeft(65,1000*k);    
    }
    upperBody.moveRight(60,2000*k);       //2000
    for (int l=0;l<4;l++){           //4000*4=16000
        upperBody.moveRight(55,1000*k); 
        upperBody.moveRight(70,2000*k);
        upperBody.moveRight(65,1000*k);    
    }
  }
  upperBody.moveRight(15,3000*k);       //3000
  upperBody.wait(23000*k);              //23000
  upperBody.stopSequence();

  //HEAD CAUTIOUS
  head.startSequence(); 
  head.moveRight(35,2000*k);
  for (int i=0;i<2;i++){             //34000*2=68000
    for (int j=0;j<4;j++){           //4000*4=16000
        head.moveRight(30,1000*k); 
        head.moveRight(40,2000*k);
        head.moveRight(35,1000*k);    
    }
    head.moveLeft(35,2000*k);       //2000
    for (int l=0;l<4;l++){           //4000*4=16000
        head.moveLeft(30,1000*k); 
        head.moveLeft(40,2000*k);
        head.moveLeft(35,1000*k);    
    }
  }
  head.moveLeft(10,3000*k);      //3000
  head.wait(23000*k);            //23000
  head.stopSequence();

  //UPPERCAP CAUTIOUS      
  upperCap.startSequence();
  upperCap.moveUp(40,4000*k);          //chiedo max angolo
  for (int i=0;i<2;i++){             //32000*2=64000
    for (int j=0;j<4;j++){           //3000*4=12000
        upperCap.moveUp(30,1000*k); 
        upperCap.moveUp(35,1000*k);
        upperCap.moveUp(20,1000*k);    
    }
    upperCap.moveDown(20,8000*k);
    for (int l=0;l<4;l++){           //3000*4=12000
        upperCap.moveDown(15,1000*k); 
        upperCap.moveDown(5,1000*k);
        upperCap.moveDown(10,1000*k);    
    }
  }
  upperCap.moveDown(5,5000*k);     //5000
  upperCap.moveUp(5,1000*k);       //1000
  for (int i=0;i<5;i++){           //4000*5=20000
      upperCap.moveDown(5,2000*k); 
      upperCap.moveUp(5,2000*k);  
  }
  upperCap.moveDown(5,2000*k);    //2000
  upperCap.stopSequence();

  //LOWERCAP CAUTIOUS
  lowerCap.startSequence();
  lowerCap.moveDown(20,1000*k);
  for (int i=0;i<2;i++){             //32000*2=64000
    for (int j=0;j<4;j++){           //3000*4=12000
        lowerCap.moveDown(5,1000*k); 
        lowerCap.moveDown(20,1000*k);
        lowerCap.moveDown(10,1000*k);    
    }
    lowerCap.moveUp(20,8000*k);
    for (int l=0;l<4;l++){           //3000*4=12000
        lowerCap.moveUp(15,1000*k); 
        lowerCap.moveUp(5,1000*k);
        lowerCap.moveUp(10,1000*k);    
    }
  }
  lowerCap.moveUp(5,5000*k);     //5000
  lowerCap.moveDown(5,1000*k);       //1000
  for (int i=0;i<5;i++){           //4000*5=20000
      lowerCap.moveUp(5,2000*k); 
      lowerCap.moveDown(5,2000*k);  
  }
  lowerCap.moveUp(5,2000*k);    //2000
  lowerCap.stopSequence();
}
void RobotMovement::beCautiousShort3Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //LOWERBODY CAUTIOUS
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(25,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    lowerBody.moveRight(20,1000*k); 
    lowerBody.moveRight(35,2000*k);
    lowerBody.moveRight(30,1000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY CAUTIOUS
  upperBody.startSequence(); 
  upperBody.moveLeft(60,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    upperBody.moveLeft(55,1000*k); 
    upperBody.moveLeft(70,2000*k);
    upperBody.moveLeft(65,1000*k);    
  }
  upperBody.stopSequence();

  //HEAD CAUTIOUS
  head.startSequence(); 
  head.moveRight(35,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    head.moveRight(30,1000*k); 
    head.moveRight(40,2000*k);
    head.moveRight(35,1000*k);    
  }
  head.stopSequence();

  //UPPERCAP CAUTIOUS       
  upperCap.startSequence();
  upperCap.moveUp(40,4000*k);          //chiedo max angolo
  for (int j=0;j<2;j++){           //3000*2=6000
    upperCap.moveUp(30,1000*k); 
    upperCap.moveUp(35,1000*k);
    upperCap.moveUp(20,1000*k);    
  }
  upperCap.stopSequence();

  //LOWERCAP CAUTIOUS
  lowerCap.startSequence();
  lowerCap.moveDown(20,4000*k);
  for (int j=0;j<2;j++){           //3000*2=6000
    lowerCap.moveDown(5,1000*k); 
    lowerCap.moveDown(20,1000*k);
    lowerCap.moveDown(10,1000*k);    
  }
  lowerCap.stopSequence();
}
void RobotMovement::beCautiousShort2Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //LOWERBODY CAUTIOUS
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(20,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    lowerBody.moveRight(15,1000*k); 
    lowerBody.moveRight(30,2000*k);
    lowerBody.moveRight(25,1000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY CAUTIOUS
  upperBody.startSequence(); 
  upperBody.moveLeft(55,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    upperBody.moveLeft(50,1000*k); 
    upperBody.moveLeft(65,2000*k);
    upperBody.moveLeft(60,1000*k);    
  }
  upperBody.stopSequence();

  //HEAD CAUTIOUS
  head.startSequence(); 
  head.moveRight(30,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    head.moveRight(25,1000*k); 
    head.moveRight(35,2000*k);
    head.moveRight(30,1000*k);    
  }
  head.stopSequence();

  //UPPERCAP CAUTIOUS       
  upperCap.startSequence();
  upperCap.moveUp(35,4000*k);          
  for (int j=0;j<2;j++){           //3000*2=6000
    upperCap.moveUp(25,1000*k); 
    upperCap.moveUp(30,1000*k);
    upperCap.moveUp(15,1000*k);    
  }
  upperCap.stopSequence();

  //LOWERCAP CAUTIOUS
  lowerCap.startSequence();
  lowerCap.moveDown(15,4000*k);
  for (int j=0;j<2;j++){           //3000*2=6000
    lowerCap.goIdle(1000*k); 
    lowerCap.moveDown(15,1000*k);
    lowerCap.moveDown(5,1000*k);    
  }
  lowerCap.stopSequence();
}
void RobotMovement::beCautiousShort1Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //LOWERBODY CAUTIOUS
  lowerBody.startSequence(robotAngularPosition); 
  lowerBody.moveRight(15,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    lowerBody.moveRight(10,1000*k); 
    lowerBody.moveRight(25,2000*k);
    lowerBody.moveRight(20,1000*k);    
  }
  lowerBody.stopSequence();

  // UPPERBODY CAUTIOUS
  upperBody.startSequence(); 
  upperBody.moveLeft(50,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    upperBody.moveLeft(45,1000*k); 
    upperBody.moveLeft(60,2000*k);
    upperBody.moveLeft(55,1000*k);    
  }
  upperBody.stopSequence();

  //HEAD CAUTIOUS
  head.startSequence(); 
  head.moveRight(25,2000*k);
  for (int j=0;j<2;j++){           //4000*2=8000
    head.moveRight(20,1000*k); 
    head.moveRight(30,2000*k);
    head.moveRight(25,1000*k);    
  }
  head.stopSequence();

  //UPPERCAP CAUTIOUS      
  upperCap.startSequence();
  upperCap.moveUp(30,4000*k);          
  for (int j=0;j<2;j++){           //3000*2=6000
    upperCap.moveUp(20,1000*k); 
    upperCap.moveUp(25,1000*k);
    upperCap.moveUp(10,1000*k);    
  }
  upperCap.stopSequence();

  //LOWERCAP CAUTIOUS
  lowerCap.startSequence();
  lowerCap.moveDown(10,4000*k);
  for (int j=0;j<3;j++){           //2000*3=6000
    lowerCap.goIdle(1000*k); 
    lowerCap.moveDown(10,1000*k);   
  }
  lowerCap.stopSequence();
}



void RobotMovement::beAngryLeft(unsigned long duration, int robotAngularPosition) {
  float k = duration/85500.0;

  //UPPERBODY ANGRY
  upperBody.startSequence(); 
  upperBody.moveLeft(25,500*k);
  upperBody.moveLeft(30,1500*k);
  upperBody.wait(1500*k);
  for (int i=0;i<3;i++){           //11000*3=33000
    upperBody.moveRight(25,1000*k);
    upperBody.moveRight(30,3000*k);
    upperBody.wait(1500*k);
    upperBody.moveLeft(25,1000*k);
    upperBody.moveLeft(30,3000*k);   
    upperBody.wait(1500*k);
  }
  for (int i=0;i<3;i++){           //8000*3=24000
    upperBody.moveRight(35,1000*k);
    upperBody.moveRight(40,3000*k);
    upperBody.moveLeft(35,1000*k);
    upperBody.moveLeft(40,3000*k);     
  }  
  upperBody.moveRight(10,1000*k);       //1000
  for (int i=0;i<4;i++){           //6000*4=24000
    upperBody.moveLeft(10,1000*k);
    upperBody.moveRight(10,1000*k);
    upperBody.moveLeft(10,2000*k);
    upperBody.moveRight(10,2000*k);    
  }
  upperBody.stopSequence();

  //HEAD ANGRY
  head.startSequence(); 
  head.moveLeft(25,500*k);
  head.moveLeft(30,2000*k);
  head.wait(1000*k);
  for (int i=0;i<3;i++){           //11000*3=33000
    head.moveRight(25,500*k);
    head.moveRight(30,4000*k);
    head.wait(1000*k);
    head.moveLeft(25,500*k);
    head.moveLeft(30,4000*k);   
    head.wait(1000*k);
  }
  for (int i=0;i<3;i++){           //8000*3=24000
    head.moveRight(50,1000*k);
    head.moveRight(55,3000*k);
    head.moveLeft(50,1000*k);
    head.moveLeft(55,3000*k);     
  } 
  head.moveRight(10,1000*k);       //1000
  for (int i=0;i<4;i++){           //6000*4=24000
    head.moveLeft(10,1000*k);
    head.moveRight(10,1000*k);
    head.moveLeft(10,2000*k);
    head.moveRight(10,2000*k);    
  } 
  head.stopSequence();

  //UPPERCAP ANGRY
  upperCap.startSequence(); //movim deve finire entro movim upperBody
  upperCap.wait(2500*k);
  upperCap.moveDown(20,500*k);  
  upperCap.moveUp(20,500*k);
  for (int i=0;i<6;i++){   //5500*6=33000
    upperCap.wait(4500*k);
    upperCap.moveDown(20,500*k);  
    upperCap.moveUp(20,500*k);
  }
  for (int i=0;i<6;i++){   //4000*6=24000
    upperCap.wait(1000*k);
    upperCap.moveDown(20,1500*k);  
    upperCap.moveUp(20,1500*k);
  }
  upperCap.wait(25000*k);    //25000
  upperCap.stopSequence();

  //LOWERCAP ANGRY
  lowerCap.startSequence();
  lowerCap.wait(2500*k);
  lowerCap.moveUp(20,500*k);
  lowerCap.moveDown(20,500*k); 
  for (int i=0;i<6;i++){   //5500*6=33000
    lowerCap.wait(4500*k);
    lowerCap.moveUp(20,500*k);  
    lowerCap.moveDown(20,500*k);
  }
  for (int i=0;i<6;i++){   //4000*6=24000
    lowerCap.wait(1000*k);
    lowerCap.moveUp(20,1500*k);  
    lowerCap.moveDown(20,1500*k);
  }
  lowerCap.wait(25000*k);    //25000  
  lowerCap.stopSequence();
}
void RobotMovement::beAngryShort3Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //UPPERBODY ANGRY
  upperBody.startSequence(); 
  upperBody.moveLeft(35,500*k);
  upperBody.moveLeft(40,1500*k);
  upperBody.wait(1500*k);
  upperBody.moveRight(35,1000*k);
  upperBody.moveRight(40,3000*k);
  upperBody.wait(2500*k);
  upperBody.stopSequence();

  //HEAD ANGRY
  head.startSequence(); 
  head.moveLeft(50,500*k);
  head.moveLeft(55,2000*k);
  head.wait(1000*k);
  head.moveRight(50,500*k);
  head.moveRight(55,4000*k);
  head.wait(2000*k);
  head.stopSequence();

  //UPPERCAP ANGRY
  upperCap.startSequence(); 
  upperCap.wait(2500*k);
  upperCap.moveDown(20,500*k);  
  upperCap.moveUp(20,500*k);
  upperCap.wait(4500*k);
  upperCap.moveDown(20,500*k);  
  upperCap.moveUp(20,500*k);
  upperCap.wait(1000*k);
  upperCap.stopSequence();

  //LOWERCAP ANGRY
  lowerCap.startSequence();
  lowerCap.wait(2500*k);
  lowerCap.moveUp(20,500*k);
  lowerCap.moveDown(20,500*k); 
  lowerCap.wait(4500*k);
  lowerCap.moveUp(20,500*k);  
  lowerCap.moveDown(20,500*k);
  lowerCap.stopSequence();
  lowerCap.wait(1000*k);
}
void RobotMovement::beAngryShort2Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //UPPERBODY ANGRY
  upperBody.startSequence(); 
  upperBody.moveLeft(25,500*k);
  upperBody.moveLeft(30,1500*k);
  upperBody.wait(1500*k);
  upperBody.moveRight(25,1000*k);
  upperBody.moveRight(30,3000*k);
  upperBody.wait(2500*k);
  upperBody.stopSequence();

  //HEAD ANGRY
  head.startSequence(); 
  head.moveLeft(25,500*k);
  head.moveLeft(30,2000*k);
  head.wait(1000*k);
  head.moveRight(25,500*k);
  head.moveRight(30,4000*k);
  head.wait(2000*k);
  head.stopSequence();

  //UPPERCAP ANGRY
  upperCap.startSequence(); 
  upperCap.wait(2500*k);
  upperCap.moveDown(15,500*k);  
  upperCap.moveUp(15,500*k);
  upperCap.wait(4500*k);
  upperCap.moveDown(15,500*k);  
  upperCap.moveUp(15,500*k);
  upperCap.wait(1000*k);
  upperCap.stopSequence();

  //LOWERCAP ANGRY
  lowerCap.startSequence();
  lowerCap.wait(2500*k);
  lowerCap.moveUp(15,500*k);
  lowerCap.moveDown(15,500*k); 
  lowerCap.wait(4500*k);
  lowerCap.moveUp(15,500*k);  
  lowerCap.moveDown(15,500*k);
  lowerCap.wait(1000*k);
  lowerCap.stopSequence();
}
void RobotMovement::beAngryShort1Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //UPPERBODY ANGRY
  upperBody.startSequence(); 
  upperBody.moveLeft(15,500*k);
  upperBody.moveLeft(20,1500*k);
  upperBody.wait(1500*k);
  upperBody.moveRight(15,1000*k);
  upperBody.moveRight(20,3000*k);
  upperBody.wait(2500*k);
  upperBody.stopSequence();

  //HEAD ANGRY
  head.startSequence(); 
  head.moveLeft(15,500*k);
  head.moveLeft(20,2000*k);
  head.wait(1000*k);
  head.moveRight(15,500*k);
  head.moveRight(20,4000*k);
  head.wait(2000*k);
  head.stopSequence();

  //UPPERCAP ANGRY
  upperCap.startSequence(); 
  upperCap.wait(2500*k);
  upperCap.moveDown(10,500*k);  
  upperCap.moveUp(10,500*k);
  upperCap.wait(4500*k);
  upperCap.moveDown(10,500*k);  
  upperCap.moveUp(10,500*k);
  upperCap.wait(1000*k);
  upperCap.stopSequence();

  //LOWERCAP ANGRY
  lowerCap.startSequence();
  lowerCap.wait(2500*k);
  lowerCap.moveUp(10,500*k);
  lowerCap.moveDown(10,500*k); 
  lowerCap.wait(4500*k);
  lowerCap.moveUp(10,500*k);  
  lowerCap.moveDown(10,500*k);
  lowerCap.wait(1000*k);
  lowerCap.stopSequence();
}

void RobotMovement::beAngryRight(unsigned long duration, int robotAngularPosition) {
  float k = duration/85500.0;

  //UPPERBODY ANGRY
  upperBody.startSequence(); 
  upperBody.moveRight(25,500*k);
  upperBody.moveRight(30,1500*k);
  upperBody.wait(1500*k);
  for (int i=0;i<3;i++){           //11000*3=33000
    upperBody.moveLeft(25,1000*k);
    upperBody.moveLeft(30,3000*k);
    upperBody.wait(1500*k);
    upperBody.moveRight(25,1000*k);
    upperBody.moveRight(30,3000*k);   
    upperBody.wait(1500*k);
  }
  for (int i=0;i<3;i++){           //8000*3=24000
    upperBody.moveLeft(35,1000*k);
    upperBody.moveLeft(40,3000*k);
    upperBody.moveRight(35,1000*k);
    upperBody.moveRight(40,3000*k);     
  }  
  upperBody.moveLeft(10,1000*k);       //1000
  for (int i=0;i<4;i++){           //6000*4=24000
    upperBody.moveRight(10,1000*k);
    upperBody.moveLeft(10,1000*k);
    upperBody.moveRight(10,2000*k);
    upperBody.moveLeft(10,2000*k);    
  }
  upperBody.stopSequence();

  //HEAD ANGRY
  head.startSequence(); 
  head.moveRight(25,500*k);
  head.moveRight(30,2000*k);
  head.wait(1000*k);
  for (int i=0;i<3;i++){           //11000*3=33000
    head.moveLeft(25,500*k);
    head.moveLeft(30,4000*k);
    head.wait(1000*k);
    head.moveRight(25,500*k);
    head.moveRight(30,4000*k);   
    head.wait(1000*k);
  }
  for (int i=0;i<3;i++){           //8000*3=24000
    head.moveLeft(50,1000*k);
    head.moveLeft(55,3000*k);
    head.moveRight(50,1000*k);
    head.moveRight(55,3000*k);     
  } 
  head.moveLeft(10,1000*k);       //1000
  for (int i=0;i<4;i++){           //6000*4=24000
    head.moveRight(10,1000*k);
    head.moveLeft(10,1000*k);
    head.moveRight(10,2000*k);
    head.moveLeft(10,2000*k);    
  } 
  head.stopSequence();

  //UPPERCAP ANGRY
  upperCap.startSequence(); //movim deve finire entro movim upperBody
  upperCap.wait(2500*k);
  upperCap.moveDown(20,500*k);  
  upperCap.moveUp(20,500*k);
  for (int i=0;i<6;i++){   //5500*6=33000
    upperCap.wait(4500*k);
    upperCap.moveDown(20,500*k);  
    upperCap.moveUp(20,500*k);
  }
  for (int i=0;i<6;i++){   //4000*6=24000
    upperCap.wait(1000*k);
    upperCap.moveDown(20,1500*k);  
    upperCap.moveUp(20,1500*k);
  }
  upperCap.wait(25000*k);    //25000
  upperCap.stopSequence();

  //LOWERCAP ANGRY
  lowerCap.startSequence();
  lowerCap.wait(2500*k);
  lowerCap.moveUp(20,500*k);
  lowerCap.moveDown(20,500*k); 
  for (int i=0;i<6;i++){   //5500*6=33000
    lowerCap.wait(4500*k);
    lowerCap.moveUp(20,500*k);  
    lowerCap.moveDown(20,500*k);
  }
  for (int i=0;i<6;i++){   //4000*6=24000
    lowerCap.wait(1000*k);
    lowerCap.moveUp(20,1500*k);  
    lowerCap.moveDown(20,1500*k);
  }
  lowerCap.wait(25000*k);    //25000  
  lowerCap.stopSequence();
}
void RobotMovement::beAngryShort3Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //UPPERBODY ANGRY
  upperBody.startSequence(); 
  upperBody.moveRight(35,500*k);
  upperBody.moveRight(40,1500*k);
  upperBody.wait(1500*k);
  upperBody.moveLeft(35,1000*k);
  upperBody.moveLeft(40,3000*k);
  upperBody.wait(2500*k);
  upperBody.stopSequence();

  //HEAD ANGRY
  head.startSequence(); 
  head.moveRight(50,500*k);
  head.moveRight(55,2000*k);
  head.wait(1000*k);
  head.moveLeft(50,500*k);
  head.moveLeft(55,4000*k);
  head.wait(2000*k);
  head.stopSequence();

  //UPPERCAP ANGRY
  upperCap.startSequence(); 
  upperCap.wait(2500*k);
  upperCap.moveDown(20,500*k);  
  upperCap.moveUp(20,500*k);
  upperCap.wait(4500*k);
  upperCap.moveDown(20,500*k);  
  upperCap.moveUp(20,500*k);
  upperCap.wait(1000*k);
  upperCap.stopSequence();

  //LOWERCAP ANGRY
  lowerCap.startSequence();
  lowerCap.wait(2500*k);
  lowerCap.moveUp(20,500*k);
  lowerCap.moveDown(20,500*k); 
  lowerCap.wait(4500*k);
  lowerCap.moveUp(20,500*k);  
  lowerCap.moveDown(20,500*k);
  lowerCap.stopSequence();
  lowerCap.wait(1000*k);
}
void RobotMovement::beAngryShort2Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //UPPERBODY ANGRY
  upperBody.startSequence(); 
  upperBody.moveRight(25,500*k);
  upperBody.moveRight(30,1500*k);
  upperBody.wait(1500*k);
  upperBody.moveLeft(25,1000*k);
  upperBody.moveLeft(30,3000*k);
  upperBody.wait(2500*k);
  upperBody.stopSequence();

  //HEAD ANGRY
  head.startSequence(); 
  head.moveRight(25,500*k);
  head.moveRight(30,2000*k);
  head.wait(1000*k);
  head.moveLeft(25,500*k);
  head.moveLeft(30,4000*k);
  head.wait(2000*k);
  head.stopSequence();

  //UPPERCAP ANGRY
  upperCap.startSequence(); 
  upperCap.wait(2500*k);
  upperCap.moveDown(15,500*k);  
  upperCap.moveUp(15,500*k);
  upperCap.wait(4500*k);
  upperCap.moveDown(15,500*k);  
  upperCap.moveUp(15,500*k);
  upperCap.wait(1000*k);
  upperCap.stopSequence();

  //LOWERCAP ANGRY
  lowerCap.startSequence();
  lowerCap.wait(2500*k);
  lowerCap.moveUp(15,500*k);
  lowerCap.moveDown(15,500*k); 
  lowerCap.wait(4500*k);
  lowerCap.moveUp(15,500*k);  
  lowerCap.moveDown(15,500*k);
  lowerCap.wait(1000*k);
  lowerCap.stopSequence();
}
void RobotMovement::beAngryShort1Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;

  //UPPERBODY ANGRY
  upperBody.startSequence(); 
  upperBody.moveRight(15,500*k);
  upperBody.moveRight(20,1500*k);
  upperBody.wait(1500*k);
  upperBody.moveLeft(15,1000*k);
  upperBody.moveLeft(20,3000*k);
  upperBody.wait(2500*k);
  upperBody.stopSequence();

  //HEAD ANGRY
  head.startSequence(); 
  head.moveRight(15,500*k);
  head.moveRight(20,2000*k);
  head.wait(1000*k);
  head.moveLeft(15,500*k);
  head.moveLeft(20,4000*k);
  head.wait(2000*k);
  head.stopSequence();

  //UPPERCAP ANGRY
  upperCap.startSequence(); 
  upperCap.wait(2500*k);
  upperCap.moveDown(10,500*k);  
  upperCap.moveUp(10,500*k);
  upperCap.wait(4500*k);
  upperCap.moveDown(10,500*k);  
  upperCap.moveUp(10,500*k);
  upperCap.wait(1000*k);
  upperCap.stopSequence();

  //LOWERCAP ANGRY
  lowerCap.startSequence();
  lowerCap.wait(2500*k);
  lowerCap.moveUp(10,500*k);
  lowerCap.moveDown(10,500*k); 
  lowerCap.wait(4500*k);
  lowerCap.moveUp(10,500*k);  
  lowerCap.moveDown(10,500*k);
  lowerCap.wait(1000*k);
  lowerCap.stopSequence();
}



void RobotMovement::beAnnoyedLeft(unsigned long duration, int robotAngularPosition) {
  float k = duration/79000.0;
  
  //UPPERBODY ANNOYED
  upperBody.startSequence(); 
  upperBody.moveLeft(40,1500*k);
  upperBody.moveLeft(55,2000*k);   
  upperBody.moveLeft(65,1000*k);
  upperBody.wait(1500*k);
  for (int i=0;i<3;i++){       //14000*3=42000
    upperBody.moveRight(40,3000*k);
    upperBody.moveRight(55,2000*k);
    upperBody.moveRight(65,1000*k);
    upperBody.wait(1000*k);
    upperBody.moveLeft(40,3000*k);
    upperBody.moveLeft(55,2000*k);   
    upperBody.moveLeft(65,1000*k);
    upperBody.wait(1000*k);
  }
  upperBody.moveRight(30,3000*k);      //3000
  for (int i=0;i<6;i++){          //2000*6=12000
    upperBody.moveRight(20,1000*k);
    upperBody.moveRight(30,1000*k);
  }
  upperBody.moveLeft(50,3000*k);       //3000
  upperBody.moveLeft(30,1000*k);       //1000
  for (int i=0;i<6;i++){          //2000*6=12000
    upperBody.moveLeft(20,1000*k);
    upperBody.moveLeft(30,1000*k);
  }
  upperBody.goIdle(1000*k);
  upperBody.stopSequence();

  //HEAD ANNOYED
  head.startSequence(); 
  head.wait(46500*k);//da qui in poi sarebbe tipo sayNo
  head.moveLeft(30,500*k);
  for (int i=0;i<6;i++){       //2000*6=12000
    head.moveRight(30,1000*k);
    head.moveLeft(30,1000*k);
  } 
  for (int i=0;i<4;i++){       //2000*4=8000
    head.moveRight(15,1000*k);
    head.moveLeft(15,1000*k);
  } 
  head.wait(2000*k);            //2000
  for (int i=0;i<5;i++){      //2000*5=10000
    head.moveRight(20,1000*k);
    head.moveLeft(20,1000*k);
  } 
  head.stopSequence();

  //UPPERCAP ANNOYED
  upperCap.startSequence();
  upperCap.wait(3000*k);
  upperCap.moveDown(30,1500*k);
  upperCap.moveDown(15,1500*k);
  for (int i=0;i<6;i++){         //7000*6=42000
    upperCap.wait(3000*k);
    upperCap.moveDown(30,2000*k);
    upperCap.moveDown(15,2000*k);
  }
  upperCap.stopSequence();

 //LOWERCAP ANNOYED  
  lowerCap.startSequence();
  lowerCap.wait(1500*k);
  lowerCap.moveUp(20,1500*k);
  lowerCap.moveUp(15,1500*k);
  for (int i=0;i<6;i++){         //7000*6=42000
    lowerCap.wait(3000*k);
    lowerCap.moveUp(20,2000*k);
    lowerCap.moveUp(15,2000*k);
  }
  lowerCap.stopSequence();
}
void RobotMovement::beAnnoyedShort3Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;
  
  //UPPERBODY ANNOYED
  upperBody.startSequence(); 
  upperBody.moveLeft(40,1500*k);
  upperBody.moveLeft(55,2000*k);   
  upperBody.moveLeft(65,1000*k);
  upperBody.wait(5500*k);
  upperBody.stopSequence();

  //HEAD ANNOYED
  head.startSequence(); 
  head.wait(4500*k);//da qui in poi sarebbe tipo sayNo
  head.moveLeft(30,500*k);
  for (int i=0;i<2;i++){     
    head.moveRight(30,1000*k);
    head.moveLeft(30,1000*k);
  } 
  head.moveRight(30,1000*k);
  head.stopSequence();

  //UPPERCAP ANNOYED
  upperCap.startSequence();
  for (int i=0;i<2;i++){  
    upperCap.wait(2000*k);
    upperCap.moveDown(30,1500*k);
    upperCap.moveDown(15,1500*k);
  }
  upperCap.stopSequence();

 //LOWERCAP ANNOYED  
  lowerCap.startSequence();
  for (int i=0;i<6;i++){       
    lowerCap.wait(2000*k);
    lowerCap.moveUp(20,1500*k);
    lowerCap.moveUp(15,1500*k);
  }
  lowerCap.stopSequence();
}
void RobotMovement::beAnnoyedShort2Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;
  
  //UPPERBODY ANNOYED
  upperBody.startSequence(); 
  upperBody.moveLeft(30,1500*k);
  upperBody.moveLeft(45,2000*k);   
  upperBody.moveLeft(55,1000*k);
  upperBody.wait(5500*k);
  upperBody.stopSequence();

  //HEAD ANNOYED
  head.startSequence(); 
  head.wait(4500*k);//da qui in poi sarebbe tipo sayNo
  head.moveLeft(20,500*k);
  for (int i=0;i<2;i++){     
    head.moveRight(20,1000*k);
    head.moveLeft(20,1000*k);
  } 
  head.moveRight(20,1000*k);
  head.stopSequence();

  //UPPERCAP ANNOYED
  upperCap.startSequence();
  for (int i=0;i<2;i++){  
    upperCap.wait(2000*k);
    upperCap.moveDown(25,1500*k);
    upperCap.moveDown(10,1500*k);
  }
  upperCap.stopSequence();

 //LOWERCAP ANNOYED  
  lowerCap.startSequence();
  for (int i=0;i<6;i++){       
    lowerCap.wait(2000*k);
    lowerCap.moveUp(15,1500*k);
    lowerCap.moveUp(10,1500*k);
  }
  lowerCap.stopSequence();
}
void RobotMovement::beAnnoyedShort1Left(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;
  
  //UPPERBODY ANNOYED
  upperBody.startSequence(); 
  upperBody.moveLeft(20,1500*k);
  upperBody.moveLeft(35,2000*k);   
  upperBody.moveLeft(45,1000*k);
  upperBody.wait(5500*k);
  upperBody.stopSequence();

  //HEAD ANNOYED
  head.startSequence(); 
  head.wait(4500*k);//da qui in poi sarebbe tipo sayNo
  head.moveLeft(10,500*k);
  for (int i=0;i<2;i++){     
    head.moveRight(10,1000*k);
    head.moveLeft(10,1000*k);
  } 
  head.moveRight(10,1000*k);
  head.stopSequence();

  //UPPERCAP ANNOYED
  upperCap.startSequence();
  for (int i=0;i<2;i++){  
    upperCap.wait(2000*k);
    upperCap.moveDown(20,1500*k);
    upperCap.moveDown(5,1500*k);
  }
  upperCap.stopSequence();

 //LOWERCAP ANNOYED  
  lowerCap.startSequence();
  for (int i=0;i<6;i++){       
    lowerCap.wait(2000*k);
    lowerCap.moveUp(10,1500*k);
    lowerCap.moveUp(5,1500*k);
  }
  lowerCap.stopSequence();
}

void RobotMovement::beAnnoyedRight(unsigned long duration, int robotAngularPosition) {
  float k = duration/79000.0;
  
  //UPPERBODY ANNOYED
  upperBody.startSequence(); 
  upperBody.moveRight(40,1500*k);
  upperBody.moveRight(55,2000*k);   
  upperBody.moveRight(65,1000*k);
  upperBody.wait(1500*k);
  for (int i=0;i<3;i++){       //14000*3=42000
    upperBody.moveLeft(40,3000*k);
    upperBody.moveLeft(55,2000*k);
    upperBody.moveLeft(65,1000*k);
    upperBody.wait(1000*k);
    upperBody.moveRight(40,3000*k);
    upperBody.moveRight(55,2000*k);   
    upperBody.moveRight(65,1000*k);
    upperBody.wait(1000*k);
  }
  upperBody.moveLeft(30,3000*k);      //3000
  for (int i=0;i<6;i++){          //2000*6=12000
    upperBody.moveLeft(20,1000*k);
    upperBody.moveLeft(30,1000*k);
  }
  upperBody.moveRight(50,3000*k);       //3000
  upperBody.moveRight(30,1000*k);       //1000
  for (int i=0;i<6;i++){          //2000*6=12000
    upperBody.moveRight(20,1000*k);
    upperBody.moveRight(30,1000*k);
  }
  upperBody.goIdle(1000*k);
  upperBody.stopSequence();

  //HEAD ANNOYED
  head.startSequence(); 
  head.wait(46500*k);//da qui in poi sarebbe tipo sayNo
  head.moveRight(30,500*k);
  for (int i=0;i<6;i++){       //2000*6=12000
    head.moveLeft(30,1000*k);
    head.moveRight(30,1000*k);
  } 
  for (int i=0;i<4;i++){       //2000*4=8000
    head.moveLeft(15,1000*k);
    head.moveRight(15,1000*k);
  } 
  head.wait(2000*k);            //2000
  for (int i=0;i<5;i++){      //2000*5=10000
    head.moveLeft(20,1000*k);
    head.moveRight(20,1000*k);
  } 
  head.stopSequence();

  //UPPERCAP ANNOYED
  upperCap.startSequence();
  upperCap.wait(3000*k);
  upperCap.moveDown(30,1500*k);
  upperCap.moveDown(15,1500*k);
  for (int i=0;i<6;i++){         //7000*6=42000
    upperCap.wait(3000*k);
    upperCap.moveDown(30,2000*k);
    upperCap.moveDown(15,2000*k);
  }
  upperCap.stopSequence();

 //LOWERCAP ANNOYED  
  lowerCap.startSequence();
  lowerCap.wait(1500*k);
  lowerCap.moveUp(20,1500*k);
  lowerCap.moveUp(15,1500*k);
  for (int i=0;i<6;i++){         //7000*6=42000
    lowerCap.wait(3000*k);
    lowerCap.moveUp(20,2000*k);
    lowerCap.moveUp(15,2000*k);
  }
  lowerCap.stopSequence();
}
void RobotMovement::beAnnoyedShort3Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;
  
  //UPPERBODY ANNOYED
  upperBody.startSequence(); 
  upperBody.moveRight(40,1500*k);
  upperBody.moveRight(55,2000*k);   
  upperBody.moveRight(65,1000*k);
  upperBody.wait(5500*k);
  upperBody.stopSequence();

  //HEAD ANNOYED
  head.startSequence(); 
  head.wait(4500*k);//da qui in poi sarebbe tipo sayNo
  head.moveRight(30,500*k);
  for (int i=0;i<2;i++){     
    head.moveLeft(30,1000*k);
    head.moveRight(30,1000*k);
  } 
  head.moveLeft(30,1000*k);
  head.stopSequence();

  //UPPERCAP ANNOYED
  upperCap.startSequence();
  for (int i=0;i<2;i++){  
    upperCap.wait(2000*k);
    upperCap.moveDown(30,1500*k);
    upperCap.moveDown(15,1500*k);
  }
  upperCap.stopSequence();

 //LOWERCAP ANNOYED  
  lowerCap.startSequence();
  for (int i=0;i<6;i++){       
    lowerCap.wait(2000*k);
    lowerCap.moveUp(20,1500*k);
    lowerCap.moveUp(15,1500*k);
  }
  lowerCap.stopSequence();
}
void RobotMovement::beAnnoyedShort2Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;
  
  //UPPERBODY ANNOYED
  upperBody.startSequence(); 
  upperBody.moveRight(30,1500*k);
  upperBody.moveRight(45,2000*k);   
  upperBody.moveRight(55,1000*k);
  upperBody.wait(5500*k);
  upperBody.stopSequence();

  //HEAD ANNOYED
  head.startSequence(); 
  head.wait(4500*k);//da qui in poi sarebbe tipo sayNo
  head.moveRight(20,500*k);
  for (int i=0;i<2;i++){     
    head.moveLeft(20,1000*k);
    head.moveRight(20,1000*k);
  } 
  head.moveLeft(20,1000*k);
  head.stopSequence();

  //UPPERCAP ANNOYED
  upperCap.startSequence();
  for (int i=0;i<2;i++){  
    upperCap.wait(2000*k);
    upperCap.moveDown(25,1500*k);
    upperCap.moveDown(10,1500*k);
  }
  upperCap.stopSequence();

 //LOWERCAP ANNOYED  
  lowerCap.startSequence();
  for (int i=0;i<6;i++){       
    lowerCap.wait(2000*k);
    lowerCap.moveUp(15,1500*k);
    lowerCap.moveUp(10,1500*k);
  }
  lowerCap.stopSequence();
}
void RobotMovement::beAnnoyedShort1Right(unsigned long duration, int robotAngularPosition) {
  float k = duration/10000.0;
  
  //UPPERBODY ANNOYED
  upperBody.startSequence(); 
  upperBody.moveRight(20,1500*k);
  upperBody.moveRight(35,2000*k);   
  upperBody.moveRight(45,1000*k);
  upperBody.wait(5500*k);
  upperBody.stopSequence();

  //HEAD ANNOYED
  head.startSequence(); 
  head.wait(4500*k);//da qui in poi sarebbe tipo sayNo
  head.moveRight(10,500*k);
  for (int i=0;i<2;i++){     
    head.moveLeft(10,1000*k);
    head.moveRight(10,1000*k);
  } 
  head.moveLeft(10,1000*k);
  head.stopSequence();

  //UPPERCAP ANNOYED
  upperCap.startSequence();
  for (int i=0;i<2;i++){  
    upperCap.wait(2000*k);
    upperCap.moveDown(20,1500*k);
    upperCap.moveDown(5,1500*k);
  }
  upperCap.stopSequence();

 //LOWERCAP ANNOYED  
  lowerCap.startSequence();
  for (int i=0;i<6;i++){       
    lowerCap.wait(2000*k);
    lowerCap.moveUp(10,1500*k);
    lowerCap.moveUp(5,1500*k);
  }
  lowerCap.stopSequence();
}

void RobotMovement::updatePosition() {
  head.updatePosition(); //horizontal
  upperCap.updatePosition();
  lowerCap.updatePosition();
  upperBody.updatePosition();//horizontal
  lowerBody.updatePosition();//horizontal
}