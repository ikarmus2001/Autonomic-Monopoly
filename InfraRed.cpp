#include "InfraRed.h"
#include <IRremote.hpp>

void Signal::begin() {
	IrReceiver.begin(this->IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

// Zczytuje sygna³ z pilota i zwraca go w postaci HEXa
uint32_t Signal::get() {
	if (IrReceiver.decode()) {
		return IrReceiver.decodedIRData.decodedRawData;
	}
    return 0;
}

// Dekoduje sygna³ i zwraca go w postaci chara
char InfraRed::decode() {
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
        // TODO: dodaæ pozosta³e przyciski
	}
}

