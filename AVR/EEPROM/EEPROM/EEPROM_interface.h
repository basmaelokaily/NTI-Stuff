#ifndef			EEPROM_INTERFACE_H
#define			EEPROM_INTERFACE_H
#include "std_macros.h"

void EEPROM_u8WriteByte(uint16_t Add , uint8_t Data);

void EEPROM_u8ReadByte(uint16_t Add, uint8_t * Data);

#endif
