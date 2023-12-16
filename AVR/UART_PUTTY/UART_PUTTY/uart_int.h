/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _USART_INT_H
#define _USART_INT_H
#include "std_macros.h"

/****************************************************************/	
/** !comment : SPEED_OPERATION							   		*/
/****************************************************************/
#define DOUBLE_SPEED_MODE			0
#define NORMAL_SPEED_MODE			3


/****************************************************************/
/* Description    :  This function used to initialize USART     */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/
void USART_Init( );


/****************************************************************/
/* Description    : This function used to Send Data				*/ 
/*																*/
/*					Inputs : u8 data				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
void USART_Transmit_SYNC( uint8_t data );


/****************************************************************/
/* Description    : This function used to Receive Data			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u8			 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
uint8_t USART_Receive_SYNC(void);

void USART_STRING_SYNC( uint8_t* data );


#endif	/** !comment  :  End of guard                          **/