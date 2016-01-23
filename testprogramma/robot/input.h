structBericht bericht;
byte laatsteResultaatStatusMotor = 0;

void input(){
  bericht = ontvang();
  if(bericht.statusMotor == 13){
    bericht.statusMotor = laatsteResultaatStatusMotor;
  }
  else{
    laatsteResultaatStatusMotor = bericht.statusMotor;
  }
}
