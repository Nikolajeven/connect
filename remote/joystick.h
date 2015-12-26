// Knoppen
boolean joystick_knopIngedrukt(byte pinKnop) {
  boolean resultaat;

  if(!digitalRead(pinKnop)) {resultaat = true;}
  else {resultaat = false;}

  return resultaat;
}

// Analog
byte joystick_setupAnalog(byte pinAnalog){
  return analogRead(pinAnalog);
}

byte joystick_staatAnalog(byte pinAnalog, byte setupAnalog) {
  // 0 = links of beneden
  // 1 = midden
  // 2 = rechts of boven
  byte resultaat;

  if(pinAnalog == 0){ //505
    if(analogRead(pinAnalog) < 490) {resultaat = 0;}
    else if(analogRead(pinAnalog) > 510) {resultaat = 2;}
    else {resultaat = 1;}
  }
  if(connect_pinAnalog == 1){ //535
    if(analogRead(connect_pinAnalog) < 520) {connect_resultaat = 0;}
    else if(analogRead(connect_pinAnalog) > 550) {connect_resultaat = 2;}
    else {connect_resultaat = 1;}
  }

  return connect_resultaat;
}
