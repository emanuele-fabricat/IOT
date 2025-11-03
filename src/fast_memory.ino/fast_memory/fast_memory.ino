#include "lamps.h"
#include "buttons.h"
#include "difficult.h"
#include "stand_by.h"


void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.print(getLampValue(2));
}
