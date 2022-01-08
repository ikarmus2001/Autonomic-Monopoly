#include <Arduino.h>
#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
// write your initialization code here
    lcd.init();
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print("Witaj!");
    delay(1000);
}

void przewijanie() {
    lcd.clear();
    //lcd.print("  EEWORLDONLINE  EEWORLDONLINE  EEWORLDO");
    lcd.clear();
    lcd.setCursor(0, 0);
    //lcd.print("eeworldonline.com  engineersgarage.com  ");
    lcd.print(" Rozstawiamy pionki  Rozstawiamy pionki ");
    for (int counter = 0; counter < 24; counter++) {
        lcd.scrollDisplayLeft();
        delay(600);
    }
}

void static_disp() {
    lcd.setCursor(0,0);
    lcd.print("Wybierz ilosc");
    lcd.setCursor(0,1);
    lcd.print("graczy:");
    delay(1000);
}

void static_disp2() {
    lcd.setCursor(0,0);
    lcd.print("Podaj poprawna ");
    lcd.setCursor(0,1);
    lcd.print("ilxzc graczy. dd");
    delay(1000);
}

void loop()
{
    //przewijanie();
    static_disp();
    delay(2000);
    static_disp2();
}