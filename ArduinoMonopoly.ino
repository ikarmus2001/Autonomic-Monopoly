//#include <IRremote.hpp>
#include <IRremote.hpp>
#include "LiquidCrystal_I2C.h"
#include "Wire.h"
#include "Player.h"
#include "board.h"
#include "InfraRed.h"

// Bookmarks:
// TODO
// string polishing
// Done
// CHECK
// @Kacper
// @Seba

void setup()
{
    Board board = Board(); // init board
}

void loop()
{
    bool end_condition = false;  // TODO
    while (end_condition == false)  // turns till someone wins/game is terminated
    {

    }
}

/*
// Przyk³adowa funkcja pokazuj¹ca jak pracowaæ z czujnikiem podczerwieni

InfraRed IR(2); // Tworzy obiekt czujnika podczerwieni podlaczonego do pinu 2

void wyswietl() 
{
    char znak;
    if (IR.available()) {
        if (IR.decode() != '?') {
            znak = IR.decode();

            if (znak == '-') {
                Serial.println("-");
                cursor -= 1;
                lcd.setCursor(cursor, 1);
                lcd.print(" ");
            }
            else {
                Serial.println(znak);
                lcd.setCursor(cursor, 1);
                lcd.print(znak);
                cursor += 1;
            }
        }
        IR.resume();
    }

}
*/
