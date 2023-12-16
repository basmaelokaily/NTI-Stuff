/*
 * SERVO.c
 *
 * Created: 10/31/2023 10:50:12 AM
 *  Author: LENOVO
 */ 
#include "SERVO.h"
void SERVO_MOVE_POS_90()
{
	OCR1A = 2000;
}
void SERVO_MOVE_POS_45()
{
	OCR1A = 1750;
}
void SERVO_MOVE_CENTER()
{
	OCR1A = 1500;
}
void SERVO_MOVE_NEG_45()
{
	OCR1A = 1250;
}
void SERVO_MOVE_NEG_90()
{
	OCR1A = 1000;
}