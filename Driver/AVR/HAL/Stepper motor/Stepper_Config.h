/*********************************************************************************************/
/*************************** Name     :  Karam Yaseen   **************************************/
/*************************** Data     :  4/5/2023       **************************************/
/*************************** SWC      :  STEPPER_MOTOR  **************************************/
/*************************** E_Mail   :  karamyaseen725@gmail.com    *************************/
/*************************** version  :  1.0            **************************************/
/*********************************************************************************************/

#ifndef CONFIG_H_
#define CONFIG_H_

#define F_CPU                   8000000UL

#define STEPPER_MOTOR_PORT      DIO_u8_PORTD

#define IN1_PIN                  DIO_u8_PIN3
#define IN2_PIN                  DIO_u8_PIN4
#define IN3_PIN                  DIO_u8_PIN5
#define IN4_PIN                  DIO_u8_PIN6

#define STEP_ANGLE               45

#endif /* CONFIG_H_ */