structBericht bericht;
uint8_t buttons;

void input(){
  
  bericht = ontvang();
  buttons = lcd.readButtons(); 
 
}
