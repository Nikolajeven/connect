#include <JeeLib.h>
#include <Connect-testprogramma.h>
#include <Wire.h>                   //I2C library
#include <Adafruit_MCP23017.h>      //Display library
#include <Adafruit_RGBLCDShield.h>  //Display library

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// unique node ID of receiver (1 through 30)
const byte C0_apparaatID = 2;

C0_structBericht C0_bericht;

void setup(){
  rf12_initialize(C0_apparaatID, freq, network, 1600);

  Serial.begin(9600);
  Serial.println("...");
  Serial.println("C0NNECT - Ontvanger");

  lcd.begin(16, 2);
  lcd.setCursor(5, 0);
  lcd.print("STATUS");
}

void loop() {
  C0_bericht = C0_ontvang();

  if(C0_bericht.knopSelectIngedrukt) {Serial.println("Ontvanger: knopSelectIngedrukt");}
  else if(C0_bericht.knopRechtsIngedrukt) {
    Serial.println("Ontvanger: knopRechtsIngedrukt");
    lcd.setCursor(1, 0);lcd.print("X");
    lcd.setCursor(1, 1);lcd.print("X");
  }
  else if(C0_bericht.knopLinksIngedrukt) {Serial.println("Ontvanger: knopLinksIngedrukt");}
  else if(C0_bericht.knopOnderIngedrukt) {Serial.println("Ontvanger: knopOnderIngedrukt");}
  else if(C0_bericht.knopBovenIngedrukt) {Serial.println("Ontvanger: knopBovenIngedrukt");}

  if(C0_bericht.C0_staatAnalogX == 0 || C0_bericht.C0_staatAnalogX == 2) {
    Serial.print("Ontvanger: staatAnalogX: ");
    Serial.println(C0_bericht.C0_staatAnalogX);
  }
  if(C0_bericht.C0_staatAnalogY == 0 || C0_bericht.C0_staatAnalogY == 2) {
    Serial.print("Ontvanger: staatAnalogY: ");
    Serial.println(C0_bericht.C0_staatAnalogY);
  }
}
