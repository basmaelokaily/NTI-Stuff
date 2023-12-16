/*
 * TIMER.h
 *
 * Created: 10/29/2023 11:56:38 AM
 *  Author: LENOVO
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "std_macros.h"

#define PORTD0_output DDRD |=0b00000001;

extern void (*timer0_ctc_isr)(void);

void TIMER_INIT_NORMAL(void);
void TIMER0_CTCMOD_INIT(uint8_t ocr);
void TIMER_START(void);
void TIMER_STOP(void);
void TIMER_DELAY_SEC(int s);
void TIMER_DELAY_MLSEC(int ms);






#endif /* TIMER_H_ */