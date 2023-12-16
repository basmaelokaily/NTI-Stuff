
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"
#include "GPIO_interface.h"

#include <stdio.h>
#include <string.h>

u8 GlobalArray[1665];//1000 bytes of data & 409 bytes for the rest of the record & 256 extra to replace the ':'
u8 NewPageRecieved=0;
u8 BeginingOfRecord=0;
void MUSART1_voidInit(void)
{
	/*	baud rate = 115200		*/
	USART1 -> BRR = 0x045;

	SET_BIT((USART1-> CR[0]), 3);			/* Enabling Transmitter */
	SET_BIT((USART1-> CR[0]), 2);			/* Enabling Receiver */
	SET_BIT((USART1-> CR[0]), 13);			/* Enabling USART */
	
	USART1 -> SR = 0;						/* Clearing status register */
}

void MUSART1_voidTransmit(u8 arr[])
{
	u8 i = 0;
	while(arr[i] != '\0'){
		USART1 -> DR = arr[i];
		while((GET_BIT((USART1 -> SR), 6)) == 0);
		i++;
	}
	
}

void MUSART1_u8Receive(void)
{
	static u16 GlobalArrayIndex=0;
	u8 Loc_u8ReceivedData = 0;
	while((GET_BIT((USART1 -> SR), 5)) == 0);
	Loc_u8ReceivedData = USART1 -> DR;

	if(BeginingOfRecord)
	{
		GlobalArray[GlobalArrayIndex]=Loc_u8ReceivedData;
		trace_printf("Add:%p    val:%x\n", &GlobalArray[GlobalArrayIndex],GlobalArray[GlobalArrayIndex]);
		GlobalArrayIndex++;
	}
	else
	{
		GlobalArray[GlobalArrayIndex]=Loc_u8ReceivedData;
		//trace_printf("Add:%p    val:%x\n", &GlobalArray[GlobalArrayIndex],GlobalArray[GlobalArrayIndex]);
		GlobalArrayIndex++;
	}


	if( GET_BIT((USART1 -> SR), 2) || GET_BIT((USART1 -> SR), 3) || GET_BIT((USART1 -> SR), 1) )
	{

		trace_printf("UART Data Corrupted ! ");
	}

	//end of record
	if(GlobalArray[GlobalArrayIndex-1]==0xfd)
	{
		if(GlobalArray[GlobalArrayIndex-2]==0x1)
		{
			if(GlobalArray[GlobalArrayIndex-3]==0x0)
			{
				if(GlobalArray[GlobalArrayIndex-4]==0x0 )
				{
					if(GlobalArray[GlobalArrayIndex-5]==0x0)
					{
						NewPageRecieved=1;
						Parser(GlobalArray);
						trace_printf("  val:%d\n",GlobalArrayIndex-5);
						GlobalArrayIndex=0;
						MUSART1_voidTransmit("C");
						BeginingOfRecord=0;
					}
				}
			}
		}
	}


	//begin of record
	if(GlobalArray[GlobalArrayIndex-1]==0xfe)
	{
		if(GlobalArray[GlobalArrayIndex-2]==0x1)
		{
			if(GlobalArray[GlobalArrayIndex-3]==0x0)
			{
				if(GlobalArray[GlobalArrayIndex-4]==0x0 )
				{
					if(GlobalArray[GlobalArrayIndex-5]==0x0)
					{
						memset(GlobalArray,0,sizeof(GlobalArray));
						BeginingOfRecord=1;
						MUSART1_voidTransmit("Z");
						GlobalArrayIndex=0;
					}
				}
			}
		}
	}





	//end of file
	else if(GlobalArray[GlobalArrayIndex-1]==0xFF)
	{
		if(GlobalArray[GlobalArrayIndex-2]==0x01)
		{
			if(GlobalArray[GlobalArrayIndex-3]==0x00)
			{
				if(GlobalArray[GlobalArrayIndex-4]==0x00 )
				{
					if(GlobalArray[GlobalArrayIndex-5]==0x00)
					{
						NewPageRecieved=1;
						GlobalArrayIndex=0;
						MUSART1_voidTransmit("D");
						MGPIO_VoidSetPinValue(GPIOA,GPIN0,GPIO_HIGH);
					}
				}
			}
		}
	}

		MUSART1_voidTransmit("K");

}





















