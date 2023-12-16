/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_macros.h"


/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "uart_int.h"



/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize USART     */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/


void USART_Init( )
{
	
	SETBIT(UCSRC, URSEL);
	CLRBIT(UCSRC, UMSEL);
	CLRBIT(UCSRC, USBS);
	CLRBIT(UCSRC, UPM0);
	CLRBIT(UCSRC, UPM1);
	CLRBIT(UCSRA, U2X);
	SETBIT(UCSRC, UCSZ0);
	SETBIT(UCSRC, UCSZ1);
	CLRBIT(UCSRB, UCSZ2);
	CLRBIT(UCSRC, URSEL);
	CLRBIT(UBRRH, 0);
	CLRBIT(UBRRH, 1);
	CLRBIT(UBRRH, 2);
	CLRBIT(UBRRH, 3);
	UBRRL = 0b00110011;
	SETBIT(UCSRB, RXEN);
	SETBIT(UCSRB, TXEN);
	
}



/****************************************************************/
/* Description    : This function used to Send Data				*/ 
/*																*/
/*					Inputs : u8 data				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
void USART_Transmit_SYNC( uint8_t data )
{
	UDR = data;
	while(READBIT(UCSRA, TXC) == 0);	

}

/****************************************************************/
/* Description    : This function used to Receive Data			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u8			 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
uint8_t USART_Receive_SYNC(void)
{
	while(READBIT(UCSRA, RXC) == 0);
	return UDR;
}

void USART_STRING_SYNC( uint8_t* data )
{	
	uint8_t i;
	i=0;
	while(data[i] !=  '\0' )
	{
		USART_Transmit_SYNC(data[i]);
		_delay_ms(100);
	    /*UDR=data[i];
		while(READBIT(UCSRA, TXC) == 0);*/
		i++;	
	}
	
	
}