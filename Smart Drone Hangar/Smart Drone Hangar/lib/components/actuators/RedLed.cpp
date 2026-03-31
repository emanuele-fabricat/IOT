#include "RedLed.h"

RedLed::RedLed(/* args */)
{
    pinMode(pin, OUTPUT);
}

void RedLed::On()
{
    digitalWrite(pin, HIGH);
}

void RedLed::off()
{
    digitalWrite(pin, LOW);
}

void RedLed::test()
{
    On();
    delay(2000);
    off();
    delay(2000);
}

RedLed::~RedLed()
{
}
