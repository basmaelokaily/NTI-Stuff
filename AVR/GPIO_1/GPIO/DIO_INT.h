#ifndef   DIO_INT_H_
#define   DIO_INT_H_

#define PIN_OUTPUT 0x1 
#define PIN_INPUT  0x0

#define PORT_OUTPUT 0xFF
#define PORT_INPUT 0x00

#define LOW  0 
#define HIGH 1 

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
} PIN;

typedef enum {
	PORT_A =1 ,
	PORT_B,
	PORT_C,
	PORT_D
}PORT;

// typedef enum
// {
//     E_OK,
//     E_NOK
//  }ERROR_status;

typedef enum
{
    INPUT,
    OUTPUT
}STATE;

//prototypes
void INIT(void); // ddrx input 
uint_8 SETPINDIrection(uint_8 PORT,uint_8 PIN,STATE ST);
uint_8 setpinvalue(uint_8 PORT,uint_8 PIN,int value);
uint_8 getpinvalue(uint_8 PORT,uint_8 PIN,int*value);
uint_8 togglepinvalue(uint_8 PORT,uint_8 PIN); 
uint_8 ControlPortDIR(uint_8 PORT,uint_8 STATE);
uint_8 controlPortValue(uint_8 PORT,int Value);

#endif