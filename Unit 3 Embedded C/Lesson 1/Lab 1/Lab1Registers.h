/*
 * Lab1Registers.h
 *
 *  Created on: Apr 27, 2023
 *      Author: user
 */

#ifndef LAB1REGISTERS_H_
#define LAB1REGISTERS_H_
#include "Platform_Types.h"


#define PORTA_BASEADDRESS 0x40010800
#define RCC_BASEADDRESS   0x40021000
#define RCC_APB2ENR       *(volatile uint32*)(RCC_BASEADDRESS+0x18)
#define PORTA_CRH         *(volatile uint32*)(PORTA_BASEADDRESS+0x04)
#define PORTA_ODR         *(volatile uint32*)(PORTA_BASEADDRESS+0x0C)

typedef union
{
	vuint32_t AllPins;
	struct
	{
		vuint32_t pin0:1;
		vuint32_t pin1:1;
		vuint32_t pin2:1;
		vuint32_t pin3:1;
		vuint32_t pin4:1;
		vuint32_t pin5:1;
		vuint32_t pin6:1;
		vuint32_t pin7:1;
		vuint32_t pin8:1;
		vuint32_t pin9:1;
		vuint32_t pin10:1;
		vuint32_t pin11:1;
		vuint32_t pin12:1;
		vuint32_t pin13:1;
		vuint32_t pin14:1;
		vuint32_t pin15:1;
		vuint32_t pin16:1;
		vuint32_t pin17:1;
		vuint32_t pin18:1;
		vuint32_t pin19:1;
		vuint32_t pin20:1;
		vuint32_t pin21:1;
		vuint32_t pin22:1;
		vuint32_t pin23:1;
		vuint32_t pin24:1;
		vuint32_t pin25:1;
		vuint32_t pin26:1;
		vuint32_t pin27:1;
		vuint32_t pin28:1;
		vuint32_t pin29:1;
		vuint32_t pin30:1;
		vuint32_t pin31:1;


	}pin;
}R_ODR;

volatile  R_ODR * R_ODR_t =(volatile R_ODR*)(PORTA_BASEADDRESS+0x0C);


#endif /* LAB1REGISTERS_H_ */
