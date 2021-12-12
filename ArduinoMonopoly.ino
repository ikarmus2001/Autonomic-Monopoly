#include <LiquidCrystal_I2C.h>
#include <IRremote.hpp>
#include <Wire.h>
#include "Player.h"
#include "board.h"
#include "InfraRed.h"

int player_count()
{
    char result = 0;
    // read amount of players
    result = 4;

    return result;
}

int dice_roll()
{
    int dice_result = 0;
    // odczytanie wyniku z klawiaturki <somehow>
    return dice_result;
}


void setup()
{
    //Board board;

    InfraRed IR;
    // IR.IR_RECEIVE_PIN = 2;  // S³u¿y do ustawiania pinu od czujnika IR
    IR.begin();

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
