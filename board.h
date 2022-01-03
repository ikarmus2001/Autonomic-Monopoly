// board.h

#ifndef _BOARD_h
#define _BOARD_h

#include "LiquidCrystal_I2C.h"
#include <vector>
#include "Player.h"
#include "InfraRed.h"

class Tile
{
public:
	int id;
	int type;
	// 0 - start, 1 - usual property, 2 - airport, 3 - penalty, 
	// 4 - chance/social credit, 5 - prison, 6 - go to prison
	// 7 - roll value-based property, 8 - parking/do-nothing
	std::vector<int> value;  // buy price/penalty
	int owner;  // 0 - bank, <player id> - player
	bool pledge;  // 1 if property is pledged, otherwise 0
	int color;
	// 0 - no_color, 1 - brown, 2 - turquoise/light blue, 3 - pink, 4 - orange, 5 - red, 
	// 6 - yellow, 7 - green, 8 - dark blue, 9 - newspaper(id12) and waterworks(id28),
	// 10 - airports
	int property_level; // amount of houses
	const static char name[] PROGMEM;

	Tile(int id, const __FlashStringHelper* name, int type, std::vector<int> value, int color)
	{
		this->id = id;
		this->name = name;
		this->type = type;
		this->value = value;
		this->color = color;
		this->owner = 0;
		this->pledge = false;
		this->property_level = 0;
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

	InfraRed ir_initializing(int pin);
	InfraRed ir = ir_initializing(2);

	std::vector<Tile> initialize_tiles(Board board);
	std::vector<Tile> tiles_list = initialize_tiles(*this);

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

