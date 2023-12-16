#ifndef   STD_TYPES_H_
#define   STD_TYPES_H_


typedef unsigned char      uint_8;
typedef signed char        int_8 ;
typedef   float            float_32;
typedef double             float_64;
typedef  unsigned short    uint_16;
typedef  signed short      int_16;
typedef unsigned long      uint_32;
typedef signed long        int_32;
typedef unsigned long long uint_64;
typedef signed long long   int_64;

#define E_OK  0
#define E_NOK 1

#define LOW 0
#define HIGH 1

#define PIN_OUTPUT 0x1
#define PIN_INTPUT 0x0

#define PORT_OUTPUT 0xFF
#define PORT_INTPUT 0x00

// typedef enum {
// PORTA ,
// PORTB ,
// PORTC ,
// PORTD 
// }PORTS;

typedef enum {
PIN0,
PIN1,
PIN2,
PIN3,
PIN4,
PIN5,
PIN6,
PIN7,
}PINS;

//prototypes
// void INIT(void); // ddrx input 
// ERROR_status SETPINDIrection(PORT,PIN,STATE);
// ERROR_status setpinvalue(port,pin,value);
// ERROR_status getpinvalue(port,pin,*value);
// ERROR_status togglepinvalue(port,pin); 
// ERROR_status ControlPort(PORT,DIRECTION);
// ERROR_status controlPortValue(PORT,Value);

#endif