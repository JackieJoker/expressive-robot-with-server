#ifndef RobotMovement_h
#define RobotMovement_h
#include "HorizontalServo.h"
#include "VerticalServo.h"
#include "ShiftedHorizontalServo.h"


class RobotMovement {
  private:
    int groupPositions[8]={0, -22, -39, -56, -73, 0, 73, 56};
    
    ShiftedHorizontalServo lowerBody; 
    HorizontalServo upperBody;
    HorizontalServo head;
    VerticalServo lowerCap;
    VerticalServo upperCap;

    void sayNo(unsigned long duration, int robotAngularPosition);     

    void beHappyLeft(unsigned long duration, int robotAngularPosition);    
    void beSadLeft(unsigned long duration, int robotAngularPosition);     
    void beAngryLeft(unsigned long duration, int robotAngularPosition);     
    void beSurprisedLeft(unsigned long duration, int robotAngularPosition); 
    void beAnnoyedLeft(unsigned long duration, int robotAngularPosition); 
    void beEmbarassedLeft(unsigned long duration, int robotAngularPosition);
    void beCautiousLeft(unsigned long duration, int robotAngularPosition); 
    void beNeutralLeft(unsigned long duration, int robotAngularPosition);   
    
    void beHappyRight(unsigned long duration, int robotAngularPosition);
    void beSadRight(unsigned long duration, int robotAngularPosition);      
    void beAngryRight(unsigned long duration, int robotAngularPosition);    
    void beSurprisedRight(unsigned long duration, int robotAngularPosition); 
    void beAnnoyedRight(unsigned long duration, int robotAngularPosition); 
    void beEmbarassedRight(unsigned long duration, int robotAngularPosition);
    void beCautiousRight(unsigned long duration, int robotAngularPosition); 
    void beNeutralRight(unsigned long duration, int robotAngularPosition); 

    void beHappyShort1Left(unsigned long duration, int robotAngularPosition);    
    void beSadShort1Left(unsigned long duration, int robotAngularPosition);   
    void beAngryShort1Left(unsigned long duration, int robotAngularPosition);        
    void beSurprisedShort1Left(unsigned long duration, int robotAngularPosition); 
    void beAnnoyedShort1Left(unsigned long duration, int robotAngularPosition); 
    void beEmbarassedShort1Left(unsigned long duration, int robotAngularPosition);
    void beCautiousShort1Left(unsigned long duration, int robotAngularPosition);       
    
    void beHappyShort1Right(unsigned long duration, int robotAngularPosition); 
    void beSadShort1Right(unsigned long duration, int robotAngularPosition);   
    void beAngryShort1Right(unsigned long duration, int robotAngularPosition);       
    void beSurprisedShort1Right(unsigned long duration, int robotAngularPosition); 
    void beAnnoyedShort1Right(unsigned long duration, int robotAngularPosition); 
    void beEmbarassedShort1Right(unsigned long duration, int robotAngularPosition);
    void beCautiousShort1Right(unsigned long duration, int robotAngularPosition);  

    void beHappyShort2Left(unsigned long duration, int robotAngularPosition);    
    void beSadShort2Left(unsigned long duration, int robotAngularPosition);       
    void beAngryShort2Left(unsigned long duration, int robotAngularPosition);        
    void beSurprisedShort2Left(unsigned long duration, int robotAngularPosition); 
    void beAnnoyedShort2Left(unsigned long duration, int robotAngularPosition); 
    void beEmbarassedShort2Left(unsigned long duration, int robotAngularPosition); 
    void beCautiousShort2Left(unsigned long duration, int robotAngularPosition);   
    
    void beHappyShort2Right(unsigned long duration, int robotAngularPosition); 
    void beSadShort2Right(unsigned long duration, int robotAngularPosition);       
    void beAngryShort2Right(unsigned long duration, int robotAngularPosition);       
    void beSurprisedShort2Right(unsigned long duration, int robotAngularPosition); 
    void beAnnoyedShort2Right(unsigned long duration, int robotAngularPosition); 
    void beEmbarassedShort2Right(unsigned long duration, int robotAngularPosition); 
    void beCautiousShort2Right(unsigned long duration, int robotAngularPosition); 

    void beHappyShort3Left(unsigned long duration, int robotAngularPosition);      
    void beSadShort3Left(unsigned long duration, int robotAngularPosition);       
    void beAngryShort3Left(unsigned long duration, int robotAngularPosition);      
    void beSurprisedShort3Left(unsigned long duration, int robotAngularPosition); 
    void beAnnoyedShort3Left(unsigned long duration, int robotAngularPosition); 
    void beEmbarassedShort3Left(unsigned long duration, int robotAngularPosition);   
    void beCautiousShort3Left(unsigned long duration, int robotAngularPosition);    
    void beNeutralShort3Left(unsigned long duration, int robotAngularPosition);
    
    void beHappyShort3Right(unsigned long duration, int robotAngularPosition); 
    void beSadShort3Right(unsigned long duration, int robotAngularPosition);       
    void beAngryShort3Right(unsigned long duration, int robotAngularPosition);       
    void beSurprisedShort3Right(unsigned long duration, int robotAngularPosition); 
    void beAnnoyedShort3Right(unsigned long duration, int robotAngularPosition); 
    void beEmbarassedShort3Right(unsigned long duration, int robotAngularPosition);   
    void beCautiousShort3Right(unsigned long duration, int robotAngularPosition);    
    void beNeutralShort3Right(unsigned long duration, int robotAngularPosition);     

    void beEmbarassedShort4Right(unsigned long duration, int robotAngularPosition);      
    void beEmbarassedShort4Left(unsigned long duration, int robotAngularPosition);
  public:
    RobotMovement();
    
    int getAngleLowerBody();
    int getAngleUpperBody();
    int getAngleHead();
    int getAngleLowerCap();
    int getAngleUpperCap();
    
    void setup();

    /// this function is used for testing movements and angles
    /// (input) unsigned long duration: the duration in milliseconds of the movement
    /// (input) int groupNumber: the number of the robot
    void test(unsigned long duration, int groupNumber);

    /// this function is used to test that all the motors work properly
    /// (input) unsigned long duration: the duration in milliseconds of the movement
    /// (input) int groupNumber: the number of the robot
    void initialization(unsigned long duration,  int robotAngularPosition);

    void calibration(unsigned long duration);
    void idle(unsigned long duration);

    /// this function says if the robot we have to react to it's on the left of our robot
    /// (input)  int groupNumber: the number of the robot
    /// (output)  true or false
    bool isRobotLeftOriented(int groupNumber);

    /// this function returns the angular position of the robot we are interested in
    /// (input)    int groupNumber: the number of the robot
    /// (output)   angular position
    int getRobotPosition(int groupNumber);

    /// this function returns the value of the parameter used in order to better orientate the movements of our robot with respect to the robot we are talking to
    /// (input)   int robotAngularPosition: angular position of the other robot
    /// (output)  parameter p
    int getParameter(int robotAngularPosition);    

    void happy(unsigned long duration, int groupNumber, int intensity = 3, bool shortMovement = true);     
    void sad(unsigned long duration, int groupNumber, int intensity = 3, bool shortMovement = true);
    void angry(unsigned long duration, int groupNumber, int intensity = 3, bool shortMovement = true);
    void surprised(unsigned long duration, int groupNumber, int intensity = 3, bool shortMovement = true);
    void annoyed(unsigned long duration, int groupNumber, int intensity = 3, bool shortMovement = true);
    void embarassed(unsigned long duration, int groupNumber, int intensity = 3, bool shortMovement = true);
    void cautious(unsigned long duration, int groupNumber, int intensity = 3, bool shortMovement = true);
    void neutral(unsigned long duration, int groupNumber, int intensity = 3, bool shortMovement = true);

    void updatePosition();     
};

#endif