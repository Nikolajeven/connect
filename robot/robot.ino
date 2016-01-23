#include <JeeLib.h>
#include <Connect.h>
#include <Wire.h>                   //I2C library
#include <Adafruit_MCP23017.h>      //Display library
#include <Adafruit_RGBLCDShield.h>  //Display library

#include "input.h"
#include "think.h"
#include "output.h"

// unique node ID of receiver (1 through 30)
const byte apparaatID = 2;

void setup(){
  setupConnect(apparaatID);

  Serial.begin(9600);
  Serial.println("...");
  Serial.println("Robot");

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Actie:");
}

void loop() {
  
  input();
  think();
  output();
  
}
