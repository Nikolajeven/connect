structBericht bericht;
byte laatsteResultaatStatusMotor = 0;
unsigned long tijdLaatsteBerichtOntvangen;
boolean nietVerbonden;

void input(){
  bericht = ontvang();

  // Negeer berichten die niet door de remote zijn verzonden (13 is de standaard waarde van bericht.statusMotor, gedefinieerd in structBericht. De remote verstuurt nooit 13, dus als bericht.statusMotor 13 is, dan is dat bericht niet door de remote verzonden.)
  if(bericht.statusMotor == 13){
    bericht.statusMotor = laatsteResultaatStatusMotor;
    
    if(millis() > (tijdLaatsteBerichtOntvangen + 500)){
      nietVerbonden = true;
    }
    else{nietVerbonden = false;}//wel verbonden
    
  else{
    laatsteResultaatStatusMotor = bericht.statusMotor;
    tijdLaatsteBerichtOntvangen = millis();
  }
 
}
