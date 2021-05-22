/*****************************************************/
/* Author  : Omar Hazem 							 */
/* Version : V1.0                                    */
/* Date    : 5 May 2021	   		                     */
/*****************************************************/

#ifndef _I2C_INTERFACE_H 
#define _I2C_INTERFACE_H 

void I2C_voidInit(void);

void I2C_voidStartBit(void);
void I2C_voidStopBit(void);
void I2C_voidWrite(u8 Copy_u8DTS);
u8   I2C_u8Read(void);


#endif 