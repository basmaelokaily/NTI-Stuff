#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "I2C.h"

void EEPROM_u8WriteByte(uint16_t Add , uint8_t Data)
{
	I2C_master_start();
	I2C_slave_Init(0xA8);
	I2C_master_write(Add);
	I2C_master_write(Data);
	I2C_master_stop();
}

void EEPROM_u8ReadByte(uint16_t Add, uint8_t * Data)
{
	I2C_master_start();
	I2C_slave_Init(0xA8);
	I2C_master_write(Add);
	I2C_master_start();
	I2C_master_write(Add);
	I2C_master_write(Data);
	I2C_master_stop();
	
	
}