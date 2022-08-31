/*
 ============================================================================
 Name        : LectureWorkOuts.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void function();
void StringCopy(char* String1,char *String2 , int len1,int len2);
int StringLength(char * String);
void StringCat(char * String1 , char *String2 , char spaces);
int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	//function();
	char text1[]="Ahmed";
	char text2[]="Alaa";
	StringCat(&text1,&text2,1);
	printf("%s",text1);
	return EXIT_SUCCESS;
}

void function()
{
	int arr[]={1,2,3,4,5,6,7,8,9,0};
	for(int i=0;i<10;i++)
	{

		printf("%d\r\n",*(arr+i));
		printf("%d\r\n",arr[i]);
	}
}
void StringCopy(char* String1,char* String2 , int len1,int len2)
{
	int len=(len1>len2)?len1:len2;
	int i;
	for(i=0; i<len && String1[i]!=0 ;i++)
	{
		String2[i]=String1[i];
	}
	String2[i+1]=0;
}
int StringLength(char * String)
{
	int length=0 , i=0;
	while(String[i]!=0)
	{
		length++;
		i++;
	}
	length++;
	return length;
}
void StringCat(char * String1 , char * String2 , char spaces)
{
	int i , j;
	for(i=0 ; String1[i]!=0;i++)
	{

	}
	if(spaces)
	{
		String1[i]=' ';
		i++;
	}
	for(j=0;String2[j]!=0;i++,j++)
	{
		String1[i]=String2[j];
	}
	String1[i+1]=0;
}
