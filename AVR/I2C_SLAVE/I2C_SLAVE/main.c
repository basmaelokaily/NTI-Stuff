/*
 * i2c_slave1.c
 *
 * Created: 8/27/2022 1:41:46 PM
 *  Author: safifi
 */ 


#include "I2C.h"
#include "LCD.h"

int main(void)
{
	LCD_init();
	LCD_write_string("~~~SLAVE~~~");
	_delay_ms(100);
	I2C_slave_Init(50);
    while(1)
    {
		LCD_write_command(0xc0);
		LCD_write_command(0x1);
		LCD_write_string("RECIEVING...");
		_delay_ms(100);
		if(I2C_slave_avialable() == 1){
			uint8_t data = I2C_slave_read();
			LCD_write_command(0x80);
			LCD_write_command(0xc0);
			LCD_write_command(0x1);
			LCD_write_num(data);
			_delay_ms(1000);
		}			
    }
}