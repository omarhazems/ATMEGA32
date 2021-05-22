/*****************************************************/
/* Author  : Omar Hazem 							 */
/* Version : V1.0                                    */
/* Date    : 5 May 2021	   		                     */
/*****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_INTERFACE.h"
#include "I2C_PRIVATE.h"
#include "I2C_CONFIG.h"

void I2C_voidInit(){
	
	TWBR = ((F_CPU/SCL_Frequency)-16)/2 ;	// set I2C frequency
	TWSR = 0x00;
	
}



void I2C_voidStartBit(void){
	TWCR = (1<<TWINT)|(1<<TWSTA)}|(1<<TWEN); //send a start bit 
	while(!(TWCR &(1<<TWINT))); //wait till flag indicates start bit is sent
	if (((TWSR & 0xF8) != START) || (((TWSR & 0xF8) != REP_START))){ // if status doesn't indicate a start or repeated start send again
		I2C_voidStartBit();
	}
}

void I2C_voidStopBit(void){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void I2C_voidWrite(u8 Copy_u8DTS){
	TWDR = Copy_u8DTS;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
}

u8   I2C_u8Read(void){
	u8 Local_u8DTR = 0;
	Local_u8DTR = TWDR;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (!(TWCR & (1<<TWINT)));
	// status register should be 0x50 for reading with acknowledge
}