structBericht bericht;

// Constanten aansluitingen knoppen
const byte pinKnopSelect= 7;
const byte pinKnopRechts = 3;
const byte pinKnopLinks = 6;
const byte pinKnopOnder = 5;
const byte pinKnopBoven = 4;

const byte pinAnalogX = 0;
const byte pinAnalogY = 1;

void setupInputs(){
  pinMode(pinKnopSelect, INPUT);
   digitalWrite(pinKnopSelect, HIGH);

   pinMode(pinKnopRechts, INPUT);
   digitalWrite(pinKnopRechts, HIGH);

   pinMode(pinKnopLinks, INPUT);
   digitalWrite(pinKnopLinks, HIGH);

   pinMode(pinKnopOnder, INPUT);
   digitalWrite(pinKnopOnder, HIGH);

   pinMode(pinKnopBoven, INPUT);
   digitalWrite(pinKnopBoven, HIGH);
}

//test
boolean knopIngedrukt(byte pinKnop) {
  boolean resultaat;

  if(!digitalRead(pinKnop)) {resultaat = true;}
  else {resultaat = false;}

  return resultaat;
}

byte staatAnalog(byte pinAnalog) {
  // 0 = links of beneden
  // 1 = midden
  // 2 = rechts of boven
  byte resultaat;

  if(pinAnalog == 0){//505
    if(analogRead(pinAnalog) < 490) {resultaat = 0;}
    else if(analogRead(pinAnalog) > 550) {resultaat = 2;}
    else {resultaat = 1;}
  }
  if(pinAnalog == 1){//535
    if(analogRead(pinAnalog) < 490) {resultaat = 0;}
    else if(analogRead(pinAnalog) > 550) {resultaat = 2;}
    else {resultaat = 1;}
  }

  return resultaat;
}

void input(){
  bericht.knopSelectIngedrukt = knopIngedrukt(pinKnopSelect);
  bericht.knopRechtsIngedrukt = knopIngedrukt(pinKnopRechts);
  bericht.knopLinksIngedrukt = knopIngedrukt(pinKnopLinks);
  bericht.knopOnderIngedrukt = knopIngedrukt(pinKnopOnder);
  bericht.knopBovenIngedrukt = knopIngedrukt(pinKnopBoven);

  bericht.staatAnalogX = staatAnalog(pinAnalogX);
  bericht.staatAnalogY = staatAnalog(pinAnalogY);
}
