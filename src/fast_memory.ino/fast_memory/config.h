#ifndef __CONFIG__
#define __CONFIG__


#define THOUSAND 1000

extern int t1;
extern int f;
extern int startTime; //utilizzato per prendere le differenze di tempo
extern int solution[4]; //array con la combinazione corretta
volatile extern int guess[4]; //array con la combinazione digitata
volatile extern int number; //numero delle cifre inserite
extern int phase; //intero per la fase attuale
extern int score;

enum Mode {
    INIT = 0,
    LV_1 = 1,
    LV_2 = 2,
    LV_3 = 3,
    LV_4 = 4
};

#endif