/*
 * ADC.h
 *
 * Created: 8/20/2022 12:55:27 PM
 *  Author: safifi
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "std_macros.h"

void ADC_init(void);

uint16_t ADC_read(void);

#endif /* ADC_H_ */