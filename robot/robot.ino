// connect

#include <JeeLib.h>
#include <connect_joystick.h>
#include <connect.h>

// unique node ID of receiver (1 through 30)
const byte connect_apparaatID = 2;

int RedLed=18;           // the PWM pin that the RedLED is attached to
int GreenLed=19;         // the A5=D19 pin that the GreenLED is attached to

connect_structBericht connect_bericht;

void setup()
{
  Serial.begin(9600);
  rf12_initialize(connect_apparaatID, freq, network, 1600);

  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  digitalWrite(GreenLed, 1);
  digitalWrite(RedLed, 1);

  Serial.println("...");
  Serial.println("connect - Ontvanger");
}

void loop() {
  connect_bericht = connect_ontvang();

  if(connect_bericht.knopSelectIngedrukt) {Serial.println("Ontvanger: knopSelectIngedrukt");}
  if(connect_bericht.knopRechtsIngedrukt) {Serial.println("Ontvanger: knopRechtsIngedrukt");}
  if(connect_bericht.knopLinksIngedrukt) {Serial.println("Ontvanger: knopLinksIngedrukt");}
  if(connect_bericht.knopOnderIngedrukt) {Serial.println("Ontvanger: knopOnderIngedrukt");}
  if(connect_bericht.knopBovenIngedrukt) {Serial.println("Ontvanger: knopBovenIngedrukt");}

  if(connect_bericht.knopSelectIngedrukt == true || connect_bericht.knopRechtsIngedrukt == true
  || connect_bericht.knopLinksIngedrukt == true || connect_bericht.knopOnderIngedrukt == true
  || connect_bericht.knopBovenIngedrukt == true) {
    digitalWrite(GreenLed, 0);
    delay(100);
  }
  else{digitalWrite(GreenLed, 1);}

  if(connect_bericht.connect_staatAnalogX == 0 || connect_bericht.connect_staatAnalogX == 2) {
    Serial.print("Ontvanger: staatAnalogX: ");
    Serial.println(connect_bericht.connect_staatAnalogX);
  }
  if(connect_bericht.connect_staatAnalogY == 0 || connect_bericht.connect_staatAnalogY == 2) {
    Serial.print("Ontvanger: staatAnalogY: ");
    Serial.println(connect_bericht.connect_staatAnalogY);
  }
}
