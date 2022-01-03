#include "board.h"


LiquidCrystal_I2C Board::lcd_initializing()
{
	LiquidCrystal_I2C lcd_tmp = LiquidCrystal_I2C(0x27, 16, 2);
	lcd_tmp.begin(16, 2);
	lcd_tmp.backlight();
	lcd_tmp.setCursor(0, 0);
	lcd_tmp.print("Witaj!");
	lcd_tmp.setCursor(0, 1);
	lcd_tmp.print("Setup...");
	return lcd_tmp;
}

void Board::write_text(String text)
{
	// TODO strings
	this->lcd.write(text);
}

bool Board::keyboard_response()
{
	bool decision;
	//TODO
	//this->
	return decision;
}

std::vector<Player> Board::players_initializing()
{
	// TODO this->lcd.print("Dobra, to w ilu gramy?");
	int odp = 4; // pobrac z klawiaturki
	bool recycle = true;
	std::vector<Player> players_list;
	Player p1 = Player(1);  // can't initialize vars in switch/skip initializing as it was earlier
	Player p2 = Player(2);  // https://stackoverflow.com/a/19830820/14345698
	Player p3 = Player(3);
	Player p4 = Player(4);
	while (recycle)
	{
		switch (odp)
		{
		case 4:
			players_list.push_back(p4);
		case 3:
			players_list.push_back(p3);
		case 2:
			players_list.push_back(p2);
		case 1:			
			players_list.push_back(p1);
			recycle = false;
			break;
		default:
			recycle = true;
		}
	}
	return players_list;
	
}

std::vector<Tile> Board::initialize_tiles(Board board)
{
	std::vector<Tile> lista;
	std::vector<int> cokolwiek;
	cokolwiek.push_back(board.start_money);
	Tile var0 = Tile(0, F("Start"), 0, cokolwiek, 0);
	lista.push_back(var0);

	return lista;
}

Tile Board::tile_from_id(char searched_id)
{
	if (searched_id >= 0 && searched_id <= 36)
	{
		return this->tiles_list[searched_id];
	}
}

Player Board::player_from_id(char player_id)
{
	// TODO fix mess with players_list
	for (int i = 0; i < this->players_list.size(); i++)
	{
		if (this->players_list[i].player_id == player_id)
		{
			return this->players_list[i];
		}
	}
}
