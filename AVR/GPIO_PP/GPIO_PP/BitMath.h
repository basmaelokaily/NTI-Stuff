#ifndef   BITMATH_H_
#define   BITMATH_H_


#define SETBIT(Reg,bit)   Reg|=(1<<bit)
#define CLEARBIT(Reg,bit) Reg&=~(1<<bit)
#define TOGGLE(Reg,bit)   Reg^=(1<<bit)
#define GET_BIT(REG,BIT)   ((REG&(1<<BIT))>>BIT)

#endif



