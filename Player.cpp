#include <Player.h>


void Player::turn(char roll, Board board)
{
    this->player_position += roll;
    this->check_position();
    this->further_operations(board);
}

void Player::check_position()
{
    // no idea how to refer position to Tile::id
}

void Player::further_operations(Board board)
{
    board.lcd.print("Koniec ruchu, chcesz jeszcze:");
    delay(1500);
    board.lcd.print("<wpisz mnie>");
    // TODO
    // klawiaturka pobieranie odpowiedzi
}

void Player::exchange_properties(Player second_player, int charge=0, char exchanged_tile_id=NULL)
{
    // 
    
}

void Player::pledge_property(char property_id)
{
    int property_value = 1; // somehow get value
    this->balance += 0.6 * property_value;
}

void Player::retake_property(char property_id)
{

}

// TODO
void Player::buy_property(Tile tile, Board board)
{
	// chyba nie powinni�my sprawdza� czy pole jest buyable, o tym powinna zadecydowa� wywo�uj�ca funkcja
	if (tile.type == 1 || tile.type == 2)  // is buyable
	{
		if (tile.owner == 0)
		{

			if (this->balance >= tile.value)
			{
				board.lcd.print("Kupujesz za " + tile.value.to_string());
				bool info_zwrotne = true;  // info zwrotne via klawiaturka, p�ki co hardcode true
				if (info_zwrotne == true)
				{
					tile.owner = this->player_id;
					this->balance -= tile.value;
				}
			}


		}
	}
}

void Player::pay_penalty(Tile tile, Board board)
{
	if (this->balance >= tile.value)
	{
		board.lcd.print("musisz zap�aci� kar�, blablabla");
		// przy�o�enie karty, zabranie kaski z konta
		this->balance -= tile.value;
	}
	else
	{
		// policzy� ewentualn� warto�� posiad�o�ci po sprzedaniu (cena_pocz�tkowa * 0.8?)
		board.lcd.print("Ale si� ch�opie sp�uka�e�, musisz co� sprzeda�");
	}
}

