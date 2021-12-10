// board.h
#include <LiquidCrystal_I2C.h>
#include <Player.h>

#ifndef _BOARD_h
#define _BOARD_h

class Tile
{
public:
	char id;
	char type;  // 0 - start, 1 - usual property, 2 - airport, 3 - penalty
	char value;  // buy price/penalty
	char owner;  // 0 - bank, <player id> - player

	void buy_field(Player player, Board board);
	void pay_penalty(Player player, Board board);

	Tile(char tile_id, char tile_type, char tile_value, char tile_owner=0)
	{
		this->id = tile_id;
		this->type = tile_type;
		this->value = tile_value;
		this->owner = tile_owner;
	}
};

class Board
{
public:

	LiquidCrystal_I2C lcd_initializing();

	Tile tab[36]; // zainicjowaæ tablicê ze wszystkimi polami
	LiquidCrystal_I2C lcd = lcd_initializing();
	
	int players_initializing();
	
	Board()
	{
		
		int players_count = players_initializing();
		//Player players[4];
	}
	
	  // eee idk dlaczego tmp ma tu problem


};

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

