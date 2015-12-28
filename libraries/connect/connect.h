MilliTimer sendTimer;
const byte network  = 100;
const byte Receiver = 2;
const byte freq = RF12_868MHZ;
const byte RF12_NORMAL_SENDWAIT = 0;


// setupConnect() wordt in setup() uitgevoerd
void setupConnect(byte apparaat){

  rf12_initialize(apparaat, freq, network, 1600);
  // rf12_initialize(): http://jeelabs.org/pub/docs/jeelib/RF12_8cpp.html#a555976cae59adf4533db8b1e6967ba9c

}

// Definieer een struct (structBericht)
typedef struct {
   byte afzender = 0;           // randomID van de afzender (0 = standaard waarde)
   byte geadresseerde = 0;      // randomID van de geadresseerde (0 = standaard waarde)
   byte status = 0;               // statusupdate (0 = standaard waarde)
   byte rgb[4];  // kleur van rgb led (wit = standaard waarde)

   /* Status bericht:
      0 = standaard waarde
      1 = ik ben beschikbaar, ik wil verbinding maken met geadresseerde
      2 = ik accepteer verbinding van ...
      3 = er is sprake van dubbele randomID's
   */

} structBericht; // Naam van structure

structBericht ontvang(){
  structBericht bericht;
  bericht.rgb[0] = 255;
  bericht.rgb[1] = 255;
  bericht.rgb[2] = 255;

  return bericht;
}
void verstuur(structBericht bericht){
}



/*






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

} connect_structBericht; // Naam van structure

connect_structSetupBericht setupBericht;
connect_structBericht bericht;

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

*/
