#include <JeeLib.h>
#include <connect.h>

#include "struct.h"
#include "joystick.h"

const byte apparaatID = 1;

// Constanten aansluitingen knoppen
const byte pinKnopSelect= 7;
const byte pinKnopRechts = 3;
const byte pinKnopLinks = 6;
const byte pinKnopOnder = 5;
const byte pinKnopBoven = 4;

const byte pinAnalogX = 0;
const byte pinAnalogY = 1;

structBericht bericht;

void setup() {
   pinMode(pinKnopSelect, INPUT);
   digitalWrite(pinKnopSelect, HIGH);

   pinMode(pinKnopRechts, INPUT);
   digitalWrite(pinKnopRechts, HIGH);

   pinMode(pinKnopLinks, INPUT);
   digitalWrite(pinKnopLinks, HIGH);

   pinMode(pinKnopOnder, INPUT);
   digitalWrite(pinKnopOnder, HIGH);

   pinMode(pinKnopBoven, INPUT);
   digitalWrite(pinKnopBoven, HIGH);


   // Om de A/D conversie veel sneller te laten lopen. Scheelt 0.33 msec per conversie
   bitClear(ADCSRA,ADPS0);
   bitClear(ADCSRA,ADPS1);
   bitSet(ADCSRA,ADPS2);

   Serial.begin(9600);
   rf12_initialize(apparaatID, freq, network, 1600);

   Serial.println("...");
   Serial.println("C0NNECT - Zender");
}


void loop() {

   bericht.afzender = apparaatID;

   bericht.knopSelectIngedrukt = knopIngedrukt(pinKnopSelect);
   bericht.knopRechtsIngedrukt = knopIngedrukt(pinKnopRechts);
   bericht.knopLinksIngedrukt = knopIngedrukt(pinKnopLinks);
   bericht.knopOnderIngedrukt = knopIngedrukt(pinKnopOnder);
   bericht.knopBovenIngedrukt = knopIngedrukt(pinKnopBoven);

   bericht.staatAnalogX = staatAnalog(pinAnalogX);
   bericht.staatAnalogY = staatAnalog(pinAnalogY);


   if(bericht.knopSelectIngedrukt) {Serial.println("Zender: knopSelectIngedrukt");}
   if(bericht.knopRechtsIngedrukt) {Serial.println("Zender: knopRechtsIngedrukt");}
   if(bericht.knopLinksIngedrukt) {Serial.println("Zender: knopLinksIngedrukt");}
   if(bericht.knopOnderIngedrukt) {Serial.println("Zender: knopOnderIngedrukt");}
   if(bericht.knopBovenIngedrukt) {Serial.println("Zender: knopBovenIngedrukt");}

   if(bericht.staatAnalogX == 0 || bericht.staatAnalogX == 2) {
     Serial.print("Zender: staatAnalogX: ");
     Serial.println(bericht.staatAnalogX);
   }
   if(bericht.staatAnalogY == 0 || bericht.staatAnalogY == 2) {
     Serial.print("Zender: staatAnalogY: ");
     Serial.println(bericht.staatAnalogY);
   }

   zend(bericht);

}
