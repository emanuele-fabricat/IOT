#include <Arduino.h>
#include <Servo.h>

class Rotor
{
private:
    int pin;
    Servo motor;
    int pos = 0;
    int delta = 1;
public:
    Rotor(const int pin);
    void rotate(const int angle);
    void test();
    ~Rotor();
};