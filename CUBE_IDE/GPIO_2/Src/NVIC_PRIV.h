#ifndef DNVIC_PRIV_H_
#define DNVIC_PRIV_H_


/**
 * @def 	NVIC_BASE_ADDRESS
 * @brief 	NVIC peripheral base address 
 */
#define NVIC_BASE_ADDRESS  (( NVIC_t*) 0XE000E100)
/**
 * @def 	SCB_AIRCR
 * @brief 	NVIC Application Interrupt and Reset Control Register 
 */
#define SCB_AIRCR *((volatile u32*) 0XE000ED0C)

/**
 * @def 	SCB_VTOR
 * @brief 	Vector Table Offset register
 */
#define SCB_VTOR  *((volatile u32*) 0xE000ED08)


/**
 * @typedef		NVIC_t 
 * @brief		Struct of All Registers in NVIC Driver	
 */

/**
 * @brief NV pointer to struct NVIC_t 
 */


#endif
