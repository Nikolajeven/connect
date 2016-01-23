structBericht bericht;

// Constanten aansluitingen knoppen
const byte pinKnopSelect= 7;
const byte pinKnopRechts = 3;
const byte pinKnopLinks = 6;
const byte pinKnopOnder = 5;
const byte pinKnopBoven = 4;

const byte pinAnalogX = 0;
const byte pinAnalogY = 1;

int staatAnalogX = 500;
int staatAnalogY = 500;

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

void input(){
  staatAnalogX = analogRead(pinAnalogX);
  staatAnalogY = analogRead(pinAnalogY);
}
