
#include "SPI_INT.h"




void SPI_voidInit(void)
{
	/*
	 1- Data order
	 2- Master/Slave
	 3- Clock Polarity
	 4- Clock phase
	 5- Enable SPI
	 */
	
	CLRBIT(SPCR, MSTR);
	CLRBIT(SPCR, CPOL); //rising edge
	SETBIT(SPCR, CPHA); //setup-write sample-read	
	SETBIT(SPCR, SPE);
	CLRBIT(DDRB, MOSI);
	SETBIT(DDRB,SS);
	CLRBIT(DDRB,SCK);
	SETBIT(DDRB, MISO);
}

void SPI_voidINTEnable()
{
	
}
void SPI_voidINTDisable()
{
	
}
void SPI_init_slave(void){
	SETBIT(DDRB,MISO);
	SPCR =  1<<SPE;
}
uint8_t SPI_slave_input(void){
	while(READBIT(SPSR,SPIF) == 0);
	return SPDR;
}

void SPI_u8SendByteSynch(uint8_t Data)
{
	/* timeout mechanism with the flag 
	SPDR = Data;
	while(READBIT(SPSR, SPIF) == 0);
	return OK;*/
	SPDR = Data;
}

uint8_t SPI_u8ReceiveByteSynch(void)
{
	while(READBIT(SPSR, SPIF) == 0);
	return SPDR;
	
}

ErrorStatus SPI_u8SendReceiveBufferASynch(uint8_t *Data_S,uint8_t *Data_R,uint8_t BufferSize,void(*NotificationFuction)(void))
{

}


void __vector_12 (void)
{
	
}