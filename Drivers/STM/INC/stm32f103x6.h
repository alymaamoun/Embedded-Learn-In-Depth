#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_


//-----------------------------
//Includes
//-----------------------------

#include "stdlib.h"
#include <stdint.h>

//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BASE 						0x08000000UL
#define SYSTEM_MEMORY_BASE 						0x1FFFF000UL
#define SRAM_MEMORY_BASE 						0x20000000UL
#define PERIPHERLARS_BASE    					0x40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERLARS_BASE 	0xE0000000UL
//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------

//RCC
#define RCC_BASE		(PERIPHERLARS_BASE+0x00021000UL)



//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------
//GPIO
//A,B fully included in LQFP48
#define GPIOA_BASE		(PERIPHERLARS_BASE+0x00010800UL)
#define GPIOB_BASE		(PERIPHERLARS_BASE+0x00010C00UL)
//C,D partially included in LQFP48
#define GPIOC_BASE		(PERIPHERLARS_BASE+0x00011000UL)
#define GPIOD_BASE		(PERIPHERLARS_BASE+0x00011400UL)
//E not included
#define GPIOE_BASE		(PERIPHERLARS_BASE+0x00011800UL)

//EXTI
#define EXTI_BASE		(PERIPHERLARS_BASE+0x00010400UL)

//AFIO
#define AFIO_BASE		(PERIPHERLARS_BASE+0x00010000UL)

//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------


//========================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{

	union
	{
		volatile uint64_t ALL;
		struct
		{
			uint8_t MODE0 :2;
			uint8_t CNF0  :2;
			uint8_t MODE1 :2;
			uint8_t CNF1  :2;
			uint8_t MODE2 :2;
			uint8_t CNF2  :2;
			uint8_t MODE3 :2;
			uint8_t CNF3  :2;
			uint8_t MODE4 :2;
			uint8_t CNF4  :2;
			uint8_t MODE5 :2;
			uint8_t CNF5  :2;
			uint8_t MODE6 :2;
			uint8_t CNF6  :2;
			uint8_t MODE7 :2;
			uint8_t CNF7  :2;
			uint8_t MODE8  :2;
			uint8_t CNF8   :2;
			uint8_t MODE9  :2;
			uint8_t CNF9   :2;
			uint8_t MODE10 :2;
			uint8_t CNF10  :2;
			uint8_t MODE11 :2;
			uint8_t CNF11  :2;
			uint8_t MODE12 :2;
			uint8_t CNF12  :2;
			uint8_t MODE13 :2;
			uint8_t CNF13  :2;
			uint8_t MODE14 :2;
			uint8_t CNF14  :2;
			uint8_t MODE15 :2;
			uint8_t CNF15  :2;
		}fields;
		struct
		{
			volatile uint32_t CRL;
			volatile uint32_t CRH;
		};

	};
}GPIOx_CR;

typedef struct
{
	union
	{
		struct
		{
			uint8_t Bit0:1;
			uint8_t Bit1:1;
			uint8_t Bit2:1;
			uint8_t Bit3:1;
			uint8_t Bit4:1;
			uint8_t Bit5:1;
			uint8_t Bit6:1;
			uint8_t Bit7:1;
			uint8_t Bit8:1;
			uint8_t Bit9:1;
			uint8_t Bit10:1;
			uint8_t Bit11:1;
			uint8_t Bit12:1;
			uint8_t Bit13:1;
			uint8_t Bit14:1;
			uint8_t Bit15:1;
		};
		uint16_t All;
	};
	uint16_t reserved;

}GPIOx_16BitReg;

typedef struct
{
	union
	{
		struct
		{
			uint8_t Bit0:1;
			uint8_t Bit1:1;
			uint8_t Bit2:1;
			uint8_t Bit3:1;
			uint8_t Bit4:1;
			uint8_t Bit5:1;
			uint8_t Bit6:1;
			uint8_t Bit7:1;
			uint8_t Bit8:1;
			uint8_t Bit9:1;
			uint8_t Bit10:1;
			uint8_t Bit11:1;
			uint8_t Bit12:1;
			uint8_t Bit13:1;
			uint8_t Bit14:1;
			uint8_t Bit15:1;
			uint8_t Bit16:1;
			uint8_t Bit17:1;
			uint8_t Bit18:1;
			uint8_t Bit19:1;
			uint8_t Bit20:1;
			uint8_t Bit21:1;
			uint8_t Bit22:1;
			uint8_t Bit23:1;
			uint8_t Bit24:1;
			uint8_t Bit25:1;
			uint8_t Bit26:1;
			uint8_t Bit27:1;
			uint8_t Bit28:1;
			uint8_t Bit29:1;
			uint8_t Bit30:1;
			uint8_t Bit31:1;
		};
		uint32_t All;
	};
}GPIOx_32BitReg;

typedef struct
{
	union
	{
		struct
		{
			uint8_t Bit0:1;
			uint8_t Bit1:1;
			uint8_t Bit2:1;
			uint8_t Bit3:1;
			uint8_t Bit4:1;
			uint8_t Bit5:1;
			uint8_t Bit6:1;
			uint8_t Bit7:1;
			uint8_t Bit8:1;
			uint8_t Bit9:1;
			uint8_t Bit10:1;
			uint8_t Bit11:1;
			uint8_t Bit12:1;
			uint8_t Bit13:1;
			uint8_t Bit14:1;
			uint8_t Bit15:1;
			uint8_t LCKK:1;
			uint16_t reserved:15;

		};
		uint32_t All;
	};
}GPIOx_LCKR;

typedef struct
{
	volatile GPIOx_CR CRL_Plus_CRH;
	volatile GPIOx_16BitReg IDR;
	volatile GPIOx_16BitReg ODR;
	volatile GPIOx_32BitReg BSRR;
	volatile GPIOx_16BitReg BRR;
	volatile GPIOx_LCKR LCKR;
}GPIO_TypeDef;

//typedef struct
//{
//	volatile uint32_t CRL_Plus_CRH;
//	volatile uint32_t IDR;
//	volatile uint32_t ODR;
//	volatile uint32_t BSRR;
//	volatile uint32_t BRR;
//	volatile uint32_t LCKR;
//}GPIO_TypeDef;



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTIRC1;
	volatile uint32_t EXTIRC2;
	volatile uint32_t EXTIRC3;
	volatile uint32_t EXTIRC4;
	volatile uint32_t RESERVED;
	volatile uint32_t MAPR2;



}AFIO_TypeDef;

//=================================================


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA  	((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB  	((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC  	((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD  	((GPIO_TypeDef*)GPIOD_BASE)
#define GPIOE  	((GPIO_TypeDef*)GPIOE_BASE)


#define RCC  	((RCC_TypeDef*)RCC_BASE)

#define EXTI 	((EXTI_TypeDef*)EXTI_BASE)

#define AFIO   	((AFIO_TypeDef*)AFIO_BASE)

//================================================================


//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIOA_CLK_EN() (RCC->APB2ENR |=1<<2)
#define RCC_GPIOB_CLK_EN() (RCC->APB2ENR |=1<<3)
#define RCC_GPIOC_CLK_EN() (RCC->APB2ENR |=1<<4)
#define RCC_GPIOD_CLK_EN() (RCC->APB2ENR |=1<<5)
#define AFIO_GPIO_CLK_EN() (RCC->APB2ENR |=1<<0)



//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define E_NOT_OK 0
#define E_OK 	 1


#endif
