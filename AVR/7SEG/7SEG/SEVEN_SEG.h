/*
 * SEVEN_SEG.h
 *
 * Created: 8/13/2022 12:53:05 PM
 *  Author: safifi
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "std_macros.h"

#define INIT_SEVEN_SEG_PINS DDRA |= 0b11111100;

void SEVEN_SEG_init(void);
void SEVEN_SEG_write(uint8_t data);

#define EN1(x) if(x == 1) SETBIT(PORTA,3); else CLRBIT(PORTA,3);
#define EN2(x) if(x == 1) SETBIT(PORTA,2); else CLRBIT(PORTA,2);
#define A(x)  if(x == 1) SETBIT(PORTA,4); else CLRBIT(PORTA,4);
#define B(x)  if(x == 1) SETBIT(PORTA,5); else CLRBIT(PORTA,5);
#define C(x)  if(x == 1) SETBIT(PORTA,6); else CLRBIT(PORTA,6);
#define D(x)  if(x == 1) SETBIT(PORTA,7); else CLRBIT(PORTA,7);



#endif /* SEVEN_SEG_H_ */