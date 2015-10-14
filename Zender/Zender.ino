// C0NNECT

// Voeg JeeLib bibliotheek toe (voor zenden en ontvangen)
#include <JeeLib.h>
#include <C0_struct.h>
#include <C0_joystick.h>
#include <C0NNECT.h>

const byte C0_apparaatID = 1;

// Constanten aansluitingen knoppen
const byte C0_pinKnopSelect= 7;
const byte C0_pinKnopRechts = 3;
const byte C0_pinKnopLinks = 6;
const byte C0_pinKnopOnder = 5;
const byte C0_pinKnopBoven = 4;

const byte C0_pinAnalogX = 0;
const byte C0_pinAnalogY = 1;

C0_structBericht C0_bericht;
  
void setup() {
   pinMode(C0_pinKnopSelect, INPUT);  
   digitalWrite(C0_pinKnopSelect, HIGH);  
  
   pinMode(C0_pinKnopRechts, INPUT);  
   digitalWrite(C0_pinKnopRechts, HIGH);
  
   pinMode(C0_pinKnopLinks, INPUT);  
   digitalWrite(C0_pinKnopLinks, HIGH);
  
   pinMode(C0_pinKnopOnder, INPUT);  
   digitalWrite(C0_pinKnopOnder, HIGH);
   
   pinMode(C0_pinKnopBoven, INPUT);  
   digitalWrite(C0_pinKnopBoven, HIGH);  
  

   // Om de A/D conversie veel sneller te laten lopen. Scheelt 0.33 msec per conversie
   bitClear(ADCSRA,ADPS0);
   bitClear(ADCSRA,ADPS1);
   bitSet(ADCSRA,ADPS2);

   Serial.begin(9600);    
   rf12_initialize(C0_apparaatID, freq, network, 1600); 
   
   Serial.println("...");
   Serial.println("C0NNECT - Zender");
}
 

void loop() {

   C0_bericht.afzender = C0_apparaatID;

   C0_bericht.knopSelectIngedrukt = C0_knopIngedrukt(C0_pinKnopSelect);
   C0_bericht.knopRechtsIngedrukt = C0_knopIngedrukt(C0_pinKnopRechts);
   C0_bericht.knopLinksIngedrukt = C0_knopIngedrukt(C0_pinKnopLinks);
   C0_bericht.knopOnderIngedrukt = C0_knopIngedrukt(C0_pinKnopOnder);
   C0_bericht.knopBovenIngedrukt = C0_knopIngedrukt(C0_pinKnopBoven);
   
   C0_bericht.C0_staatAnalogX = C0_staatAnalog(C0_pinAnalogX);
   C0_bericht.C0_staatAnalogY = C0_staatAnalog(C0_pinAnalogY);
   
   
   if(C0_bericht.knopSelectIngedrukt) {Serial.println("Zender: knopSelectIngedrukt");}
   if(C0_bericht.knopRechtsIngedrukt) {Serial.println("Zender: knopRechtsIngedrukt");}
   if(C0_bericht.knopLinksIngedrukt) {Serial.println("Zender: knopLinksIngedrukt");}
   if(C0_bericht.knopOnderIngedrukt) {Serial.println("Zender: knopOnderIngedrukt");}
   if(C0_bericht.knopBovenIngedrukt) {Serial.println("Zender: knopBovenIngedrukt");}
   
   if(C0_bericht.C0_staatAnalogX == 0 || C0_bericht.C0_staatAnalogX == 2) {
     Serial.print("Zender: staatAnalogX: ");
     Serial.println(C0_bericht.C0_staatAnalogX);
   }
   if(C0_bericht.C0_staatAnalogY == 0 || C0_bericht.C0_staatAnalogY == 2) {
     Serial.print("Zender: staatAnalogY: ");
     Serial.println(C0_bericht.C0_staatAnalogY);
   } 

   C0_zend(C0_bericht); 
   
}
