/***********************************************************************/
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *      
 *                 Author  : Karam A.Yaseen                            * 
 *                 Layer   : MCAL                                      *
 *                 SWC     : DIO                                       *
 *                 Data    : 29/04/2023                                *
 *                 E_Mail  : karamyaseen725@gmail.com                  *
 *                 version : 1.0                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *      
 */
/***********************************************************************/

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

        /*LIB*/
#include    "../../5-LIB/BIT_MATH.h"

        /*MCAL*/
#include    "DIO_Register.h"
#include    "DIO_Config.h"


/*********************** MACROS FOR PORTS ***********************/
#define DIO_u8_PORTA                                          0
#define DIO_u8_PORTB                                          1
#define DIO_u8_PORTC                                          2
#define DIO_u8_PORTD                                          3

/*********************** MACROS FOR PINS  ***********************/
#define DIO_u8_PIN0                                           0
#define DIO_u8_PIN1                                           1
#define DIO_u8_PIN2                                           2
#define DIO_u8_PIN3                                           3
#define DIO_u8_PIN4                                           4
#define DIO_u8_PIN5                                           5
#define DIO_u8_PIN6                                           6
#define DIO_u8_PIN7                                           7

/*********************** MACROS FOR Pins Direction **************/
#define DIO_u8_INITIAL_OUTPUT                                 1
#define DIO_u8_INITIAL_INPUT                                  0

#define DIO_u8_OUTPUT                                         1
#define DIO_u8_INPUT                                          0

#define DIO_u8_PORT_INPUT_DIR                                 0x00
#define DIO_u8_PORT_OUTPUT_DIR                                0xFF

/*********************** MACROS FOR Pins Values     *************/
#define DIO_u8_OUTPUT_LOW                                     0
#define DIO_u8_OUTPUT_HIGH                                    1
#define DIO_u8_INPUT_FLOATING                                 0
#define DIO_u8_INTPUT_PULLUP                                  1

#define DIO_u8_HIGH                                           1
#define DIO_u8_LOW                                            0

/*********************** Concatination     ***********************/

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)                         CONC_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_Help(b7,b6,b5,b4,b3,b2,b1,b0)                    0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif
