#include "Player.h"

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
		// player id, tile and charge should be taken from keyboard and returned as array
		// then passed to exchange_properties method
		//TODO keyboard answers
		char second_player_id = 0;
		char tile_id = 20; 
		int charge = 0; //optional charge, check if is >= balance TODO
		//this->exchange_properties(second_player, charge, board.tile_from_id(tile_id));
		this->exchange_properties(board.player_from_id(second_player_id), board.tile_from_id(tile_id), charge);
		break;
	case 3: // TODO use chance/social credit card
		break;
	case 4: // TODO upgrade property/buy houses
		break;
	default: // 
		// board.lcd.print("jakies info");
		break;
	}
}

void Player::exchange_properties(Player second_player, Tile tile, int charge=0)
{
	// assuming balance is >= charge
	tile.owner = this->player_id;
	Tile tmp;
	for (int x = 0; x < this->owned_properties.size(); x++)
	{
		tmp = this->owned_properties[x];
		if (&tile == &tmp)
		{
			this->owned_properties.erase(this->owned_properties.x); // TODO dokonczyc asap, del certain element
		}
	}
	if (charge > 0)
	{
		this->balance -= charge;
		second_player.balance += charge;
	}
}

void Player::pledge_property(Tile tile)
{
	tile.pledge = true;
    this->balance += 0.6 * tile.value;
}

void Player::retake_property(Tile tile)
{
	tile.pledge = false;
	this->balance -= (0 * 6 * 1.2 * tile.value);
}

void Player::buy_property(Tile tile, Board board)
{
	// assuming property is owned by value
	if (this->balance >= tile.value)
	{
		// TODO print kupujesz za tyle i tyle
		this->balance -= tile.value;
		tile.owner = this->player_id;
		this->owned_properties.push_back(tile);
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
		int debt = tile.value;
		debt -= this->balance;
		this->balance = 0;
		this->sell_to_live(debt, board);
	}
}

void Player::sell_to_live(int debt, Board board)
{
	//TODO if someone wants to buy that person debt/exchange it for property or sth
	// mixing up pledging and selling properties to other players
	int possible_pledge_value = 0;
	for (int i = 0; i < this->owned_properties.size(); i++)
	{
		possible_pledge_value += this->owned_properties[i].value * 0.6;  // pledge value
	}

	bool clean_or_dead = true;
	while (clean_or_dead)
	{
		// ask if giving up?
		bool give_up = false;
		if (give_up)
		{
			// TODO del from board.players_list, all properties back to bank, del houses from owned tiles etc.
		}

		if (possible_pledge_value >= debt)
		{
			bool inputing_values = true;
			bool odp = false;
			int tmp_pledge_value = 0;
			std::vector<Tile> tiles_to_pledge;
			while (inputing_values)
			{
				// TODO ask which properties, end with inputing_values -> false
				odp = true;
				if (odp)
				{
					inputing_values = false;  // end up with pledging
				}
			}

			// ask if done
			bool done = false;
			if (done)
			{
				break;
			}
		}
		// sell properties to other player

		// ask if any player wants to buy any of properties
		bool anyone_buy = true;
		if (anyone_buy)
		{
			int total_sell_value = 0;
			while (total_sell_value < debt)
			{
				// ask for tile, player, price; ofc values hardcoded for greater reason
				char scnd_player_id = 1;
				Player second_player = board.player_from_id(scnd_player_id);
				char tile_id = 12;
				Tile tile = board.tile_from_id(tile_id);
				int charge = 50;
				this->exchange_properties(second_player, tile, charge);

				// ask if done
				bool done_2 = true;
				if (done_2)
				{
					int tmp = debt;
					debt -= total_sell_value;
					total_sell_value = abs(total_sell_value - debt);
					break;
				}
			}
		}

		if (debt <= 0)
		{
			this->balance += abs(debt);
			clean_or_dead = false; // DELETE ME LATER just for safety
			return;
		}

	}
	
}

void Player::pay_rent(Tile tile, Board board)
{
	if (tile.pledge == false) // property not pledged
	{
		if (tile.value <= this->balance) // can pay the rent
		{
			this->balance -= tile.value;

			Player player = board.player_from_id(tile.owner);
			player.balance += tile.value; // ? add cash to owner's balance
			// TODO print "you were charged {tile.value}, your balance is {this->balance}, thank you"
		}
		else // not enough money for paying the rent
		{
			int debt = tile.value - this->balance;
			this->balance = 0;
			this->sell_to_live(debt, board);
		}
	}
	// else property is pledged, can't charge players, return
}
