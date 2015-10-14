// C0NNECT
 
#include <JeeLib.h>
#include <C0_struct.h>
#include <C0_joystick.h>
#include <C0NNECT.h>

// unique node ID of receiver (1 through 30)
const byte C0_apparaatID = 2;

int RedLed=18;           // the PWM pin that the RedLED is attached to
int GreenLed=19;         // the A5=D19 pin that the GreenLED is attached to

C0_structBericht C0_bericht;

void setup()
{
  Serial.begin(9600); 
  rf12_initialize(C0_apparaatID, freq, network, 1600);

  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  digitalWrite(GreenLed, 1);
 digitalWrite(RedLed, 1); 

  Serial.println("...");
  Serial.println("C0NNECT - Ontvanger");  
}
   
void loop() {
  C0_bericht = C0_ontvang();
  
  if(C0_bericht.knopSelectIngedrukt) {Serial.println("Ontvanger: knopSelectIngedrukt");}
  if(C0_bericht.knopRechtsIngedrukt) {Serial.println("Ontvanger: knopRechtsIngedrukt");}
  if(C0_bericht.knopLinksIngedrukt) {Serial.println("Ontvanger: knopLinksIngedrukt");}
  if(C0_bericht.knopOnderIngedrukt) {Serial.println("Ontvanger: knopOnderIngedrukt");}
  if(C0_bericht.knopBovenIngedrukt) {Serial.println("Ontvanger: knopBovenIngedrukt");}
  
  if(C0_bericht.knopSelectIngedrukt == true || C0_bericht.knopRechtsIngedrukt == true 
  || C0_bericht.knopLinksIngedrukt == true || C0_bericht.knopOnderIngedrukt == true 
  || C0_bericht.knopBovenIngedrukt == true) {
    digitalWrite(GreenLed, 0);
    delay(100);
  }
  else{digitalWrite(GreenLed, 1);}
   
  if(C0_bericht.C0_staatAnalogX == 0 || C0_bericht.C0_staatAnalogX == 2) {
    Serial.print("Ontvanger: staatAnalogX: ");
    Serial.println(C0_bericht.C0_staatAnalogX);
  }
  if(C0_bericht.C0_staatAnalogY == 0 || C0_bericht.C0_staatAnalogY == 2) {
    Serial.print("Ontvanger: staatAnalogY: ");
    Serial.println(C0_bericht.C0_staatAnalogY);
  }
}


