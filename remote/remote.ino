#include <JeeLib.h>    // Library voor radiografische communicatie
#include <connect.h>   // Library voor uitwerking zenden en ontvangen
#include "joystick.h"  // Extern bestand voor joystick

const byte apparaatID = 1;

// Constanten aansluitingen knoppen
const byte joystick_pinKnopSelect = 7;
const byte joystick_pinKnopRechts = 3;
const byte joystick_pinKnopLinks = 6;
const byte joystick_pinKnopOnder = 5;
const byte joystick_pinKnopBoven = 4;

const byte joystick_pinAnalogX = 0;
const byte joystick_pinAnalogY = 1;

const byte joystick_setupAnalogX = joystick_setupAnalog(joystick_pinAnalogX);
const byte joystick_setupAnalogY = joystick_setupAnalog(joystick_pinAnalogY);

connect_structBericht bericht;

void setup() {
  //joystick
  pinMode(joystick_pinKnopSelect, INPUT);
   digitalWrite(joystick_pinKnopSelect, HIGH);

   pinMode(joystick_pinKnopRechts, INPUT);
   digitalWrite(joystick_pinKnopRechts, HIGH);

   pinMode(joystick_pinKnopLinks, INPUT);
   digitalWrite(joystick_pinKnopLinks, HIGH);

   pinMode(joystick_pinKnopOnder, INPUT);
   digitalWrite(joystick_pinKnopOnder, HIGH);

   pinMode(joystick_pinKnopBoven, INPUT);
   digitalWrite(joystick_pinKnopBoven, HIGH);

   // Om de A/D conversie veel sneller te laten lopen. Scheelt 0.33 msec per conversie
   bitClear(ADCSRA,ADPS0);
   bitClear(ADCSRA,ADPS1);
   bitSet(ADCSRA,ADPS2);

   Serial.begin(9600);
   rf12_initialize(apparaatID, freq, network, 1600);

   Serial.println("...");
   Serial.println("connect: remote");
}


void loop() {

   bericht.afzender = connect_apparaatID;

   bericht.knopSelectIngedrukt = joystick_knopIngedrukt(joystick_pinKnopSelect);
   bericht.knopRechtsIngedrukt = joystick_knopIngedrukt(joystick_pinKnopRechts);
   bericht.knopLinksIngedrukt = joystick_knopIngedrukt(joystick_pinKnopLinks);
   bericht.knopOnderIngedrukt = joystick_knopIngedrukt(joystick_pinKnopOnder);
   bericht.knopBovenIngedrukt = joystick_knopIngedrukt(joystick_pinKnopBoven);

   bericht.joystic_staatAnalogX = joystic_staatAnalog(joystick_pinAnalogX);
   bericht.joystic_staatAnalogY = joystic_staatAnalog(joystick_pinAnalogY);


   if(bericht.knopSelectIngedrukt) {Serial.println("Remote: knopSelectIngedrukt");}
   if(bericht.knopRechtsIngedrukt) {Serial.println("Remote: knopRechtsIngedrukt");}
   if(bericht.knopLinksIngedrukt) {Serial.println("Remote: knopLinksIngedrukt");}
   if(bericht.knopOnderIngedrukt) {Serial.println("Remote: knopOnderIngedrukt");}
   if(bericht.knopBovenIngedrukt) {Serial.println("Remote: knopBovenIngedrukt");}

   if(bericht.joystick_staatAnalogX == 0 || bericht.joystick_staatAnalogX == 2) {
     Serial.print("Remote: staatAnalogX: ");
     Serial.println(bericht.joystick_staatAnalogX);
   }
   if(bericht.joystick_staatAnalogY == 0 || bericht.joystick_staatAnalogY == 2) {
     Serial.print("Remote: staatAnalogY: ");
     Serial.println(bericht.joystick_staatAnalogY);
   }

   connect_zend(bericht);

}
