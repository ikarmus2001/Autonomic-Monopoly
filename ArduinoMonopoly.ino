#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Player.h>

void lcd_initializing()
{
    LiquidCrystal_I2C lcd(0x27, 16, 2);  // init lcd
    lcd.init();
    lcd.begin(16, 2);
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Witaj!");
    lcd.setCursor(0, 1);
    lcd.print("Setup...");
}



int player_count()
{
    char result = 0;
    // read amount of players
    result = 4;

    return result;
}

int dice_roll()
{
    int dice_result = 0;
    // odczytanie wyniku z klawiaturki <somehow>
    return dice_result;
}


void setup()
{
#include <LiquidCrystal_I2C.h>
    lcd_initializing();

    //  rfid_init(); ?
    //  clock_init(); ?
    //  ustawienie diod/domków

    //  
}

void loop()//player_list)
{

    bool end_condition = false;
    while (end_condition == false)  // tury lec¹ dopóki nie ma koñca gry
    {

        //for (int x = 0; x < player_count; x++)
        //{
            // Player.turn()
        //}

    }
    // put your main code here, to run repeatedly:

}

int main()
{
    int players = player_count();
    setup();
    while (true)
    {
        loop();
    }
    return 0;
}

