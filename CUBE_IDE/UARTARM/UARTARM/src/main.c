#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "USART_interface.h"





int main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2, 14);		/* Enable USART1 Clock */

	/* Setting A9:TX pin as Output alternate function push pull w max speed 50 MHz */
	MGPIO_VoidSetPinDirection(GPIOA,GPIN9,OUTPUT_SPEED_50MHZ_AFPP);
	/* Setting A10:RX pin as input floating */
	MGPIO_VoidSetPinDirection(GPIOA,GPIN10,INPUT_FLOATING);

	MGPIO_VoidSetPinDirection(GPIOA,GPIN1,OUTPUT_SPEED_2MHZ_PP);

	MGPIO_VoidSetPinValue(GPIOA,GPIN1,GPIO_HIGH);

	MUSART1_voidInit();

	while(1)
	{

	MUSART1_u8Receive();


	}

	return 0;
}
