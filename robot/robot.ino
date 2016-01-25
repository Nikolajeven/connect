#include <JeeLib.h>
#include <Connect.h>
#include <Wire.h>                   //I2C library
#include <Adafruit_MCP23017.h>      //Display library
#include <Adafruit_RGBLCDShield.h>  //Display library

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();//wordt in input (knoppen) en output (beeldscherm) gebruikt

#include "input.h"
#include "think.h"
#include "output.h"

byte eersteStap[8] = {
  B00110,
  B00110,
  B00000,
  B00110,
  B00101,
  B01001,
  B10010,
};
byte tweedeStap[8] = {
  B00110,
  B00110,
  B00000,
  B00110,
  B01010,
  B01010,
  B10100,
};
byte eersteHallo[8] = {
  B01100,
  B01100,
  B00000,
  B11111,
  B01100,
  B01100,
  B10010,
};
byte tweedeHallo[8] = {
  B01100,
  B01100,
  B00001,
  B11110,
  B01100,
  B01100,
  B10010,
};
byte verbonden[8] = {
  B00000,
  B00000,
  B00001,
  B00010,
  B10100,
  B01000,
  B00000,
};

// unique node ID of receiver (1 through 30)
const byte apparaatID = 2;

void setup(){
  
  
  
  setupConnect(apparaatID);

  Serial.begin(9600);
  Serial.println("...");
  Serial.println("Robot");

  lcd.begin(16, 2);
  lcd.createChar(0, eersteStap);
  lcd.createChar(1, tweedeStap);
  lcd.createChar(2, eersteHallo);
  lcd.createChar(3, tweedeHallo);
  lcd.createChar(4, verbonden);
  
}

void loop() {
  
  input();
  think();
  output();
  
}
