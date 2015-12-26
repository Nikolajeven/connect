//test
boolean connect_knopIngedrukt(byte connect_pinKnop) {
  boolean connect_resultaat;

  if(!digitalRead(connect_pinKnop)) {connect_resultaat = true;}
  else {connect_resultaat = false;}

  return connect_resultaat;
}

byte connect_staatAnalog(byte connect_pinAnalog) {
  // 0 = links of beneden
  // 1 = midden
  // 2 = rechts of boven
  byte connect_resultaat;

  if(connect_pinAnalog == 0){//505
    if(analogRead(connect_pinAnalog) < 490) {connect_resultaat = 0;}
    else if(analogRead(connect_pinAnalog) > 510) {connect_resultaat = 2;}
    else {connect_resultaat = 1;}
  }
  if(connect_pinAnalog == 1){//535
    if(analogRead(connect_pinAnalog) < 520) {connect_resultaat = 0;}
    else if(analogRead(connect_pinAnalog) > 550) {connect_resultaat = 2;}
    else {connect_resultaat = 1;}
  }

  return connect_resultaat;
}
