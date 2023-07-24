# AVR Drivers - ATMEGA32

## Table of Contents
1. [Introduction](#introduction)
2. [Stepper Motor Driver](#stepper-motor-driver)
3. [LCD Driver](#lcd-driver)
4. [Keypad Driver](#keypad-driver)
5. [DC Motor Driver](#dc-motor-driver)
6. [Digital I/O (DIO) Driver](#digital-io-driver)
7. [Usage](#usage)
8. [Support and Contact](#support-and-contact)

---

## Introduction
Welcome to the AVR Drivers repository! This collection of AVR drivers provides you with easy-to-use interfaces to interact with various peripherals in your AVR microcontroller-based projects. The drivers are designed to be highly configurable and can be easily customized to suit your specific project requirements.

Please feel free to explore the different drivers provided and don't hesitate to contact me if you need any assistance or have any questions.

---

## <span style="color: blue">Stepper Motor Driver</span>

### Description
The Stepper Motor Driver provides functions to control the movement of a stepper motor. It includes initialization, moving the motor to a specified angle and direction, and stopping the motor.

### Functions
- `ES_t StepperMotor_enu_Init(void);`
- `ES_t StepperMotor_enu_Move(u16 Copy_u16_STeeperangle, u8 Copy_u8_STeeperdirection);`
- `ES_t Stepper_enu_Stop(void);`

---

## <span style="color: blue">LCD Driver</span>

### Description
The LCD Driver provides functions to interface with an LCD in both 8-bit and 4-bit modes. It supports writing characters, strings, numbers, moving the cursor, and creating custom characters on the LCD.

### Functions
- `ES_t LCD_enu_Init_8bit_Mode(void);`
- `ES_t LCD_enu_Init_4bit_Mode(void);`
- `ES_t LCD_enu_SendCommand(u8 Copy_u8_command);`
- `ES_t LCD_enu_WriteCharacter(u8 Copy_u8_char);`
- `ES_t LCD_enu_WriteString(s8 * Copy_ps8_String);`
- `ES_t LCD_enu_WriteSizedString(s8 * Copy_ps8_String, u8 Copy_u8_size);`
- `ES_t LCD_enu_WriteNumber(u16 Copy_u16_Number);`
- `ES_t LCD_enu_WriteSizedNumber(u16 Copy_u16_Number, u8 Copy_u8_size);`
- `ES_t LCD_enu_GoToXY(u8 Copy_u8_LineNumber, u8 Copy_u8_Location);`
- `ES_t LCD_enu_CreateCustomChar(u8 * Copy_pu8_Char, u8 Copy_u8_Location);`
- `ES_t LCD_vidClearSpace(u8 Copy_u8_xPosStart, u8 Copy_u8_xPosEnd, u8 Copy_u8_yPos);`
- `ES_t LCD_enu_Clear(void);`

---

## <span style="color: blue">Keypad Driver</span>

### Description
The Keypad Driver provides functions to interface with a keypad and get key press inputs.

### Functions
- `ES_t KPD_enu_GetKey(u8 *Copy_pu8_ReturnKey);`
- `ES_t KeyPad_enu_Init(void);`

---

## <span style="color: blue">DC Motor Driver</span>

### Description
The DC Motor Driver provides functions to control the rotation of a DC motor. It includes initialization, rotating the motor in a specified direction, and stopping the motor.

### Functions
- `ES_t DC_Motor_enu_Init(void);`
- `ES_t DC_Motor_enu_Rotate(u8 Copy_u8_Direction);`
- `ES_t DC_Motor_enu_Stop(void);`

---

## <span style="color: blue">Digital I/O (DIO) Driver</span>

### Description
The Digital I/O (DIO) Driver provides functions to initialize, set the direction, set the value, and read the value of digital I/O pins.

### Functions
- `ES_t DIO_enu_Init(void);`
- `ES_t DIO_enu_SetPinDirection(u8 Copy_u8_PortId, u8 Copy_u8_PinId, u8 Copy_u8_PinDirection);`
- `ES_t DIO_enu_SetPinValue(u8 Copy_u8_PortId, u8 Copy_u8_PinId, u8 Copy_u8_PinValue);`
- `ES_t DIO_enu_GetPinValue(u8 Copy_u8_PortId, u8 Copy_u8_PinId, u8 *Copy_pu8_ReturnPinValue);`
- `ES_t DIO_enu_GetPinDir(u8 Copy_u8_PortId, u8 Copy_u8_PinId, u8 *Copy_pu8_ReturnPinDirection);`
- `ES_t DIO_enu_SetPortDirection(u8 Copy_u8_PortId, u8 Copy_u8_PortDirection);`
- `ES_t DIO_enu_SetPortValue(u8 Copy_u8_PortId, u8 Copy_Port_Value);`
- `ES_t DIO_enu_SetPortValue_v2(u8 Copy_u8_PortId, u8 Copy_u8_PortValue);`
- `ES_t DIO_enu_GetPortValue(u8 Copy_u8_PortId, u8 *Copy_pu8_ReturnPortValue);`

---

## Usage
To use any of the drivers, follow these steps:

1. Configure the required settings in the corresponding driver's configuration header file (if available).
2. Include the necessary driver header file in your project.
3. Call the initialization function to initialize the driver.
4. Use the driver's functions to interface with the peripheral.

**Note:** You can easily customize the drivers for your specific setup by changing the configuration settings in the configuration header files. Once the drivers are configured, you can simply change the pins and other settings in the configuration files and start using them in your projects.

I encourage you to follow a layered architecture approach in your project. You can arrange the drivers based on the specific layer they belong to. For example:

- **HAL (Hardware Abstraction Layer):** LCD Driver, Keypad Driver, DC Motor Driver,Stepper Motor Driver
- **MCAL (Microcontroller Abstraction Layer):** Digital I/O Driver
- **SWC (Software Component):** 

Feel free to modify and improve these drivers according to your project's requirements and the specific layer they belong to.

---

## Support and Contact
If you have any questions, issues, or need assistance with using these drivers, feel free to contact us:

- **Email:** [karamyaseen725@gmail.com](mailto:karamyaseen725@gmail.com)
- **GitHub Repository:** [Karam_Yaseen](https://github.com/karamyaseen/karamyaseen)

I'm always here to help you with any problems you may encounter during your project development.
