/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
typedef volatile unsigned int vuint32_t;


#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(vuint32_t *)(GPIOA_BASE+0x04)
#define GPIOA_ODR *(vuint32_t *)(GPIOA_BASE+0x0C)

#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(vuint32_t *)(RCC_BASE+0x18)
#define GPIOA_RCC 2
#define RCC_CFGR *(vuint32_t *)(RCC_BASE+0x4)
#define RCC_CR *(vuint32_t *)(RCC_BASE+0x0)

#define SWS_SHIFT 0
#define AHB_PRESCALAR_SHIFT 4
#define ABP1_PRESCALAR_SHIFT 8
#define ABP2_PRESCALAR_SHIFT 11
#define PLLSRC_SHIFT 16
#define PLLMUL_SHIFT 18
#define PLLON_SHIFT 24
int main(void)
{
	//SETTING CLOCK
	//SYSTEM CLOCK IS PLL
	RCC_CFGR|=0b10<<SWS_SHIFT;
	//HSI INPUT TO PLL
	RCC_CFGR|=0b0<<PLLSRC_SHIFT;
	//PLL MUL 8
	RCC_CFGR|=0b110<<PLLMUL_SHIFT;
	//AHB PRESCALAR:1
	RCC_CFGR|=0b0<<AHB_PRESCALAR_SHIFT;
	//APB1 4MhZ
	RCC_CFGR|=0b100<<ABP1_PRESCALAR_SHIFT;
	//APB2 2MhZ
	RCC_CFGR|=0b101<<ABP2_PRESCALAR_SHIFT;
	//OPEN PLL CIRCUIT
	RCC_CR|=0b1<<PLLON_SHIFT;
	//GPIOA CLOCK ENABLED
	RCC_APB2ENR|=1<<GPIOA_RCC;


	GPIOA_CRH &=0xFF0FFFFF;
	GPIOA_CRH |=0x00200000;

	while(1)
	{
		GPIOA_ODR|=1<<13;
		for(int i=0;i<5000;i++);
		GPIOA_ODR&=~(1<<13);
		for(int i=0;i<5000;i++);

	}
}
