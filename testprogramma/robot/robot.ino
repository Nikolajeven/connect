#include <JeeLib.h>
#include <Connect-testprogramma.h>
#include <Wire.h>                   //I2C library
#include <Adafruit_MCP23017.h>      //Display library
#include <Adafruit_RGBLCDShield.h>  //Display library

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

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

// unique node ID of receiver (1 through 30)
const byte apparaatID = 2;

structBericht bericht;

void setup(){
  rf12_initialize(apparaatID, freq, network, 1600);

  Serial.begin(9600);
  Serial.println("...");
  Serial.println("Robot");

  lcd.begin(16, 2);
  lcd.setCursor(5, 0);
  lcd.print("STATUS");
}

void loop() {
  bericht = ontvang();

  if(bericht.knopSelectIngedrukt) {Serial.println("Robot | knopSelectIngedrukt");}
  else if(bericht.knopRechtsIngedrukt) {
    Serial.println("Robot | knopRechtsIngedrukt");
    lcd.setCursor(0, 0);lcd.print(" ");
    lcd.setCursor(1, 0);lcd.print("X");
    lcd.setCursor(0, 1);lcd.print(" ");
    lcd.setCursor(1, 1);lcd.print("X");
    motorDrive(MotorRight, turnCW,75);
  }
  else if(bericht.knopLinksIngedrukt) {
    Serial.println("Ontvanger: knopLinksIngedrukt");
    motorDrive(MotorRight, turnCCW,100);
  }
  else if(bericht.knopLinksIngedrukt) {
    Serial.println("Robot | knopLinksIngedrukt");
    lcd.setCursor(0, 0);lcd.print("X");
    lcd.setCursor(1, 0);lcd.print(" ");
    lcd.setCursor(0, 1);lcd.print("X");
    lcd.setCursor(1, 1);lcd.print(" ");
  }
  else if(bericht.knopOnderIngedrukt) {
    Serial.println("Robot | knopOnderIngedrukt");
    lcd.setCursor(0, 0);lcd.print(" ");
    lcd.setCursor(1, 0);lcd.print(" ");
    lcd.setCursor(0, 1);lcd.print("X");
    lcd.setCursor(1, 1);lcd.print("X");
  }
  else if(bericht.knopBovenIngedrukt) {
    Serial.println("Robot | knopBovenIngedrukt");
    lcd.setCursor(0, 0);lcd.print("^");
    lcd.setCursor(1, 0);lcd.print("^");
    lcd.setCursor(0, 1);lcd.print(" ");
    lcd.setCursor(1, 1);lcd.print(" ");
  }
  else if(bericht.knopOnderIngedrukt) {Serial.println("Ontvanger: knopOnderIngedrukt");}
  else if(bericht.knopBovenIngedrukt) {Serial.println("Ontvanger: knopBovenIngedrukt");}

  if(bericht.staatAnalogX == 0 || bericht.staatAnalogX == 2) {
    Serial.print("Robot | staatAnalogX: ");
    Serial.println(bericht.staatAnalogX);
  }
  if(bericht.staatAnalogY == 0 || bericht.staatAnalogY == 2) {
    Serial.print("Robot | staatAnalogY: ");
    Serial.println(bericht.staatAnalogY);
  }
}
