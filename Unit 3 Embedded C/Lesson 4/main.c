/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Aly Maamoun
 * @brief          : Main program body
 ******************************************************************************
 */

#include "Platform_types.h"
#include "Mem_Map.h"




int main(void)
{
	volatile uint32 delay=0;
	SYSCTL_RCGC2_R=(uint32)0x20;
	//delay to power on port f
	for(delay=0;delay<200;delay++);
	GPIO_PORTF_DIR_R|=1<<3;
	GPIO_PORTF_DEN_R|=1<<3;
	while(1)
	{
		GPIO_PORTF_DATA_R|=1<<3;
		for(delay=0;delay<20000;delay++);
		GPIO_PORTF_DATA_R&=~(1<<3);
		for(delay=0;delay<20000;delay++);
	}

	return 0;
}
