/*****************************************************/
/* Author  : Omar Hazem 							 */
/* Version : V1.0                                    */
/* Date    : 28 APRIL 2021			                 */
/*****************************************************/

#ifndef _USART_CONFIG_H 
#define _USART_CONFIG_H 

/*	You can choose between two modes --> 1) SYNC 
										 2) ASYNC */
#define USARTMode	ASYNC

/*	Choose Your Baud Rate */
#define USARTBaudRate	9600

/* Choose number of stop bits --> 1 OR 2 */
#define USARTStopBits	1

/*	You can choose from three options --> 1) DISABLED
										  2) EVEN
										  3) ODD     */
#define USARTParity	DISABLED

/* select number of DataBits --> 5 - 6 - 7 - 8 - 9 */
#define USARTDataBits	8	

#endif 