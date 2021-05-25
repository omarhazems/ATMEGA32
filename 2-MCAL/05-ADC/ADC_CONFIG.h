/*****************************************************/
/* Author  : Omar Hazem 							 */
/* Version : V1.0                                    */
/* Date    : 22 MAY 2021			                 */
/*****************************************************/

#ifndef _ADC_CONFIG_H 
#define _ADC_CONFIG_H 


/* select ADC voltage reference, you can choose between
1. AREF
2. AVCC, with external capacitor at AVCC
3. INTERNAL, 2.56V voltage reference with external capacitor at AREF pin
*/
#define	VOLTAGE_REFERENCE	AVCC



/* select result adjust - available optiions:
1. LEFT --> neglects small changes in case of 8 bit resolution 
2. Right--> focuses on small changes in case of 8 bit resolution
*/
#define RESULT_ADJUST	RIGHT



/* select ADC clock prescaler relative to XTAL frequency, available options: 
TWO - FOUR - EIGHT - SIXTEEN - THIRTY_TWO - SIXTY_FOUR - ONE_TWENTY_EIGHT
*/
#define	ADC_PRESCALER	EIGHT



/* select ADC resolution needed, options:
1. EIGHT_BIT --> 8  BIT result
2. TEN_BIT   --> 10 BIT result
*/
#define	ADC_RESOLUTION	TEN_BIT



#endif 