/*****************************************************/
/* Author  : Omar Hazem 							 */
/* Version : V1.0                                    */
/* Date    : 12 APRIL 2021			                 */
/*****************************************************/

#include "STD_TYPS.h"
#include "BIT_MATH.h"

#include "GPIO_INTERFACE.h"
#include "GPIO_PRIVATE.h"
#include "GPIO_CONFIG.h"

void GPIO_voidPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode) {
	
	if (Copy_u8Mode == OUTPUT){
	switch (Copy_u8Port){
		
			case GPIOA:
			SET_BIT(DDRA,Copy_u8Pin);
			break;
			
			case GPIOB:
			SET_BIT(DDRB,Copy_u8Pin);
			break;
			
			case GPIOC:
			SET_BIT(DDRC,Copy_u8Pin);
			break;
			
			case GPIOD:
			SET_BIT(DDRD,Copy_u8Pin);
			break;
			
		}
	}else if (Copy_u8Mode == INPUT) {
		switch (Copy_u8Port){
			
			case GPIOA:
			CLR_BIT(DDRA,Copy_u8Pin);
			break;
			
			case GPIOB:
			CLR_BIT(DDRB,Copy_u8Pin);
			break;
			
			case GPIOC:
			CLR_BIT(DDRC,Copy_u8Pin);
			break;
			
			case GPIOD:
			CLR_BIT(DDRD,Copy_u8Pin);
			break;
		}		
	}else {
		switch (Copy_u8Port){
			
			case GPIOA:
			CLR_BIT(DDRA,Copy_u8Pin);
			SET_BIT(PORTA,Copy_u8Pin);
			break;
			
			case GPIOB:
			CLR_BIT(DDRB,Copy_u8Pin);
			SET_BIT(PORTB,Copy_u8Pin);
			break;
			
			case GPIOC:
			CLR_BIT(DDRC,Copy_u8Pin);
			SET_BIT(PORTC,Copy_u8Pin);
			break;
			
			case GPIOD:
			CLR_BIT(DDRD,Copy_u8Pin);
			SET_BIT(PORTD,Copy_u8Pin);
			break;
		}
	}
}

void GPIO_voidPinState(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8State) {
	
	if (Copy_u8State == HIGH){
	switch (Copy_u8Port){
		
			case GPIOA:
			SET_BIT(PORTA,Copy_u8Pin);
			break;
			
			case GPIOB:
			SET_BIT(PORTB,Copy_u8Pin);
			break;
			
			case GPIOC:
			SET_BIT(PORTC,Copy_u8Pin);
			break;
			
			case GPIOD:
			SET_BIT(PORTD,Copy_u8Pin);
			break;
			
		}
	}else {
		switch (Copy_u8Port){
			
			case GPIOA:
			CLR_BIT(PORTA,Copy_u8Pin);
			break;
			
			case GPIOB:
			CLR_BIT(PORTB,Copy_u8Pin);
			break;
			
			case GPIOC:
			CLR_BIT(PORTC,Copy_u8Pin);
			break;
			
			case GPIOD:
			CLR_BIT(PORTD,Copy_u8Pin);
			break;
		}		
	}	
}

void GPIO_voidTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin) {
	
	switch (Copy_u8Port){
		
		case GPIOA:
		TOG_BIT(PORTA,Copy_u8Pin);
		break;
		
		case GPIOB:
		TOG_BIT(PORTB,Copy_u8Pin);
		break;
		
		case GPIOC:
		TOG_BIT(PORTC,Copy_u8Pin);
		break;
		
		case GPIOD:
		TOG_BIT(PORTD,Copy_u8Pin);
		break;
		
	}
}
	
u8	 GPIO_u8GetPin(u8 Copy_u8Port, u8 Copy_u8Pin) {
	
	u8 Local_u8result = 0;

	switch (Copy_u8Port){
	
		case GPIOA:
		Local_u8result = GET_BIT(PORTA,Copy_u8Pin);
		break;
		
		case GPIOB:
		Local_u8result = GET_BIT(PORTB,Copy_u8Pin);
		break;
		
		case GPIOC:
		Local_u8result = GET_BIT(PORTC,Copy_u8Pin);
		break;
		
		case GPIOD:
		Local_u8result = GET_BIT(PORTD,Copy_u8Pin);
		break;
		
	}
	return Local_u8result; 
}	
	
void GPIO_voidDisablePullUp() {
	
	SET_BIT(SFIOR,PUD);

}

void GPIO_voidEnablePullUp() {
	
	CLR_BIT(SFIOR,PUD);
	
}