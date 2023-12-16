/*
 * SEVEN_SEG.c
 *
 * Created: 8/13/2022 12:52:50 PM
 *  Author: safifi
 */ 
#include "SEVEN_SEG.h"

void SEVEN_SEG_init(void){
	INIT_SEVEN_SEG_PINS;
}
void SEVEN_SEG_write(uint8_t data){ // 0 to 99
	uint8_t x = data % 10; // 
	EN2(1);
	EN1(0);
	A(READBIT(x,0));
	B(READBIT(x,1));
	C(READBIT(x,2));
	D(READBIT(x,3));
	_delay_ms(10);
	
	x = data / 10;
	EN2(0);
	EN1(1);
	A(READBIT(x,0));
	B(READBIT(x,1));
	C(READBIT(x,2));
	D(READBIT(x,3));
	_delay_ms(10);
	
	
}
