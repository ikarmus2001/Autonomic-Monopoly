// Player.h

#ifndef _PLAYER_h
#define _PLAYER_h

class Player
{
public:
    char player_id;
    char player_position;
    int balance; // nie wiem jakie wartoœci chcemy przechowywaæ

    Player(char id, char pos = 0, int starting_cash = 100)
    {
        this->player_id = id;
        this->player_position = pos;
        this->balance = starting_cash;
    }
    void turn(char roll);
    void check_position();
    void further_operations();
};

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

