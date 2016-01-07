// Libraries
#include <JeeLib.h>
#include <connect.h>

// Var/const voor zenden en ontvangen
MilliTimer sendTimer; // Om getimed te zenden.
const byte network = 100;
const byte Receiver = 2;
const byte freq = RF12_868MHZ;
const byte RF12_NORMAL_SENDWAIT = 0;

connect_structBericht bericht;

void setup() {

  Serial.begin(9600);
  Serial.println("robot");
  
}

void loop(){
  
  // ontvang bericht
  if (rf12_recvDone() && rf12_crc == 0 && (rf12_hdr & RF12_HDR_CTL) == 0) {
    bericht = *(connect_structBericht*)rf12_data;
    Serial.println(bericht.inhoud);
  }
  
}
