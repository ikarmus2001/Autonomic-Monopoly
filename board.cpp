#include "board.h"
#include <Player.cpp>




class Field
{
	char id;
	char type;  // 0 - start, 1 - usual property, 2 - airport, 3 - penalty
	char value;  // buy price/penalty
	char owner;  // 0 - bank, <player id> - player

	void buy_field(Player player)
	{
		if (this->type == 1)  // is buyable
		{
			if (this->owner == 0)
			{
				lcd.print("Kupujesz za %s?", this->value);
				// TODO ^this w jakiœ sposób trzeba te importy ogarn¹æ


			}
		}
	}
};

class Board
{
	
};

