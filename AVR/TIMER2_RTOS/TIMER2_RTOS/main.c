/*
 * TIMER2_RTOS.c
 *
 * Created: 11/19/2023 3:19:54 PM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "TIMER.h"
#include "LCD.h"

uint8_t i = 0;
static void CTC_ISR(void);

int main(void)
{
	LCD_init();
	SETBIT(DDRB, 0);
	timer0_ctc_isr = CTC_ISR;
	TIMER0_CTCMOD_INIT(249);
    /* Replace with your application code */
    while (1) 
    {
		LCD_write_command(0x80);
		LCD_write_num(i);
		_delay_ms(100);
    }
}

static void CTC_ISR(void)
{
	static uint32_t counts = 0;
	counts++;
	if (counts == 250)
	{
		i++;
		counts = 0;
	}
	TOGBIT(PORTB, 0);
}