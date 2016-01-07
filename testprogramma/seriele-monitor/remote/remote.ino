#include <JeeLib.h>
#include <connect.h>

#include "struct.h"
#include "joystick.h"

const byte apparaatID = 1;

structBericht bericht;

void setup() {

   // Om de A/D conversie veel sneller te laten lopen. Scheelt 0.33 msec per conversie
   bitClear(ADCSRA,ADPS0);
   bitClear(ADCSRA,ADPS1);
   bitSet(ADCSRA,ADPS2);

   Serial.begin(9600);
   rf12_initialize(apparaatID, freq, network, 1600);

   Serial.println("...");
   Serial.println("connect - remote");
}


void loop() {

   bericht.afzender = apparaatID;

   bericht.inhoud = 123;

   zend(bericht);

}
