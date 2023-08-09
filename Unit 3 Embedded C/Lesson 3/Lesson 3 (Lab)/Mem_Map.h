/*
 * Mem_Map.h
 *
 *  Created on: Jul 10, 2023
 *      Author: user
 */

#ifndef MEM_MAP_H_
#define MEM_MAP_H_
#include "Platform_types.h"

#define RCC_BASE_ADDRESS   	0x40021000
#define RCC_APB2ENR_OFFSET 	0x18
#define RCC_APB2ENR_ADDRESS RCC_BASE_ADDRESS+RCC_APB2ENR_OFFSET
#define PortA_Base_ADDRESS 	0x40010800
#define PortA_CRH_OFSSET   	0x04
#define PortA_ODR_OFFSET   	0x0C
#define PortA_ODR_ADDRESS	PortA_Base_ADDRESS+PortA_ODR_OFFSET
#define PortA_CRH_ADDRESS	PortA_Base_ADDRESS+PortA_CRH_OFSSET
#define RCC_APB2ENR 		*((volatile uint32 *)(RCC_APB2ENR_ADDRESS))
#define PortA_CRH   		*((volatile uint32 *)(PortA_CRH_ADDRESS))
#define PortA_ODR   		*((volatile uint32 *)(PortA_ODR_ADDRESS))

typedef union
{
	volatile uint16 AllPins;
	struct
	{
		vuint32_t Pin0:1;
		vuint32_t Pin1:1;
		vuint32_t Pin2:1;
		vuint32_t Pin3:1;
		vuint32_t Pin4:1;
		vuint32_t Pin5:1;
		vuint32_t Pin6:1;
		vuint32_t Pin7:1;
		vuint32_t Pin8:1;
		vuint32_t Pin9:1;
		vuint32_t Pin10:1;
		vuint32_t Pin11:1;
		vuint32_t Pin12:1;
		vuint32_t Pin13:1;
		vuint32_t Pin14:1;
		vuint32_t Pin15:1;

	}pin;
}PortA_Data;


typedef union
{
	volatile uint32 AllPins;
	struct
	{
		vuint8_t Pin8:4;
		vuint8_t Pin9:4;
		vuint8_t Pin10:4;
		vuint8_t Pin11:4;
		vuint8_t Pin12:4;
		vuint8_t Pin13:4;
		vuint8_t Pin14:4;
		vuint8_t Pin15:4;
	}pin;
}PortA_Mode;

volatile PortA_Data * PORTA_Data=(volatile PortA_Data *)(PortA_ODR_ADDRESS);
volatile PortA_Mode * PORTA_Mode=(volatile PortA_Mode *)(PortA_CRH_ADDRESS);



#endif /* MEM_MAP_H_ */
