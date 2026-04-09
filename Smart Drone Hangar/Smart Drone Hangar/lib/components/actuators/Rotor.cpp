#include "Rotor.h"

Rotor::Rotor(const int pin)
{
    this->pin = pin;
    motor.attach(pin);

}

void Rotor::rotate(const int angle)
{
    if (angle <= 180)
    {
        motor.write(angle);
    }
}

void Rotor::test()
{
  int pos = 0;
  int delta = 1;
  for (int i = 0; i < 180; i++) {
    Serial.println(pos);
    this->rotate(pos);         
    delay(2);            
    pos += delta;
  }
  pos -= delta;
  delta = -delta;
  delay(1000);        
}

Rotor::~Rotor()
{
    motor.detach();
}
