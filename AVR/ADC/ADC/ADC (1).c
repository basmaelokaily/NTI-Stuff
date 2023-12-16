/*
 * ADC.c
 *
 *  Created on: Oct 2, 2021
 *  Author: Menna Sayed
 *
 ***********************************************************************************/

#include "ADC (1).h"



void ADC_init(const ADC_ConfigType* Config_ptr){

	ADMUX=0;
	switch(Config_ptr->ref_volt)
	{
	case 3:                   /*internal vref..2.56v*/
		SETBIT(ADMUX,REFS1);
		SETBIT(ADMUX,REFS0);
		break;
	case 0:                    /* Aref...External voltage*/
		break;
	case 1:                    /*avcc .. 5v*/
		SETBIT(ADMUX,REFS0);
		break;
	}
	ADCSRA =0;
	switch(Config_ptr->Prescaler)            //selecting the prescaler
	{
	case 0:
		break;
	case 1:
		SETBIT(ADCSRA,ADPS0);
		break;
	case 2:
		SETBIT(ADCSRA,ADPS1);
		break;
	case 3:
		SETBIT(ADCSRA,ADPS0);
		SETBIT(ADCSRA,ADPS1);
		break;
	case 4:
		SETBIT(ADCSRA,ADPS2);
		break;
	case 5:
		SETBIT(ADCSRA,ADPS0);
		SETBIT(ADCSRA,ADPS2);
		break;
	case 6:
		SETBIT(ADCSRA,ADPS1);
		SETBIT(ADCSRA,ADPS2);
		break;
	case 7:
		SETBIT(ADCSRA,ADPS0);
		SETBIT(ADCSRA,ADPS1);
		SETBIT(ADCSRA,ADPS2);
		break;
	}
	SETBIT(ADCSRA,ADEN);   //ADC enable
	CLRBIT(ADCSRA,ADIE);  //to disable interrupt

}
uint16_t ADC_readChannel(uint8_t ch_num){

ch_num &= 0x07;                /*for making sure that the entered no is only 3 bits*/
ADMUX &= 0xE0;                  /*for clearing the first 5 bits in the reg */
ADMUX |= ch_num;                /*inserting channel num in admux reg*/
SETBIT(ADCSRA,ADSC);           /*START CONVERSION*/
while(READBIT(ADCSRA,ADIF) == 0);   /*polling till the flag is set*/
SETBIT(ADCSRA,ADIF);            /*for clearing the flag after conversion*/
return ADC;                      /*to read the value after the conversion from adc data reg.*/
}

