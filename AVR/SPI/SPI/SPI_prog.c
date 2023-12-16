
#include "SPI_INT.h"
#include "LCD.h"




void SPI_voidInit(void)
{
	/*
	 1- Data order
	 2- Master/Slave
	 3- Clock Polarity
	 4- Clock phase
	 5- Enable SPI
	 
	SETBIT(SPCR, DORD);
	SETBIT(SPCR, MSTR);
	CLRBIT(SPCR, CPOL); //rising edge
	SETBIT(SPCR, CPHA); //setup-write sample-read	
	SETBIT(SPCR, SPE);
	CLRBIT(SPCR, SPR1);
	CLRBIT(SPCR, SPR0);
	SETBIT(DDRB, MOSI);
	SETBIT(DDRB,SS);
	SETBIT(DDRB,SCK);
	CLRBIT(DDRB, MISO);*/
	SETBIT(DDRB,MOSI);
	SETBIT(DDRB,SS);
	SETBIT(DDRB,SCK);
	SETBIT(SPCR, MSTR);
	SETBIT(SPCR, SPE);
}


void SPI_voidINTEnable()
{
	 SETBIT(SPCR, SPIE);
}
void SPI_voidINTDisable()
{
	CLRBIT(SPCR,  SPIE);
}
void SPI_u8SendByteSynch(uint8_t Data)
{
	
	/* timeout mechanism with the flag */
	/*while(READBIT(SPCR, WCOL) == 1);
	SPDR = Data;
	while(READBIT(SPSR, SPIF) == 0);
	*data = SPDR;*/
	while(READBIT(SPSR, WCOL) == 1);
	
	LCD_write_command(0x01);
	_delay_ms(100);
	LCD_write_string("SENDING....");
	SPDR = Data;
	while(READBIT(SPSR,SPIF) == 0);
	LCD_write_command(0x01);
	_delay_ms(100);
	LCD_write_string("PROCRESS OVER");
	_delay_ms(500);
	LCD_write_command(0x01);
	_delay_ms(100);
	
	
	
}

uint8_t SPI_u8ReceiveByteSynch(uint8_t *Data)
{//as long as its one dont send flag collision
	  /* send dummy byte to receive and wait flag and timeout mechanism */ 
	/*SPDR = 0xff;
	while(READBIT(SPSR, SPIF) == 0);
	return SPDR;*/
	
}
void SPI_u8_Send_Receive_ByteSynch(uint8_t Data_S)
{
	while(READBIT(SPSR, WCOL) == 1);
	SPDR = Data_S;
}
void SET_CALL_BACK(void (*ptr)(uint8_t))
{
	spi_callback = ptr;
}


ErrorStatus SPI_u8SendReceiveBufferASynch(uint8_t *Data_S,uint8_t *Data_R,uint8_t BufferSize,void(*NotificationFuction)(void))
{
	

}


void __vector_12 (void)
{
	spi_callback(SPDR);
	
}