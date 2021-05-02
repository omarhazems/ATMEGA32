/*****************************************************/
/* Author  : Omar Hazem 							 */
/* Version : V1.0                                    */
/* Date    : 28 APRIL 2021			                 */
/*****************************************************/

#ifndef _USART_INTERFACE_H 
#define _USART_INTERFACE_H 

void USART_voidInitUSART(void);
void USART_voidEnableTransmitter(void);
void USART_voidEnableReceiver(void);
void USART_voidDisableTransmitter(void);
void USART_voidDisableReceiver(void);
void USART_voidSendChar(u8 Copy_u8Data); // currently sends a maximum of 8 bits, 9 bits not working - To be Updated
void USART_voidSendString(u8 *Copy_u8PtrToString);

#endif 