typedef struct {

   byte afzender; // De zendende nodeID

   // false = niet ingedrukt / true = ingedrukt
   boolean knopSelectIngedrukt = false;
   boolean knopRechtsIngedrukt = false;
   boolean knopLinksIngedrukt = false;
   boolean knopOnderIngedrukt = false;
   boolean knopBovenIngedrukt = false;

   // 0 tot 1000 (500 is standaard)
   int staatAnalogX = 500;
   int staatAnalogY = 500;

} connect_connect_structBericht; // Naam van structure

// Var/const voor zenden en ontvangen
MilliTimer sendTimer; // Om getimed te zenden.
const byte network = 100;
const byte Receiver = 2;
const byte freq = RF12_868MHZ;
const byte RF12_NORMAL_SENDWAIT = 0;

void connect_verstuurBericht (connect_structBericht inhoud) {
  rf12_recvDone();

  if (rf12_canSend() && sendTimer.poll(1)) {

    sendTimer.set(0);

    rf12_sendStart(RF12_HDR_DST|Receiver, &inhoud, sizeof inhoud);
    rf12_sendWait(RF12_NORMAL_SENDWAIT);

   }
}

connect_structBericht connect_ontvangBericht() {
  connect_structBericht inhoud;

  if (rf12_recvDone() && rf12_crc == 0 && (rf12_hdr & RF12_HDR_CTL) == 0) {
    inhoud = *(connect_structBericht*)rf12_data;
  }

  return inhoud;
}
