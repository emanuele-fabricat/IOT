#include "Led.h"

Led::Led(const int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void Led::On()
{
    digitalWrite(pin, HIGH);
}

void Led::off()
{
    digitalWrite(pin, LOW);
}

void Led::test()
{
    On();
    delay(2000);
    off();
    delay(2000);
}

Led::~Led()
{
}
