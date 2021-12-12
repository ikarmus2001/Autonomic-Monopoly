#ifndef _INFRARED_h
#define _INFRARED_h

#define ir0 0xE916FF00
#define ir1 0xF30CFF00
#define ir2 0xE718FF00
#define ir3 0xA15EFF00
#define ir4 0xF708FF00
#define ir5 0xE31CFF00
#define ir6 0xA55AFF00
#define ir7 0xBD42FF00
#define ir8 0xAD52FF00
#define ir9 0xB54AFF00

class Signal {
public:
	int IR_RECEIVE_PIN = 2; // Signal pin, default is 2
	
	void begin();	// Uruchamia IrReceiver
	auto get();		// Pobiera sygna³ z pilota
};

class InfraRed : public Signal
{
public:
	char decode();	// Dekoduje pobrany sygna³ na akcje
};


#endif
