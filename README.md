# AVR-Drivers
Atmega 32 drivers (Version 1.5)
# Peripheral And Module Drivers For Atmega32
Sure, here's the collected and organized README for the AVR drivers:

# AVR Drivers - README

## Table of Contents
1. [Stepper Motor Driver](#stepper-motor-driver)
2. [LCD Driver](#lcd-driver)
3. [Keypad Driver](#keypad-driver)
4. [DC Motor Driver](#dc-motor-driver)
5. [Digital I/O (DIO) Driver](#digital-io-driver)

---

## Stepper Motor Driver

### Description
The Stepper Motor Driver provides functions to control a stepper motor's movement. It includes initialization, moving the motor to a specified angle and direction, and stopping the motor.

### Functions
| Function Name                      | Description                                          | Input Parameters                          | Output Parameters    |
|------------------------------------|------------------------------------------------------|-------------------------------------------|----------------------|
| StepperMotor_enu_Init              | Initialize the stepper motor driver.                | None                                      | Error State          |
| StepperMotor_enu_Move              | Move the stepper motor to a specified angle and direction. | Copy_u16_STeeperangle (angle value), Copy_u8_STeeperdirection (direction) | Error State          |
| Stepper_enu_Stop                   | Stop the stepper motor.                             | None                                      | Error State          |

---

## LCD Driver

### Description
The LCD Driver provides functions to interface with an LCD in both 8-bit and 4-bit modes. It supports writing characters, strings, numbers, moving the cursor, and creating custom characters on the LCD.

### Functions
| Function Name                      | Description                                          | Input Parameters                          | Output Parameters    |
|------------------------------------|------------------------------------------------------|-------------------------------------------|----------------------|
| LCD_enu_Init_8bit_Mode             | Initialize the LCD in 8-bit mode.                   | None                                      | Error State          |
| LCD_enu_Init_4bit_Mode             | Initialize the LCD in 4-bit mode.                   | None                                      | Error State          |
| LCD_enu_SendCommand                | Send a command to the LCD.                          | Copy_u8_command (LCD command)             | Error State          |
| LCD_enu_WriteCharacter             | Write a single character to the LCD.               | Copy_u8_char (character to be written)    | Error State          |
| LCD_enu_WriteString                | Write a null-terminated string to the LCD.          | Copy_ps8_String (pointer to the string)   | Error State          |
| LCD_enu_WriteSizedString           | Write a string with a specified length to the LCD.  | Copy_ps8_String (pointer to the string), Copy_u8_size (length of the string) | Error State          |
| LCD_enu_WriteNumber                | Write an integer number to the LCD.                 | Copy_u16_Number (number to be written)    | Error State          |
| LCD_enu_WriteSizedNumber           | Write an integer number with a specified number of digits to the LCD. | Copy_u16_Number (number to be written), Copy_u8_size (number of digits) | Error State          |
| LCD_enu_GoToXY                     | Move the cursor to a specified position on the LCD. | Copy_u8_LineNumber (line number), Copy_u8_Location (cursor position) | Error State          |
| LCD_enu_CreateCustomChar           | Create a custom character on the LCD.               | Copy_pu8_Char (array representing the character), Copy_u8_Location (character location) | Error State          |
| LCD_vidClearSpace                  | Clear a range of characters on the LCD.             | Copy_u8_xPosStart (start position), Copy_u8_xPosEnd (end position), Copy_u8_yPos (line number) | Error State          |
| LCD_enu_Clear                      | Clear the entire LCD screen.                        | None                                      | Error State          |

---

## Keypad Driver

### Description
The Keypad Driver provides functions to interface with a keypad and get key press inputs.

### Functions
| Function Name                      | Description                                          | Input Parameters                          | Output Parameters    |
|------------------------------------|------------------------------------------------------|-------------------------------------------|----------------------|
| KPD_enu_GetKey                     | Get a key press from the keypad.                    | Copy_pu8_ReturnKey (pointer to store the key) | Error State          |
| KeyPad_enu_Init                    | Initialize the keypad driver.                       | None                                      | Error State          |

---

## DC Motor Driver

### Description
The DC Motor Driver provides functions to control the rotation of a DC motor. It includes initialization, rotating the motor in a specified direction, and stopping the motor.

### Functions
| Function Name                      | Description                                          | Input Parameters                          | Output Parameters    |
|------------------------------------|------------------------------------------------------|-------------------------------------------|----------------------|
| DC_Motor_enu_Init                  | Initialize the DC motor driver.                     | None                                      | Error State          |
| DC_Motor_enu_Rotate                | Rotate the DC motor in a specified direction.       | Copy_u8_Direction (rotation direction)    | Error State          |
| DC_Motor_enu_Stop                  | Stop the DC motor.                                  | None                                      | Error State          |

---

## Digital I/O (DIO) Driver

### Description
The Digital I/O (DIO) Driver provides functions to initialize, set the direction, set the value, and read the value of digital I/O pins.

### Functions
| Function Name                      | Description                                          | Input Parameters                          | Output Parameters    |
|------------------------------------|------------------------------------------------------|-------------------------------------------|----------------------|
| DIO_enu_Init                       | Initialize the digital I/O pins.                    | None                                      | Error State          |
| DIO_enu_SetPinDirection            | Set the direction of a specific pin.                | Copy_u8_PortId (port ID), Copy_u8_PinId (pin ID), Copy_u8_PinDirection (pin direction) | Error State          |
| DIO_enu_SetPinValue                | Set the value of a specific pin.                    | Copy_u8_PortId (port ID), Copy_u8_PinId (pin ID), Copy_u8_PinValue (pin value) | Error State          |
| DIO_enu_GetPinValue                | Get the value of a specific pin.                    | Copy_u8_PortId (port ID), Copy_u8_PinId (pin ID), Copy_pu8_ReturnPinValue (pointer to store the pin value) | Error State          |
| DIO_enu_GetPinDir                  | Get the direction of a specific pin.                | Copy_u8_PortId (port ID), Copy_u8_PinId (pin ID), Copy_pu8_ReturnPinDirection (pointer to store the pin direction) | Error State          |
| DIO_enu_SetPortDirection           | Set the direction of a whole port.                  | Copy_u8_PortId (port ID), Copy_u8_PortDirection (port direction) | Error State          |
| DIO_enu_SetPortValue               | Set the value of a whole port.                      | Copy_u8_PortId (port ID), Copy_Port_Value   | Error State          |
| DIO_enu_SetPortValue_v2            | Set the value of a whole port (alternative function). | Copy_u8_PortId (port ID), Copy_u8_PortValue | Error State          |
| DIO_enu_GetPortValue               | Get the value of a whole port.                      | Copy_u8_PortId

 (port ID), Copy_pu8_ReturnPortValue (pointer to store the port value) | Error State          |

---

Feel free to update the formatting and content as per your requirements.
