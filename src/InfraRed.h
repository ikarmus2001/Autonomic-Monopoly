#ifndef _INFRARED_h
#define _INFRARED_h

#include <IRremote.h>

#define ir0		0xE916FF00
#define ir1		0xF30CFF00
#define ir2		0xE718FF00
#define ir3		0xA15EFF00
#define ir4		0xF708FF00
#define ir5		0xE31CFF00
#define ir6		0xA55AFF00
#define ir7		0xBD42FF00
#define ir8		0xAD52FF00
#define ir9		0xB54AFF00
#define irMinus		0xF807FF00
#define irPlus		0xEA15FF00
#define irEQ		0xF609FF00
#define irPrev		0xBB44FF00
#define irNext		0xBF40FF00
#define irPlay		0xBC43FF00

// Zarezerwowane adresy, ale nie maja zastosowania póki co
#define irCHminus	0xBA45FF00
#define irCHplus	0xB847FF00
#define irCH		0xB946FF00
#define ir100		0xE619FF00
#define ir200		0xF20DFF00

class InfraRed
{
private:
	int IR_RECEIVE_PIN = 2;
public:
	InfraRed(int IR_RECEIVE_PIN);
	void begin();		// Rozpoczyna prace z czujnikiem
	void resume();		// Wznawia prace czujnika
	bool available();	// Sprawdza, czy pojawil sie jakis sygnal
	char decode();		// Dekoduje pobrany sygnal na akcje
	int accumulate_num(); // do wywalenia
};



#endif
