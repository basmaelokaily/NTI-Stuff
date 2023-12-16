/*
 * TIMER1.cpp
 *
 * Created: 9/12/2022 1:13:13 AM
 * Author : lenovo 520
 */ 

#include "TIMER1.h"

/***********************************
function_name: TIMER1_PWM_OC1A_INIT
purpose: the initialization timer1 pwm pin OC1A (fast freq, fast pwm, non inverting, noprescale)
parameters: void
return_type: void
************************************/

void TIMER1_PWM_OC1A_INIT(void)
{
	SETBIT(DDRD, 5);
	SETBIT(DDRD, 4);
	SETBIT(TCCR1A, COM1A1);
	SETBIT(TCCR1A, COM1B1);
	SETBIT(TCCR1A, WGM11);	
	SETBIT(TCCR1A, WGM12);
	SETBIT(TCCR1B, WGM13);
	SETBIT(TCCR1B, CS11);
	ICR1 = 19999;
}

/***********************************
function_name: TIMER1_PWM_OC1A_INIT
purpose: the initialization timer1 pwm pin OC1A (fast freq, fast pwm, non inverting, noprescale)
parameters: void
return_type: void
ocr1A = duty*1024/100
************************************/

void TIMER1_PWM_OC1A_DUTY(uint8_t duty)
{
	OCR1A = (duty * 10.24) - 1;
	
}
void WDT_off(void)
{
	/* reset WDT */
	
	/* Write logical one to WDTOE and WDE */
	WDTCR |= (1<<WDTOE) | (1<<WDE);
	/* Turn off WDT */
	WDTCR = 0x00;
}