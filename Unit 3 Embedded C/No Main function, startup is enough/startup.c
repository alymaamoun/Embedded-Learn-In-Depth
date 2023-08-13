//startup.c
//Aly Maamoun
#include <stdint.h>


#include <stdint.h>

#define CPU_TYPE CPU_TYPE_16
#define CPU_BIT_ORDER LSB_FIRST
#define CPU_BYTE_ORDER HIGH_BYTE_FIRST

typedef unsigned char boolean;
typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef int8_t   sint8;
typedef int16_t  sint16;
typedef int32_t  sint32;
typedef int64_t  sint64;

typedef uint8  uint8_least;
typedef uint16 uint16_least;
typedef uint32 uint32_least;
typedef uint64 uint64_least;
typedef sint8  sint8_least;
typedef sint16 sint16_least;
typedef sint32 sint32_least;
typedef sint64 sint64_least;


typedef volatile sint8  vint8_t;
typedef volatile uint8  vuint8_t;
typedef volatile sint16 vint16_t;
typedef volatile uint16 vuint16_t;
typedef volatile sint32 vint32_t;
typedef volatile uint32 vuint32_t;
typedef volatile sint64 vint64_t;
typedef volatile uint64 vuint64_t;

typedef double float32;
typedef long double float64;

typedef void* VoidPtr;
typedef const void* ConstVoidPtr;

//typedef enum {CPU_TYPE_8,CPU_TYPE_16,CPU_TYPE_32,CPU_TYPE_64}CPU_TYPE_;
//typedef enum {MSB_FIRST,LSB_FIRST}CPU_BIT_ORDER_;
//typedef enum {HIGH_BYTE_FIRST,LOW_BYTE_FIRST}CPU_BYTE_ORDER_;
typedef enum {FALSE,TRUE}TRUE_FALSE;


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


#define STACK_START_SP 0x20001000
extern int main(void);
extern unsigned int _E_TEXT;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;
extern unsigned int _STACK_TOP;

void Default_Handler();
void Reset_Handler ();
void NMI_Handler () __attribute__((weak,alias("Default_Handler")));
void HardFault_Handler () __attribute__((weak,alias("Default_Handler")));


static unsigned long Stack_top[256];


void  (*const g_p_fn_Vectors[])() __attribute__((section(".vectors")))={
	(void(*)())((unsigned long)Stack_top+sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&HardFault_Handler
}; 

void Reset_Handler()
{
	//copy data section from flash to RAM

	unsigned int DATA_size= ((unsigned char*)&_E_DATA-(unsigned char*)&_S_DATA);
	unsigned char* P_src=(unsigned char*)&_E_TEXT;
	unsigned char* P_dst=(unsigned char*)&_S_DATA;
	for(int i=0;i<DATA_size;i++)
	{
		*((unsigned char*)P_dst++)=*((unsigned char*)P_src++);
	}

	//init bss in sram

	unsigned int BSS_size= ((unsigned char*)&_E_BSS-(unsigned char*)&_S_BSS);
	P_dst=(unsigned char*)&_S_BSS;
	for(int i=0;i<BSS_size;i++)
	{
		*((unsigned char*)P_dst++)=(unsigned char)0;
	}
	//jump to main
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
}

void Default_Handler ()
{
	Reset_Handler();
}
