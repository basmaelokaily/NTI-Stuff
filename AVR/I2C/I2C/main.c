/*
 * I2C_app.c
 *
 * Created: 8/27/2022 12:31:31 PM
 *  Author: safifi
 */ 


#include "I2C.h"
#include "LCD.h"

int main(void)
{
	/**/LCD_init();
	I2C_master_init();
	uint8_t count =0;
	_delay_ms(100);
	LCD_write_string("~~~MASTER~~~");
    while(1)
    {
		I2C_master_start();
		I2C_master_addr(50,0);
		I2C_master_write(count++);
		I2C_master_stop();
		_delay_ms(400);
		LCD_write_command(0xc0);
		LCD_write_command(0x1);
		_delay_ms(1000);
		LCD_write_string("TRANS COMPLETE");
		
        //TODO:: Please write your application code 
    }
}