/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: dell
 */
#include "seven_segment.h"
#include <util/delay.h>

int main(void)
{
	while(1)
	{
		SevenSegmentCommonAnode(5,1);
		 _delay_ms(1000);
		 SevenSegmentCommonAnode(5,5);
		 _delay_ms(1000);

		 SevenSegmentCommonAnode(7,2);
		 _delay_ms(1000);
		 SevenSegmentCommonAnode(7,5);
		 _delay_ms(1000);
	}
	return 0;
}
