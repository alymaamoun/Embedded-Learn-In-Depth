//startup.c
//Aly Maamoun
#include <stdint.h>
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
	main();
}

void Default_Handler ()
{
	Reset_Handler();
}
