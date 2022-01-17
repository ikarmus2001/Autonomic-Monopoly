#include "InfraRed.h"
#include <IRremote.h>
#include <string.h>



// Konstruktor ustawiajacy pin dla czujnika
InfraRed::InfraRed(int IR_RECEIVE_PIN) {
    this->IR_RECEIVE_PIN = IR_RECEIVE_PIN;
}


// Rozpoczyna prace z czujnikiem
void InfraRed::begin()  // DONE
{
    IrReceiver.begin(this->IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

// Wznawia prace czujnika
void InfraRed::resume()  // DONE
{
    IrReceiver.resume();
}

// Sprawdza, czy pojawil sie jakis sygnal
bool InfraRed::available()  // DONE
{
    return IrReceiver.decode();
}

void InfraRed::start(int tickRate) 
{
  IrReceiver.start(tickRate);
}

void InfraRed::stop()
{
  IrReceiver.stop();
}

// Dekoduje sygnal i zwraca go w postaci chara
char InfraRed::decode() // DONE
{
    // Pobiera HEX i dekoduje go na jego odpowiednik w charze
    switch (IrReceiver.decodedIRData.decodedRawData) {
    case ir0:
        //Serial.println("0");
        return '0';
        break;
    case ir1:
        //Serial.println("1");
        return '1';
        break;
    case ir2:
        //Serial.println("2");
        return '2';
        break;
    case ir3:
        //Serial.println("3");
        return '3';
        break;
    case ir4:
        //Serial.println("4");
        return '4';
        break;
    case ir5:
        //Serial.println("5");
        return '5';
        break;
    case ir6:
        //Serial.println("6");
        return '6';
        break;
    case ir7:
        //Serial.println("7");
        return '7';
        break;
    case ir8:
        //Serial.println("8");
        return '8';
        break;
    case ir9:
        //Serial.println("9");
        return '9';
        break;
    case irMinus:
        // Obsluga przycisku - na pilocie, planowo ma sluzyc jako wymazywanie wartosci
        return '-';
        break;
    case irPlus:
        // Obsluga przycisku + na pilocie
        return '+';
        break;
    case irPrev:
        // Obsluga przycisku "previous" na pilocie
        return '<';
        break;
    case irNext:
        // Obsluga przycisku "next" na pilocie
        return '>';
        break;
    case irPlay:
        // Obsluga przycisku "play/pause" na pilocie
        // tymczasowo jako 'p', bo funkcja zwraca char, mozna zmienic funkcje na stringa dla wiekszej czytelnosci
        return 'p';
        break;
    case irEQ:
        // Obsluga przycisku EQ na pilocie
        // tymczasowo jako 'e'
        return 'e';
        break;
    default:
        return '?';
        break;
        // Opcjonalnie: dodac obsluge pozostalych przyciskow jesli zajdzie taka potrzeba
    }
    return '?';
}
