structBericht ontvangenBericht;
boolean knopIsIngedrukt;
unsigned long huidigeTijd;

void input(){
  ontvangenBericht = ontvang(); // connect.h
  knopIsIngedrukt = false;
  huidigeTijd = millis();
}
