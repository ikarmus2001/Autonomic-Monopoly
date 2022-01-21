#include <Arduino.h>
#include "board.h"

//LiquidCrystal_I2C lcd(0x27, 16, 2);
Board board = Board();

void setup() {
// write your initialization code here
    board.ir.begin();
    board.lcd = board.lcd_initializing();
    delay(10000);
    board.players_list = board.players_initializing();
}

void loop()
{

}