
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
#include "SPI_config.h"
#include "SPI_PRIV.h"
#include "std_macros.h"

void SPI_voidInit(void);
void SPI_init_slave(void);
uint8_t SPI_slave_input(void);
void SPI_voidINTEnable();
void SPI_voidINTDisable();
void SPI_u8SendByteSynch(uint8_t Data);
uint8_t SPI_u8ReceiveByteSynch(void);
ErrorStatus SPI_u8_Send_Receive_ByteSynch(uint8_t Data_S,uint8_t *Data_R);

ErrorStatus SPI_u8SendReceiveBufferASynch(uint8_t *Data_S,uint8_t *Data_R,uint8_t BufferSize,void(*NotificationFuction)(void));




#endif