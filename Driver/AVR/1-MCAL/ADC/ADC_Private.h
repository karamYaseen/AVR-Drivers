/***********************************************************************/
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                 Author  : Karam A.Yaseen                            *
 *                 Layer   : MCAL                                      *
 *                 SWC     : ADC                                       *
 *                 Data    : 05/08/2023                                *
 *                 E_Mail  : karamyaseen725@gmail.com                  *
 *                 version : 1.0                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
/***********************************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/************** MACROS FOR ADC Register Definitions   ******************/
#define ADMUX_REG                                       (*(volatile u8*) 0x27)
#define ADCSRA_REG                                      (*(volatile u8*) 0x26)
#define ADCH_REG                                        (*(volatile u8*) 0x25)
#define ADCL_REG                                        (*(volatile u8*) 0x24)
#define SFIOR_REG                                       (*(volatile u8*) 0x50)

#define ADC_REG                                         (*(volatile u16*)0x24)

/************** MACROS FOR ADMUX bitmask              ******************/
#define ADC_ADMUX_MASK                                  0x1F
#define ADC_REFS1_BIT                                   7
#define ADC_REFS0_BIT                                   6
#define ADC_ADLAR_BIT                                   5

/************** MACROS FOR ADCSRA bitmask             ******************/
#define ADC_ADCSRA_MASK                                 0xF8
#define ADC_ADEN_BIT                                    7
#define ADC_ADSC_BIT                                    6
#define ADC_ADATE_BIT                                   5
#define ADC_ADIF_BIT                                    4
#define ADC_ADIE_BIT                                    3
#define ADC_ADPS2_BIT                                   2
#define ADC_ADPS1_BIT                                   1
#define ADC_ADPS0_BIT                                   0

/************** MACROS FOR SFIOR bitmask              ******************/
#define ADC_ADTS2_BIT                                   2
#define ADC_ADTS1_BIT                                   1
#define ADC_ADTS0_BIT                                   0

/************** MACROS FOR ADC Channel Selection Bits ******************/
#define ADC_CH0                                         0
#define ADC_CH1                                         1
#define ADC_CH2                                         2
#define ADC_CH3                                         3
#define ADC_CH4                                         4
#define ADC_CH5                                         5
#define ADC_CH6                                         6
#define ADC_CH7                                         7
#define ADC_NUM_OF_CHANNEL					            8

#define ADC_MAX_CHANNEL                                 32

/************** MACROS FOR Options for reference voltage ****************/
#define ADC_REF_AREF                                    0
#define ADC_REF_AVCC                                    1
#define ADC_REF_INTERNAL_VOLTAGE                        2

/************** MACROS FOR Options for ADC conversion mode **************/
#define ADC_CONV_START_CONVERSION                       0
#define ADC_CONV_FREE_RUNNING                           1
#define ADC_CONV_EXTERNAL_INT                           2

/************** MACROS FOR Options for ADC presentation mode*************/
#define ADC_RIGHT_ADJUST                                0
#define ADC_LEFT_ADJUST                                 1

/************** MACROS FOR Options for ADC clock (division factor)  *****/
#define ADC_CLOCK_DIV_BY_2                              0
#define ADC_CLOCK_DIV_BY_4                              2
#define ADC_CLOCK_DIV_BY_8                              3
#define ADC_CLOCK_DIV_BY_16                             4
#define ADC_CLOCK_DIV_BY_32                             5
#define ADC_CLOCK_DIV_BY_64                             6
#define ADC_CLOCK_DIV_BY_128                            7

#endif
