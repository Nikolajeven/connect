// Libraries
#include <JeeLib.h>
#include <connect.h>

#include "input.h"
#include "think.h"
#include "output.h"

const byte apparaat = 2; // robot = 2, remote = 1, GEEN ID!

byte pinRed = 0;
byte pinGreen = 0;
byte pinBlue  = 0;

void setup() {

  setupConnect(apparaat); // connect.h

  Serial.begin(9600);
  Serial.println("robot");

  randomSeed(analogRead(0));
}

const int randomID = -1 * random(1, 32769); // robots hebben een negatief ID

void loop(){

  input();  // input.h
  think(randomID);  // think.h
  output(pinRed, pinGreen, pinBlue); // output.h

}
