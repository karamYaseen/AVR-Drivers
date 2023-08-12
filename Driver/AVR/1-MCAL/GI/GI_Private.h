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
#ifndef GI_PRIVATE_H
#define GI_PRIVATE_H

/* SREG Register Bit Definitions */
#define GI_GLOBAL_INTERRUPT_ENABLE   7

#define SREG_REG                     *((volatile u8*)0x5F)

#endif /* GI_PRIVATE_H */
