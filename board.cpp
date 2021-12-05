#include "board.h"
#include <Player.h>
#include <LiquidCrystal_I2C.h>

//using namespace LiquidCrystal_I2C;  // ????

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

LiquidCrystal_I2C Board::lcd_initializing()
{
	LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // init lcd eee to trzeba naprawiæ
	lcd.init();
	lcd.begin(16, 2);
	lcd.backlight();
	lcd.setCursor(0, 0);
	lcd.print("Witaj!");
	lcd.setCursor(0, 1);
	lcd.print("Setup...");
	return lcd;
}

int Board::players_initializing()
{
	lcd.print("Dobra, to w ilu gramy?");
	int odp = 4; // pobraæ z klawiaturki wartoœæ
	return odp;
}

void Tile::buy_field(Player player)
{
	if (this->type == 1)  // is buyable
	{
		if (this->owner == 0)
		{
			
			if (player.balance >= this->value)
			{
				lcd.print("Kupujesz za %s?", this->value);
				// TODO ^this w jakiœ sposób trzeba te importy ogarn¹æ
				bool info_zwrotne = true;  // info zwrotne via klawiaturka, póki co hardcode true
				if (info_zwrotne == true)
				{
					this->owner = player.player_id;
					

				}
			}
		}
	}
}



void Tile::pay_penalty(Player player)
{
	if (player.balance >= this->value)
	{
		lcd.print("musisz zap³aciæ karê, blablabla");
		// przy³o¿enie karty, zabranie kaski z konta
		player.balance -= this->value;
	}
	else
	{
		// policzyæ ewentualn¹ wartoœæ posiad³oœci po sprzedaniu (cena_pocz¹tkowa * 0.8?)
		lcd.print("Ale siê ch³opie sp³uka³eœ, musisz coœ sprzedaæ");
	}
}


