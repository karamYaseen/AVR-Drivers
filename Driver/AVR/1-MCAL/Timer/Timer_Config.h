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
#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H


/*
    -----------------------------Your Options-------------------------------------
		*****************
        * Timer0 Config *
        *****************

I-      Options For Mode:
                    1- TIMER_NORMAL_MODE 
                    2- TIMER_CTC_MODE	  
*/

/***    Choose Timer Mode           *************/
#define TIMER0_GENERATION_MODE             TIMER_CTC_MODE


/*
II-     Options For Required Prescaler:
	                 1- TIMER_NO_CLOCK_SOURCE
	                 2- TIMER_NO_PRESCALER_FACTOR
	                 3- TIMER_DIVISION_FACTOR_8
	                 4- TIMER_DIVISION_FACTOR_64
	                 5- TIMER_DIVISION_FACTOR_256
	                 6- TIMER_DIVISION_FACTOR_1024
	                 7- TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING
	                 8- TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING
*/

/***    Choose Prescaler         *************/
#define TIMER0_PRESCALER                   TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING



//#if TIMER0_GENERATION_MODE == TIMER_NORMAL_MODE
    
    /*Set the Required Preload on TIMER0 Normal Mode*/
#define TIMER0_PRELOAD_VALUE                192  

/*
    Options For Set Timer0 Overflow Interrupt
                     1- TIMER_DISABLE	
                     2- TIMER_ENABLE	
*/
#define TIMER0_OVERFLOW_INTERRUPT			TIMER_ENABLE


//#elif TIMER0_GENERATION_MODE == TIMER_CTC_MODE

    /*Set the Required Compare Match Value on TIMER0 CTC Mode*/
#define TIMER0_CTC_VAL						0

/*  Set Timer0 CTC Interrupt
                     1- TIMER_DISABLE	
                     2- TIMER_ENABLE	
*/
#define TIMER0_CTC_INTERRUPT		    	TIMER_ENABLE

//#endif
#endif
