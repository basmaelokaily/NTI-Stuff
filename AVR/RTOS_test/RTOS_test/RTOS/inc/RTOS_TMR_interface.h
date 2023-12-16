/*
 * RTOS_TMR_interface.h
 *
 *  Created on: Nov 19, 2023
 *      Author: Kareem Hussein
 */

#ifndef RTOS_INC_RTOS_TMR_INTERFACE_H_
#define RTOS_INC_RTOS_TMR_INTERFACE_H_


                /*************** APIS PROTOTYPES ***************/
				
void RTOS_TMR_voidInit                (void);
void RTOS_TMR_voidStart               (void);
void RTOS_TMR_voidStop                (void);
void RTOS_TMR_voidSetCallBackCTC      (void(*ptrToFun)(void));
void RTOS_TMR_voidSetCompareMatchValue(u8 copy_u8CompareValue);


#endif /* RTOS_INC_RTOS_TMR_INTERFACE_H_ */
