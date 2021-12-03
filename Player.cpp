#include "Player.h"
// #include 

class Player
{
    char player_id;
    char player_position;

public:
    Player(char id, char pos = 0)
    {
        this->player_id = id;
        this->player_position = pos;
    }

    void turn(char roll, )
    {
        this -> player_position += roll;
        check_position();
    }



};