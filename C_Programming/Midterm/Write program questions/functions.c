#include <stdio.h>
#include <string.h>

int   Mid1Func1DigSum(int num );
float Mid1Func2Root  (int num );
void  Mid1Func3Prime (int Base,int Max);
int   Mid1Func4Rev	 (int num );
int   Mid1Func5Bin   (int num );
int   Mid1Func6Unq   (int *arr,int len);
int   Mid1Func7NLP   (int num);
void  Mid1Func8Rev   (int *arr,int len);
char*  Mid1Func9RvW  (char*str);
int   Mid1Func10Bin  (int num );
int main(void)
{		setvbuf(stdout,NULL,_IONBF,0);
		setvbuf(stderr,NULL,_IONBF,0);


		printf("%d\n",Mid1Func10Bin(14));
		printf("%d",Mid1Func10Bin(110));
		return 0;
}
int   Mid1Func10Bin  (int num )
{
	int max=0;
	int tempmax=0;
	for(int i=0;i<32;i++)
	{
		int bit=(1<<i);
		if((num&bit)>>i)
		{
			tempmax++;
		}
		else
		{
			if(tempmax>max)
			{
				max=tempmax;
				tempmax=0;
			}
		}
	}
	return max;

}
char*  Mid1Func9RvW  (char*str)
{

	int len=strlen(str);
	char temp1[100];
	strcpy(temp1,str);
	strtok(temp1," ");
	int spaceIndx=strlen(temp1);
	char temp2[100];
	for(int i=0;i<len-spaceIndx-1;i++)
	{
		temp2[i]=str[spaceIndx+i+1];
	}
	str=" ";
	strcat(temp2," ");
	strcat(temp2,temp1);
	str=temp2;
	printf("%s\n",str);
	char *temp3=temp2;
	return temp3;
}
void  Mid1Func8Rev   (int *arr,int len)
{
	for(int i=0;i<len/2;i++)
	{
		int temp=arr[i];
		arr[i]=arr[len-1-i];
		arr[len-i-1]=temp;
	}

}
int   Mid1Func7NLP   (int num)
{
	if(num)
	    return num + Mid1Func7NLP(num-1);
	else
		return num;
}
int   Mid1Func6Unq   (int *arr,int len)
{
	int result=-1;
	for(int i=0;i<len;i++)
	{
		char flag=1;
		for(int j=0;j<len;j++)
		{
			if(i==j)
				continue;
			if(arr[i]==arr[j])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			return arr[i];
		}
	}

	return result;
}
int   Mid1Func5Bin   (int num)
{
	int count=0;
	for(int i=0;i<32;i++)
	{
		int bit=(1<<i);
		count+=(num&bit)>>i;
	}
	return count;
}
int   Mid1Func4Rev	 (int num)
{
	int out=0;
	while(num!=0)
	{
		out+=num%10;
		num/=10;
		if(num!=0)
		{
			out*=10;
		}
	}
	return out;
}
int   Mid1Func1DigSum(int num)
{
	int sum=0;
	while(num!=0)
	{
		sum+=num%10;
		num/=10;
	}
	return sum;
}
float Mid1Func2Root  (int num)
{
	for(float i=0.000;i<=(num/2+1);i+=0.001)
	{
		if(((int)(i*i))==num)
		{
			return i;
		}

	}
	return -1;
}
void  Mid1Func3Prime (int Base,int Max)
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
				printf("Output: ");
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
