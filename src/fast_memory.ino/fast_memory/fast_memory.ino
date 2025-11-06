#include "buttonsFun.h"
#include "phases.h"
#include "pontAndDisp.h"
#include "lamps.h"
#include "config.h"
#include <EnableInterrupt.h>

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(lampsPin[i], OUTPUT);
  }
  enableInterrupt(BUTTON_1, button1Fun,RISING);
  enableInterrupt(BUTTON_2, button2Fun,RISING);
  enableInterrupt(BUTTON_3, button3Fun,RISING);
  enableInterrupt(BUTTON_4, button4Fun,RISING);
  pinMode(RED_LED_PIN, OUTPUT);
  int t1 = INIT;
  Serial.begin(9600);
  writeText("Welcome to TOS! Press B1 to Start");
  
}

void loop() {
  playPhase(phase);
}
