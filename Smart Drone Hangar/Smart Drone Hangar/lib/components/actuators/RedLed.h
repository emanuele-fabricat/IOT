#include <Arduino.h>

class RedLed
{
private:
    const int pin = 7;
public:
    RedLed();
    void On();
    void off();
    void test();
    ~RedLed();
};