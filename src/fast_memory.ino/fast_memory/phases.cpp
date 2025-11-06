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
  switch (getPotLev()) {
    case INIT:
      t1 = T_0;
      break;
    case LV_1:
      t1 = T_1;
      break;
    case LV_2:
      t1 = T_2;
      break;
    case LV_3:
      t1 = T_3;
      break;
    case LV_4:
      t1 = T_4;
      break;
    default:
      break;   
  }
  writeText("GO!");
  delay(THOUSAND);
  phase = MEMORIZATION;
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
  //prendere il tempo
}

void attempt() {
    /*
    stop interupt
      lampOn
      solution
      number ++
    start interrupt
    controllo soluzione
      totale
        giusta
          score ++
          reset
          display
          f ++
        sbagliata
          set phase
          reset
      parziale
        sbagliata
          reset
    Controllo tempo con T - f
    */
}

void lose() {
  String text = "Score ";
  redOn();
  text += String(score);
  writeText("Game Over");
  writeText(text.c_str());
  delay(2 * THOUSAND);
  phase = SLEEP;
}

void sleep() {
  /*
  mettere in sleep
  */
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
    case DIGITATION:
      attempt();
      break;
    case GAME_OVER:
      lose();
      break;
    case SLEEP:
      sleep();
      break;
    default:
      break;
  }
}