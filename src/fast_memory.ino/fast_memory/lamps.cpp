#include "lamps.h"
#include "config.h"
#include <Arduino.h>

int lampsPin[] = {4, 5, 6, 7};

void setLedOn(int i) {
  digitalWrite(lampsPin[i], HIGH);
}
void ledsOff() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(lampsPin[i], LOW);
  }
}

void redPulsingOn() {
  redOn();
  delay(THOUSAND);
  redOff();
  delay(THOUSAND);
}

void redOn() {
  digitalWrite(RED_LED_PIN, HIGH);
}

void redOff() {
  digitalWrite(RED_LED_PIN, LOW);
}