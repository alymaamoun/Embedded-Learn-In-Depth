#include "uart.h"


#define New_Reg_M(Address,Offset,size) *((volatile size * const)((size*)(Address+Offset)))

#define UART0DR_T New_Reg_M(0x101f1000,0,unsigned int)


void Uart_Send_String(unsigned char* P_Tx_String)
{
	while(*P_Tx_String!='\0')
	{
		UART0DR_T=(unsigned int)(*P_Tx_String);
		P_Tx_String++;
	}
} 