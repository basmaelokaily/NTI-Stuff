/*
 * TIMER0.c
 *
 * Created: 9/5/2022 3:38:39 AM
 *  Author: lenovo 520
 */ 
#include "TIMER0.h"
/*
void (*timer0_ovf_isr)(void);
void (*timer0_ctc_isr)(void);*/

/***********************************
function_name: TIMER0_NORMMOD_INIT
purpose: the initialization of normal mode without prescaler
parameters: void
return_type: void
************************************/
void TIMER0_NORMMOD_INIT(void)
{
	PORTD0_output;
	SETBIT(TCCR0, CS00);
	SETBIT(TCCR0, FOC0);
	SETBIT(TIMSK, TOIE0);
	SETBIT(SREG, 7);

}
/***********************************
function_name: TIMER0_NORMMOD_INIT
purpose: the initialization of CTC mode without prescaler
parameters: void
return_type: void
************************************/
void TIMER0_CTCMOD_INIT(uint8_t ocr)
{
	PORTD0_output;
	//SETBIT(TCCR0, CS00);
	SETBIT(TCCR0, CS02);
	SETBIT(TCCR0, FOC0);
	SETBIT(TCCR0, WGM01);
	SETBIT(TCCR0, COM00);
	OCR0 = ocr;
	//SETBIT(TIMSK, OCIE0);
	//SETBIT(SREG, 7);
}
void TIMER_START()
{
	//256 pre-scaler
	SETBIT(TCCR0, CS02);
	TCNT0 = 0;
}

/***********************************
function_name: TIMER0_NORMMOD_INIT
purpose: the initialization of CTC mode without prescaler
parameters: void
return_type: void
************************************/
void TIMER0_FREQ_GEN_INIT(uint8_t ocr)
{
	SETBIT(TCCR0, CS00);
	SETBIT(TCCR0, CS02);
	SETBIT(TCCR0, FOC0);
	SETBIT(TCCR0, WGM01);
	OCR0 = ocr;
	SETBIT(TIMSK, OCIE0);
	SETBIT(SREG, 7);
}

