#include "board.h"

LiquidCrystal_I2C Board::lcd_initializing()  // DONE
{
	LiquidCrystal_I2C lcd_tmp = LiquidCrystal_I2C(0x27, 16, 2);  // standard lcd init
	lcd_tmp.init();
	lcd_tmp.backlight();
	lcd_tmp.setCursor(0, 0);
	lcd_tmp.print(F("Witaj!"));
	delay(5000);
	lcd_tmp.clear();
	lcd_tmp.setCursor(0, 0);
	lcd_tmp.print(F("Rozstawiamy")); // Limited by 16x2 display
	lcd_tmp.setCursor(0, 1);
	lcd_tmp.print(F("pionki"));
	return lcd_tmp;
}

Vector<Player> Board::players_initializing()
{
	Vector<Player> players_list;
	Player p1 = Player(1);  // initialize players with their id
	Player p2 = Player(2);  // https://stackoverflow.com/a/19830820/14345698
	Player p3 = Player(3);  // can't initialize vars in switch/skip initializing as it was earlier
	Player p4 = Player(4);

	bool validState = true;  // while loop ending condition
    lcd.clear();
    delay(100);

    lcd.setCursor(0, 0);
    lcd.print(F("Wybierz ilosc"));
    lcd.setCursor(0, 1);
    lcd.print(F("graczy: "));

	while (validState)
	{
		char odp = '?';
		if (this->ir.available()) {
			odp = this->ir.decode(); // load value from InfraRed
			this->lcd.print(odp);
		}
		
		switch (odp)
		{  // push chosen amount of Player entities to vector 
		case '4':
			players_list.push_back(p4);
            players_list.push_back(p3);
            players_list.push_back(p2);
            players_list.push_back(p1);
            validState = false;
            break;
		case '3':
            players_list.push_back(p3);
            players_list.push_back(p2);
            players_list.push_back(p1);
            validState = false;
            break;
		case '2':
            players_list.push_back(p2);
            players_list.push_back(p1);
            validState = false;
            break;
		case '1':
			players_list.push_back(p1);
            validState = false;  // break 'while' loop, that's proper amount of players
			break;  // break switch, everything done
		case '?':
			break;	// break switch if there was no signal from remote
		default:
			this->lcd.clear();
			this->lcd.setCursor(0, 0);
			this->lcd.print(F("Podaj poprawna"));
			this->lcd.setCursor(0, 1);
			this->lcd.print(F("ilosc graczy."));
            this->ir.resume();

            delay(2000);
            this->lcd.clear();
            delay(100);

            this->lcd.setCursor(0, 0);
            this->lcd.print(F("Wybierz ilosc"));
            this->lcd.setCursor(0, 1);
            this->lcd.print(F("graczy: "));
            break;
		}
	}
	return players_list;
}

Vector<Tile> Board::initialize_tiles(const Board& board)  // TODO check
{
	// TODO inializing buy and pledge
	// @Seba check Tile constructor types (names and values)
	Vector<Tile> lista;

	Vector<int> cokolwiek0;
	cokolwiek0.push_back(board.start_money);
	Tile var0(0, F("Start"), 0, cokolwiek0, 0, 0,0,0,0);
	lista.push_back(var0);


	Vector<int> cokolwiek1;
	cokolwiek1.push_back((2, 10, 30, 90, 160, 250));
	Tile var1(1, F("Teznie, Ciechocinek"), 1, cokolwiek1, 1, 0, 0, 0, 0);
	lista.push_back(var1);


	Vector<int> cokolwiek2;
	cokolwiek2.push_back(NULL);
	Tile var2(2, F("Kasa spoleczna"), 4, cokolwiek2, 0, 0, 0, 0, 0);
	lista.push_back(var2);


	Vector<int> cokolwiek3;
	cokolwiek3.push_back((4, 20, 60, 150, 350, 450));
	Tile var3(3, F("Kopalnia soli, Wieliczka"), 1, cokolwiek3, 1, 0, 0, 0, 0, 0);
	lista.push_back(var3);


	Vector<int> cokolwiek4;
	cokolwiek4.push_back(200);
	Tile var4(4, F("Podatek dochodowy"), 3, cokolwiek4, 0, 0, 0, 0, 0, 0);
	lista.push_back(var4);


	Vector<int> cokolwiek5;
	cokolwiek5.push_back((25, 50, 100, 200));
	Tile var5(5, F("Lotnisko im. Lecha Walesy, Gdansk"), 2, cokolwiek5, 10, 0, 0, 0, 0, 0);
	lista.push_back(var5);


	Vector<int> cokolwiek6;
	cokolwiek6.push_back((6, 30, 90, 270, 400, 550));
	Tile var6(6, F("Muzeum zabawkarstwa, Kielce"), 1, cokolwiek6, 2, 0, 0, 0, 0, 0);
	lista.push_back(var6);


	Vector<int> cokolwiek7;
	cokolwiek7.push_back(NULL);
	Tile var7(7, F("Szansa"), 4, cokolwiek7, 0, 0, 0, 0, 0, 0);
	lista.push_back(var7);


	Vector<int> cokolwiek8;
	cokolwiek8.push_back((6, 30, 90, 270, 400, 550));
	Tile var8(8, F("Planetarium, Torun"), 1, cokolwiek8, 2, 0, 0, 0, 0, 0);
	lista.push_back(var8);


	Vector<int> cokolwiek9;
	cokolwiek9.push_back((8, 40, 100, 300, 450, 600));
	Tile var9(9, F("Park Myslecinek, Bydgoszcz"), 1, cokolwiek9, 2, 0, 0, 0, 0, 0);
	lista.push_back(var9);


	Vector<int> cokolwiek10;
	cokolwiek10.push_back(NULL);
	Tile var10(10, F("Wiezienie"), 5, cokolwiek10, 0, 0, 0, 0, 0, 0);
	lista.push_back(var10);


	Vector<int> cokolwiek11;
	cokolwiek11.push_back((10, 50, 150, 450, 625, 750));
	Tile var11(11, F("Tor regatowy Malta, Poznan"), 1, cokolwiek11, 3, 0, 0, 0, 0, 0);
	lista.push_back(var11);


	Vector<int> cokolwiek12;
	cokolwiek12.push_back((4, 10));
	Tile var12(12, F("TVN"), 7, cokolwiek12, 9, 0, 0, 0, 0, 0);
	lista.push_back(var12);


	Vector<int> cokolwiek13;
	cokolwiek13.push_back((10, 50, 150, 450, 625, 750));
	Tile var13(13, F("Wielka krokiew, Zakopane"), 1, cokolwiek13, 3, 0, 0, 0, 0, 0);
	lista.push_back(var13);


	Vector<int> cokolwiek14;
	cokolwiek14.push_back((12, 60, 180, 500, 700, 900));
	Tile var14(14, F("Stadion slaski, Chorzow"), 1, cokolwiek14, 3, 0, 0, 0, 0, 0);
	lista.push_back(var14);


	Vector<int> cokolwiek15;
	cokolwiek15.push_back((25, 50, 100, 200));
	Tile var15(15, F("Lotnisko Sadkow, Radom"), 2, cokolwiek15, 10, 0, 0, 0, 0, 0);
	lista.push_back(var15);


	Vector<int> cokolwiek16;
	cokolwiek16.push_back((14, 70, 200, 550, 750, 950));
	Tile var16(16, F("Panorama raclawicka, Wroclaw"), 1, cokolwiek16, 4, 0, 0, 0, 0, 0);
	lista.push_back(var16);


	Vector<int> cokolwiek17;
	cokolwiek17.push_back(NULL);
	Tile var17(17, F("Kasa spoleczna"), 4, cokolwiek17, 0, 0, 0, 0, 0, 0);
	lista.push_back(var17);


	Vector<int> cokolwiek18;
	cokolwiek18.push_back((14, 70, 200, 550, 750, 950));
	Tile var18(18, F("Narodowa Orkiestra Symfoniczna, Katowice"), 1, cokolwiek18, 4, 0, 0, 0, 0, 0);
	lista.push_back(var18);


	Vector<int> cokolwiek19;
	cokolwiek19.push_back((16, 80, 220, 600, 800, 1000));
	Tile var19(19, F("Teatr Wielki, Warszawa"), 1, cokolwiek19, 4, 0, 0, 0, 0, 0);
	lista.push_back(var19);


	Vector<int> cokolwiek20;
	cokolwiek20.push_back(NULL);
	Tile var20(20, F("Parking"), 8, cokolwiek20, 0, 0, 0, 0, 0, 0);
	lista.push_back(var20);


	Vector<int> cokolwiek21;
	cokolwiek21.push_back((18, 90, 250, 700, 875, 1050));
	Tile var21(21, F("Nowa Huta"), 1, cokolwiek21, 5, 0, 0, 0, 0, 0);
	lista.push_back(var21);


	Vector<int> cokolwiek22;
	cokolwiek22.push_back(NULL);
	Tile var22(22, F("Szansa"), 4, cokolwiek22, 0, 0, 0, 0, 0, 0);
	lista.push_back(var22);


	Vector<int> cokolwiek23;
	cokolwiek23.push_back((18, 90, 250, 700, 875, 1050));
	Tile var23(23, F("Stocznia Gdanska"), 1, cokolwiek23, 5, 0, 0, 0, 0, 0);
	lista.push_back(var23);


	Vector<int> cokolwiek24;
	cokolwiek24.push_back((20, 100, 300, 750, 925, 1100));
	Tile var24(24, F("Palac Kultury i Nauki, Warszawa"), 1, cokolwiek24, 5, 0, 0, 0, 0, 0);
	lista.push_back(var24);


	Vector<int> cokolwiek25;
	cokolwiek25.push_back((25, 50, 100, 200));
	Tile var25(25, F("Lotnisko Balice, Krakow"), 1, cokolwiek25, 10, 0, 0, 0, 0, 0);
	lista.push_back(var25);


	Vector<int> cokolwiek26;
	cokolwiek26.push_back((22, 110, 330, 800, 975, 1150));
	Tile var26(26, F("Monciak - Molo, Sopot"), 1, cokolwiek26, 6, 0, 0, 0, 0, 0);
	lista.push_back(var26);


	Vector<int> cokolwiek27;
	cokolwiek27.push_back((22, 110, 330, 800, 975, 1150));
	Tile var27(27, F("Krupowki, Zakopane"), 1, cokolwiek27, 6, 0, 0, 0, 0, 0);
	lista.push_back(var27);


	Vector<int> cokolwiek28;
	cokolwiek28.push_back((4, 10));
	Tile var28(28, F("Gazeta Wyborcza"), 7, cokolwiek28, 9, 0, 0, 0, 0, 0);
	lista.push_back(var28);


	Vector<int> cokolwiek29;
	cokolwiek29.push_back((24, 120, 360, 850, 1025, 1200));
	Tile var29(29, F("Ul. Piotrkowska, Lodz"), 1, cokolwiek29, 6, 0, 0, 0, 0, 0);
	lista.push_back(var29);


	Vector<int> cokolwiek30;
	cokolwiek30.push_back(NULL);
	Tile var30(30, F("Idz do wiezienia"), 6, cokolwiek30, 0, 0, 0, 0, 0, 0);
	lista.push_back(var30);


	Vector<int> cokolwiek31;
	cokolwiek31.push_back((26, 130, 390, 900, 1100, 1275));
	Tile var31(31, F("Slowinski Park Narodowy"), 1, cokolwiek31, 7, 0, 0, 0, 0, 0);
	lista.push_back(var31);


	Vector<int> cokolwiek32;
	cokolwiek32.push_back((26, 130, 390, 900, 1100, 1275));
	Tile var32(32, F("Bialowieski Park Narodowy"), 1, cokolwiek32, 7, 0, 0, 0, 0, 0);
	lista.push_back(var32);


	Vector<int> cokolwiek33;
	cokolwiek33.push_back(NULL);
	Tile var33(33, F("Kasa spoleczna"), 4, cokolwiek33, 0, 0, 0, 0, 0, 0);
	lista.push_back(var33);


	Vector<int> cokolwiek34;
	cokolwiek34.push_back((28, 150, 450, 1000, 1200, 1400));
	Tile var34(34, F("Tatrzanski Park Narodowy"), 1, cokolwiek34, 7, 0, 0, 0, 0, 0);
	lista.push_back(var34);


	Vector<int> cokolwiek35;
	cokolwiek35.push_back((25, 50, 100, 200));
	Tile var35(35, F("Lotnisko im. Fryderyka Chopina, Warszawa"), 2, cokolwiek35, 10, 0, 0, 0, 0, 0);
	lista.push_back(var35);


	Vector<int> cokolwiek36;
	cokolwiek36.push_back(NULL);
	Tile var36(36, F("Szansa"), 4, cokolwiek36, 0,0, 0, 0, 0, 0);
	lista.push_back(var36);


	Vector<int> cokolwiek37;
	cokolwiek37.push_back((35, 175, 500, 1100, 1300, 1500));
	Tile var37(37, F("Rynek Glowny, Krakow"), 1, cokolwiek37, 8, 0, 0, 0, 0, 0);
	lista.push_back(var37);


	Vector<int> cokolwiek38;
	cokolwiek38.push_back(100);
	Tile var38(38, F("Domiar podatkowy"), 3, cokolwiek38, 0, 0, 0, 0, 0, 0);
	lista.push_back(var38);


	Vector<int> cokolwiek39;
	cokolwiek39.push_back((50, 200, 600, 1400, 1700, 2000));
	Tile var39(39, F("Trakt Krolewski, Warszawa"), 1, cokolwiek39, 8, 0, 0, 0, 0, 0);
	lista.push_back(var39);


	return lista;
}

Tile Board::tile_from_id(char searched_id)  // Done
{
	if (searched_id >= 0 && searched_id <= 38)  // prevents IndexError
	{
		return this->tiles_list[searched_id];  // well, no need to explain
	}
}

Player Board::player_from_id(char player_id)  // Done | can be simplified to range-based loop
{
	for (int i = 0; i < this->players_list.size(); i++)  // iterate thru board.players_list
	{
		if (this->players_list[i].player_id == player_id)  // if player_id from list == searched id
		{
			return this->players_list[i];  // return Player obj from list
		}
	}
}
