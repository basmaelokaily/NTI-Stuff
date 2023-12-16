/*
 * LCD.c
 *
 *  Created on: Nov 7, 2023
 *      Author: LENOVO
 */
/*
 * LCD.c
 *
 * Created: 8/12/2022 10:44:41 AM
 *  Author: Basma
 */
#include "LCD.h"

void LCD_PIN_DI(void)
{
	MRCC_voidInit();
	MRCC_enumSetPeripheralClock(APB2 , IOPBEN_ID, RCC_ENABLE );
	DIO_voidSetPinDirection(PORTB, 2, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTB, 3, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTB, 4, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTB, 5, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTB, 6, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTB, 7, GPIO_OUTPUT_10MHZ_PP);
	/*DIO_voidSetPinValue(PORTB, 2, GPIO_HIGH);
	DIO_voidSetPinValue(PORTB, 3, GPIO_HIGH);
	DIO_voidSetPinValue(PORTB, 4, GPIO_HIGH);
	DIO_voidSetPinValue(PORTB, 5, GPIO_HIGH);
	DIO_voidSetPinValue(PORTB, 6, GPIO_HIGH);
	DIO_voidSetPinValue(PORTB, 7, GPIO_HIGH);*/
}
/*****************************************************************************
* Function Name: LCD_init
* Purpose      : Init lcd in 4 bit mode, clear lcd and turn off cursor
* Parameters   : void
* Return value : void
*****************************************************************************/
void LCD_init(void){
	LCD_write_command(0x3);
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();
	LCD_write_command(0x3);
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();
	LCD_write_command(0x3);
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();
	LCD_write_command(0x2);
	LCD_write_command(0x28);
	LCD_write_command(0x08);
	LCD_write_command(0x1);
	LCD_write_command(0x6);
	LCD_write_command(0xc);
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();
}



/*****************************************************************************
* Function Name: LCD_write_command
* Purpose      : write command to lcd
* Parameters   : data: one of LCD commands
* Return value : void
*****************************************************************************/
void LCD_write_command(u8 data){ // 0x53
	RS(0);
	D7(GET_BIT(data,7)); // Data bit7  = D7
	D6(GET_BIT(data,6)); // Data bit6  = D6
	D5(GET_BIT(data,5)); // Data bit5  = D5
	D4(GET_BIT(data,4)); // Data bit4  = D4
	EN(1);
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();
	EN(0);
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();
	D7(GET_BIT(data,3)); // Data bit3  = D7
	D6(GET_BIT(data,2)); // Data bit2  = D6
	D5(GET_BIT(data,1)); // Data bit1  = D5
	D4(GET_BIT(data,0)); // Data bit0  = D4
	EN(1);
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();
	EN(0);
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();

}




/*****************************************************************************
* Function Name: LCD_write_data
* Purpose      : write symbol on lcd
* Parameters   : data: Ascii value of specific symbol
* Return value : void
*****************************************************************************/
void LCD_write_data(u8 data){ // 0x53
	u8 i = 0 ;
	RS(1);
	D7(GET_BIT(data,7)); // Data bit7  = D7
	D6(GET_BIT(data,6)); // Data bit6  = D6
	D5(GET_BIT(data,5)); // Data bit5  = D5
	D4(GET_BIT(data,4)); // Data bit4  = D4
	EN(1);
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();
	EN(0);
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();
	D7(GET_BIT(data,3)); // Data bit3  = D7
	D6(GET_BIT(data,2)); // Data bit2  = D6
	D5(GET_BIT(data,1)); // Data bit1  = D5
	D4(GET_BIT(data,0)); // Data bit0  = D4
	EN(1);
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();
	EN(0);
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();
}

/*****************************************************************************
* Function Name: LCD_write_data
* Purpose      : write a string on lCD
* Parameters   : *data: array of char
* Return value : void
*****************************************************************************/
void LCD_write_string(u8 *data){
	u8 i =0;
	while(data[i] != '\0'){
		LCD_write_data(data[i]);
		i++;
	}
}

/*
12345 % 10  = 5 + 48 >> arr[0]
12345/10 = 1234 % 10 = 4 + 48 >> arr[1]
1234/10 = 123 % 10 = 3 + 48 >> arr[2]
123/10 = 12 % 10 = 2 + 48 >> arr[3]
12/10 = 1 % 10 = 1 + 48 >> arr[4]
1/10 = 0
*/
/*****************************************************************************
* Function Name: LCD_write_num
* Purpose      : write a number on lCD
* Parameters   : num: number to be written
* Return value : void
*****************************************************************************/
void LCD_write_num(u32 num){
	int8 i = 0;
	u8 num_arr[10];

	if(num == 0) {
		LCD_write_data('0');
		return;
	}

	for(i = 0; num != 0 ;i++){
		num_arr[i] = num % 10 + 48;
		num /= 10;
	}
	i--;
	while (i >= 0){
		LCD_write_data(num_arr[i]);
		i--;
	}
}

