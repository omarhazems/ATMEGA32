/*****************************************************/
/* Author  : Omar Hazem 							 */
/* Version : V1.0                                    */
/* Date    : 22 MAY 2021			                 */
/*****************************************************/

#ifndef _ADC_INTERFACE_H 
#define _ADC_INTERFACE_H 

/* This Version supports single ended mode only 
   and it uses pooling, no Interrupts
*/

void ADC_voidEnable(void);
void ADC_voidInit(void);
u16	 ADC_u16StartConversion(u8 Copy_u8Channel); // takes channel name and returns conversion value 
u16  ADC_u16AverageItrations(u8 Copy_u8Channel, u8 Copy_u8Iterations); // gets average value for certain channel and number of iterations

#endif 