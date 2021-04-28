/*****************************************************/
/* Author  : Omar Hazem 							 */
/* Version : V1.0                                    */
/* Date    : 13 APRIL 2021			                 */
/*****************************************************/

#ifndef _INTERRUPT_INTERFACE_H 
#define _INTERRUPT_INTERFACE_H 

void INTERRUPT_voidInit(void);
void INTERRUPT_voidEnable(u8 Copy_u8Name, u8 Copy_u8Trigger, void (*Copy_PtrToFunc) (void));
void INTERRUPT_voidDisable(u8 Copy_u8Name);

#endif 