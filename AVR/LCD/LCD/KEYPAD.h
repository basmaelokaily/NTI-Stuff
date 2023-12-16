/*
 * KEYPAD.h
 *
 * Created: 10/23/2023 10:15:27 AM
 *  Author: LENOVO
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "std_macros.h"

#define KEYPAD_ROWS DDRC |= 0b11111111
#define KEYPAD_COLS DDRD |= 0b00000000 /*all rows and columns as inputs. */
//#define KEYPAD_PULL PORTD |= 0b11101000

#define KEYPAD_R1(x)		if (x == 1) SETBIT(PORTC, 5); else CLRBIT(PORTC, 5)
#define KEYPAD_R2(x)		if (x == 1)	SETBIT(PORTC, 4); else CLRBIT(PORTC, 4)
#define KEYPAD_R3(x)		if (x == 1) SETBIT(PORTC, 3); else CLRBIT(PORTC, 3)
#define KEYPAD_R4(x)		if (x == 1) SETBIT(PORTC, 2); else CLRBIT(PORTC, 2)
#define KEYPAD_C1			READBIT(PIND, 7) 
#define KEYPAD_C2			READBIT(PIND, 6)
#define KEYPAD_C3			READBIT(PIND, 5) 
#define KEYPAD_C4			READBIT(PIND, 3) 

void KEYPAD_INIT(void);
uint8_t KEYPAD_READ(void);
uint32_t KEYPAD_ADD(uint16_t num1, uint16_t num2);
uint32_t KEYPAD_SUB(uint16_t num1, uint16_t num2);
uint32_t KEYPAD_TIME(uint16_t num1, uint16_t num2);
void KEYPAD_SET_NUM1(uint16_t number);
void KEYPAD_SET_NUM2(uint16_t number);
uint16_t KEYPAD_GET_NUM1(void);
uint16_t KEYPAD_GET_NUM2(void);
void KEYPAD_CLR_NUM1(void);
void KEYPAD_CLR_NUM2(void);
uint8_t IS_A_DIGIT (uint8_t x);



#endif /* KEYPAD_H_ */


/*#define KEYPAD_R1			READBIT(PINC, 5)
#define KEYPAD_R2			READBIT(PINC, 4)
#define KEYPAD_R3			READBIT(PINC, 3)
#define KEYPAD_R4			READBIT(PINC, 2)
#define KEYPAD_C1(x)		if (x == 1) SETBIT(PORTD, 7); else CLRBIT(PORTD, 7)
#define KEYPAD_C2(x)		if (x == 1) SETBIT(PORTD, 6); else CLRBIT(PORTD, 6)
#define KEYPAD_C3(x)		if (x == 1) SETBIT(PORTD, 5); else CLRBIT(PORTD, 5)
#define KEYPAD_C4(x)		if (x == 1) SETBIT(PORTD, 3); else CLRBIT(PORTD, 3)
)*/