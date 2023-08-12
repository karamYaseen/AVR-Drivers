/***********************************************************************/
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                 Author  : Karam A.Yaseen                            *
 *                 Layer   : MCAL                                      *
 *                 SWC     : Timers                                    *
 *                 Data    : 11/08/2023                                *
 *                 E_Mail  : karamyaseen725@gmail.com                  *
 *                 version : 1.0                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
/***********************************************************************/

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H
#include "../../5-LIB/STD_TYPES.h"

/************** MACROS FOR TIMER Register Definitions ******************/
#define TIMER_U8_TIMSK_REG             					*((volatile u8 *)0x59)
#define TIMER_U8_TIFR_REG              					*((volatile u8 *)0x58)

/*TIMER 0*/
#define TIMER0_U8_TCCR0_REG            					*((volatile u8 *)0x53)  
#define TIMER0_U8_TCNT0_REG            					*((volatile u8 *)0x52)
#define TIMER0_U8_OCR0_REG             					*((volatile u8 *)0x5c)

/************** MACROS FOR TCCR0 bitmask              ******************/
#define TIMER0_U8_TCCR0_FOC0           					7
#define TIMER0_U8_TCCR0_WGM00	     					6
#define TIMER0_U8_TCCR0_COM01	    					5
#define TIMER0_U8_TCCR0_COM00	    					4
#define TIMER0_U8_TCCR0_WGM01	    					3
#define TIMER0_U8_TCCR0_CS02           					2
#define TIMER0_U8_TCCR0_CS01	    					1
#define TIMER0_U8_TCCR0_CS00	    					0

/************** MACROS FOR TIMSK bitmask              ******************/
#define TIMER_U8_TIMSK_TOIE0           					0
#define TIMER_U8_TIMSK_OCIE0           					1

/************** MACROS FOR TIFR bitmask               ******************/
#define TIMER_U8_TIFR_TOV0             					0
#define TIMER_U8_TIFR_OCF0             					1


/************** MACROS FOR Options for Timer mode     *****************/
#define TIMER_NORMAL_MODE   	       				    0
#define TIMER_CTC_MODE	    	       				    1

/************** MACROS FOR Options for Timer Interrupt  mode **********/
#define TIMER_DISABLE				                    0
#define TIMER_ENABLE						            1

// #define TIMER_FALLING_EDGE				            0
// #define TIMER_RISING_EDGE				            1

/************** MACROS FOR Options for Required Prescaler  ************/
#define TIMER_NO_CLOCK_SOURCE	 	                    0
#define TIMER_NO_PRESCALER_FACTOR 	                    1
#define TIMER_DIVISION_FACTOR_8	 	                    2
#define TIMER_DIVISION_FACTOR_64	                    3
#define TIMER_DIVISION_FACTOR_256	                    4
#define TIMER_DIVISION_FACTOR_1024	                    5
#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING	        6
#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING	        7

#define TIMER_PRESCALER_MASK					        0XF8 /* This Value also could use for bit masking */

#endif
