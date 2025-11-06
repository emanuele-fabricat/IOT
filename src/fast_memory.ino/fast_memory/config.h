#ifndef __CONFIG__
#define __CONFIG__


#define THOUSAND 1000

extern int t1;
extern int f;
extern int startTime; //utilizzato per prendere le differenze di tempo
extern int solution[4]; //array con la combinazione corretta
extern int guess[4]; //array con la combinazione digitata
extern int number; //numero delle cifre inserite
extern int phase; //intero per la fase attuale

enum Times {
    INIT = 5,
    LV_1 = 4,
    LV_2 = 3,
    LV_3 = 2,
    LV_4 = 1
};

#endif