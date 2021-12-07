void setup() 
{
  #include <LiquidCrystal_I2C.h>
  lcd_initializing();
//  rfid_init(); ?
//  clock_init(); ?
//  ustawienie diod/domków
//  player_count = player_count();
//  
}

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

}

void move_player(int player, int steps)
{
  
}

int dice_roll()
{
  int dice_result
  return dice_result
}

void loop() 
{
  end_condition = false
  while(end_condition == false)  // tury lecą dopóki nie ma końca gry
  {
    move_player(player, dice_roll());
  }
  // put your main code here, to run repeatedly:
  
}

void turn()
{
  
}
