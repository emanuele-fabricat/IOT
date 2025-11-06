#include "phases.h"
#include <Arduino.h>
#include "config.h"
#include "buttonsFun.h"
#include "lamps.h"
#include "pontAndDisp.h"



void wakeUp() {
  redPulsingOn();
  if (buttonsPress[0]) {
    phase = STARTING_GAME;
  }
}

void setUp() {

}

void extractNumber() {
  String text = "";
  for (int i = 0; i < 4;) {
    bool duplicate = false;
    int num = random(1, 5);
    for (int j = 0; j < i ; j ++) {
      if (solution[j] == num) {
        duplicate = true;
      }
    }
    if (!duplicate) {
      solution[i] = num;
      i ++;
    }
  }
  for (int i = 0; i < 4; i ++) {
    text += String(solution[i]);
  }
  writeText(text.c_str());
  delay(2 * THOUSAND);
  phase = DIGITATION;
}

void attempt() {

}

void sleep() {

}

void playPhase(int i) {
  switch (i) {
    case WAKE_UP:
      wakeUp();
      break;
    case STARTING_GAME:
      setUp();
      break;
    case MEMORIZATION:
      extractNumber();
      break;
    default:
      break;
  }
}