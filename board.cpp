#include "board.h"
#include <Player.h>
#include <LiquidCrystal_I2C.h>

//using namespace LiquidCrystal_I2C;  // ????

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

LiquidCrystal_I2C Board::lcd_initializing()
{
	LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // init lcd eee to trzeba naprawi�
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
	int odp = 4; // pobra� z klawiaturki warto��
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
				// TODO ^this w jaki� spos�b trzeba te importy ogarn��
				bool info_zwrotne = true;  // info zwrotne via klawiaturka, p�ki co hardcode true
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
		lcd.print("musisz zap�aci� kar�, blablabla");
		// przy�o�enie karty, zabranie kaski z konta
		player.balance -= this->value;
	}
	else
	{
		// policzy� ewentualn� warto�� posiad�o�ci po sprzedaniu (cena_pocz�tkowa * 0.8?)
		lcd.print("Ale si� ch�opie sp�uka�e�, musisz co� sprzeda�");
	}
}


