/*
 * Mem_Map.h
 *
 *  Created on: Jul 10, 2023
 *      Author: user
 */

#ifndef MEM_MAP_H_
#define MEM_MAP_H_
#include "Platform_types.h"


#define New_Reg_M(Address,Offset,size) (*((volatile size * const)((size *)(Address+Offset))))

#define SYSCTL_RCG_ADDRESS     0x400FE000
#define SYSCTL_RCGC2_OFFSET    0x108
#define GPIO_PORTF_ADDRESS     0x40025000
#define GPIO_PORTF_DIR_OFFSET  0x400
#define GPIO_PORTF_DATA_OFFSET 0x3FC
#define GPIO_PORTF_DEN_OFFSET  0x51C

#define SYSCTL_RCGC2_R    New_Reg_M(SYSCTL_RCG_ADDRESS,SYSCTL_RCGC2_OFFSET,uint32)
#define GPIO_PORTF_DIR_R  New_Reg_M(GPIO_PORTF_ADDRESS,GPIO_PORTF_DIR_OFFSET,uint32)
#define GPIO_PORTF_DATA_R New_Reg_M(GPIO_PORTF_ADDRESS,GPIO_PORTF_DATA_OFFSET,uint32)
#define GPIO_PORTF_DEN_R  New_Reg_M(GPIO_PORTF_ADDRESS,GPIO_PORTF_DEN_OFFSET,uint32)





#endif /* MEM_MAP_H_ */
