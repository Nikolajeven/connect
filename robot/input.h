structBericht bericht;
uint8_t buttons;
unsigned long tijd;

void input(){
  
  tijd = millis();
  bericht = ontvang();
  buttons = lcd.readButtons(); 
 
}
