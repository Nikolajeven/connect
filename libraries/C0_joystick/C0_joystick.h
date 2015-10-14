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
    else if(analogRead(C0_pinAnalog) > 510) {C0_resultaat = 2;}
    else {C0_resultaat = 1;}
  }
  if(C0_pinAnalog == 1){//535
    if(analogRead(C0_pinAnalog) < 520) {C0_resultaat = 0;}
    else if(analogRead(C0_pinAnalog) > 550) {C0_resultaat = 2;}
    else {C0_resultaat = 1;}
  }

  return C0_resultaat;
}
