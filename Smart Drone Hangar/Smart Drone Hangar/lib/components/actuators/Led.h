#include <Arduino.h>

class Led
{
private:
    int pin;
public:
    Led(const int pin);
    void On();
    void off();
    void test();
    ~Led();
};