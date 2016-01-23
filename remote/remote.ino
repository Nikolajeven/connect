#include <JeeLib.h>
#include <Connect.h>

#include "input.h"
#include "think.h"
#include "output.h"

const byte apparaatID = 1;

void setup() {
  setupInputs();
  setupConnect(apparaatID);
  
  Serial.begin(9600);
  Serial.println("...");
  Serial.println("Remote");
}

void loop() {
  input();
  think();
  output();
}
