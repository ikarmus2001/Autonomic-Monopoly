#include "InfraRed.h"
#include <IRremote.hpp>

void Signal::begin() {
	IrReceiver.begin(this->IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

// Zczytuje sygna� z pilota i zwraca go w postaci HEXa
uint32_t Signal::get() {
	if (IrReceiver.decode()) {
		return IrReceiver.decodedIRData.decodedRawData;
	}
    return 0;
}

// Dekoduje sygna� i zwraca go w postaci chara
char InfraRed::decode() {
    // Pobiera HEX i dekoduje go na jego odpowiednik w charze
	switch (this->get()) {
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
            // Obs�uga przycisku - na pilocie, planowo ma sluzyc jako wymazywanie wartosci
            return '-';
            break;
        case irPlus:
            // Obs�uga przycisku + na pilocie
            return '+';
            break;
        case irPrev:
            // Obs�uga przycisku "previous" na pilocie
            return '<';
            break;
        case irNext:
            // Obs�uga przycisku "next" na pilocie
            return '>';
            break;
        case irPlay:
            // Obs�uga przycisku "play/pause" na pilocie
            // tymczasowo jako 'p', bo funkcja zwraca char, mo�na zmieni� funkcje na stringa dla wi�kszej czytelno�ci
            return 'p';
            break;
        case irEQ:
            // Obs�uga przycisku EQ na pilocie
            // tymczasowo jako 'e'
            return 'e';
            break;
        // Opcjonalnie: doda� obs�uge pozosta�ych przycisk�w je�li zajdzie taka potrzeba
	}
}

