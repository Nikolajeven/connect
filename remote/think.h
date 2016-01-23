byte statusMotor = 0;
void think(){
  if(staatAnalogX > 450 && staatAnalogX < 550 && staatAnalogY > 450 && staatAnalogY < 550){
    statusMotor = 0; //Stilstand
  }
  
  if(staatAnalogX > 50 && staatAnalogX < 450 && staatAnalogY > 400 && staatAnalogY < 600){
    statusMotor = 1; //Halve kracht vooruit
  }
  if(staatAnalogX < 50 && staatAnalogY > 400 && staatAnalogY < 600){
    statusMotor = 2; //Volle kracht vooruit
  }
  
  if(staatAnalogX > 550 && staatAnalogX < 950 && staatAnalogY > 400 && staatAnalogY < 600){
    statusMotor = 3; //Halve kracht achteruit
  }
  if(staatAnalogX > 950 && staatAnalogY > 400 && staatAnalogY < 600){
    statusMotor = 4; //Volle kracht achteruit
  }
  
  if(staatAnalogX > 450 && staatAnalogX < 550 && staatAnalogY > 50 && staatAnalogY < 450){
    statusMotor = 5; //Halve kracht links (draaien)
  }
  if(staatAnalogX > 450 && staatAnalogX < 550 && staatAnalogY < 50){
    statusMotor = 6; //Volle kracht links (draaien)
  }
  
  if(staatAnalogX > 450 && staatAnalogX < 550 && staatAnalogY > 550 && staatAnalogY < 950){
    statusMotor = 7; //Halve kracht rechts (draaien)
  }
  if(staatAnalogX > 450 && staatAnalogX < 550 && staatAnalogY > 950){
    statusMotor = 8; //Volle kracht rechts (draaien)
  }
  
  if(staatAnalogX < 400 && staatAnalogY < 450){
    statusMotor = 9; //Links vooruit
  }
  if(staatAnalogX < 400 && staatAnalogY > 550){
    statusMotor = 10; //Rechts vooruit
  }
  if(staatAnalogX > 600 && staatAnalogY < 450){
    statusMotor = 11; //Links achteruit
  }
  if(staatAnalogX > 600 && staatAnalogY > 550){
    statusMotor = 12; //Rechts achteruit
  }
  
  bericht.statusMotor = statusMotor;
}
