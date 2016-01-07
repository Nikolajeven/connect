// Libraries
#include <JeeLib.h>
#include <connect.h>

const byte apparaat = 2; // robot = 2, remote = 1, GEEN ID!

void setup() {

  Serial.begin(9600);
  Serial.println("robot");

  randomSeed(analogRead(0));
}

void loop(){

}
