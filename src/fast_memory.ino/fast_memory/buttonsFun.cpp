#include "config.h"
#include "buttonsFun.h"
#include "lamps.h"
#include <Arduino.h>

bool buttonsPress[] = {false, false, false, false};

void button1Fun() {
  buttonsPress[0] = true;
}

void button2Fun() {
  buttonsPress[1] = true;
}

void button3Fun() {
  buttonsPress[2] = true;
}

void button4Fun() {
  buttonsPress[3] = true;
}