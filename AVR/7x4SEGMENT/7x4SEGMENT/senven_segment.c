
#include "seven_segment.h"

void SevenSegmentCommonAnode(uint8_t num,uint8_t EN)
{	
 	  SETBIT(DDRB, 0);
	  SETBIT(DDRB, 1);
	  SETBIT(DDRB, 2);
	  SETBIT(DDRB, 4);

 	  SETBIT(DDRB, 5);
	  SETBIT(DDRB, 6);
	  SETBIT(DDRA, 2);
	  SETBIT(DDRA, 3);
      switch(EN)
      {
      case 1:
		 SETBIT(PORTB, 5);
		 CLRBIT(PORTB, 6);
		 SETBIT(PORTA, 2);
		 SETBIT(PORTA, 3);
      	 
		 break;
      case 2:
       	 CLRBIT(PORTB, 5);
		 SETBIT(PORTB, 6);
		 SETBIT(PORTA, 2);
		 SETBIT(PORTA, 3);
       	 break;
      case 3:
       	 SETBIT(PORTB, 5);
       	 SETBIT(PORTB, 6);
       	 CLRBIT(PORTA, 2);
       	 SETBIT(PORTA, 3);
		break;
      case 4:
       	 SETBIT(PORTB, 5);
		 SETBIT(PORTB, 6);
		 SETBIT(PORTA, 2);
		 CLRBIT(PORTA, 3);
       	 break;
      case 5:
        SETBIT(PORTB, 5);
   	    SETBIT(PORTB, 6);
  	    SETBIT(PORTA, 2);
		SETBIT(PORTA, 3);
      	break;
      }
      switch(num)
      {
      case 0:
     	 CLRBIT(PORTB, 0);
		 CLRBIT(PORTB, 1);
		 CLRBIT(PORTB, 2);
		 CLRBIT(PORTB, 4);
		 
         break;
      case 1:
     	 SETBIT(PORTB, 0);
		 CLRBIT(PORTB, 1);
		 CLRBIT(PORTB, 2);
		 CLRBIT(PORTB, 4);
         break;
      case 2:
     	 CLRBIT(PORTB, 0);
		 SETBIT(PORTB, 1);
		 CLRBIT(PORTB, 2);
		 CLRBIT(PORTB, 4);
         break;
      case 3:
     	 SETBIT(PORTB, 0);
		 SETBIT(PORTB, 1);
		 CLRBIT(PORTB, 2);
		 CLRBIT(PORTB, 4);
         break;
      case 4:
     	 CLRBIT(PORTB, 0);
         CLRBIT(PORTB, 1);
         SETBIT(PORTB, 2);
         CLRBIT(PORTB, 4);
		 break;
      case 5:
     	 SETBIT(PORTB, 0);
		 CLRBIT(PORTB, 1);
		 SETBIT(PORTB, 2);
		 CLRBIT(PORTB, 4);
         break;
      case 6:
     	 CLRBIT(PORTB, 0);
		 SETBIT(PORTB, 1);
		 SETBIT(PORTB, 2);
		 CLRBIT(PORTB, 4);
         break;
      case 7:
     	 SETBIT(PORTB, 0);
		 SETBIT(PORTB, 1);
		 SETBIT(PORTB, 2);
		 CLRBIT(PORTB, 4);
         break;
      case 8:
     	 CLRBIT(PORTB, 0);
		 CLRBIT(PORTB, 1);
		 CLRBIT(PORTB, 2);
		 SETBIT(PORTB, 4);
         break;
      case 9:
     	 SETBIT(PORTB, 0);
		 CLRBIT(PORTB, 1);
		 CLRBIT(PORTB, 2);
		 SETBIT(PORTB, 4);
         break;

      }
}
void set_int0(void)
{
	SETBIT(DDRD, 2);
	SETBIT(MCUCR, ISC00);
	SETBIT(GICR, INT0);
	sei();

}
void set_int1(void)
{
	SETBIT(DDRD, 4);
	SETBIT(MCUCR,  ISC10);
	SETBIT(GICR, INT1);
	sei();

}