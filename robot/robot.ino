#include <JeeLib.h>
#include <Connect.h>
#include <Wire.h>                   //I2C library
#include <Adafruit_MCP23017.h>      //Display library
#include <Adafruit_RGBLCDShield.h>  //Display library

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();//wordt in input (knoppen) en output (beeldscherm) gebruikt

#include "input.h"
#include "think.h"
#include "output.h"

// unique node ID of receiver (1 through 30)
const byte apparaatID = 2;

void setup(){
  
  setupConnect(apparaatID);
  setupOutput();

  Serial.begin(9600);
  Serial.println("...");
  Serial.println("Robot");
  
}

void loop() {
  
  input();
  think();
  output();
  
}
