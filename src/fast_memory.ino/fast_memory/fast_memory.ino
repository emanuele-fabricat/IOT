#include "buttonsFun.h"
#include "phases.h"
#include "pontAndDisp.h"
#include "lamps.h"
#include "config.h"
#include <EnableInterrupt.h>

void setup() {
  for (int i = 0; i < 4; i++) {
    enableInterrupt(buttonsPin[i], button1Fun,RISING);
    pinMode(lampsPin[i], OUTPUT);
  }
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
  int t1 = INIT;
  Serial.begin(9600);
}

void loop() { 
}
