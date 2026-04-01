#include <Arduino.h>

class DistanceSensor
{
private:
    int trigPin;
    int echoPin;
public:
    DistanceSensor(const int trigPin, const int echoPin);
    
    ~DistanceSensor();
};
