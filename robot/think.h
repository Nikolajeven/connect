byte laatsteResultaatStatusMotor = 0;
unsigned long tijdLaatsteBerichtOntvangen;
boolean nietVerbonden;
boolean schermAan;

void think(){
  
  // Negeer berichten die niet door de remote zijn verzonden (13 is de standaard waarde van bericht.statusMotor, gedefinieerd in structBericht. De remote verstuurt nooit 13, dus als bericht.statusMotor 13 is, dan is dat bericht niet door de remote verzonden.)
  if(bericht.statusMotor == 13){
    bericht.statusMotor = laatsteResultaatStatusMotor;
    
    // De robot ontvangt niet continu berichten van de remote, ook als ze wel verbonden zijn. Als het meer dan een halve seconde geleden is dat de remote voor het laatst een bericht van de remote heeft ontvangen, is de remote niet meer verbonden met de robot.
    if(millis() > (tijdLaatsteBerichtOntvangen + 500)){
      nietVerbonden = true;
    }
    else{nietVerbonden = false;}//wel verbonden
    
  }
  else{// Het bericht is door de remote verzonden
    laatsteResultaatStatusMotor = bericht.statusMotor;
    tijdLaatsteBerichtOntvangen = millis();
  }
  
  if (buttons) {
    if (buttons & BUTTON_UP) {schermAan = true;}
    if (buttons & BUTTON_DOWN) {schermAan = false;}
  }
  
}
