#include <LiquidCrystal_I2C.h>
#include "InfraRed.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);
int cursor = 0;

InfraRed IR(2);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IR.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  player_init();
  Serial.println(F("Wyszło z pętli, świat uratowany, można świętować"));
  IR.stop();
  Serial.println(F("to uruchamiamy debug"));
  IR.start();
  lcd.clear();
  delay(100);
  while(true) {
    if (IR.available()) {
    char odp = '?';
    odp = IR.decode();
    Serial.println("odp: " + odp);
    lcd.print(odp);
    delay(100);
    }
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  //wyswietl();
  //player_init();
  //delay(100);
}

char getAns() {
  char odp = '?';
 
  if (IR.available()) {
    odp = IR.decode();
    Serial.println("odp: " + odp);
    lcd.print(odp);
  }

  return odp;
}

void gracze() {
    lcd.setCursor(0, 0);
    lcd.print(F("Wybierz ilosc"));
    lcd.setCursor(0, 1);
    lcd.print(F("graczy: "));
}

void player_init() {
  bool validState = true;
  lcd.clear();
  delay(100);
  gracze();
  while (validState) {
    char odp = '?';

    odp = getAns();
    
    delay(100);

    switch (odp) {
      case '4':
        Serial.println("tworze 4 gracza");
        Serial.println("tworze 3 gracza");
        Serial.println("tworze 2 gracza");
        Serial.println("tworze 1 gracza");
        validState = false;
        delay(100);
        break;
      case '3':
        Serial.println("tworze 3 gracza");
        Serial.println("tworze 2 gracza");
        Serial.println("tworze 1 gracza");
        validState = false;
        delay(100);
        break;
      case '2':
        Serial.println("tworze 2 gracza");
        Serial.println("tworze 1 gracza");
        validState = false;
        delay(100);
        break;
      case '1':
        Serial.println("tworze 1 gracza");
        validState = false;
        delay(100);
        break;
      case '?':
        break;
      default:
        lcd.clear();
        delay(200);

        lcd.setCursor(0, 0);
        lcd.print(F("Podaj poprawna"));
        lcd.setCursor(0, 1);
        lcd.print(F("ilosc graczy."));
        IR.resume();
        //odp = getAns();
        delay(2000);
        lcd.clear();
        delay(100);
        gracze();
        break;
    }
    delay(500);
  }
}
