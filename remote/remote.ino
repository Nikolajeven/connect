#include <JeeLib.h>    // Library voor radiografische communicatie
#include <connect.h>   // Library voor uitwerking zenden en ontvangen
#include "joystick.h"  // Extern bestand voor joystick

const byte connect_apparaatID = 1;

// Constanten aansluitingen knoppen
const byte remote_pinKnopSelect= 7;
const byte remote_pinKnopRechts = 3;
const byte remote_pinKnopLinks = 6;
const byte remote_pinKnopOnder = 5;
const byte remote_pinKnopBoven = 4;

const byte remote_pinAnalogX = 0;
const byte remote_pinAnalogY = 1;

connect_structBericht connect_bericht;

void setup() {
   pinMode(remote_pinKnopSelect, INPUT);
   digitalWrite(remote_pinKnopSelect, HIGH);

   pinMode(remote_pinKnopRechts, INPUT);
   digitalWrite(remote_pinKnopRechts, HIGH);

   pinMode(remote_pinKnopLinks, INPUT);
   digitalWrite(remote_pinKnopLinks, HIGH);

   pinMode(remote_pinKnopOnder, INPUT);
   digitalWrite(remote_pinKnopOnder, HIGH);

   pinMode(remote_pinKnopBoven, INPUT);
   digitalWrite(remote_pinKnopBoven, HIGH);


   // Om de A/D conversie veel sneller te laten lopen. Scheelt 0.33 msec per conversie
   bitClear(ADCSRA,ADPS0);
   bitClear(ADCSRA,ADPS1);
   bitSet(ADCSRA,ADPS2);

   Serial.begin(9600);
   rf12_initialize(connect_apparaatID, freq, network, 1600);

   Serial.println("...");
   Serial.println("connect: remote");
}


void loop() {

   connect_bericht.afzender = connect_apparaatID;

   connect_bericht.knopSelectIngedrukt = connect_knopIngedrukt(remote_pinKnopSelect);
   connect_bericht.knopRechtsIngedrukt = connect_knopIngedrukt(remote_pinKnopRechts);
   connect_bericht.knopLinksIngedrukt = connect_knopIngedrukt(remote_pinKnopLinks);
   connect_bericht.knopOnderIngedrukt = connect_knopIngedrukt(remote_pinKnopOnder);
   connect_bericht.knopBovenIngedrukt = connect_knopIngedrukt(remote_pinKnopBoven);

   connect_bericht.connect_staatAnalogX = connect_staatAnalog(remote_pinAnalogX);
   connect_bericht.connect_staatAnalogY = connect_staatAnalog(remote_pinAnalogY);


   if(connect_bericht.knopSelectIngedrukt) {Serial.println("Remote: knopSelectIngedrukt");}
   if(connect_bericht.knopRechtsIngedrukt) {Serial.println("Remote: knopRechtsIngedrukt");}
   if(connect_bericht.knopLinksIngedrukt) {Serial.println("Remote: knopLinksIngedrukt");}
   if(connect_bericht.knopOnderIngedrukt) {Serial.println("Remote: knopOnderIngedrukt");}
   if(connect_bericht.knopBovenIngedrukt) {Serial.println("Remote: knopBovenIngedrukt");}

   if(connect_bericht.remote_staatAnalogX == 0 || connect_bericht.remote_staatAnalogX == 2) {
     Serial.print("Remote: staatAnalogX: ");
     Serial.println(connect_bericht.remote_staatAnalogX);
   }
   if(connect_bericht.remote_staatAnalogY == 0 || connect_bericht.remote_staatAnalogY == 2) {
     Serial.print("Remote: staatAnalogY: ");
     Serial.println(connect_bericht.remote_staatAnalogY);
   }

   connect_zend(connect_bericht);

}
