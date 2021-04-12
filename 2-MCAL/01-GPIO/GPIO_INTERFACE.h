/*****************************************************/
/* Author  : Omar Hazem 							 */
/* Version : V1.0                                    */
/* Date    : 12 APRIL 2021			                 */
/*****************************************************/

#ifndef _GPIO_INTERFACE_H 
#define _GPIO_INTERFACE_H 

void GPIO_voidPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8State);
void GPIO_voidPinState(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8State);
void GPIO_voidTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin);
u8	 GPIO_u8GetPin(u8 Copy_u8Port, u8 Copy_u8Pin);
void GPIO_voidDisablePullUp(void);
void GPIO_voidEnablePullUp(void);

#endif 