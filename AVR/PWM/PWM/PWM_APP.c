/*
 * TIMER1.cpp
 *
 * Created: 9/12/2022 1:13:13 AM
 * Author : lenovo 520
 */ 

#include <avr/io.h>
#include "TIMER1.h"
#include "ADC (1).h"
#include "SERVO.h"


int main(void)
{
	
	TIMER1_PWM_OC1A_INIT();
	TCNT1=0;
	DDRB|=(1<<DDB1);
	
    /* Replace with your application code */
    while (1) 
    {
		OCR1A = 16000;
		
		
    }
}

/*uint8_t i = 0;
	ADC_ConfigType ADC_CONFIG = {AVCC, F_8};
	ADC_init(&ADC_CONFIG);
	TIMER1_PWM_OC1A_INIT();
	TCNT1=0;
	DDRB|=(1<<DDB1);
	
    /* Replace with your application code 
    while (1) 
    {
		/*
		//TIMER1_PWM_OC1A_DUTY(50);
		for(int i=1000;i<=2000;i++)
		{
			OCR1A=i;
			_delay_us(500);
		}
		//_delay_ms(500);
		for(int i=2000;i>=1000;i=i-1)
		{
			OCR1A=i;
			_delay_us(500);
		}
		
		SERVO_MOVE_NEG_90();
		_delay_ms(1000);
		SERVO_MOVE_NEG_45();
		_delay_ms(1000);
		SERVO_MOVE_CENTER();
		_delay_ms(1000);
		SERVO_MOVE_POS_45();
		_delay_ms(1000);
		SERVO_MOVE_POS_90();
		_delay_ms(1000);
		
		
		
		/*
		TIMER1_PWM_OC1A_DUTY(i++);
		_delay_ms(10);
		if (i == 101)	i = 0;*/
		