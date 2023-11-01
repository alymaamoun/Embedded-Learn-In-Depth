#ifndef STM32F103X6_GPIO_DRIVER_H_
#define STM32F103X6_GPIO_DRIVER_H_

//includes
#include "stm32f103x6.h"
//=========================

#define SAFE_MODE 0
//Config Struct
typedef struct
{
	uint16_t GPIO_PinNumber 	;	//Specifies the pin number
									//Must be assigned from @ref GPIO_PINS_define

	uint8_t  GPIO_PortNumber    ;	//Specifies the port number
									//Must be assigned from @ref GPIO_PORT_define

	uint8_t  GPIO_Direction     ;	//Specifies the pin direction
									//Must be assigned from @ref GPIO_PORT_define

	uint8_t  GPIO_Resistance    ;	//Specifies the Internal resistance in input mode
									//Must be assigned from @ref GPIO_RESISTANCE_define

	uint8_t  GPIO_OutputMode    ;	//specifies if the output is pushpull or open drain
									//Must be assigned from @ref GPIO_OUTPUTMODE_define

	uint8_t  GPIO_ALTERNATE     ;	//Specifies the operating mode of the selected pin
									//Must be assigned from @ref GPIO_ALTERNATE_define

	uint8_t  GPIO_Output_Speed	;	//Specifies the operating output speed of the selected pin
									//Must be assigned from @ref GPIO_SPEED_define

}GPIO_PinConfig_t;

//Container
#define ConfiguredPins 4
extern GPIO_PinConfig_t GPIO_Configuration[ConfiguredPins];

//================================
//Macros Configuration References
//================================

//@ref GPIO_PINS_define
#define GPIO_PIN_0		((uint64_t)0x0000)	/*Pin 0 selected*/
#define GPIO_PIN_1		((uint64_t)0x0001)	/*Pin 1 selected*/
#define GPIO_PIN_2		((uint64_t)0x0002)  /*Pin 2 selected*/
#define GPIO_PIN_3		((uint64_t)0x0003)  /*Pin 3 selected*/
#define GPIO_PIN_4		((uint64_t)0x0004)  /*Pin 4 selected*/
#define GPIO_PIN_5		((uint64_t)0x0005)  /*Pin 5 selected*/
#define GPIO_PIN_6		((uint64_t)0x0006)  /*Pin 6 selected*/
#define GPIO_PIN_7		((uint64_t)0x0007)  /*Pin 7 selected*/
#define GPIO_PIN_8		((uint64_t)0x0008)  /*Pin 8 selected*/
#define GPIO_PIN_9		((uint64_t)0x0009)  /*Pin 9 selected*/
#define GPIO_PIN_10		((uint64_t)0x000A)  /*Pin 10 selected*/
#define GPIO_PIN_11		((uint64_t)0x000B)  /*Pin 11 selected*/
#define GPIO_PIN_12		((uint64_t)0x000C)  /*Pin 12 selected*/
#define GPIO_PIN_13		((uint64_t)0x000D)  /*Pin 13 selected*/
#define GPIO_PIN_14		((uint64_t)0x000E)  /*Pin 14 selected*/
#define GPIO_PIN_15		((uint64_t)0x000F)  /*Pin 15 selected*/
#define GPIO_PIN_ALL	((uint64_t)0xFFFF)  /*All pins selected*/

#define GPIO_PIN_MASK 	0x0000FFFFu


//@ref GPIO_PORT_define
#define GPIO_PORT_A		((uint16_t)0x0000)	/*Port A selected*/
#define GPIO_PORT_B		((uint16_t)0x0001)	/*Port B selected*/
#define GPIO_PORT_C		((uint16_t)0x0002)  /*Port C selected*/
#define GPIO_PORT_D		((uint16_t)0x0003)  /*Port D selected*/
#define GPIO_PORT_E		((uint16_t)0x0004)  /*Port E selected*/


//@ref GPIO_PORT_define

#define GPIO_PORT_INPUT  0x00000000u	/*INPUT*/
#define GPIO_PORT_OUTPUT 0x00000001u  /*OUTPUT*/

//@ref GPIO_RESISTANCE_define

#define GPIO_RESISTANCE_PULLDOWN 	0x00000000u	/*PULL DOWN INTERNAL RESISTANCE*/
#define GPIO_RESISTANCE_PULLUP	 	0x00000001u	/*PULL UP   INTERNAL RESISTANCE*/
#define GPIO_RESISTANCE_FLOATING	0x00000004u /*FLOATING*/

//@ref GPIO_OUTPUTMODE_define
#define GPIO_OUTPUTMODE_PUSH_PULL	0x00000000u /*PUSH PULL*/
#define GPIO_OUTPUTMODE_OPEN_DRAIN	0x00000004u	/*OPEN DRAIN*/


//@ref GPIO_ALTERNATE_define

#define GPIO_ALTERNATE_DIO		0x00000000u //DIO
#define GPIO_ALTERNATE_ADC		0x00000001u //ADC
#define GPIO_ALTERNATE_ALT		0x00000008u //ALTERNATE PERIPHERAL

//@ref GPIO_SPEED_define
#define GPIO_SPEED_10M			0x00000001u //Output mode, max speed 10Mhz
#define GPIO_SPEED_2M			0x00000002u //Output mode, max speed 2Mhz
#define GPIO_SPEED_50M			0x00000003u //Output mode, max speed 50Mhz


//@ref GPIO_PIN_STATE_define
#define GPIO_PIN_STATE_RESET	0
#define GPIO_PIN_STATE_SET      1

//@ref GPIO_LOCK_RETURN_define
#define GPIO_LOCK_RETURN_ERROR   0
#define GPIO_LOCK_RETURN_ENABLED 1

/*
 * ====================================================================
 * 						APIs Supported by "MCAL GPIO DRIVER"
 * ====================================================================
 */
uint8_t MCAL_GPIO_InitAll(GPIO_PinConfig_t *Container);
uint8_t MCAL_GPIO_Init(GPIO_PinConfig_t* PinConfig);

void MCAL_GPIO_SetDirection(uint8_t Direction);
uint8_t MCAL_GPIO_GetDirection(uint8_t Port,uint16_t Pin);
void MCAL_GPIO_SetResistance(uint8_t Resistance);
uint8_t MCAL_GPIO_GetResistance(uint8_t Port,uint16_t Pin);
void MCAL_GPIO_SetOutputMode(uint8_t OutputMode);
uint8_t MCAL_GPIO_GettOutputMode(uint8_t Port,uint16_t Pin);
void MCAL_GPIO_SetALTERNATE(uint8_t Alternate);
uint8_t MCAL_GPIO_GetALTERNATE(uint8_t Port,uint16_t Pin);
void MCAL_GPIO_SetOutput_Speed(uint8_t OutputSpeed);
uint8_t MCAL_GPIO_GetOutput_Speed(uint8_t Port,uint16_t Pin);

void MCAL_GPIO_DeInit(uint8_t Port);
uint8_t MCAL_GPIO_ReadPin(uint8_t Port,uint16_t Pin);
uint16_t MCAL_GPIO_ReadPort(uint8_t Port);
void MCAL_GPIO_WritePin(uint8_t Port,uint16_t Pin,uint8_t Value);
void MCAL_GPIO_WritePort(uint8_t Port,uint16_t Value);
void MCAL_GPIO_TogglePin(uint8_t Port,uint16_t PinNumber);
void MCAL_GPIO_TogglePort(uint8_t Port);
uint8_t MCAL_GPIO_LockPin(uint8_t Port,uint16_t PinNumber);


#endif
/*
 * typedef struct
{
	uint16_t GPIO_PinNumber 	;	//Specifies the pin number
									//Must be assigned from @ref GPIO_PINS_define

	uint8_t  GPIO_PortNumber    ;	//Specifies the port number
									//Must be assigned from @ref GPIO_PORT_define

	uint8_t  GPIO_Direction     ;	//Specifies the pin direction
									//Must be assigned from @ref GPIO_PORT_define

	uint8_t  GPIO_Resistance    ;	//Specifies the Internal resistance in input mode
									//Must be assigned from @ref GPIO_RESISTANCE_define

	uint8_t  GPIO_OutputMode    ;	//specifies if the output is pushpull or open drain
									//Must be assigned from @ref GPIO_OUTPUTMODE_define

	uint8_t  GPIO_ALTERNATE     ;	//Specifies the operating mode of the selected pin
									//Must be assigned from @ref GPIO_ALTERNATE_define

	uint8_t  GPIO_Output_Speed	;	//Specifies the operating output speed of the selected pin
									//Must be assigned from @ref GPIO_SPEED_define

}GPIO_PinConfig_t;
 */
