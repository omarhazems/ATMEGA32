/*****************************************************/
/* Author  : Omar Hazem 							 */
/* Version : V1.0                                    */
/* Date    : 13 APRIL 2021			                 */
/*****************************************************/

#include <avr/interrupt.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "INTERRUPT_INTERFACE.h"
#include "INTERRUPT_PRIVATE.h"
#include "INTERRUPT_CONFIG.h"

static void (*EXTI0_CallBack) (void) = 0 ;
static void (*EXTI1_CallBack) (void) = 0 ;
static void (*EXTI2_CallBack) (void) = 0 ;

void INTERRUPT_voidInit(void){
	
	sei();
	
}

void INTERRUPT_voidEnable(u8 Copy_u8Name, u8 Copy_u8Trigger, void (*Copy_PtrToFunc) (void)) {
	
	switch(Copy_u8Name){
		
		case EXTI0:
		SET_BIT(GICR,INT0);
		MCUCR &= ~(3<<0);
		MCUCR |= (Copy_u8Trigger<<0);
		EXTI0_CallBack = Copy_PtrToFunc;
		break;
		
		case EXTI1:
		SET_BIT(GICR,INT1);
		MCUCR &= ~(3<<2);
		MCUCR |= (Copy_u8Trigger<<2);
		EXTI1_CallBack = Copy_PtrToFunc;
		break;
		
		case EXTI2:
		CLR_BIT(GICR,INT2);
		if (Copy_u8Trigger == FALLING){
		CLR_BIT(MCUCSR,ISC2);	
		}else if(Copy_u8Trigger == RISING) {
		SET_BIT(MCUCSR,ISC2);	
		}else {
		}
		EXTI2_CallBack = Copy_PtrToFunc;
		SET_BIT(GICR,INT2);
		break;
	}
	
}

void INTERRUPT_voidDisable(u8 Copy_u8Name){
	
	switch(Copy_u8Name){
		
		case EXTI0:
		CLR_BIT(GICR,INT0);
		break;
		
		case EXTI1:
		CLR_BIT(GICR,INT1);
		break;
		
		case EXTI2:
		CLR_BIT(GICR,INT2);
		break;
	}
}

ISR(INT0_vect){
	EXTI0_CallBack();
}

ISR(INT1_vect){
	EXTI1_CallBack();
}

ISR(INT2_vect){
	EXTI2_CallBack();
}