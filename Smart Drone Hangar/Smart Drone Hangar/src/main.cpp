#include <Arduino.h>
#include "Scheduler.h"
#include "actuators/Rotor.h"


void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
}

void loop() {
  Rotor* r = new Rotor(11);
  r->test();
  r->~Rotor();
}
