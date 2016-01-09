C0_structBericht C0_bericht;

// Constanten aansluitingen knoppen
const byte C0_pinKnopSelect= 7;
const byte C0_pinKnopRechts = 3;
const byte C0_pinKnopLinks = 6;
const byte C0_pinKnopOnder = 5;
const byte C0_pinKnopBoven = 4;

const byte C0_pinAnalogX = 0;
const byte C0_pinAnalogY = 1;

void setupInputs(){
  pinMode(C0_pinKnopSelect, INPUT);
   digitalWrite(C0_pinKnopSelect, HIGH);

   pinMode(C0_pinKnopRechts, INPUT);
   digitalWrite(C0_pinKnopRechts, HIGH);

   pinMode(C0_pinKnopLinks, INPUT);
   digitalWrite(C0_pinKnopLinks, HIGH);

   pinMode(C0_pinKnopOnder, INPUT);
   digitalWrite(C0_pinKnopOnder, HIGH);

   pinMode(C0_pinKnopBoven, INPUT);
   digitalWrite(C0_pinKnopBoven, HIGH);
}

//test
boolean C0_knopIngedrukt(byte C0_pinKnop) {
  boolean C0_resultaat;

  if(!digitalRead(C0_pinKnop)) {C0_resultaat = true;}
  else {C0_resultaat = false;}

  return C0_resultaat;
}

byte C0_staatAnalog(byte C0_pinAnalog) {
  // 0 = links of beneden
  // 1 = midden
  // 2 = rechts of boven
  byte C0_resultaat;

  if(C0_pinAnalog == 0){//505
    if(analogRead(C0_pinAnalog) < 490) {C0_resultaat = 0;}
    else if(analogRead(C0_pinAnalog) > 550) {C0_resultaat = 2;}
    else {C0_resultaat = 1;}
  }
  if(C0_pinAnalog == 1){//535
    if(analogRead(C0_pinAnalog) < 490) {C0_resultaat = 0;}
    else if(analogRead(C0_pinAnalog) > 550) {C0_resultaat = 2;}
    else {C0_resultaat = 1;}
  }

  return C0_resultaat;
}

void input(){
  C0_bericht.knopSelectIngedrukt = C0_knopIngedrukt(C0_pinKnopSelect);
  C0_bericht.knopRechtsIngedrukt = C0_knopIngedrukt(C0_pinKnopRechts);
  C0_bericht.knopLinksIngedrukt = C0_knopIngedrukt(C0_pinKnopLinks);
  C0_bericht.knopOnderIngedrukt = C0_knopIngedrukt(C0_pinKnopOnder);
  C0_bericht.knopBovenIngedrukt = C0_knopIngedrukt(C0_pinKnopBoven);

  C0_bericht.C0_staatAnalogX = C0_staatAnalog(C0_pinAnalogX);
  C0_bericht.C0_staatAnalogY = C0_staatAnalog(C0_pinAnalogY);
}
