/*
 ============================================================================
 Name        : HomeWork3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void MatrixFiller(int *  Matrix  ,int row , int coloumn);
void MatrixPrinter(int *  Matrix  ,int row , int coloumn);
void MatrixTranspose(int * Matrix , int row , int coloumn);
void ArrayShifter(int *array,int len , int index, int number);
void ArrayPrinter(int *arr , int len);
int  ArraySearch (int *arr , int len , int number );
int  CharFrequency (char * str , char target);
char isInteger(double val);
int StringLength(char * str );
void StringMirror(char *str );
void  Ex1(int *  Matrix1,int *  Matrix2,int *  Result, int row , int coloumn);
float Ex2(float * arr,int len);
void  Ex3(int * arr, int row , int coloumn);
void  EX4(int * arr, int len , int number , int index);
int   Ex5(int * arr, int len );
int   Ex6 (char * str );
int   Ex7 (char * str );
void   Ex8 (char * str );

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	//int matrix1[2][2];
	//int matrix2[2][2];
	//int matrix3[2][2];
	//MatrixFiller((int*) matrix1 ,2,2);
	//MatrixFiller((int*) matrix2 ,2,2);
	//Ex1((int *) matrix1,(int *)matrix2,(int * ) matrix3, 2 , 2);
	//MatrixPrinter((int*) matrix3 ,2,2);
	//float arr[100];
	//float x=Ex2((float*)arr, 7);
	//printf("Average = %f",x);
	//int Matrix[100][100];
	//Ex3((int*)Matrix,100,100);
	//int arr[10]={1,2,3,5,6};
	//int index=Ex5( (int*) arr,  10  );
	//printf("\nindex is %d",index);
	char string[200]="";
	//int length=Ex7((char*)string);
	Ex8((char*)string);
	printf("\String is %s",string);

	return 1 ;
}

void MatrixFiller(int * Matrix  ,int row , int coloumn)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<coloumn;j++)
		{
			printf("Enter M[%d][%d]\n",i,j);
			setvbuf(stdout,NULL,_IONBF,0);
			setvbuf(stderr,NULL,_IONBF,0);
			scanf("%d",((Matrix+i*coloumn)+j));
			printf("Entered value for M[%d][%d] is %d \n",i,j,*((Matrix+i*coloumn)+j));
			setvbuf(stdout,NULL,_IONBF,0);
			setvbuf(stderr,NULL,_IONBF,0);

		}
	}
}
void Ex1(int *  Matrix1,int *  Matrix2,int *  Result, int row , int coloumn)
{
	for(int i =0 ;i <row ; i++)
	{
		for(int j=0 ; j< coloumn ;j++)
		{
			*((Result+i*coloumn)+j)=*((Matrix1+i*coloumn)+j)+*((Matrix2+i*coloumn)+j);
		}
	}
}
void MatrixPrinter(int *  Matrix  ,int row , int coloumn)
{

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<coloumn;j++)
		{
			printf("%d\t",*((Matrix+i*coloumn)+j));
		}
		printf("\n");
	}
}
float Ex2(float * arr,int len)
{
	int items;
	printf("Enter the number of data: ");
	scanf("%d",&items);
	if(items>len)
	{
		printf("\nToo much items!");
		return -1;
	}
	for(int i=0;i<items;i++)
	{
		printf("\nEnter the number %d: ",i+1);
		scanf("%f",(arr+i));
	}
	float average=*(arr+0);
	for(int i=1; i<items ;i++ )
	{
		average+=(*(arr+i));
	}
	average=average/(float)items;
	return average;
}
void MatrixTranspose(int * Matrix , int row , int coloumn)
{
	/*
	 * M[0][0]	M[0][1]	M[0][2]
	 * M[1][0]	M[1][1]	M[1][2]
	 * M[2][0]	M[2][1]	M[2][2]
	 *
	 */
	int tempi=0;
	int tempj=0;
	short swaps=(row*coloumn-coloumn)/2;
	for(int looper=0;looper<((row*coloumn)) ;looper++)
	{

		for(int i=0;i<row;i++)
		{
			for(int j=0;j<coloumn;j++)
			{
				if((tempi==i)&&(tempj==j))
				{
					continue;
				}
				if((tempi==j)&&(tempj==i))
				{
					//					*((Matrix+i*coloumn)+j)=*((Matrix+i*coloumn)+j)+*((Matrix+tempi*coloumn)+tempj);
					//					*((Matrix+tempi*coloumn)+tempj)=*((Matrix+i*coloumn)+j)-*((Matrix+tempi*coloumn)+tempj);
					//					*((Matrix+i*coloumn)+j)=*((Matrix+i*coloumn)+j)-*((Matrix+tempi*coloumn)+tempj);
					int temp=*((Matrix+i*coloumn)+j);
					*((Matrix+i*coloumn)+j)=*((Matrix+tempi*coloumn)+tempj);
					*((Matrix+tempi*coloumn)+tempj)=temp;
					printf("M[%d][%d] with M[%d][%d]\n",tempi,tempj,i,j);
					MatrixPrinter(Matrix, row, coloumn);
					tempj++;
					if(tempj%(coloumn)==0)
					{
						tempj=0;
						tempi++;
					}
					swaps--;
					if(!swaps)
					{
						return;
					}


				}
			}

		}

		tempj++;
		if(tempj%(coloumn)==0)
		{
			tempj=0;
			tempi++;
		}
	}

}
void  Ex3(int * arr, int row , int coloumn)
{
	int r,c;
	printf("Enter number of rows\n");
	scanf("%d",&r);
	printf("Enter number of coloumns\n");
	scanf("%d",&c);
	MatrixFiller(arr  ,r , c);
	//int arr1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	printf("Before transpose \n");
	MatrixPrinter(arr, r, c);
	MatrixTranspose(arr, r, c);
	printf("After transpose \n");
	MatrixPrinter(arr, r, c);

}
void  EX4(int * arr, int len , int number , int index)
{
	if(*(arr+index)==NULL)
	{
		*(arr+index)=number;
		return;
	}
	if(index>=len)
	{
		printf("index out of range, max index is %d",len-1);
		return;
	}

	ArrayShifter(arr, len, index, number);
	ArrayPrinter(arr, len);
}
char isInteger(double val)
{
    int truncated = (int)val;
    return (val == truncated);
}
void ArrayShifter(int *array,int len , int index, int number)
{
	for(int i=len-1;i>index;i--)
	{
		*(array+i)=*(array+i-1);
		ArrayPrinter(array, len);
	}
	*(array+index)=number;
	ArrayPrinter(array, len);
}
void ArrayPrinter(int *arr,int  len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d \t",*(arr+i));
	}
	printf("\n");
}
int  ArraySearch (int *arr , int len , int number )
{
	int index=-1;
	for(int i=0;i<len ;i++)
	{
		if (*(arr+i)==number)
		{
			index=i;
			break;
		}
	}
	return index;
}
int  Ex5(int * arr, int len  )
{
	printf("\nEnter number of elements: ");
	int elements;
	scanf("%d",&elements);
	printf("\nEnter number to be searched: ");
	int number;
	scanf("%d",&number);

	return ArraySearch(arr,elements,number);
}
int  CharFrequency (char * str, char target)
{
	int frequency=0;
	for(int i=0; *(str+i)!=0;i++)
	{
		if(*(str+i)==target)
		{
			frequency++;
		}
	}
	return frequency;
}
int   Ex6 (char * str )
{
	printf("Enter String \n");
	gets(str);
	char target;
	printf("enter target character \n");
	scanf("%c",&target);
	return CharFrequency(str,target);
}
int StringLength(char * str )
{
	int length=0;
	for(int character=0;*(str+character)!=0;character++)
	{
		length++;
	}
	return length;
}
int   Ex7 (char * str )
{
	printf("Enter String \n");
	gets(str);
	return StringLength(str);
}
void StringMirror(char *str )
{
	int length=StringLength(str);

	for(int character=0;character<length/2;character++)
	{
		//printf("%c\n",str[length-character-1]);
		char temp=str[length-character-1];
		str[length-character-1]=str[character];
		str[character]=temp;
		//printf("temp: %c\n",temp);

	}

}
void   Ex8 (char * str )
{
	printf("Enter String \n");
	gets(str);
	StringMirror(str);

}
