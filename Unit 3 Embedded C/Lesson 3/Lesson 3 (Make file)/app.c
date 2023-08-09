#include "uart.h"
unsigned char string_buffer[100]="learn-in-depth:Aly Maamooun";
void main(void)
{
	Uart_Send_String(string_buffer);
}