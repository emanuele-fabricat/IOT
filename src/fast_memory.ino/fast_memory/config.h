#ifndef __CONFIG__
#define __CONFIG__


#define THOUSAND 1000
#include "pontAndDisp.h"
#include "phases.h"


extern int t1;
extern int f = 0;
extern unsigned long startTime = 0; //utilizzato per prendere le differenze di tempo
extern int solution[4] = {0, 0, 0, 0}; //array con la combinazione corretta
volatile extern int guess[4] = {0, 0, 0, 0}; //array con la combinazione digitata
volatile extern int number = 0; //numero delle cifre inserite
extern int phase = WAKE_UP; //intero per la fase attuale
extern int score = 0;

enum Mode {
    INIT = 0,
    LV_1 = 1,
    LV_2 = 2,
    LV_3 = 3,
    LV_4 = 4
};

#endif
