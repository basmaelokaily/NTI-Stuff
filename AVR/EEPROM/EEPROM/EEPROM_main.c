#include "EEPROM_interface.h"
#include "LCD.h"
#include "I2C.h"
#include <util/delay.h>

int main(void)
{
	uint8_t Return_Data = 0;
	I2C_master_init();
	LCD_init();
	/*	In case using 8K Bits (1024 Byte) EEPROM		*/
	EEPROM_u8WriteByte(512 , 10);
	_delay_ms(10);
	EEPROM_u8ReadByte(512 , &Return_Data);
	LCD_write_string("The Value = ");
	LCD_write_num(Return_Data);
	while(1)
	{
		
	}
	return 0;
}
