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
#include "../../5-LIB/Error_State.h"
#include "../../5-LIB/STD_TYPES.h"
#include "../../5-LIB/BIT_MATH.h"

#include "../DIO/DIO_Interface.h"
#include "Timer_Private.h"
#include "Timer_Config.h"

#define F_CPU 8000000UL

/*Global Pointer to array of Function to Hold the Call Back Function Address for Timer*/
static void (*Timers_pf_CallBackFunc[2])(void) = {NULL};

ES_t Timer_enu_Timer0Init(void)
{

#if TIMER0_GENERATION_MODE == TIMER_NORMAL_MODE
    /*Initialize Waveform Generation Mode as Normal Mode*/
    CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_TCCR0_WGM00);
    CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_TCCR0_WGM01);

    /*Set the Required Preload Value*/
    TIMER0_U8_TCNT0_REG = TIMER0_PRELOAD_VALUE;
/*Timer0 Overflow Interrupt Enable*/
#if TIMER0_OVERFLOW_INTERRUPT == TIMER_DISABLE
    CLR_BIT(TIMER_U8_TIMSK_REG, TIMER_U8_TIMSK_TOIE0);
#elif (TIMER0_OVERFLOW_INTERRUPT == TIMER_ENABLE)
    SET_BIT(TIMER_U8_TIMSK_REG, TIMER_U8_TIMSK_TOIE0);
#endif

#elif TIMER0_GENERATION_MODE == TIMER_CTC_MODE
    /*Initialize Waveform Generation Mode as CTC Mode*/
    CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_TCCR0_WGM00);
    SET_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_TCCR0_WGM01);

    /*Set the Required CTC Value*/
    TIMER0_U8_OCR0_REG = TIMER0_CTC_VAL;

/*Timer0 Compare Match Interrupt Enable*/
#if TIMER0_CTC_INTERRUPT == TIMER_DISABLE
    CLR_BIT(TIMER_U8_TIMSK_REG, TIMER_U8_TIMSK_OCIE0);
#elif TIMER0_CTC_INTERRUPT == TIMER_ENABLE
    SET_BIT(TIMER_U8_TIMSK_REG, TIMER_U8_TIMSK_OCIE0);
#endif
#endif

    /*Set the Required Prescaler*/
    TIMER0_U8_TCCR0_REG &= TIMER_PRESCALER_MASK;
    TIMER0_U8_TCCR0_REG |= TIMER0_PRESCALER;
    return STD_TYPES_OK;
}

ES_t Timers_enu_TIMER0SetPreload(u8 Copy_u8_Preload)
{
    TIMER0_U8_TCNT0_REG = Copy_u8_Preload;
    return STD_TYPES_OK;
}

ES_t Timers_enu_TIMER0SetCTC(u8 Copy_u8_CTC)
{
    TIMER0_U8_OCR0_REG = Copy_u8_CTC;
    return STD_TYPES_OK;
}

ES_t TIMER0_u8GetTimerCounterValue(u8 *Copy_pu8_ReturnValue)
{
    u8 Local_u8_ErrorState = STD_TYPES_OK;
    if (Copy_pu8_ReturnValue != NULL)
    {
        *Copy_pu8_ReturnValue = TIMER0_U8_TCNT0_REG;
        Local_u8_ErrorState = STD_TYPES_OK;
    }
    else
    {
        Local_u8_ErrorState = STD_TYPES_NOK;
    }
    return Local_u8_ErrorState;
}

ES_t Timer_enu_SetCallBack(void (*Copy_pf_CallBackFunc)(void), u8 Copy_u8_Mode)
{
    u8 Local_u8_ErrorState = STD_TYPES_OK;
    if (Copy_pf_CallBackFunc != NULL)
    {
        Timers_pf_CallBackFunc[Copy_u8_Mode] = Copy_pf_CallBackFunc;
    }
    else
    {
        Local_u8_ErrorState = STD_TYPES_NOK;
    }
    return Local_u8_ErrorState;
}

/*TIMER0 Normal Mode ISR*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
#if (TIMER0_PRESCALER == TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING) || (TIMER0_PRESCALER == TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING)
    if (Timers_pf_CallBackFunc[TIMER_CTC_MODE] != NULL)
        Timers_pf_CallBackFunc[TIMER_CTC_MODE]();
#else
    static u16 Local_u16_CounterOVF = 0;
    Local_u16_CounterOVF++;
    if (Local_u16_CounterOVF == 3906)
    {
        /*clear overflow counter*/
        Local_u16_CounterOVF = 0;

        /*update preload Value*/
        TIMER0_U8_TCNT0_REG = TIMER0_PRELOAD_VALUE;

        /*calling App function*/
        if (Timers_pf_CallBackFunc[TIMER_NORMAL_MODE] != NULL)
            Timers_pf_CallBackFunc[TIMER_NORMAL_MODE]();
    }
#endif
}

/*TIMER0 CTC Mode ISR*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
#if (TIMER0_PRESCALER == TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING) || (TIMER0_PRESCALER == TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING)
    if (Timers_pf_CallBackFunc[TIMER_CTC_MODE] != NULL)
        Timers_pf_CallBackFunc[TIMER_CTC_MODE]();
#else
    static u16 Local_u16_CounterCTC = 0;
    Local_u16_CounterCTC++;
    if (Local_u16_CounterCTC == 10500)
    {
        Local_u16_CounterCTC = 0;
        if (Timers_pf_CallBackFunc[TIMER_CTC_MODE] != NULL)
            Timers_pf_CallBackFunc[TIMER_CTC_MODE]();
    }
#endif
}
