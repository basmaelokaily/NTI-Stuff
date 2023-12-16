#ifndef   DIO_PRIVATE_H_
#define   DIO_PRIVATE_H_

#define DDRA    (*((volatile uint_8*)0x3A))
#define DDRB    (*((volatile uint_8*)0x37))
#define DDRC    (*((volatile uint_8*)0x34))
#define DDRD    (*((volatile uint_8*)0x31))


#define PORTA  		(*((volatile uint_8*)0x3B))
#define PORTB		(*((volatile uint_8*)0x38))
#define PORTC		(*((volatile uint_8*)0x35))
#define PORTD		(*((volatile uint_8*)0x32))



#define PINA  		(*((volatile uint_8*)0x39))
#define PINB		(*((volatile uint_8*)0x36))
#define PINC		(*((volatile uint_8*)0x33))
#define PIND		(*((volatile uint_8*)0x30))


#endif