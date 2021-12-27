#include "board.h"
#include "Player.h"
#include "LiquidCrystal_I2C.h"
#include "array" // ?


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

std::vector<Player> Board::players_initializing()
{
	// TODO this->lcd.print("Dobra, to w ilu gramy?");
	int odp = 4; // pobrac z klawiaturki
	bool recycle = true;
	std::vector<Player> players_list;
	while (recycle)
	{
		switch (odp)
		{
		case 4:
			Player p4 = Player(4);
			players_list.push_back(p4);
		case 3:
			Player p3 = Player(3);
			players_list.push_back(p3);
		case 2:
			Player p2 = Player(2);
			players_list.push_back(p2);
		case 1:
			Player p1 = Player(1);
			players_list.push_back(p1);
			recycle = false;
		default:
			recycle = true;
		}
	}
	return players_list;
	
}

std::vector<Tile> Board::initialize_tiles()
{
	/*
	return std::array<Tile, 36> = {
	Tile start(0, 0, 100, 0),
	Tile brown_dom_wedlikowskich(1, 1, 60, 1),
	Tile kasa_spoleczna_1(2, 4, 0, 0);
	Tile brown_drapacz_chmur(3, 1, 60, 1);
	Tile radio_eska(4, 3, 200, 0);
	Tile park_kosciuszki(5, 2, 200, 10);
	Tile turquoise_osiedle_tysiaclecia(6, 1, 100, 2);
	Tile szansa_1(7, 4, 0, 0);
	Tile turquoise_osiedle_gwiazdy(8, 1, 100, 2);

	Tile turquoise_(9, 1, 120, 2);
	}
	*/

	//Tile prison();
	//Tile pink_();
	//
	//Tile green_dworcowa()
	//looking for better monopoly pics 
	// zwykle: https://ocdn.eu/images/pulscms/YmE7MDA_/ae26bab2aa7b6620d816db7a126f1a20.jpg
	// kato https://ecsmedia.pl/c/16346400915680805-jpg-gallery.big-iext97058458.jpg


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


