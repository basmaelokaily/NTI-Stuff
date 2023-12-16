/*
 * KEYPAD.c
 *
 * Created: 10/23/2023 10:15:47 AM
 *  Author: LENOVO
 */ 
#include "KEYPAD.h"
const uint8_t KEYPAD_MATRIX[] = {'7', '8', '9', 'D'
								,'4', '5', '6', '*'
								,'1', '2', '3', '-'
								,'C', '0', '=', '+'};
								
static uint16_t NUMBER1 = 0;
static uint16_t NUMBER2 = 0;
unsigned char operation = ' ';

void KEYPAD_INIT() 
{
	KEYPAD_ROWS;
	KEYPAD_COLS;
	//KEYPAD_PULL;
}
uint8_t KEYPAD_READ()
{
	KEYPAD_R1(0); KEYPAD_R2(1); KEYPAD_R3(1); KEYPAD_R4(1);
	if(KEYPAD_C1 == 0)		return KEYPAD_MATRIX[0];
	if(KEYPAD_C2 == 0)		return KEYPAD_MATRIX[4];
	if(KEYPAD_C3 == 0)		return KEYPAD_MATRIX[8];
	if(KEYPAD_C4 == 0)		return KEYPAD_MATRIX[12];
	_delay_ms(1);	
	
	KEYPAD_R1(1); KEYPAD_R2(0); KEYPAD_R3(1); KEYPAD_R4(1);
	if(KEYPAD_C1 == 0)		return KEYPAD_MATRIX[1];
	if(KEYPAD_C2 == 0)		return KEYPAD_MATRIX[5];
	if(KEYPAD_C3 == 0)		return KEYPAD_MATRIX[9];
	if(KEYPAD_C4 == 0)		return KEYPAD_MATRIX[12];
	_delay_ms(1);
	
	KEYPAD_R1(1); KEYPAD_R2(1); KEYPAD_R3(0); KEYPAD_R4(1);
	if(KEYPAD_C1 == 0)		return KEYPAD_MATRIX[2];
	if(KEYPAD_C2 == 0)		return KEYPAD_MATRIX[6];
	if(KEYPAD_C3 == 0)		return KEYPAD_MATRIX[10];
	if(KEYPAD_C4 == 0)		return KEYPAD_MATRIX[14];
	_delay_ms(1);
	
	KEYPAD_R1(1); KEYPAD_R2(1); KEYPAD_R3(1); KEYPAD_R4(0); 
	if(KEYPAD_C1 == 0)		return KEYPAD_MATRIX[3];
	if(KEYPAD_C2 == 0)		return KEYPAD_MATRIX[7];
	if(KEYPAD_C3 == 0)		return KEYPAD_MATRIX[11];
	if(KEYPAD_C4 == 0)		return KEYPAD_MATRIX[15];
	_delay_ms(1);
		
	return 0;	
}


uint32_t KEYPAD_ADD(uint16_t num1, uint16_t num2)
{
	return num1+num2;
}
uint32_t KEYPAD_SUB(uint16_t num1, uint16_t num2)
{
	return num1-num2;
}
uint32_t KEYPAD_TIME(uint16_t num1, uint16_t num2)
{
	return num1 * num2;
}
void KEYPAD_SET_NUM1(uint16_t number)
{
	NUMBER1 = 0;
	NUMBER1 = number;
}
void KEYPAD_SET_NUM2(uint16_t number)
{
	NUMBER2 = 0;
	NUMBER2 = number;
}
uint16_t KEYPAD_GET_NUM1(void)
{
	return NUMBER1;
}
uint16_t KEYPAD_GET_NUM2(void)
{
	return NUMBER2;
}
void KEYPAD_CLR_NUM1(void)
{
	NUMBER1 = 0;
}
void KEYPAD_CLR_NUM2(void)
{
	NUMBER2 = 0;	
}

uint8_t IS_A_DIGIT (uint8_t x)
{
	if ((x == '+') || (x == '-') || (x == '*') || (x == 'D') || (x == '=') || (x == 'C'))
	{
		return 0;
	}
	else
		return 1;
}