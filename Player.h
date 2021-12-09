// Player.h
#include "board.h"

#ifndef _PLAYER_h
#define _PLAYER_h

class Player
{
public:
    char player_id;  // id related to player colour?
    char player_position;  // actually Tile::id
    int balance; // idk what else
    // list owned_properties?

    Player(char id, char pos = 0, int starting_cash = 100)
    {
        this->player_id = id;
        this->player_position = pos;
        this->balance = starting_cash;
    }
    void turn(char roll);
    void check_position();
    void further_operations(Board board);
    void exchange_properties(Player second_player, int charge = 0, char exchanged_tile_id = NULL);
};

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

