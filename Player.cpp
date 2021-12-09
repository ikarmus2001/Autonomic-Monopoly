#include "Player.h"
#include <board.h>
// #include 

void Player::turn(char roll)
{
    this->player_position += roll;
    this->check_position();
    this->further_operations();
}

void Player::check_position()
{
    // no idea how to refer position to Tile::id
    // if (this->player_position)
}

void Player::further_operations(Board board)
{
    board.lcd.print("Koniec ruchu, chcesz jeszcze:");
    delay(1500);
    board.lcd.print("<wpisz mnie>");
    // TODO
    // klawiaturka pobieranie odpowiedzi
}

void Player::exchange_properties(Player second_player, int charge=0, char exchanged_tile_id=NULL)
{
    // 
    
}

