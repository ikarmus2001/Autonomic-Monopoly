//#include <IRremote.hpp>
#include "LiquidCrystal_I2C.h"
#include "Wire.h"
#include "Player.h"
#include "board.h"
#include "InfraRed.h"

InfraRed IR(2); // Tworzy obiekt czujnika podczerwieni podlaczonego do pinu 2

void setup()
{
    IR.begin(); // Rozpoczyna prace czujnika podczerwieni

}

void loop()//player_list)
{

    bool end_condition = false;
    while (end_condition == false)  // turns till someone wins/game is terminated
    {

        //for (int x = 0; x < player_count; x++)
        //{
            // Player.turn()
        //}

    }
}

// Przyk³adowa funkcja pokazuj¹ca jak pracowaæ z czujnikiem podczerwieni
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
