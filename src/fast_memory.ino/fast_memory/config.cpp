#include "config.h"

int t1;
int f = 0;
unsigned long startTime = 0;          // utilizzato per prendere le differenze di tempo
int solution[4] = {0, 0, 0, 0};       // array con la combinazione corretta
volatile int guess[4] = {0, 0, 0, 0}; // array con la combinazione digitata
volatile int number = 0;              // numero delle cifre inserite
int phase = WAKE_UP;                  // intero per la fase attuale
int score = 0;