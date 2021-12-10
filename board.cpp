#include "board.h"
#include <Player.h>
#include <LiquidCrystal_I2C.h>

using namespace std;

//using namespace LiquidCrystal_I2C;  // ????

//LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

LiquidCrystal_I2C Board::lcd_initializing()
{
	LiquidCrystal_I2C lcd_tmp = LiquidCrystal_I2C(0x27, 16, 2); // init lcd eee to trzeba naprawiæ
	lcd_tmp.init();
	lcd_tmp.begin(16, 2);
	lcd_tmp.backlight();
	lcd_tmp.setCursor(0, 0);
	lcd_tmp.print("Witaj!");
	lcd_tmp.setCursor(0, 1);
	lcd_tmp.print("Setup...");
	return lcd_tmp;
}

int Board::players_initializing()
{
	this->lcd.print("Dobra, to w ilu gramy?");
	int odp = 4; // pobraæ z klawiaturki wartoœæ
	return odp;
}

void Tile::buy_field(Player player, Board board)
{
	if (this->type == 1)  // is buyable
	{
		if (this->owner == 0)
		{
			
			if (player.balance >= this->value)
			{
				board.lcd.print("Kupujesz za " + this->value);
				bool info_zwrotne = true;  // info zwrotne via klawiaturka, póki co hardcode true
				if (info_zwrotne == true)
				{
					this->owner = player.player_id;
					

				}
			}
		}
	}
}



void Tile::pay_penalty(Player player, Board board)
{
	if (player.balance >= this->value)
	{
		board.lcd.print("musisz zap³aciæ karê, blablabla");
		// przy³o¿enie karty, zabranie kaski z konta
		player.balance -= this->value;
	}
	else
	{
		// policzyæ ewentualn¹ wartoœæ posiad³oœci po sprzedaniu (cena_pocz¹tkowa * 0.8?)
		board.lcd.print("Ale siê ch³opie sp³uka³eœ, musisz coœ sprzedaæ");
	}
}


