#include <JeeLib.h>
#include <Connect.h>

MilliTimer sendTimer;
const byte network  = 100;
const byte Sender = 1;
const byte freq = RF12_868MHZ;
const byte RF12_NORMAL_SENDWAIT = 0;

connect_structBericht bericht;

void setup() {

   // Om de A/D conversie veel sneller te laten lopen. Scheelt 0.33 msec per conversie
   bitClear(ADCSRA,ADPS0);
   bitClear(ADCSRA,ADPS1);
   bitSet(ADCSRA,ADPS2);

   rf12_initialize(Sender, freq, network, 1600);

   Serial.begin(9600);
   Serial.println("...");
   Serial.println("connect - remote");
}


void loop() {

   bericht.afzender = apparaatID;

   bericht.inhoud = 123;

   rf12_recvDone();
   
   if (rf12_canSend() && sendTimer.poll(1)) {
    sendTimer.set(0);
    rf12_sendStart(RF12_HDR_DST|Sender, &bericht, sizeof bericht);
    rf12_sendWait(RF12_NORMAL_SENDWAIT);
   }
   
   delay(500);

}
