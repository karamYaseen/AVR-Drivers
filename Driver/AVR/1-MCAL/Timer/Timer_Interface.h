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
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "../../5-LIB/Error_State.h"
#include "../../5-LIB/STD_TYPES.h"

#define TIMER_NORMAL_MODE   	                        0
#define TIMER_CTC_MODE	    	                        1

#define TIMER_NO_CLOCK_SOURCE	 	                    0
#define TIMER_NO_PRESCALER_FACTOR 	                    1
#define TIMER_DIVISION_FACTOR_8	 	                    2
#define TIMER_DIVISION_FACTOR_64	                    3
#define TIMER_DIVISION_FACTOR_256	                    4
#define TIMER_DIVISION_FACTOR_1024	                    5
#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING	        6
#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING	        7


ES_t Timer_enu_Timer0Init                               (void);

ES_t Timers_enu_TIMER0SetPreload                        (u8 Copy_u8_Preload);

ES_t Timers_enu_TIMER0SetCTC                            (u8 Copy_u8_CTC);

ES_t TIMER0_u8GetTimerCounterValue                      (u8 * Copy_pu8_ReturnValue);

ES_t Timer_enu_SetCallBack                              (void(*Copy_pf_CallBackFunc)(void),u8 Copy_u8_Mode);
 
#endif