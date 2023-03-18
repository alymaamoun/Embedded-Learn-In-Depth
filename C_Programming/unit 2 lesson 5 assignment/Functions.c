/*
 * main.c
 *
 *  Created on: Mar 18, 2023
 *      Author: Aly Maamoun
 */

#include <stdio.h>

void Function1Prime(int   Base, int Max	 );
int  Function2Fac  (int   Number		 );
void Function3Rev  (char* Sent, int indx );
int  Function4Pow  (int   Base, int Power);

void Function1Test(void);
void Function2Test(void);
void Function3Test(void);
void Function4Test(void);

void Program(void);

int main(void)
{		setvbuf(stdout,NULL,_IONBF,0);
		setvbuf(stderr,NULL,_IONBF,0);
		Program();
}

void  Function1Prime(int   Base, int Max	)
{
	char init=0;
	int Loop=Base;
	for(;Loop<=Max;Loop++)
	{
		int Temp=2;
		char Flag=1;
		for(;Temp<(Loop/2 +1);Temp++)
		{
			if(Loop%Temp==0)
			{
				Flag=0;
				break;
			}
		}
		if(Flag)
		{
			if(!init)
			{
				printf("Prime numbers between %d and %d are: ",Base,Max);
				init=1;
			}
			printf("%d ",Loop);

		}
	}
	if(!init)
	{
		printf("No prime numbers between %d and %d",Base,Max);
	}
}
void  Function1Test(void)
{
	printf("Function 1 Test\n");
	int base,max;
	printf("Enter two numbers(interval)\n");
	scanf("%d",&base);
	scanf("%d",&max);
	Function1Prime(base,max);
}
int   Function2Fac  (int   Number			)
{
	if(Number>1)
	{
		return Number*Function2Fac(Number-1);
	}
	else
	{
		return Number;
	}
}
void  Function2Test(void)
{
	printf("Function 2 Test\n");
	printf("Enter a positive integer:\n");
	int Number;
	scanf("%d",&Number);
	printf("Factorial of %d = %d",Number,Function2Fac(Number));

}
void  Function3Rev  (char* Sent, int indx	)
{

	if(Sent[indx+1]!=0)
	{
		Function3Rev(Sent,indx+1);
	}

		printf("%c",Sent[indx]);

}
void Function3Test(void)
{
	printf("Function 3 Test\n");
	printf("Enter a sentence:\n");
	char Sent[100];
	gets(Sent);
	Function3Rev(Sent,0);
}
int  Function4Pow  (int   Base, int Power)
{
	if(Power!=1)
		return Base * Function4Pow(Base,Power-1);
	else
		return Base;
}
void Function4Test(void)
{
	printf("Function 4 Test\n");
	int base,pow;
	printf("Enter base number: \n");
	scanf("%d",&base);
	printf("Enter Power number: \n");
	scanf("%d",&pow);
	printf("%d ^ %d = %d",base, pow,Function4Pow(base,pow));
}

void Program(void)
{
	printf("Welcome to Functions assignment! \n");
	char Continue =0 ;
	do
	{

		printf("Choose the function you want to test \n");
		printf("1- Prime Number Between two intervals by Making User-defined Function \n");
		printf("2- C Program to Calculate Factorial of a Number using Recursion\n");
		printf("3- C Program to Reverse a Sentence Using Recursion\n");
		printf("4- C Program to Calculate the Power of a Number Using Recursion\n");
		char UserOption;
		scanf("%d",&UserOption);
		switch(UserOption)
		{
		case 1:
			Function1Test();
			break;
		case 2:
			Function2Test();
			break;
		case 3:
			Function3Test();
			break;
		case 4:
			Function4Test();
			break;
		default :
			printf("Wrong choose!\n");
			Program();
		}
		printf("\nDo You want to continue? (press 0 or 1)\n");
		scanf("%d",&Continue);
		}


	while(Continue);
}
