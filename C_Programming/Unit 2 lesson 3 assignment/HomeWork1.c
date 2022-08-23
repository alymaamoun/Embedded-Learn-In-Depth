/*
 ============================================================================
 Name        : HomeWork1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void EX1(void);
void EX2(void);
void EX3(void);
void EX4(void);
void EX5(void);
void EX6(void);
void EX7(void);

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	//EX1();
	//EX2();
	//EX3();
	//EX4();
	//EX5();
	//EX6();
	//EX7();

}

void EX1(void)
{
	printf("C Programming");
}
void EX2(void)
{
	int value;
	printf("Enter an integer \r\n");
	scanf("%d",&value);
	printf("You entered %d",value);
}
void EX3(void)
{
	int Value1,Value2;
	printf("Enter two integer \r\n");
	scanf("%d %d" ,&Value1, &Value2);
	printf("Sum is %d",Value1+Value2);
}
void EX4(void)
{
	float Value1,Value2;
	printf("Enter two numbers \r\n");
	scanf("%f %f",&Value1 , &Value2);
	printf("Product: %f" ,Value1*Value2);
}
void EX5(void)
{
	char input;
	printf("Enter a character \r\n");
	scanf("%c",&input);
	printf("ASCII value of %c = %d",input,input);
}
void EX6(void)
{
	float Value1,Value2;
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	printf("Enter value of a \r\n");
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	scanf("%f",&Value1);
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	printf("Enter value of b \r\n");
	scanf("%f",&Value2);
	float temp = Value1;
	Value1 = Value2;
	Value2= temp;
	printf("After swapping, value of a= %f \r\n",Value1);
	printf("After swapping, value of b= %f \r\n",Value2);
}
void EX7(void)
{
	float Value1,Value2;
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	printf("Enter value of a \r\n");
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	scanf("%f",&Value1);
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	printf("Enter value of b \r\n");
	scanf("%f",&Value2);
	Value1+=Value2;
	Value2=Value1-Value2;
	Value1=Value1-Value2;
	printf("After swapping, value of a= %f \r\n",Value1);
	printf("After swapping, value of b= %f \r\n",Value2);
}
