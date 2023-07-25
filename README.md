# AVR ATmega32 Driver Repository

## Overview
This repository contains a collection of drivers and utilities for the AVR ATmega32 microcontroller. The drivers are designed to provide low-level hardware abstraction and modularity, making them easy to integrate into your projects. The repository also includes three projects that demonstrate the usage of these drivers.

## Projects

### 1. Smart Login System
A simple login system implemented using a 4x4 Keypad for entering the password. Users are prompted to enter a 4-digit password. If the entered password matches the correct password, the system grants access. Otherwise, the user has three attempts before the system locks.

### 2. Smart Login System With DC & Stepper Motors
An extension of the Smart Login System, this project allows users to choose between controlling a DC motor or a stepper motor after successful login. Users can specify the direction of rotation for the DC motor and the angle of rotation for the stepper motor.

### 3. Custom Characters
This project demonstrates how to create and use custom characters on an LCD. It showcases the flexibility of the LCD driver and how you can create custom characters to display unique symbols on the screen.

## Layer Architecture

### MCAL (Microcontroller Abstraction Layer)
The MCAL layer provides low-level drivers that abstract the hardware-specific operations of the ATmega32 microcontroller.

#### DIO (Digital Input/Output)
- `DIO_enu_Init`: Initializes the Digital Input/Output pins.
- `DIO_enu_SetPinDirection`: Sets the direction of a specific pin as Input or Output.
- `DIO_enu_SetPinValue`: Sets the value (HIGH or LOW) of a specific pin.
- `DIO_enu_GetPinValue`: Reads the value of a specific pin.
- `DIO_enu_GetPinDir`: Reads the direction (Input or Output) of a specific pin.
- `DIO_enu_SetPortDirection`: Sets the direction of a whole port as Input or Output.
- `DIO_enu_SetPortValue`: Sets the value (0 to 255) of a whole port.
- `DIO_enu_GetPortValue`: Reads the value of a whole port.

### HAL (Hardware Abstraction Layer)
The HAL layer provides higher-level drivers that abstract the hardware-specific operations of the components used in the projects.

#### LCD (Liquid Crystal Display)
- `LCD_enu_Init_8bit_Mode`: Initializes the LCD in 8-bit mode.
- `LCD_enu_Init_4bit_Mode`: Initializes the LCD in 4-bit mode.
- `LCD_enu_SendCommand`: Sends a command to the LCD.
- `LCD_enu_WriteCharacter`: Writes a character to the LCD.
- `LCD_enu_WriteString`: Writes a string to the LCD.
- `LCD_enu_WriteSizedString`: Writes a string with a specific size to the LCD.
- `LCD_enu_WriteNumber`: Writes a number to the LCD.
- `LCD_enu_WriteSizedNumber`: Writes a number with a specific size to the LCD.
- `LCD_enu_GoToXY`: Sets the cursor to a specific location on the LCD.
- `LCD_enu_CreateCustomChar`: Creates a custom character and displays it on the LCD.
- `LCD_vidClearSpace`: Clears a specific space on the LCD.
- `LCD_enu_Clear`: Clears the LCD display.

#### KPD (Keypad)
- `KPD_enu_GetKey`: Reads the key pressed on the keypad.

### SWC (Software Components)
The SWC layer provides software components that combine multiple drivers to implement specific functionalities.

#### Smart Login System
- `SmartLoginSystem_Init`: Initializes the system for the smart login project.
- `SmartLoginSystem_Run`: Runs the smart login system.

#### DC Motor
- `DC_Motor_enu_Init`: Initializes the DC motor driver.
- `DC_Motor_enu_Rotate`: Rotates the DC motor in a specific direction.
- `DC_Motor_enu_Stop`: Stops the DC motor.

#### Stepper Motor
- `StepperMotor_enu_Init`: Initializes the stepper motor driver.
- `StepperMotor_enu_Move`: Moves the stepper motor to a specified angle and direction.
- `Stepper_enu_Stop`: Stops the stepper motor.

## App Architecture
The app architecture follows a modular approach, with separate projects showcasing different functionalities using the provided drivers.

1. **Smart Login System**:
   - The main function initializes the drivers and runs the smart login system.
   - Users can interact with the system using the 4x4 Keypad to enter the password.
   - The system validates the entered password and grants access upon successful login.
   - If the password is incorrect, the user has three attempts before the system locks.

2. **Smart Login System With DC & Stepper Motors**:
   - After successful login, the user can choose between controlling a DC motor or a stepper motor.
   - For the DC motor, the user can specify the rotation direction (CW or CCW).
   - For the stepper motor, the user can specify the angle of rotation.
   - The system provides options to stop the motors during operation.

3. **Custom Characters**:
   - The project demonstrates how to create and display custom characters on the LCD.
   - Users can create unique symbols and display them on the screen using the LCD driver.

## Simulations
Simulations for the projects can be found in the "simulate" folder. Each project has its own simulation to demonstrate the functionality of the drivers.

## Usage
To use the drivers, simply include the necessary header files in your project and configure the appropriate pins and settings in the "MCAL/DIO/DIO_Config.h" and "HAL/LCD/LCD_Config.h" files according to your hardware setup. You can then call the functions provided by the drivers to control the peripherals.

## Contact
If you encounter any issues or have any questions, feel free to connect with me at [karamyaseen725@gmail.com](mailto:karamyaseen725@gmail.com). I'm happy to assist you with using the drivers in your projects!

## License
This software is released under the [MIT License](https://opensource.org/licenses/MIT), which means you are free to use, modify, and distribute the software as you see fit.

Happy coding and enjoy building exciting projects with your AVR ATmega32 microcontroller! 🚀🔧
