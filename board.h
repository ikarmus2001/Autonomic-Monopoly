// board.h

#ifndef _BOARD_h
#define _BOARD_h

#include <LiquidCrystal_I2C.h>

class Tile
{
public:
	char id;
	char type;  // 0 - start, 1 - usual property, 2 - airport, 3 - penalty
	char value;  // buy price/penalty
	char owner;  // 0 - bank, <player id> - player

	void buy_property(Player player, Board board);
	void pay_penalty(Player player, Board board);
};

class Board
{
public:

	Tile tab[36]; // zainicjowaæ tablicê ze wszystkimi polami

	LiquidCrystal_I2C lcd_initializing();
	LiquidCrystal_I2C lcd = lcd_initializing();
	
	int players_initializing();
	int players_count = players_initializing();
	Player players[4];  // eee idk dlaczego tmp ma tu problem


};

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

