#include <Arduino.h>
#include "pontAndDisp.h"
#include "config.h"

int getPotLev() {
  return INIT;
}
void writeText(char* str) {
  Serial.println(str);
}