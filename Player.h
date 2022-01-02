// Player.h
#include "board.h"
#include <vector>

#ifndef _PLAYER_h
#define _PLAYER_h

class Player
{
public:
    char player_id;  // id related to player color?
    char player_position;  // actually Tile::id
    char in_prison;
    int balance; // idk what else
    std::vector<Tile> owned_properties;

    Player(char id, char pos = 0, int starting_cash = 100, char in_prison=false)
    {
        this->player_id = id;
        this->player_position = pos;
        this->balance = starting_cash;
        this->in_prison = in_prison;
    }

    void turn(char roll, Board board);
    void check_position(Board board, Tile tile);
    void further_operations(Board board);
    void exchange_properties(Player second_player, Tile tile, int charge=0);
    void pledge_property(Tile tile);
    void retake_property(Tile tile);
    void buy_property(Tile tile, Board board);
    void pay_penalty(Tile tile, Board board);
    void pay_rent(Tile tile, Board board);
    void sell_to_live(int debt, Board board);
};

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

