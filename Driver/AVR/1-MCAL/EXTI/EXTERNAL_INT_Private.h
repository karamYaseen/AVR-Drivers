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
#ifndef EXTERNAL_INT_PRIVATE_H
#define EXTERNAL_INT_PRIVATE_H


/************** MACROS FOR External Interrupt Control Registers ********/
#define MCUCR                                   *((volatile u8*)0x55)
#define MCUCSR                                  *((volatile u8*)0x54)
#define GICR                                    *((volatile u8*)0x5B)
#define GIFR                                    *((volatile u8*)0x5A)

/************** MACROS FOR External Interrupt Numbers ******************/
#define INT0                                    0
#define INT1                                    1
#define INT2                                    2
#define EXTERNAL_INT_NUM                        3

/************** MACROS FOR MCUCR Register Bits        ******************/
#define EXTI_U8_ISC00                           0
#define EXTI_U8_ISC01                           1
#define EXTI_U8_ISC10                           2
#define EXTI_U8_ISC11                           3

/************** MACROS FOR MCUCSR Register Bits        *****************/
#define EXTI_U8_ISC2                            6

/************** MACROS FOR GICR Register Bits          *****************/
#define EXTI_U8_INT0                            6
#define EXTI_U8_INT1                            7
#define EXTI_U8_INT2                            5

/************** MACROS FOR GIFR Register Bits          *****************/
#define EXTI_U8_INTF0                           6
#define EXTI_U8_INTF1                           7
#define EXTI_U8_INTF2                           5

#define  EXTI_u8_ISC00_MASK                     0x01

/*********************** MACROS FOR External Interrupt Modes ***********/
#define EXTI_FALLING_EDGE                       0
#define EXTI_RISING_EDGE                        1
#define EXTI_LOW_LEVEL                          2
#define EXTI_ANY_CHANGE                         3

#define EXTI_Modes_NUM                          4

/*********************** MACROS FOR External Interrupt Pins *************/
#define EXTI_INT0                               0
#define EXTI_INT1                               1
#define EXTI_INT2                               2
#define EXTERNAL_INT_NUM                        3

/*********************** MACROS FOR Register Definitions ****************/
#define EXTI_REG_MODE                           MCUCR
#define EXTI_REG_ISC                            MCUCR
#define EXTI_REG_GICR                           GICR

/*********************** MACROS FOR Bit Definitions *********************/
#define EXTI_U8_ISC00                           0
#define EXTI_U8_ISC01                           1
#define EXTI_U8_ISC10                           2
#define EXTI_U8_ISC11                           3
#define EXTI_U8_INT0                            6
#define EXTI_U8_INT1                            7
#define EXTI_U8_INT2                            5


#endif /* EXTERNAL_INT_PRIVATE_H */
