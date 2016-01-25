unsigned long tijdSchermBijgewerkt;
byte tijd;
boolean beweegStap;

// These #defines make it easy to set the backlight color
#define OFF 0x0
#define ON 0x1

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

void motorDrive(boolean motorNumber, boolean motorDirection, int motorSpeed){
  /*
  This Drives a specified motor, in a specific direction, at a specified speed:
    - motorNumber: MotorRight or MotorLeft ---> Motor 1 or Motor 2
    - motorDirection: turnCW or turnCCW ---> clockwise or counter-clockwise
    - motorSpeed: 0 to 255 ---> 0 = stop / 255 = fast
  */

  boolean pinIn1;  //Relates to AIN1 or BIN1 (depending on the motor number specified)

  //Specify the Direction to turn the motor
  //Clockwise: AIN1/BIN1 = HIGH and AIN2/BIN2 = LOW
  //Counter-Clockwise: AIN1/BIN1 = LOW and AIN2/BIN2 = HIGH
  if (motorDirection == turnCW) {pinIn1 = HIGH;}
  else {pinIn1 = LOW;}

  //Select the motor to turn, and set the direction and the speed
  if (motorNumber == MotorRight){
    digitalWrite(pinAIN1, pinIn1);
    digitalWrite(pinAIN2, !pinIn1);  //This is the opposite of the AIN1
    analogWrite(pinPWMA, motorSpeed);
  }
  else{
    digitalWrite(pinBIN1, pinIn1);
    digitalWrite(pinBIN2, !pinIn1);  //This is the opposite of the BIN1
    analogWrite(pinPWMB, motorSpeed);
   }

  //Finally , make sure STBY is disabled - pull it HIGH
  digitalWrite(pinSTBY, HIGH);
}

void motorBrake(boolean motorNumber){
  //  This "Short Brake"s the specified motor, by setting speed to zero
  if (motorNumber == MotorRight) analogWrite(pinPWMA, 0);
  else analogWrite(pinPWMB, 0);
}

void motorStop(boolean motorNumber){
  // This stops the specified motor by setting both IN pins to LOW
  if (motorNumber == MotorRight) {
    digitalWrite(pinAIN1, LOW);
    digitalWrite(pinAIN2, LOW);
  }
  else{
    digitalWrite(pinBIN1, LOW);
    digitalWrite(pinBIN2, LOW);
  }
}

void motorsStandby(){ // This puts the motors into Standby Mode
  digitalWrite(pinSTBY, LOW);
}


void output(){
  switch(bericht.statusMotor){
    case 0:
      motorBrake(MotorLeft);
      motorBrake(MotorRight);
      break;
    case 1:
      motorDrive(MotorLeft, turnCCW,128);
      motorDrive(MotorRight, turnCCW,128);
      break;
    case 2:
      motorDrive(MotorLeft, turnCCW,255);
      motorDrive(MotorRight, turnCCW,255);
      break;
    case 3:
      motorDrive(MotorLeft, turnCW,128);
      motorDrive(MotorRight, turnCW,128);
      break;
    case 4:
      motorDrive(MotorLeft, turnCW,255);
      motorDrive(MotorRight, turnCW,255);
      break;
    case 5:
      motorDrive(MotorLeft, turnCW,128);
      motorDrive(MotorRight, turnCCW,128);
      break;
    case 6:
      motorDrive(MotorLeft, turnCW,225);
      motorDrive(MotorRight, turnCCW,225);
      break;
    case 7:
      motorDrive(MotorLeft, turnCCW,128);
      motorDrive(MotorRight, turnCW,128);
      break;
    case 8:
      motorDrive(MotorLeft, turnCW,225);
      motorDrive(MotorRight, turnCCW,225);
      break;
    case 9:
      motorDrive(MotorLeft, turnCCW,100);
      motorDrive(MotorRight, turnCCW,200);
      break;
    case 10:
      motorDrive(MotorLeft, turnCCW,200);
      motorDrive(MotorRight, turnCCW,100);
      break;
    case 11:
      motorDrive(MotorLeft, turnCW,100);
      motorDrive(MotorRight, turnCW,200);
      break;
    case 12:
      motorDrive(MotorLeft, turnCW,200);
      motorDrive(MotorRight, turnCW,100);
      break;
  }

  if(millis() > (tijdSchermBijgewerkt + 500)){
    lcd.setCursor(15, 0);
    if(bericht.statusMotor == 0){
      if(beweegStap){beweegStap = false;lcd.write(byte(2));}
      else{beweegStap = true;lcd.write(byte(3));}
    }
    else{
      if(beweegStap){beweegStap = false;lcd.write(byte(0));}
      else{beweegStap = true;lcd.write(byte(1));}
    }
    
    lcd.setCursor(14, 0);
    if(nietVerbonden){
      laatsteResultaatStatusMotor = 0; // Als de robot geen bericht ontvangt van de remote (13) stopt de motor
      lcd.print(" "); // Verwijder vinkje van beeldscherm
    }
    else{lcd.write(byte(4));} // Plaats vinkje
    
    if(schermAan){lcd.setBacklight(ON);}
    else{lcd.setBacklight(OFF);}
    
    Serial.println(bericht.statusMotor);    
    tijdSchermBijgewerkt = millis();
  }
}
