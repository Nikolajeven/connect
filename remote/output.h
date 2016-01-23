//unsigned long tijdLaatstVerstuurdBericht;
unsigned long abc;

void output(){
  //Verstuur iedere 50ms een bericht
  //if(millis() > (tijdLaatstVerstuurdBericht + 10)){
    zend(bericht);
  //  tijdLaatstVerstuurdBericht = millis();
  //}
  if(millis() > (abc + 500)){
    Serial.println(bericht.statusMotor);
    abc = millis();
  }
}

