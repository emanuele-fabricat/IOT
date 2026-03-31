#include "Lcd.h"

Lcd::Lcd():lcd(0x27,20,4) {
    lcd.init();
    lcd.backlight();
}

void Lcd::write(const char *string) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(string);
}

Lcd::~Lcd()
{
}

