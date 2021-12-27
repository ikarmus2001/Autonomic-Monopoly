#include "Player.h"
#include "board.h"

void Player::turn(char roll, Board board)
{
	if (this->in_prison < 1) // player is not in prison
	{
		this->player_position += roll; // move player by roll value
		if (this->player_position > 36)
		{
			this->player_position %= 36;  //mod board length
			this->balance += board.start_money; // passed start, add money
		}
		this->check_position(board, board.tile_from_id(this->player_position));
		this->further_operations(board);
	}
	else
	{
		this->in_prison -= 1; // decrement amount of turns left to leave prison
	}
}

void Player::check_position(Board board, Tile tile)
{
	switch (tile.type) // 0 - start, 1 - usual property, 2 - airport, 3 - penalty, 4 - chance/social credit
	{
	case 0: // start, don't do anything
		break;
	case 1: // usual property, buyable
	case 2: // airport, same stuff
		if (tile.owner != this->player_id) // property doesen't belong to current player
		{
			if (tile.owner == 0) // tile belongs to bank/is available to buy
			{
				//ask if you want to buy property TODO
				bool decision = true; // hardcoded so far
				if (decision = true)
				{
					this->buy_property(tile, board);
				}
				else
				{
					//licytacja TODO_later
				}
			}
			else // tile belongs to other player, pay rent
			{
				this->pay_rent(tile, board);
			}
		}
		//else  // property belongs to current player
		//{
			//well whatever, go to player.further_operations
		//	break;
		//}
		break;
	case 3: //penalty
		this->pay_penalty(tile, board);
		break;
	case 4:
		// TODO random chance cards, probably with moving to other places, giving money etc.
	}
}

void Player::further_operations(Board board)
{
	// TODO klawiaturka pobieranie odpowiedzi
	//board.lcd.print("Koniec ruchu, chcesz jeszcze:");
    //delay(1500);
    //board.lcd.print("<wpisz mnie>");
	char decision = 1;
	switch (decision)
	{
	case 1: // pledge properties
		char tile_id = 0; // klawiaturka
		this->pledge_property(board.tile_from_id(tile_id));
	case 2: // buy property from other player
		// somehow we need to check if second player even wants to trade xd
		//TODO choose tile
		//tile_id;
		//charge;
		//this->exchange_properties(second_player, charge, board.tile_from_id(tile_id));
		break;
	case 3: // use chance/social credit card
		break;
	case 4: // TODO upgrade property/buy houses
		break;
	default: // 
		// board.lcd.print("jakies info");
		break;
	}
}

void Player::exchange_properties(Player second_player, int charge=0, char exchanged_tile_id=NULL)
{
    
}

void Player::pledge_property(Tile tile)
{
	tile.pledge = true;
    this->balance += 0.6 * tile.value;
}

void Player::retake_property(Tile tile)
{

}

void Player::buy_property(Tile tile, Board board)
{
	if (tile.owner == 0) // if current owner is bank
	{
		if (this->balance >= tile.value)
		{
			// TODO print kupujesz za tyle i tyle
			this->balance -= tile.value;
			tile.owner = this->player_id;
		}
	}
}

void Player::pay_penalty(Tile tile, Board board)
{
	if (this->balance >= tile.value)
	{
		board.lcd.print("musisz zaplacic kare, blablabla");
		// przylozenie karty, zabranie kaski z konta
		this->balance -= tile.value;
	}
	else // not enough cash
	{
		// TODO selling/pledging properties to pay the rent
	}
}

void Player::pay_rent(Tile tile, Board board)
{
	if (tile.pledge == false) // property not pledged
	{
		if (tile.value <= this->balance) // can pay the rent
		{
			this->balance -= tile.value;

			board.player_from_id(tile.owner).balance += tile.value; // ? add cash to owner's balance
			// TODO print "you were charged {tile.value}, your balance is {this->balance}, thank you"
		}
		else // not enough money for paying the rent
		{
			// TODO selling/pledging properties to pay the rent
		}
	}
	// else property is pledged, can't charge players, return
}
