// Var/const voor zenden en ontvangen
MilliTimer sendTimer; // Om getimed te zenden.
const byte network  = 100;
const byte Receiver = 2;
const byte freq = RF12_868MHZ;
const byte RF12_NORMAL_SENDWAIT = 0;

void C0_zend (C0_structBericht C0_bericht) {
  rf12_recvDone();

  if (rf12_canSend() && sendTimer.poll(1)) {

    sendTimer.set(0);

    rf12_sendStart(RF12_HDR_DST|Receiver, &C0_bericht, sizeof C0_bericht);
    rf12_sendWait(RF12_NORMAL_SENDWAIT);

   }
}

C0_structBericht C0_ontvang() {
  C0_structBericht C0_resultaat;

  if (rf12_recvDone() && rf12_crc == 0 && (rf12_hdr & RF12_HDR_CTL) == 0) {
    C0_resultaat = *(C0_structBericht*)rf12_data;
  }

  return C0_resultaat;
}
