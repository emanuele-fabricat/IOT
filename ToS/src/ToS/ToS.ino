#include "buttonsFun.h"
#include "phases.h"
#include "analogDevices.h"
#include "lamps.h"
#include "config.h"
#include "serviceFunction.h"
#include "interrupts.h"
#include <time.h>

void setup() {
  lcd.init();
  lcd.backlight();
  writeText("Welcome to TOS!", FIRST_ROW);
  writeText("Press B1 to Start", SECOND_ROW);
  inGameInterrupts();
  for (int i = 0; i < 4; i++) {
    pinMode(lampsPin[i], OUTPUT);
  }
  pinMode(RED_LED_PIN, OUTPUT);
  int t1 = INIT;
  phase = WAKE_UP;
  srand(time(NULL));
  takeTime();
}

void loop() {
  playPhase(phase);
}
