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
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../5-LIB/Error_State.h"
#include "../../5-LIB/STD_TYPES.h"

typedef enum {
    ADC_U8_CHANNEL0 = 0,
    ADC_U8_CHANNEL1,
    ADC_U8_CHANNEL2,
    ADC_U8_CHANNEL3,
    ADC_U8_CHANNEL4,
    ADC_U8_CHANNEL5,
    ADC_U8_CHANNEL6,
    ADC_U8_CHANNEL7,
    // Add more channels If needed
} ADC_Channel_t;

/* ADC initialization function */
ES_t ADC_enu_Init                               (void);

/* ADC synchronous conversion function */
ES_t ADC_enu_GetDigitalValueSynchNonBlocking    (u8 Copy_u8_channelNum, u16 *Copy_pu16_digitalValue);

/* ADC asynchronous conversion function */
ES_t ADC_enu_GetDigitalValueASynch              (u8 Copy_u8_channelNum, void (*Copy_pf_notificationCallback)(u16));


#endif
