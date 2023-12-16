/*
 * RTOS_TMR_program.c
 *
 *  Created on: Nov 19, 2023
 *      Author: Kareem Hussein
 */


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "std_macros.h"

/* RTOS */
#include "RTOS_TMR_interface.h"
#include "RTOS_TMR_register.h"


static void (*private_pCallBackCTC)(void) = nullptr_t;

void RTOS_TMR_voidInit(void)
{
	// Select Mode = CTC Mode
	CLRBIT(TCCR2,WGM20);
	SETBIT(TCCR2,WGM21);
	
	// Enable OC Interrupt
	SETBIT(TIMSK,OCIE2);
}


void RTOS_TMR_voidStart(void)
{
	// Select Prescaler Value = 64
	CLRBIT(TCCR2,CS20);
	CLRBIT(TCCR2,CS21);
	SETBIT(TCCR2,CS22);
}


void RTOS_TMR_voidStop(void)
{
	CLRBIT(TCCR2,CS20);
	CLRBIT(TCCR2,CS21);
	CLRBIT(TCCR2,CS22);
}


void RTOS_TMR_voidSetCallBackCTC(void(*ptrToFun)(void))
{
	if(ptrToFun!=nullptr_t)
	{
		private_pCallBackCTC = ptrToFun;
	}
}


void RTOS_TMR_voidSetCompareMatchValue(u8 copy_u8CompareValue)
{
	OCR2 = copy_u8CompareValue;
}

void __vector_4(void) __attribute__ ((signal));
void __vector_4(void)
{
	if(private_pCallBackCTC != nullptr_t)
	{
		private_pCallBackCTC();
	}
}