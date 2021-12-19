//#include <IRremote.hpp>
#include "LiquidCrystal_I2C.h"
#include "Wire.h"
#include "Player.h"
#include "board.h"
#include "InfraRed.h"

InfraRed IR(2); // Tworzy obiekt czujnika podczerwieni podlaczonego do pinu 2

void setup()
{
    //Board board;

    IR.begin(); // Rozpoczyna prace czujnika podczerwieni

}

void loop()//player_list)
{

    bool end_condition = false;
    while (end_condition == false)  // tury lec¹ dopóki nie ma koñca gry
    {

        //for (int x = 0; x < player_count; x++)
        //{
            // Player.turn()
        //}

    }
    // put your main code here, to run repeatedly:
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

//int main()
//{
//    int players = player_count();
//    setup();
//    while (true)
//    {
//        loop();
//    }
//    return 0;
//}