/*
 * ADC.h
 *
 *  Created on: Oct 2, 2021
 *      Author: Menna Sayed
 */

#include "std_macros.h"
#ifndef ADC_H_
#define ADC_H_

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef	enum{   F_2_0,F_2_1,F_4,F_8,F_16,F_32,F_64,F_128    } ADC_Prescaler;

typedef	enum{
	Aref,AVCC,Reserved,Internal
}ADC_REFRENCE_VOLT;

typedef struct{
	              ADC_REFRENCE_VOLT ref_volt;
	              ADC_Prescaler     Prescaler;   /*value from 0..to..7  corresponds to definit prescaler value*/

}ADC_ConfigType;

/************************************refrence values********************************/
#define ADC_REF_VOLT               5
#define ADC_MAX_VALUE              1023

/************************************Prototypes***********************************/

void ADC_init(const ADC_ConfigType* Config_ptr);
uint16_t ADC_readChannel(uint8_t ch_num);


#endif /* ADC_H_ */
