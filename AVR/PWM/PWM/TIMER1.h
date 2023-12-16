/*
 * TIMER1.h
 *
 * Created: 9/12/2022 1:14:16 AM
 *  Author: lenovo 520
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
#include "std_macros.h"

void TIMER1_PWM_OC1A_INIT(void);
void TIMER1_PWM_OC1A_DUTY(uint8_t duty);
void WDT_off(void);


#endif /* TIMER1_H_ */