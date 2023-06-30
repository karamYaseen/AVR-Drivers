#include "../MCAL/DIO/DIO_Interface.h"

#include "../HAL/LCD/LCD_Private.h"
#include "../HAL/LCD/LCD_Confiq.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#define HEART   0
#define ALIEN   1
#define SOUND   2
#define LOCK    3

#define NUM_OF_CHAR 16
int main(void){
DIO_enu_Init();
LCD_enu_Init_8bit_Mode();
u8 Heart[] ={0x00,0x00,0x0a,0x1f,0x1f,0x0e,0x04,0x00};
LCD_enu_CreateCustomChar(LCD_u8_CHAR0,Heart);
u8 Alien[] ={0b00011111,0b00010101,0b00011111,0b00011111,0b00001110,0b00001010,0b00011011,0b00000000};
LCD_enu_CreateCustomChar(LCD_u8_CHAR1,Alien);
u8 Sound[] = {0b00000001,0b00000011,0b00000101,0b00001001,0b00001001,0b00001011,0b00011011,0b00011000};
LCD_enu_CreateCustomChar(LCD_u8_CHAR2,Sound);
u8 Lock[] = {0b00001110,0b00010001,0b00010001,0b00011111,0b00011011,0b00011011,0b00011111,0b00000000};
LCD_enu_CreateCustomChar(LCD_u8_CHAR3,Lock);
int iterator = 0;

u8 switch1_read,switch2_read,switch3_read,switch4_read;
LCD_enu_WriteString(" Lets Play Bro ");
_delay_ms(100);
LCD_enu_Clear();

while(1){
	DIO_enu_GetPinValue(DIO_u8_PORTA, DIO_u8_PIN5, &switch1_read);
	DIO_enu_GetPinValue(DIO_u8_PORTA, DIO_u8_PIN7, &switch2_read);
	DIO_enu_GetPinValue(DIO_u8_PORTC, DIO_u8_PIN5, &switch3_read);
	DIO_enu_GetPinValue(DIO_u8_PORTD, DIO_u8_PIN5, &switch4_read);
	_delay_ms(25);
	if(switch1_read){
		iterator++;
		LCD_enu_WriteCharacter(HEART);
		_delay_ms(25);
	}else if(switch2_read){
		iterator++;
		LCD_enu_WriteCharacter(ALIEN);
		_delay_ms(25);
	}else if(switch3_read){
		iterator++;
		LCD_enu_WriteCharacter(SOUND);
		_delay_ms(25);
	}
	else if(switch4_read==1){
		iterator++;
		LCD_enu_WriteCharacter(LOCK);
		_delay_ms(25);
		}

		/*check line1*/
	if(iterator == (NUM_OF_CHAR+1))
		LCD_enu_GoToXY(1,0);
	/*check for clearing*/
	else if(iterator == (2*NUM_OF_CHAR+1)){
		iterator=0;
		LCD_enu_Clear();

	}
}
	return 0;
}
