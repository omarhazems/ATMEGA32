/*****************************************************/
/* Author  : Omar Hazem 							 */
/* Version : V1.0                                    */
/* Date    : 22 MAY 2021			                 */
/*****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_INTERFACE.h"
#include "ADC_PRIVATE.h"
#include "ADC_CONFIG.h"


void ADC_voidEnable(){
	
	SET_BIT(ADCSRA,ADEN);  //Enable ADC 
	ADMUX |= (VOLTAGE_REFERENCE << 7);
	ADMUX |= (RESULT_ADJUST << ADLAR); // sets result adjustment to preconfigured option
	ADCSRA |= (ADC_PRESCALER << 0);	// set prescaler 
	
}

void ADC_voidAInit(){
	
	u16 Local_u16Dummy ;
	SET_BIT(ADCSRA,ADSC); // start dummy conversion as initialization 
	while(GET_BIT(ADCSRA,ADSC)); // wait till conversion finishes 
	Local_u16Dummy = ADC_u16ADCReadResult();
	Local_u16Dummy = 0;
	
}

u16	 ADC_u16StartConversion(u8 Copy_u8Channel){
	
	u16 Local_u16Result ;
	
	ADMUX |= (Copy_u8Channel << 0); // select channel for conversion 
	SET_BIT(ADCSRA,ADSC); // start conversion 
	while(GET_BIT(ADCSRA,ADSC)); // wait ... 
	Local_u16Result = ADC_u16ADCReadResult(); // get conversion result
	
	return Local_u16Result ;
	
}


u16  ADC_u16AverageItrations(u8 Copy_u8Channel, u8 Copy_u8Iterations){
	
	u32 Local_u32TempVal = 0;
	u16 Local_u16AvgResult ;
	
	for(u8 i = 0 ; i < Copy_u8Iterations ; i++){
		Local_u32TempVal += ADC_u16StartConversion(Copy_u8Channel);
	}
	Local_u16AvgResult = Local_u32TempVal/Copy_u8Iterations;
	
	return Local_u16AvgResult;
}



u16 ADC_u16ADCReadResult(){
	
	u16 Local_u16Result ;
	
	#if (ADC_RESOLUTION == EIGHT_BIT)
		#if (RESULT_ADJUST == LEFT)
			Local_u16Result = ADCH ;
	 #elif (RESULT_ADJUST == RIGHT){
			Local_u16Result = ADCL ;
		#endif
	#elif (ADC_RESOLUTION == TEN_BIT)
		#if (RESULT_ADJUST == LEFT)
			Local_u16Result = (ADCL >> 8) ;
			Local_u16Result |= ADCH ;
		#elif (RESULT_ADJUST == RIGHT)
			Local_u16Result = ADCL ;
			Local_u16Result |= (ADCH << 8) ;
		#endif
	#endif
	
	return Local_u16Result ;
}