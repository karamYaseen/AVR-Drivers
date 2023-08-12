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
#include "../../5-LIB/STD_TYPES.h"
#include "../../5-LIB/Error_State.h"
#include "../../5-LIB/BIT_MATH.h"

#include "EXTERNAL_INT_Private.h"
#include "EXTERNAL_INT_Config.h"

static void (*EXTI_Apf_CallBack[EXTERNAL_INT_NUM])(void)= {NULL};

ES_t EXTI_enu_Enable(u8 Copy_u8_IntNum, u8 Copy_u8_Mode)
{
    u8 Local_u8_ErrorState = STD_TYPES_OK;
    if (Copy_u8_IntNum <= EXTI_INT2 && Copy_u8_Mode<= EXTI_Modes_NUM)
    {
        switch (Copy_u8_IntNum)
        {
        case EXTI_INT0:
            SET_BIT(EXTI_REG_GICR, EXTI_U8_INT0);
            switch(Copy_u8_Mode)
            {
            case EXTI_FALLING_EDGE:
            	                    CLR_BIT(EXTI_REG_MODE,EXTI_U8_ISC00);
            	                    SET_BIT(EXTI_REG_MODE,EXTI_U8_ISC01);
            	                    break;
            case EXTI_RISING_EDGE :
            	                    SET_BIT(EXTI_REG_MODE,EXTI_U8_ISC00);
            	                    SET_BIT(EXTI_REG_MODE,EXTI_U8_ISC01);
            	                    break;
            case EXTI_LOW_LEVEL   :
			                        CLR_BIT(EXTI_REG_MODE,EXTI_U8_ISC00);
			                        CLR_BIT(EXTI_REG_MODE,EXTI_U8_ISC01);
			                        break;
            case EXTI_ANY_CHANGE  :
				                    SET_BIT(EXTI_REG_MODE,EXTI_U8_ISC00);
				                    CLR_BIT(EXTI_REG_MODE,EXTI_U8_ISC01);
				                    break;
            }
		break;
        case EXTI_INT1:
        	SET_BIT(EXTI_REG_GICR, EXTI_U8_INT1);
			switch(Copy_u8_Mode)
			{
			case EXTI_FALLING_EDGE:
				                    CLR_BIT(EXTI_REG_MODE,EXTI_U8_ISC10);
				                    SET_BIT(EXTI_REG_MODE,EXTI_U8_ISC11);
				                    break;
			case EXTI_RISING_EDGE:
			                    	SET_BIT(EXTI_REG_MODE,EXTI_U8_ISC10);
			                    	SET_BIT(EXTI_REG_MODE,EXTI_U8_ISC11);
			                    	break;
			case EXTI_LOW_LEVEL:
			                        CLR_BIT(EXTI_REG_MODE,EXTI_U8_ISC10);
			                        CLR_BIT(EXTI_REG_MODE,EXTI_U8_ISC11);
			                        break;
			case EXTI_ANY_CHANGE:
			                    	SET_BIT(EXTI_REG_MODE,EXTI_U8_ISC10);
			                    	CLR_BIT(EXTI_REG_MODE,EXTI_U8_ISC11);
			                    	break;
			}
		break;
		case EXTI_INT2:
			SET_BIT(EXTI_REG_GICR, EXTI_U8_INT2);
			switch(Copy_u8_Mode)
			{
			case EXTI_FALLING_EDGE:
			                        CLR_BIT(EXTI_REG_GICR,EXTI_U8_ISC2);
			                        break;
			case EXTI_RISING_EDGE:
				                    SET_BIT(EXTI_REG_GICR,EXTI_U8_ISC2);
				                    break;
			}
		break;
        default:
            Local_u8_ErrorState = STD_TYPES_NOK;
            break;
        }
    }
    else
    {
        Local_u8_ErrorState = STD_TYPES_NOK;
    }
    return Local_u8_ErrorState;
}

ES_t EXTI_enu_Disable(u8 Copy_u8_IntNum)
{
    ES_t Local_u8_ErrorState = STD_TYPES_OK;
    if (Copy_u8_IntNum <= EXTI_INT2)
    {
        switch (Copy_u8_IntNum)
        {
        case EXTI_INT0:
                        /* Disable INT0 */
        	            CLR_BIT(EXTI_REG_GICR, INT0);
                        break;
        case EXTI_INT1:
                        /* Disable INT1 */
        	            CLR_BIT(EXTI_REG_GICR, INT1);
                        break;
        case EXTI_INT2:
                        /* Disable INT2 */
        	            CLR_BIT(EXTI_REG_GICR, INT2);
                        break;
        default:
                        Local_u8_ErrorState = STD_TYPES_NOK;
                        break;
        }
    }
    else
    {
        Local_u8_ErrorState = STD_TYPES_NOK;
    }
    return Local_u8_ErrorState;
}

ES_t EXTI_enu_SetCallback(u8 Copy_u8_IntNum, void (*Copy_pf_CallBack)(void))
{
    u8 Local_u8_ErrorState = STD_TYPES_OK;
    if (Copy_u8_IntNum <= EXTI_INT2)
    {
        EXTI_Apf_CallBack[Copy_u8_IntNum] = Copy_pf_CallBack;
    }
    else
    {
        Local_u8_ErrorState = STD_TYPES_NOK;
    }
    return Local_u8_ErrorState;
}

/* Interrupt Service Routine for External Interrupt 0 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if (EXTI_Apf_CallBack[EXTI_INT0] != NULL)
    {
        EXTI_Apf_CallBack[EXTI_INT0]();
    }
}

/* Interrupt Service Routine for External Interrupt 1 */
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    if (EXTI_Apf_CallBack[EXTI_INT1] != NULL)
    {
        EXTI_Apf_CallBack[EXTI_INT1]();
    }
}

/* Interrupt Service Routine for External Interrupt 2 */
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    if (EXTI_Apf_CallBack[EXTI_INT2] != NULL)
    {
        EXTI_Apf_CallBack[EXTI_INT2]();
    }
}
