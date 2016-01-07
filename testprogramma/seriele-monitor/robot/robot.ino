// Libraries
#include <JeeLib.h>
#include <Connect.h>

// Var/const voor zenden en ontvangen
MilliTimer sendTimer; // Om getimed te zenden.
const byte network = 100;
const byte Receiver = 2;
const byte freq = RF12_868MHZ;
const byte RF12_NORMAL_SENDWAIT = 0;

connect_structBericht bericht;

void setup() {
  
  // Om de A/D conversie veel sneller te laten lopen. Scheelt 0.33 msec per conversie
  bitClear(ADCSRA,ADPS0);
  bitClear(ADCSRA,ADPS1);
  bitSet(ADCSRA,ADPS2);
  
  rf12_initialize(Receiver, freq, network, 1600);

  Serial.begin(9600);
  Serial.println("...");
  Serial.println("connect - robot");;
  
}

void loop(){
  
  // ontvang bericht
  if (rf12_recvDone() && rf12_crc == 0 && (rf12_hdr & RF12_HDR_CTL) == 0) {
    bericht = *(connect_structBericht*)rf12_data;
    Serial.println(bericht.inhoud);
  }
  
}
