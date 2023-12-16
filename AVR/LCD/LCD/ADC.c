/*
 * ADC.c
 *
 * Created: 8/20/2022 12:55:18 PM
 *  Author: safifi
 */ 
#include "ADC.h"

void ADC_init(void){
	//SETBIT(ADMUX,REFS0); // AVCC will be the ref.
	SETBIT(ADCSRA,ADEN); // enable ADC
	SETBIT(ADCSRA,ADPS0);
	SETBIT(ADCSRA,ADPS1);
	SETBIT(ADCSRA,ADPS2);
}

uint16_t ADC_read(void){
	SETBIT(ADCSRA,ADSC); // start single conversion
	while(READBIT(ADCSRA,ADSC) == 1); // conversion not completed
	return ADC;
}