/*
 ============================================================================
 Name        : Lab.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void DiagonalLooper(void);


int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	DiagonalLooper();
	return EXIT_SUCCESS;
}

void DiagonalLooper(void)
{
	int loops;
	printf("Enter number of iterations \r\n");
	scanf("%d",&loops);
	for(int i=0;i<loops;i++)
	{
		for(int j=loops;j>i;j--)
		{
			printf("%d ",loops-j+i);
		}
		printf("\n");
	}
}
