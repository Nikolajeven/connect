// Voeg JeeLib bibliotheek toe (voor zenden en ontvangen)
#include <JeeLib.h>
#include <Connect-testprogramma.h>
#include "input.h"
#include "think.h"
#include "output.h"

const byte C0_apparaatID = 1;

void setup() {
  setupInputs();

  // Om de A/D conversie veel sneller te laten lopen. Scheelt 0.33 msec per conversie
  bitClear(ADCSRA,ADPS0);
  bitClear(ADCSRA,ADPS1);
  bitSet(ADCSRA,ADPS2);

  rf12_initialize(C0_apparaatID, freq, network, 1600);
  
  Serial.begin(9600);
  Serial.println("...");
  Serial.println("Remote");
}


void loop() {
  
  input();
  
  think(C0_apparaatID);
  
  output();

}
