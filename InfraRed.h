#ifndef _INFRARED_h
#define _INFRARED_h

#define ir0			0xE916FF00
#define ir1			0xF30CFF00
#define ir2			0xE718FF00
#define ir3			0xA15EFF00
#define ir4			0xF708FF00
#define ir5			0xE31CFF00
#define ir6			0xA55AFF00
#define ir7			0xBD42FF00
#define ir8			0xAD52FF00
#define ir9			0xB54AFF00
#define irMinus		0xF807FF00
#define irPlus		0xEA15FF00
#define irEQ		0xF609FF00
#define irPrev		0xBB44FF00
#define irNext		0xBF40FF00
#define irPlay		0xBC43FF00

// Zarezerwowane adresy, ale nie maj¹ zastosowania póki co
#define irCHminus	0xBA45FF00
#define irCHplus	0xB847FF00
#define irCH		0xB946FF00
#define ir100		0xE619FF00
#define ir200		0xF20DFF00

class Signal {
public:
	int IR_RECEIVE_PIN = 2;		// Signal pin, 2 is the default one
	
	void begin();				// Uruchamia IrReceiver
	uint32_t get();				// Pobiera sygna³ z pilota
};

class InfraRed : public Signal
{
public:
	char decode();				// Dekoduje pobrany sygna³ na akcje
};


#endif
