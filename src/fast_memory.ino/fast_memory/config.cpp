#include "config.h"
#include "phases.h"
#include "pontAndDisp.h"

int t1 = T_0;
int f = 0;
int startTime = 0; //utilizzato per prendere le differenze di tempo
int solution[4] = {0, 0, 0, 0}; //array con la combinazione corretta
volatile int guess[4] = {0, 0, 0, 0}; //array con la combinazione digitata
volatile int number = 0; //numero delle cifre inserite
int phase = WAKE_UP; //intero per la fase attuale
int score = 0;
