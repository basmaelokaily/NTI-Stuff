/*
 * I2C.h
 *
 * Created: 11/26/2014 6:45:32 PM
 *  Author: Basma
 */
#ifndef I2C_MASTER_
#define I2C_MASTER_H

#include "std_macros.h"


/*****************************************************************************
* Function Name: I2C_master_init
* Purpose      : init I2C to be master - generate SCL = 400K
* Parameters   : void
* Return value : void
*****************************************************************************/
void I2C_master_init(void);

/*****************************************************************************
* Function Name: I2C_master_start
* Purpose      : Send start condition to be a master and control the bus
* Parameters   : void
* Return value : void
*****************************************************************************/
void I2C_master_start(void);


/*****************************************************************************
* Function Name: I2C_master_addr
* Purpose      : Send first byte which have ID of the slave that master need to
*                talk with and set if master need to read or write.
* Parameters   : ID: id of the slave (1 to 112)
*                R_W: 0 for write and 1 for read
* Return value : void
*****************************************************************************/
void I2C_master_addr(uint8_t ID, uint8_t R_W);



/*****************************************************************************
* Function Name: I2C_master_write
* Purpose      : Send 1 byte data to slave
* Parameters   : data: 8 bit data should be sent to slave at the end of the function
* Return value : void
*****************************************************************************/
void I2C_master_write(uint8_t data);


/*****************************************************************************
* Function Name: I2C_master_stop
* Purpose      : Send stop condition to release the bus 
* Parameters   : void
* Return value : void
*****************************************************************************/
void I2C_master_stop(void);


/*****************************************************************************
* Function Name: I2C_slave_Init
* Purpose      : configure I2C to be a slave and set ID
* Parameters   : My_Add: id of the slave
* Return value : void
*****************************************************************************/
void I2C_slave_Init(uint8_t My_Add);


/*****************************************************************************
* Function Name: I2C_slave_avialable
* Purpose      : check if data will be come from master 
* Parameters   : void
* Return value : 1 if data will be came, 0 if not
*****************************************************************************/
uint8_t I2C_slave_avialable();


/*****************************************************************************
* Function Name: I2C_slave_read
* Purpose      : Read data which is comming from master 
* Parameters   : void
* Return value : data 8 bit which came from master
*****************************************************************************/
uint8_t I2C_slave_read(void);








#endif // I2C_MASTER_H