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
	// Methods

	// Attributes
	int id; // Tile id
	const static char name[] PROGMEM; // CHECK @Seba
	int type;  // determines tile's behavior
	// 0 - start, 1 - usual property, 2 - airport, 3 - penalty, 
	// 4 - chance/social credit, 5 - prison, 6 - go to prison
	// 7 - roll value-based property, 8 - parking/do-nothing
	std::vector<int> value;  // Tile value (over levels if possible)
	int color;
	// 0 - no_color, 1 - brown, 2 - turquoise/light blue, 3 - pink, 4 - orange, 5 - red, 
	// 6 - yellow, 7 - green, 8 - dark blue, 9 - newspaper(id12) and waterworks(id28),
	// 10 - airports
	int owner;  // 0 - bank, 1-4 - player_id
	bool pledge;  // true if property is pledged, otherwise false
	int property_level; // amount of houses, makes rent higher
	

	Tile(int id, const __FlashStringHelper* name, int type, std::vector<int> value,
		int color, int owner=0, bool pledge=false, int p_lvl=0)
	{
		this->id = id;
		this->name = name;  // @Seba
		this->type = type;
		this->value = value;
		this->color = color;
		this->owner = owner; // default owner is bank
		this->pledge = pledge; // default property is not pledged
		this->property_level = p_lvl; // default no houses - lvl 0
	}

	Tile()
	{
		//default constructor
	}
};

class Board
{
public:
	// Init methods
	LiquidCrystal_I2C lcd_initializing();
	InfraRed ir_initializing(int pin);
	std::vector<Tile> initialize_tiles(Board board);
	std::vector<Player> players_initializing();

	// Methods
	Tile tile_from_id(char searched_id);
	Player player_from_id(char player_id);

	// Attributes
	LiquidCrystal_I2C lcd = lcd_initializing();
	InfraRed ir = InfraRed(2);
	std::vector<Tile> tiles_list;
	std::vector<Player> players_list;

	int start_money;
	
	Board(int ir_pin=2, int start_money=200)
	{
		if (ir_pin != 2)
		{
			this->ir = ir_initializing(ir_pin);  // CHECK if pin != 2
		}
		this->tiles_list = initialize_tiles(*this); // CHECK idk if *this is correct
		this->players_list = players_initializing();
		
		this->start_money = start_money;
	}
	
};

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

