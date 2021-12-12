#include "Player.h"
#include "board.h"
// #include 



void Player::turn(char roll)
{
    this->player_position += roll;
    this->check_position();
    this->further_operations();
}

void Player::check_position()
{

    // for(int i = 0; i < )
    //this->player_position
}

void Player::further_operations()
{

}
