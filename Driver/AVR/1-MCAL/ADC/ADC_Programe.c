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
#include "../../5-LIB/Error_State.h"
#include "../../5-LIB/STD_TYPES.h"
#include "../../5-LIB/BIT_MATH.h"
#include "../DIO/DIO_Interface.h"

#include "ADC_Config.h"
#include "ADC_Private.h"

#define F_CPU 8000000UL
#include <util/delay.h>

static void (*ADC_pf_Notification)(u16) = NULL;

ES_t ADC_enu_Init(void)
{
    u8 Local_u8_ErrorState = STD_TYPES_OK;

    /*-----------Set reference voltage-----------*/

#if ADC_REFERENCE_MODE == ADC_REF_AREF
    ADMUX_REG &= ~((1 << ADC_REFS1_BIT) | (1 << ADC_REFS0_BIT));
#elif ADC_REFERENCE_MODE == ADC_REF_AVCC
    ADMUX_REG = (ADMUX_REG & ~(1 << ADC_REFS1_BIT)) | (1 << ADC_REFS0_BIT);
#elif ADC_REFERENCE_MODE == ADC_REF_INTERNAL_VOLTAGE
    ADMUX_REG |= ((1 << ADC_REFS1_BIT) | (1 << ADC_REFS0_BIT));
#endif

    /*----------Set result presentation----------*/

#if ADC_PRESENTATION_MODE == ADC_RIGHT_ADJUST
    ADMUX_REG &= ~(1 << ADC_ADLAR_BIT);
#elif ADC_PRESENTATION_MODE == ADC_LEFT_ADJUST
    ADMUX_REG |= (1 << ADC_ADLAR_BIT);
#endif

    /*----------Set CONVERSION mode --------------*/

#if ADC_CONVERSION_MODE == ADC_CONV_START_CONVERSION
    ADCSRA_REG &= ~(1 << ADC_ADATE_BIT);
#elif ADC_CONVERSION_MODE == ADC_CONV_FREE_RUNNING
    ADCSRA_REG |= (1 << ADC_ADATE_BIT);
    SFIOR_REG &= ~((1 << ADC_ADTS2_BIT) | (1 << ADC_ADTS1_BIT) | (1 << ADC_ADTS0_BIT));
#elif ADC_CONVERSION_MODE == ADC_CONV_EXTERNAL_INT
    ADCSRA_REG |= (1 << ADC_ADATE_BIT);
    SFIOR_REG &= ~((1 << ADC_ADTS2_BIT) | (1 << ADC_ADTS1_BIT));
    SFIOR_REG |= (1 << ADC_ADTS0_BIT);
#endif

    /*--------Set ADC clock (division factor)-------*/

#if ADC_CLOCK_DIVISION == ADC_CLOCK_DIV_BY_2
    ADCSRA_REG = (ADCSRA_REG & ~((1 << ADC_ADPS2_BIT) | (1 << ADC_ADPS1_BIT) | (1 << ADC_ADPS0_BIT)));
#elif ADC_CLOCK_DIVISION == ADC_CLOCK_DIV_BY_4
    ADCSRA_REG = (ADCSRA_REG & ~((1 << ADC_ADPS2_BIT) | (1 << ADC_ADPS1_BIT))) | (1 << ADC_ADPS0_BIT);
#elif ADC_CLOCK_DIVISION == ADC_CLOCK_DIV_BY_8
    ADCSRA_REG = (ADCSRA_REG & ~((1 << ADC_ADPS2_BIT) | (1 << ADC_ADPS0_BIT))) | (1 << ADC_ADPS1_BIT);
#elif ADC_CLOCK_DIVISION == ADC_CLOCK_DIV_BY_16
    ADCSRA_REG = (ADCSRA_REG & ~(1 << ADC_ADPS2_BIT)) | (1 << ADC_ADPS1_BIT) | (1 << ADC_ADPS0_BIT);
#elif ADC_CLOCK_DIVISION == ADC_CLOCK_DIV_BY_32
    ADCSRA_REG = (ADCSRA_REG & ~((1 << ADC_ADPS1_BIT) | (1 << ADC_ADPS0_BIT))) | (1 << ADC_ADPS2_BIT);
#elif ADC_CLOCK_DIVISION == ADC_CLOCK_DIV_BY_64
    ADCSRA_REG = (ADCSRA_REG & ~(1 << ADC_ADPS1_BIT)) | (1 << ADC_ADPS2_BIT) | (1 << ADC_ADPS0_BIT);
#elif ADC_CLOCK_DIVISION == ADC_CLOCK_DIV_BY_128
    ADCSRA_REG = (ADCSRA_REG & ~(1 << ADC_ADPS0_BIT)) | (1 << ADC_ADPS2_BIT) | (1 << ADC_ADPS1_BIT);
#endif

    // Enable ADC
    ADCSRA_REG |= (1 << ADC_ADEN_BIT);

    return Local_u8_ErrorState;
}

ES_t ADC_enu_GetDigitalValueSynchNonBlocking(u8 Copy_u8_channelNum, u16 *Copy_pu16_digitalValue)
{
    u8 Local_u8_ErrorState = STD_TYPES_OK;
    u32 Local_u32_TimeoutCounter = 0;

    if (Copy_pu16_digitalValue == NULL || Copy_u8_channelNum > ADC_NUM_OF_CHANNEL || (ADCSRA_REG & (1 << ADC_ADSC_BIT)))
    {
        Local_u8_ErrorState = STD_TYPES_NOK;
    }
    else
    {

        // Clear the MUX3:0 bits in ADMUX
        ADMUX_REG = (ADMUX_REG & ~ADC_ADMUX_MASK) | Copy_u8_channelNum;

        // Start the ADC conversion
        ADCSRA_REG |= (1 << ADC_ADSC_BIT);

        // Wait for the conversion to complete or timeout
        while ((ADCSRA_REG & (1 << ADC_ADSC_BIT)) && Local_u32_TimeoutCounter < ADC_TIMEOUT_MAX_VALUE)
        {
            Local_u32_TimeoutCounter++;
        }

        if (Local_u32_TimeoutCounter >= ADC_TIMEOUT_MAX_VALUE)
        {
            // ADC conversion timed out, return error
            Local_u8_ErrorState = STD_TYPES_NOK;
        }
        else
        {
            // ADC conversion complete successfully
            *Copy_pu16_digitalValue = ADC_REG;

            // If ADC result presentation is left-adjusted, right-shift the result
            if (ADMUX_REG & (1 << ADC_ADLAR_BIT))
            {
                *Copy_pu16_digitalValue >>= SHIFT_6BIT;
            }
        }
    }
    return Local_u8_ErrorState;
}

ES_t ADC_enu_GetDigitalValueASynch(u8 Copy_u8_channelNum, void (*Copy_pf_notificationCallback)(u16))
{
    u8 Local_u8_ErrorState = STD_TYPES_OK;
    if (Copy_pf_notificationCallback == NULL || Copy_u8_channelNum > ADC_NUM_OF_CHANNEL || (ADCSRA_REG & (1 << ADC_ADSC_BIT)))
    {
        Local_u8_ErrorState = STD_TYPES_NOK;
    }
    else
    {
        // Set the global pointer to the notification function
        ADC_pf_Notification = Copy_pf_notificationCallback;

        // Clear the MUX3:0 bits in ADMUX
        ADMUX_REG = (ADMUX_REG & ~ADC_ADMUX_MASK) | Copy_u8_channelNum;

        // Enable ADC interrupt
        ADCSRA_REG |= (1 << ADC_ADIE_BIT);

        // Start the ADC conversion
        ADCSRA_REG |= (1 << ADC_ADSC_BIT);
    }
    return Local_u8_ErrorState;
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{

    u16 Local_u16_digitalValue = ADC_REG;
    if (ADMUX_REG & (1 << ADC_ADLAR_BIT))
    {
        Local_u16_digitalValue >>= SHIFT_6BIT;
    }
    if (ADC_pf_Notification != NULL)
    {
        ADC_pf_Notification(Local_u16_digitalValue);
    }
}
/*						Not Important (Keep It)
 *								KAY
 */
//// ADC interrupt service routine
// ISR(ADC_vect) {
//     // Read the ADC result (16-bit)
//     u16 Local_u16_digitalValue = ADC_REG;
//
//     // If ADC result presentation is left-adjusted, right-shift the result
//     if (ADMUX_REG & (1 << ADC_ADLAR_BIT)) {
//         Local_u16_digitalValue >>= SHIFT_6BIT;
//     }
//
//     // Call the notification function if available
//     if (ADC_pf_Notification != NULL) {
//         ADC_pf_Notification(Local_u16_digitalValue);
//     }
//
// }
