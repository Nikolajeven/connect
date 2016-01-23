#include <JeeLib.h>
#include <Connect-testprogramma.h>
#include <Wire.h>                   //I2C library
#include <Adafruit_MCP23017.h>      //Display library
#include <Adafruit_RGBLCDShield.h>  //Display library

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

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

  if(bericht.staatAnalogX == 0 || bericht.staatAnalogX == 2) {
    Serial.print("Robot | staatAnalogX: ");
    Serial.println(bericht.staatAnalogX);
  }
  if(bericht.staatAnalogY == 0 || bericht.staatAnalogY == 2) {
    Serial.print("Robot | staatAnalogY: ");
    Serial.println(bericht.staatAnalogY);
  }
}
