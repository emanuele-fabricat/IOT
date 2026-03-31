#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Lcd {
private:
    LiquidCrystal_I2C lcd;
public:
    Lcd();
    void write(const char *string);
    ~Lcd();
};
