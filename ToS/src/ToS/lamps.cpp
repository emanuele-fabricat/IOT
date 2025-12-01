#include "lamps.h"
#include "config.h"
#include <Arduino.h>

#define DECREMENT_OF_PULSING 0.2

int lampsPin[] = {4, 5, 6, 7};

void setLedOn(const int i) {
  digitalWrite(lampsPin[i], HIGH);
}
void ledsOff() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(lampsPin[i], LOW);
  }
}

void redPulsingOn() {
  redOn();
  delay(DECREMENT_OF_PULSING * ONE_SECOND);
  redOff();
  delay(DECREMENT_OF_PULSING * ONE_SECOND);
}

void redOn() {
  digitalWrite(RED_LED_PIN, HIGH);
}

void redOff() {
  digitalWrite(RED_LED_PIN, LOW);
}
