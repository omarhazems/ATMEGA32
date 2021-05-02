/*****************************************************/
/* Author  : Omar Hazem 							 */
/* Version : V1.0                                    */
/* Date    : 28 APRIL 2021			                 */
/*****************************************************/

#include <avr/interrupt.h>


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_INTERFACE.h"
#include "USART_PRIVATE.h"
#include "USART_CONFIG.h"

void USART_voidInitUSART(){
	
	// set UBBR registers for defined BaudRate
	u16 BR = (F_CPU/(16L * USARTBaudRate))-1 ;
	UBRRL = (u8) BR;
	UBRRH = (u8) (BR>>8);
	
	// mode of operation : Asynchronous or Synchronous 
	if (USARTMode == SYNC){  
		UCSRC |= (1<<URSEL)|(1<<UMSEL);
	}
	
	// Select Parity 
	UCSRC |= (1<<URSEL)|(USARTParity<<5); 
	
	// Set number of stop bits
	if (USARTStopBits == 2){
		UCSRC |= (1<<URSEL)|(1<<USBS);
	}
	
	// Set number of Data bits 
	switch(USARTDataBits){
		
		case 5: 
		// do nothing 
		break;
		case 6: 
		UCSRC |= (1<<URSEL)|(1<<UCSZ0);
		break;
		case 7: 
		UCSRC |= (1<<URSEL)|(1<<UCSZ1);
		break;
		case 8: 
		UCSRC |= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
		break;
		case 9: 
		UCSRC |= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1)|(1<<UCSZ2);
		break;
	}
	
}


void USART_voidEnableTransmitter(void){
	SET_BIT(UCSRB,TXEN);
}
void USART_voidEnableReceiver(void){
	SET_BIT(UCSRB,RXEN);
}
void USART_voidDisableTransmitter(void){
	CLR_BIT(UCSRB,TXEN);
}
void USART_voidDisableReceiver(void){
	CLR_BIT(UCSRB,RXEN);
}

void USART_voidSendChar(u8 Copy_u8Data){ // sends character by pooling
	while(!(UCSRA & (1 << UDRE)));
	UDR = Copy_u8Data;
}

USART_voidSendString(u8 *Copy_u8PtrToString){
	while(*Copy_u8PtrToString != '\0'){
		USART_voidSendChar(*Copy_u8PtrToString);
		Copy_u8PtrToString ++;
	}
}