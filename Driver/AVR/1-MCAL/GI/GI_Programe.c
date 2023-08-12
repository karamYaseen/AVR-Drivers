/***********************************************************************/
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *      
 *                 Author  : Karam A.Yaseen                            * 
 *                 Layer   : MCAL                                      *
 *                 SWC     : GI                                        *
 *                 Data    : 29/07/2023                                *
 *                 E_Mail  : karamyaseen725@gmail.com                  *
 *                 version : 1.0                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *      
 */
/***********************************************************************/
#include "../../5-LIB/STD_TYPES.h"
#include "../../5-LIB/BIT_MATH.h"
#include "../../5-LIB/Error_State.h"

#include "GI_Private.h"

ES_t GI_enu_Enable(void)
{
	u8 Local_u8_ErrorState = STD_TYPES_OK;
    /* Set the I-bit in the Status Register to enable global interrupts */
	SET_BIT(SREG_REG, GI_GLOBAL_INTERRUPT_ENABLE);
    return Local_u8_ErrorState;
}

ES_t GI_enu_Disable(void)
{
	u8 Local_u8_ErrorState = STD_TYPES_OK;
    /* Clear the I-bit in the Status Register to disable global interrupts */
	CLR_BIT(SREG_REG, GI_GLOBAL_INTERRUPT_ENABLE);
    return Local_u8_ErrorState;
}
