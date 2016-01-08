#include <JeeLib.h>    // Library voor radiografische communicatie
#include <connect.h>   // Library voor uitwerking zenden en ontvangen
#include "joystick.h"  // Extern bestand voor joystick

// joystick
const byte joystick_pinKnopSelect = 7;
const byte joystick_pinKnopRechts = 3;
const byte joystick_pinKnopLinks = 6;
const byte joystick_pinKnopOnder = 5;
const byte joystick_pinKnopBoven = 4;

const byte joystick_pinAnalogX = 0;
const byte joystick_pinAnalogY = 1;

const byte joystick_setupAnalogX = joystick_setupAnalog(joystick_pinAnalogX);
const byte joystick_setupAnalogY = joystick_setupAnalog(joystick_pinAnalogY);

// connect
const byte apparaatID = 1;
connect_structSetupBericht setupBericht;
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
  while(setup){

  }
   bericht.afzender = connect_apparaatID;

   connect_zend(bericht);

}
