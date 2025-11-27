#ifndef __CONFIG__
#define __CONFIG__

#include "analogDevices.h"
#include "phases.h"

#define ONE_SECOND 1000

enum StartingTime
{
  INIT = 5 * ONE_SECOND,
  T_1 = 4 * ONE_SECOND,
  T_2 = 3 * ONE_SECOND,
  T_3 = 2 * ONE_SECOND,
  T_4 = 1 * ONE_SECOND,
};

extern int t1;
extern int f;
extern unsigned long startTime; // utilizzato per prendere le differenze di tempo
extern int solution[4];         // array con la combinazione corretta
volatile extern int guess[4];   // array con la combinazione digitata
volatile extern int number;     // numero delle cifre inserite
extern int phase;               // intero per la fase attuale
extern int score;

#endif
