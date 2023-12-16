/*
 * SPI.c
 *
 * Created: 11/3/2023 11:58:59 AM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "SPI_INT.h"
#include "LCD.h"
void APP(uint8_t data);

int main(void)
{
    LCD_init();
    _delay_ms(100);
    LCD_write_command(0x0C); // display on, cursor off
    _delay_ms(100);
    LCD_write_command(0x01);
    _delay_ms(100);
	SPI_voidInit();
	uint8_t data = 50;
	uint8_t *ptr = &data;
	LCD_write_string("Start The SPI");
	LCD_write_command(0xC0);
	LCD_write_string("Program");
    uint8_t count = 0 ;
    _delay_ms(100);
	SET_CALL_BACK(APP);
    while(1)
    {
	    CLRBIT(PORTB,SS);  // disable
	   // SETBIT(PORTD,PD7); // enable
	    SPI_u8_Send_Receive_ByteSynch(count);
		count++;

	    

	    _delay_ms(400);
    }
}
void APP(uint8_t data)
{
	LCD_write_num(data);
}
