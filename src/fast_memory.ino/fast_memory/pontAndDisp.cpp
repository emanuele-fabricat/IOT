#include <Arduino.h>
#include "pontAndDisp.h"
#include "config.h"

int getTimeLv() {
  analogRead();
}

void writeText(const char* str) {
  Serial.println(str);
}

void printScore() {
  String text = "Score ";
  text += String(score);
  writeText(text.c_str());
}
