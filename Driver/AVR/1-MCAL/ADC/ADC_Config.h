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
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/*
    -----------------------------Your Options-------------------------------------
  
    I-  Options for reference voltage
                                1- ADC_REF_AREF              
                                2- ADC_REF_AVCC              
                                3- ADC_REF_INTERNAL_VOLTAGE  

    II- Options for ADC conversion mode
                                1- ADC_CONV_START_CONVERSION 
                                2- ADC_CONV_FREE_RUNNING     
                                3- ADC_CONV_EXTERNAL_INT     
    
    III-Options for ADC presentation mode
                                1- ADC_RIGHT_ADJUST          
                                2- ADC_LEFT_ADJUST          

    IV- Options for ADC clock (division factor)
                                1- ADC_CLOCK_DIV_BY_2        
                                2- ADC_CLOCK_DIV_BY_4        
                                3- ADC_CLOCK_DIV_BY_8        
                                4- ADC_CLOCK_DIV_BY_16       
                                5- ADC_CLOCK_DIV_BY_32       
                                6- ADC_CLOCK_DIV_BY_64       
                                7- ADC_CLOCK_DIV_BY_128      
*/
// Configuration macros
#define ADC_REFERENCE_MODE         ADC_REF_AVCC
#define ADC_CONVERSION_MODE        ADC_CONV_START_CONVERSION
#define ADC_PRESENTATION_MODE      ADC_RIGHT_ADJUST
#define ADC_CLOCK_DIVISION         ADC_CLOCK_DIV_BY_128

/*Adjust the timeout value as needed*/
#define ADC_TIMEOUT_MAX_VALUE      1000000

#endif
