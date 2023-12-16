/*
 * std_macros.h
 *
 * Created: 8/11/2022 10:47:05 PM
 *  Author: lenovo 520
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_



#define SET_BIT(REG,BIT) (REG |= 1<<BIT)
#define CLEAR_BIT(REG,BIT) (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT) (REG ^= 1<<BIT)
#define GET_BIT(REG,BIT)  ((REG >> BIT) & 1)




#endif /* STD_MACROS_H_ */
