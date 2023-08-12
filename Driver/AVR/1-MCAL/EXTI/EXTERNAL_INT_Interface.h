/***********************************************************************/
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *      
 *                 Author  : Karam A.Yaseen                            * 
 *                 Layer   : MCAL                                      *
 *                 SWC     : EXTI                                      *
 *                 Data    : 29/07/2023                                *
 *                 E_Mail  : karamyaseen725@gmail.com                  *
 *                 version : 1.0                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *      
 */
/***********************************************************************/
#ifndef EXTERNAL_INT_INTERFACE_H
#define EXTERNAL_INT_INTERFACE_H

#include "../../5-LIB/STD_TYPES.h"
#include "../../5-LIB/Error_State.h"


/*********************** MACROS FOR External Interrupt Modes ***********/
#define EXTI_FALLING_EDGE                 0
#define EXTI_RISING_EDGE                  1
#define EXTI_LOW_LEVEL                    2
#define EXTI_ANY_CHANGE                   3
             
/*********************** MACROS FOR External Interrupt Pins *************/
#define EXTI_INT0                         0
#define EXTI_INT1                         1
#define EXTI_INT2                         2


ES_t EXTI_enu_Enable                      (u8 Copy_u8_IntNum, u8 Copy_u8_Mode);
ES_t EXTI_enu_Disable                     (u8 Copy_u8_IntNum);
ES_t EXTI_enu_SetCallback                 (u8 Copy_u8_IntNum, void (*Copy_pf_CallBack)(void));

#endif /* EXTERNAL_INT_INTERFACE_H */
