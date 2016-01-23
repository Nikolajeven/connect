// Var/const voor zenden en ontvangen
MilliTimer sendTimer; // Om getimed te zenden.
const byte network  = 100;
const byte Receiver = 2;
const byte freq = RF12_868MHZ;
const byte RF12_NORMAL_SENDWAIT = 0;

void setupConnect(byte apparaatID){
  // Om de A/D conversie veel sneller te laten lopen. Scheelt 0.33 msec per conversie
  bitClear(ADCSRA,ADPS0);
  bitClear(ADCSRA,ADPS1);
  bitSet(ADCSRA,ADPS2);

  rf12_initialize(apparaatID, freq, network, 1600);
}

typedef struct {
   // false = niet ingedrukt / true = ingedrukt
   boolean knopSelectIngedrukt = false;
   boolean knopRechtsIngedrukt = false;
   boolean knopLinksIngedrukt = false;
   boolean knopOnderIngedrukt = false;
   boolean knopBovenIngedrukt = false;

   // 0 tot 1000 (500 is standaard)
   int staatAnalogX = 500;
   int staatAnalogY = 500;
} structBericht; // Naam van structure

void zend (structBericht bericht) {
  rf12_recvDone();

  if (rf12_canSend() && sendTimer.poll(1)) {

    sendTimer.set(0);

    rf12_sendStart(RF12_HDR_DST|Receiver, &bericht, sizeof bericht);
    rf12_sendWait(RF12_NORMAL_SENDWAIT);

   }
}

structBericht ontvang() {
  structBericht resultaat;

  if (rf12_recvDone() && rf12_crc == 0 && (rf12_hdr & RF12_HDR_CTL) == 0) {
    resultaat = *(structBericht*)rf12_data;
  }

  return resultaat;
}
