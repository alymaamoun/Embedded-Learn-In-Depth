/*
 ============================================================================
 Name        : HomeWork2.c
 Author      : Aly Maamoun
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
void EX8(void);

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
	//EX8();
	return EXIT_SUCCESS;
}

void EX1(void)
{
	int Input;
	printf("Enter an integer you want to check: \r\n");
	scanf("%d",&Input);
	if(Input%2)
	{
		printf("%d is odd.",Input);
	}
	else
	{
		printf("%d is Even.",Input);
	}
}
void EX2(void)
{
	//97  65  101  69  105  73  111  79  117  85
	//printf("%d  %d  %d  %d  %d  %d  %d  %d  %d  %d  ", 'a','A','e','E','i','I','o','O','u','U');
	char Input;
	printf("Enter an alphabet \r\n");
	scanf("%c",&Input);
	if((Input==97)||(Input==65)||(Input==101)||(Input==69)||(Input==105)||(Input==73)||(Input==111)||(Input==79)||(Input==117)||(Input==85))
	{
		printf("%c is a vowel",Input);
	}
	else
	{
		printf("%c is a consonant",Input);
	}
}
void EX3(void)
{
	float Value1,Value2,Value3;
	printf("Enter three numbers \r\n");
	scanf("%f %f %f",&Value1,&Value2,&Value3);
	if(Value1>Value2)
	{
		if(Value1>Value3)
		{
			printf("Largest number = %f",Value1);
		}
		else
		{
			printf("Largest number = %f",Value3);
		}
	}
	else
	{
		if(Value2>Value3)
		{
			printf("Largest number = %f",Value2);
		}
		else
		{
			printf("Largest number = %f",Value3);
		}
	}
}
void EX4(void)
{
	float Input;
	printf("Enter a number \r\n");
	scanf("%f", &Input);
	(Input>=0)?printf("%f is positive",Input):printf("%f is negative",Input);
}
void EX5(void)
{
	//97  122   65   90
	//printf("%d  %d   %d   %d  ",'a','z','A','Z');
	char Input;
	printf("Enter a character \r\n");
	scanf("%c",&Input);
	(((Input>=97)&&(Input<=122))||((Input>=65)&&(Input<=90)))?printf("%c is an alphabet",Input):printf("%c is not an alphabet",Input);


}
void EX6(void)
{
	int count , sum=0;
	printf("Enter an integer: \r\n");
	scanf("%d",&count);
	for(int loop=0 ;loop<=count;loop++)
	{
		sum=sum+loop;
	}
	printf("Sum = %d", sum);
}
void EX7(void)
{
	{
		int count , sum=1;
		printf("Enter an integer: \r\n");
		scanf("%d",&count);
		if(count<0)
		{
			printf("Number is negative , there's no factorial for negative numbers");
			return;
		}
		for(int loop=1 ;loop<=count;loop++)
		{
			sum=sum*loop;
		}
		printf("Factorial = %d", sum);
	}
}
void EX8(void)
{
	char Operation;
	float Value1,Value2,result;
	printf("Enter operation either + or - or * or / : \r\n");
	scanf("%c",&Operation);
	if((Operation!='+')&&(Operation!='-')&&(Operation!='*')&&(Operation!='/'))
	{
		printf("invalid operation");
		return;
	}
	printf("Enter two operands: \r\n");
	scanf("%f %f",&Value1,&Value2);
	switch(Operation)
	{
	case '+':
		result=Value1+Value2;
		break;
	case '-':
		result=Value1-Value2;
		break;
	case '*':
		result=Value1*Value2;
		break;
	case '/':
		result=Value1/Value2;
		break;
	default:
		printf("invalid operation");
		return;
	}
	printf("%f %c %f = %f",Value1,Operation,Value2,result);
}
