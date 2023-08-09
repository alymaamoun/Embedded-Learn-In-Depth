# 1 "uart.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "uart.c"
# 1 "uart.h" 1


void Uart_Send_String(unsigned char* P_Tx_String);
# 2 "uart.c" 2







void Uart_Send_String(unsigned char* P_Tx_String)
{
 while(*P_Tx_String!='\0')
 {
  *((volatile unsigned int * const)((unsigned int*)(0x101f1000 +0)))=(unsigned int)(*P_Tx_String);
  *((volatile unsigned int * const)((unsigned int*)(0x101f1000 +0)))=(unsigned int)(*P_Tx_String);
  P_Tx_String++;
 }
}
