// connect

#include <JeeLib.h>
#include <connect_joystick.h>
#include <connect.h>

// unique node ID of receiver (1 through 30)
const byte apparaatID = 2;

int rodeLed = 18;   // the PWM pin that the RedLED is attached to
int groeneLed = 19; // the A5=D19 pin that the GreenLED is attached to

connect_structBericht bericht;

void setup() {
  rf12_initialize(apparaatID, freq, network, 1600);

  pinMode(rodeLed, OUTPUT);
  pinMode(groeneLed, OUTPUT);
  digitalWrite(groeneLed, 1);
  digitalWrite(rodeLed, 1);

  Serial.begin(9600);
  Serial.println("...");
  Serial.println("connect - Ontvanger");
}

void loop() {
  bericht = connect_ontvangBericht();

  if(bericht.knopSelectIngedrukt) {Serial.println("Ontvanger: knopSelectIngedrukt");}
  if(bericht.knopRechtsIngedrukt) {Serial.println("Ontvanger: knopRechtsIngedrukt");}
  if(bericht.knopLinksIngedrukt) {Serial.println("Ontvanger: knopLinksIngedrukt");}
  if(bericht.knopOnderIngedrukt) {Serial.println("Ontvanger: knopOnderIngedrukt");}
  if(bericht.knopBovenIngedrukt) {Serial.println("Ontvanger: knopBovenIngedrukt");}

  if(bericht.knopSelectIngedrukt == true || bericht.knopRechtsIngedrukt == true || bericht.knopLinksIngedrukt == true || bericht.knopOnderIngedrukt == true || bericht.knopBovenIngedrukt == true) {
    digitalWrite(groeneLed, 0);
    delay(100);
  }
  else{digitalWrite(groeneLed, 1);}

  if(bericht.joystic_staatAnalogX == 0 || bericht.joystic_staatAnalogX == 2) {
    Serial.print("Ontvanger: staatAnalogX: ");
    Serial.println(bericht.joystic_staatAnalogX);
  }
  if(bericht.joystic_staatAnalogY == 0 || bericht.joystic_staatAnalogY == 2) {
    Serial.print("Ontvanger: staatAnalogY: ");
    Serial.println(bericht.joystic_staatAnalogY);
  }
}
