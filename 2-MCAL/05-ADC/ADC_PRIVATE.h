/*****************************************************/
/* Author  : Omar Hazem 							 */
/* Version : V1.0                                    */
/* Date    : 22 MAY 2021			                 */
/*****************************************************/

#ifndef _ADC_PRIVATE_H 
#define _ADC_PRIVATE_H 

#define AREF		0b00
#define AVCC		0b01
#define INTERNAL	0b11

#define	LEFT	1
#define	RIGHT	0

#define ADC0	0b00000
#define ADC1	0b00001
#define ADC2	0b00010
#define ADC3	0b00011
#define ADC4	0b00100
#define ADC5	0b00101
#define ADC6	0b00110
#define ADC7	0b00111

#define	TWO					0b001
#define FOUR				0b010
#define EIGHT				0b011
#define SIXTEEN				0b100
#define THIRTY_TWO			0b101
#define SIXTY_FOUR			0b110
#define ONE_TWENTY_EIGHT	0b111


#define EIGHT_BIT	0
#define TEN_BIT 	1


u16 ADC_u16ADCReadResult(void);

#endif 