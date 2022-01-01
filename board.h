// board.h

#ifndef _BOARD_h
#define _BOARD_h

#include "LiquidCrystal_I2C.h"
#include <vector>
#include "Player.h"

class Tile
{
public:
	char id;
	char type;
	// 0 - start, 1 - usual property, 2 - airport, 3 - penalty, 4 - chance/social credit
	int value;  // buy price/penalty
	// TODO make a value-level list
	char owner;  // 0 - bank, <player id> - player
	bool pledge;  // 1 if property is pledged, otherwise 0
	char color;
	// 0 - no_color, 1 - brown, 2 - turquoise/light blue, 3 - pink, 4 - orange, 5 - red, 
	// 6 - yellow, 7 - green, 8 - dark blue, 9 - newspaper(id12) and waterworks(id28),
	// 10 - airports
	char property_level; // amount of houses

	Tile(char id, char type, int tile_value, char color, char owner=0, bool pledge=false, char property_level=0)
	{
		this->id = id;
		this->type = type;
		this->value = tile_value;
		this->color = color;
		this->owner = owner;
		this->pledge = pledge;
		this->property_level = property_level;
	}

	Tile()
	{
		//default constructor
	}
};

class Board
{
public:

	LiquidCrystal_I2C lcd_initializing();
	LiquidCrystal_I2C lcd = lcd_initializing();

	std::vector<Tile> initialize_tiles();
	std::vector<Tile> tiles_list = initialize_tiles();
	
	std::vector<Player> players_initializing();
	std::vector<Player> players_list = players_initializing();

	Tile tile_from_id(char searched_id);
	Player player_from_id(char player_id);

	int start_money;
	
	Board(int start_money=200)
	{
		this->start_money = start_money;
	}
};

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

