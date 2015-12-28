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
    else if(analogRead(pinAnalog) > 510) {resultaat = 2;}
    else {resultaat = 1;}
  }
  if(pinAnalog == 1){//535
    if(analogRead(pinAnalog) < 520) {resultaat = 0;}
    else if(analogRead(pinAnalog) > 550) {resultaat = 2;}
    else {resultaat = 1;}
  }

  return resultaat;
}

