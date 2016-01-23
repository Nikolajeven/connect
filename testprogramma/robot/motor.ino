void motorDrive(boolean motorNumber, boolean motorDirection, int motorSpeed)
{
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
  if (motorDirection == turnCW) pinIn1 = HIGH;
  else pinIn1 = LOW;

  //Select the motor to turn, and set the direction and the speed
  if (motorNumber == MotorRight)
        {
          digitalWrite(pinAIN1, pinIn1);
          digitalWrite(pinAIN2, !pinIn1);  //This is the opposite of the AIN1
          analogWrite(pinPWMA, motorSpeed);
        }
        else
        {
          digitalWrite(pinBIN1, pinIn1);
          digitalWrite(pinBIN2, !pinIn1);  //This is the opposite of the BIN1
          analogWrite(pinPWMB, motorSpeed);
        }

  //Finally , make sure STBY is disabled - pull it HIGH
  digitalWrite(pinSTBY, HIGH);
}

void motorBrake(boolean motorNumber)
{ //  This "Short Brake"s the specified motor, by setting speed to zero
  if (motorNumber == MotorRight) analogWrite(pinPWMA, 0);
  else analogWrite(pinPWMB, 0);
}

void motorStop(boolean motorNumber)
{ // This stops the specified motor by setting both IN pins to LOW
  if (motorNumber == MotorRight) {
    digitalWrite(pinAIN1, LOW);
    digitalWrite(pinAIN2, LOW);
  }
  else
  {
    digitalWrite(pinBIN1, LOW);
    digitalWrite(pinBIN2, LOW);
  }
}

void motorsStandby()
{ // This puts the motors into Standby Mode
  digitalWrite(pinSTBY, LOW);
}
