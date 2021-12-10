// board.h

#ifndef _BOARD_h
#define _BOARD_h

#include <LiquidCrystal_I2C.h>
#include <array>
#include <Player.h>

class Tile
{
public:
	char id;
	char type;  
	// 0 - start, 1 - usual property, 2 - airport, 3 - penalty, 4 - chance/social credit
	int value;  // buy price/penalty
	char owner;  // 0 - bank, <player id> - player
	bool pledge;  // czy posiadlosc zastawiona
	char color;  
	// 0 - no_color, 1 - brown, 2 - turquoise/light blue, 3 - pink, 4 - orange, 5 - red, 
	// 6 - yellow, 7 - green, 8 - dark blue, 9 - newspaper(id12) and waterworks(id28),
	// 10 - airports

	Tile(char id, char type, int tile_value, char color, char owner=0, bool pledge=false)
	{
		this->id = id;
		this->type = type;
		this->value = tile_value;
		this->color = color;
		this->owner = owner;
		this->pledge = pledge;
	}
};

class Board
{
public:

	LiquidCrystal_I2C lcd_initializing();
	std::array<Tile, 36> initialize_tiles();
	
	std::array<Player, 4> players_initializing();
	Tile tile_from_id(char searched_id);

	std::array<Tile, 36> tiles_list = initialize_tiles();
	LiquidCrystal_I2C lcd = lcd_initializing();
	std::array<Player, 4> players_list;
	//int players_count = players_initializing();
	

	
	Board()
	{
		//to ma byæ puste?
	}



};

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

