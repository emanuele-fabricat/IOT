#include "config.h"
#include "phases.h"

int t1 = INIT;
int f = 0;
int startTime = 0; //utilizzato per prendere le differenze di tempo
int solution[4] = {0, 0, 0, 0}; //array con la combinazione corretta
int guess[4] = {0, 0, 0, 0}; //array con la combinazione digitata
int number = 0; //numero delle cifre inserite
int phase = WAKE_UP; //intero per la fase attuale
