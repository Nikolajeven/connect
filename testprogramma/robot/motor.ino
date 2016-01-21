
/* Testprogramma voor de besturing van 2 DC motoren via TB6612FNG driver
***********************************************************************/
//Motor Left
int pinBIN1 =  8; //Direction
int pinBIN2 =  9; //Direction
int pinPWMB = 6; //Speed
//Motor Right
int pinAIN1 = 5; //Direction
int pinAIN2 = 4; //Direction
int pinPWMA = 3; //Speed
//Standby
int pinSTBY = 7;
//Constants die het makkelijker maken
static boolean turnCW    = 0; //for ClockWise motorDrive function
static boolean turnCCW   = 1; //for CounterClockWise motorDrive function
static boolean MotorRight= 0; //for motorDrive, motorStop, motorBrake functions
static boolean MotorLeft = 1; //for motorDrive, motorStop, motorBrake functions
float SoftStartFactor=1.0; 


//------------------------------------------------------------------
void setup() {
  Serial.begin(9600); // Alleen voor test doeleinden.   

//Setup van  motorshield aansluitingen 
  pinMode(pinPWMA, OUTPUT);
  pinMode(pinAIN1, OUTPUT);
  pinMode(pinAIN2, OUTPUT);
  pinMode(pinPWMB, OUTPUT);
  pinMode(pinBIN1, OUTPUT);
  pinMode(pinBIN2, OUTPUT);
  pinMode(pinSTBY, OUTPUT);
 
}

//------------------------------------------------------------------- 
void loop() {

/*        
 *         motorDrive(MotorLeft, turnCW,150);
          delay(1000);
          motorDrive(MotorLeft, turnCCW,75);
          delay(1000);
          */
          motorDrive(MotorRight, turnCW,75);
          delay(1000);
          motorDrive(MotorRight, turnCCW,100);
          delay(1000);         
}
