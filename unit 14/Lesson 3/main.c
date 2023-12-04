/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "STM32F103x8.h"
#include "stm32f103x8_gpio_driver.h"
#include "lcd.h"
#include "keypad.h"
#include "stm32f103x8_EXTI_driver.h"
#include "stm32f103x8_USART_driver.h"
#include "stm32f103x8_SPI_driver.h"
#include "stm32f103x8_I2C_driver.h"
#include "I2C_Slave_EEPROM.h"


 uint8_t IRQ_Flag = 0;

 typedef enum
 {
	 Privileged,
	 Unprivileged
 }CPUAccessLevel;

 void SWITCH_CPU_ACCESSLEVEL(CPUAccessLevel level)
 {
	 switch(level)
	 {
	 case Privileged:
		 //reset bit 0 in Control register
		 __asm("mrs r3,CONTROL");
		 __asm("lsr r3,r3,#0x1");
		 __asm("lsl r3,r3,#0x1");
		 __asm("msr CONTROL,r3");
		 break;

	 case Unprivileged:
		 //set bit 0 in Control register
		 __asm("mrs r3,CONTROL");
		 __asm("orr r3,r3,#0x1");
		 __asm("msr CONTROL,r3");
		 break;
	 }
 }


void EXTI9_CALLBACK(void)
{
	IRQ_Flag = 1;
	SWITCH_CPU_ACCESSLEVEL(Privileged);
}
int VAL0=0;
int VAL1=3;//for inline assembly
int VAL2=7;//for inline assembly
int VAL3=0;//for inline assembly
int main(void)
{
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	//Set EXTI Configuration
	EXTI_PinConfig_t EXTIConfig;
	EXTIConfig.EXTI_PIN = EXTI9PB9;
	EXTIConfig.Trigger_Case = EXTI_Trigger_RISING;
	EXTIConfig.P_IRQ_CallBack = EXTI9_CALLBACK;
	EXTIConfig.IRQ_EN = EXTI_IRQ_Enable;
	MCAL_EXTI_GPIO_Init(&EXTIConfig);



	IRQ_Flag = 1;
	SWITCH_CPU_ACCESSLEVEL(Unprivileged);

	__asm("nop \n\t nop \n\t nop");
	__asm("mov %0,#0xFF"
			:"=r"(VAL0));//first: output parameters
	__asm("nop \n\t nop \n\t nop");
	__asm("mov R0,%0 "
		:			//first: output parameters
		:"r"(VAL0));//second: input parameters
	__asm("nop \n\t nop \n\t nop");


//	__asm("add %0,%1,%2"
//			:"=r"(VAL3)
//			:"r"(VAL1),"r"(VAL2));
	__asm("add %[out1],%[in0],%[in1]"
			: [out1] "=r" (VAL3)
			: [in0] "r"   (VAL1),
			  [in1] "r"   (VAL2)
			:"r3","r2","r1");


	__asm("nop \n\t nop \n\t nop");
	__asm("MRS %[out1],CONTROL"
			:[out1] "=r" (VAL0));
	__asm("nop \n\t nop \n\t nop");
	while (1)
	{
		if(IRQ_Flag)
		{
			IRQ_Flag = 0;
		}
		else { /* Misra */ }
	}


}
