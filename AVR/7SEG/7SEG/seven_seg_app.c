/*
 * seven_seg_app.c
 *
 * Created: 8/13/2022 12:52:09 PM
 *  Author: safifi
 */ 


#include "SEVEN_SEG.h"

int main(void)
{
	uint8_t x = 0;
	SEVEN_SEG_init();
	
    while(1)
    {
		
		for(uint8_t i = 0; i < 20; i++){
			SEVEN_SEG_write(x);
		}		
		x++;
		if(x == 100) x  = 0;
		
        //TODO:: Please write your application code 
    }
}