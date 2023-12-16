/*
 * RTOS_TMR_program.c
 *
 *  Created on: Nov 19, 2023
 *      Author: Kareem Hussein
 */


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* RTOS */
#include "RTOS_TMR_interface.h"
#include "RTOS_TMR_register.h"


static void (*private_pCallBackCTC)(void) = NULL;

void RTOS_TMR_voidInit(void)
{
	// Select Mode = CTC Mode
	CLR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	
	// Enable OC Interrupt
	SET_BIT(TIMSK,OCIE2);
}


void RTOS_TMR_voidStart(void)
{
	// Select Prescaler Value = 64
	CLR_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
}


void RTOS_TMR_voidStop(void)
{
	CLR_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);
}


void RTOS_TMR_voidSetCallBackCTC(void(*ptrToFun)(void))
{
	if(ptrToFun!=NULL)
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
	if(private_pCallBackCTC != NULL)
	{
		private_pCallBackCTC();
	}
}