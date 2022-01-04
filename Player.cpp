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

void Player::check_position(Board board, Tile tile)  // TODO case 7
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
				if (this->balance >= tile.buy_price)
				{
					board.lcd.print("Staæ Ciê, kupujesz?");  // string polishing
					char decision = board.ir.decode();
					if (decision == '+')
					{
						this->buy_property(tile, board);
					}
					else
					{
						//licytacja TODO_later
					}
				}
			}
			else // tile belongs to other player, pay rent
			{
				this->pay_rent(tile, board);
			}
		}
		//else -> property belongs to current player, it's ok
		break;
	case 3: //penalty
		this->pay_penalty(tile, board);
		break;
	case 4:  // TODO random chance cards, probably with moving to other places, giving money etc.
	case 5:  // prison (as visitor, do nothing)
	case 6:  // go to prison 
		this->player_position = 10;  // TODO_later board.prison_location and board.prison_duration?
		this->in_prison = 3;
		break;
	case 7:
		
	}

	this->further_operations(board);
}

void Player::further_operations(Board board)  // DONE, TODO_later
{
	board.lcd.print("Koniec ruchu, chcesz jeszcze:");  // string polishing
    board.lcd.print("<opcje>");  // string polishing
	char decision = board.ir.decode();
	Tile tmp;
	switch (decision)
	{
	case '1': // pledge properties
		char tile_id = 0; // klawiaturka
		this->pledge_property(board.tile_from_id(tile_id));
	case '2': // buy property from other player
		// assuming second player wants to trade
		char tile_id = board.ir.accumulate_num(); 
		tmp = board.tile_from_id(tile_id);
		int charge = board.ir.accumulate_num(); //optional charge
		this->exchange_property(board.player_from_id(tmp.owner), tmp , charge);
		// TODO_later add some print/msg?
		break;
	case '4': // upgrade property/buy houses
		char tile_id = board.ir.accumulate_num();
		tmp = board.tile_from_id(tile_id);
		this->upgrade_property(tmp, board);
		break;
	case '3': // TODO use chance/social credit card @Seba idk if it even fits in Arduino mem XD
		board.lcd.print("Work in progress, <do something>");  // string polishing
	case '-':
	default: // 
		board.lcd.print("dobra, to lecimy do nastêpnego gracza");  // string polishing
		break;
	}
}

void Player::exchange_property(Player second_player, Tile tile, int charge=0)  // DONE
{
	// actually thats more exchange_OR_SELL_property
	// note that property remains pledged (if was before)
	// changes owner, sets property_level to 0 and updates owned_properties of both players
	// assuming 
	// - balance is >= charge 
	// - second_player != 0 (bank) <- TODO
	// - tile is buyable (type == 1/2/7)
	tile.owner = this->player_id;  // owner change: 2nd player -> this
	this->owned_properties.push_back(tile);  // append tile to this->owned_properties
	tile.property_level = 0;  // you need to buy houses on your own, can't buy hotel that easy/cheap
	Tile tmp;  // temporary tile var for comparison (owned_property - tile)
	for (int x = 0; x < second_player.owned_properties.size(); x++)  // delete tile from this->owned_properties
	{
		tmp = second_player.owned_properties[x];  // each tile from owned_properties
		if (tile.id == tmp.id)  // if iterated tile == searched tile
		{   
			// delete tile from 2nd_player.owned_properties
			// https://www.cplusplus.com/reference/vector/vector/erase/#:~:text=myvector.erase%20(myvector.begin()%2B5)%3B
			second_player.owned_properties.erase(second_player.owned_properties.begin() + x);
		}
	}
	if (charge > 0)  // this player pays second_player <charge>
	{
		this->balance -= charge;  // take off cash from this player
		second_player.balance += charge;  // add charge to seller
	}
	else if (charge < 0)  // second_player pays this player <charge>
	{
		charge = abs(charge);  // |charge|, |-100| = 100
		second_player.balance -= charge;  // take off cash from this player
		this->balance += charge;  // add charge to seller
	}
	// if charge == 0 nobody are chargedS
}

void Player::pledge_property(Tile tile)  // CHECK
{
	// assuming 
	// - tile is not pledged yet
	// - tile is pledgeable/buyable (type = 1/2/7)
	tile.pledge = true;  // pledge it
    this->balance += static_cast<int>(tile.buy_price * 0.6);  // calculate and add converted value to balance
	// @Seba 0.6? mayby board.pledge_percentage or sth
}

void Player::retake_property(Tile tile)  // CHECK
{
	// assuming 
	// - player has enough cash to unpledge tile @Seba CHECK
	// - tile is already pledged
	// - tile is pledgeable/buyable (type = 1/2/7)
	tile.pledge = false;
	this->balance -= static_cast<int>(tile.buy_price * 0.6 * 1.2);  // pledge value + 20%
	// @Seba 1.2? mayby board.retake_value or sth
}

void Player::buy_property(Tile tile, Board board)  // DONE
{
	// assuming 
	// - property is owned by bank
	// player has enough cash and will to buy property
	this->balance -= tile.buy_price;  // player pays
	tile.owner = this->player_id;  // tile owner is now player
	this->owned_properties.push_back(tile);  // note that in owned_properties
}

void Player::upgrade_property(Tile tile, Board board)  // DONE CHECK
{
	int max_level = tile.value.size();
	if (tile.property_level == max_level)
	{
		board.lcd.print("Ju¿ jest max");  // string polishing
	}
	else
	{
		board.lcd.print("Zap³acisz {tile.level_cost}");  // string polishing
		char decision = board.ir.decode();
		if (decision == '+' and this->balance >= tile.level_cost)
		{
			this->balance -= tile.level_cost;
			tile.property_level += 1;
		}
	}
}

void Player::pay_penalty(Tile tile, Board board)  // DONE
{
	// assuming
	// - player stands on penalty tile
	if (this->balance >= tile.value[0])
	{
		board.lcd.print("musisz zaplacic kare, blablabla");  // string polishing
		// @Seba RFID card, take cash off, forgot to place this comment in places when needed :<
		this->balance -= tile.value[0];  // charge player
	}
	else // not enough cash
	{
		int debt = tile.value[0];  // initialize debt
		debt -= this->balance;  // minimalize debt
		this->balance = 0;
		this->sell_to_live(debt, board);  // pledge and/or sell properties to continue playing, second_player = bank
	}
}

void Player::pay_rent(Tile tile, Board board)  // CHECK, string polishing
{
	if (tile.pledge == false) // property not pledged
	{
		if (tile.value[tile.property_level] <= this->balance) // can pay the rent
		{
			this->balance -= tile.value[tile.property_level]; // charge player

			Player player = board.player_from_id(tile.owner); // find tiles' owner
			player.balance += tile.value[tile.property_level]; // add cash to owners' balance
			
			board.lcd.print("Placisz ");  // string polishing
			board.lcd.print(tile.value[tile.property_level]);  // string polishing
			board.lcd.print(", nowy stan konta: ");  // string polishing
			board.lcd.print(this->balance);  // string polishing
			
		}
		else // not enough money for paying the rent
		{
			int debt = tile.value[tile.property_level] - this->balance;  // debt - current balance (debt as little as possible)
			this->balance = 0;  // take cash off
			this->sell_to_live(debt, board, tile.owner);  // sell/pledge tiles to stay in game
		}
	}
	// else property is pledged, can't charge players, return
}

void Player::

void Player::sell_to_live(int debt, Board board, int second_player_id = 0)
{
	// assuming
	// - balance = 0
	// - debt > 0

	bool clean_or_dead = true;
	while (clean_or_dead)
	{
		clean_or_dead = false;
		int possible_pledge_value = 0;  // init check for max pledge_value
		for (int i = 0; i < this->owned_properties.size(); i++)  // iterate thru all owned_properties
		{
			Tile tmp_tile = this->owned_properties[i];
			if (tmp_tile.pledge == false)  // you can pledge property if it's not already pledged
			{
				possible_pledge_value += static_cast<int>(tmp_tile.buy_price * 0.6);  // pledge value
				// @Seba 0.6 or board.pledge_percentage
			}
		}

		if (possible_pledge_value > 0)  // can pledge any property
		{
			board.lcd.print("D³ug = {}, mo¿esz dostaæ {} za zastawianie");  // string polishing

			// TODO_later quick pledge (few options like <least properties>, <cheapest> etc.)
			bool inputing_values = true;
			while (inputing_values)
			{
				// @Seba possible pledges may blink slowly (houses), huh?
				bool x = true;
				while (x)
				{
					x = false;
					board.lcd.print("Podaj id pola"); // string polishing
					int choice = board.ir.accumulate_num();
					// check if choice in this->owned_properties
					bool ch = false;
					for (int i = 0; i < this->owned_properties.size(); i++)
					{
						if (this->owned_properties[i].id == choice)
						{
							ch = true;
							break;
						}
					}
					if (ch)
					{
						Tile tmp_tile = board.tile_from_id(choice);
						// @Seba add some prints?

						bool odp;
						if (odp)
						{
							inputing_values = false;  // end up with pledging
						}

						board.lcd.print("Zastawiasz dalej?"); // string polishing
						char x = board.ir.decode();
						if (x == '+')
						{
							x = true;
						}
					}
				}
			}

		}
		// sell properties to other player
		board.lcd.print("Ktoœ coœ kupi?"); // string polishing ask if any player wants to buy any of properties
		char anyone_buy = board.ir.decode();
		if (anyone_buy == '+')
		{
			int total_sell_value = 0;
			bool y = true;
			while (y)
			{
				y = false;
				board.lcd.print("Podaj id pola");  // string polishing
				char tile_id = board.ir.accumulate_num();
				Tile tile = board.tile_from_id(tile_id);

				Player second_player = board.player_from_id(tile.owner);
				int charge = 0;
				if (second_player.player_id == second_player_id)
				{
					// @Seba give up debt?
					board.lcd.print("Czy ta wymiana zeruje twój d³ug?"); // string polishing
					char odp = board.ir.decode();
					if (odp == '+')
					{
						debt = 0;
						charge = 0;
					}
				}
				else
				{
					board.lcd.print("Podaj wysokoœæ op³aty");  // string polishing
					charge = board.ir.accumulate_num();
				}

				this->exchange_property(second_player, tile, charge);

				board.lcd.print("Sprzedajesz/wymieniasz dalej?"); // string polishing
				char x = board.ir.decode();
				if (x == '+')
				{
					y = true;
				}
			}
		}

		if (debt <= 0)
		{
			this->balance += abs(debt);
			return;
		}
		else  // debt remains
		{
			// TODO give up/unable to pay up
			// so far it just works, make it better!
			board.lcd.print("Twój d³ug to wci¹¿ {debt}, poddajesz siê?");  // string polishing
			char give_up_decision = board.ir.decode();
			if (give_up_decision == '+')
			{
				board.lcd.print("Jesteœ pewny?");  // string polishing
				give_up_decision = board.ir.decode();
				if (give_up_decision == '+')
				{
					this->give_up(board);
				}
			}
			clean_or_dead = true;
		}
	}
}

void Player::give_up(Board board)  // CHECK
{
	this->balance = 0;
	for (int i = 0; i < this->owned_properties.size(); i++)
	{
		int id = this->owned_properties[i];  // CHECK E0413 Tile -> int
		Tile tmp = board.tile_from_id(id);
		tmp.owner = 0; // return properties to bank
	}

	for (int i = 0; i < board.players_list.size(); i++)  // delete from players_list
	{
		if (board.players_list[i].player_id == this->player_id)
		{
			board.players_list.erase(board.players_list.begin() + i);
		}
	}
	delete this;  // CHECK
}
