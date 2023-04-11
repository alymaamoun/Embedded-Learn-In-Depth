/******************************************
 * Author: Aly Maamoun
 *
 * Date: 11/4/2023
 *
 * FileName: main.c
 *
 * Description: Structs and enums and unions assignment
 */


#include <stdio.h>

#define EX1 0
#define EX2 0
#define EX3 0
#define EX4 0
#define EX5 1

#if EX5
#define pi 3.14
#define area(r)(pi*r*r)
#endif
#if !(EX1&&EX4)

#if EX1
struct SInfo{
	char Name[50];
	int roll;
	float marks;

}SI1;
struct SInfo SInfoTaker();
void SInfoDisplayer(struct SInfo SInfoData);
#endif
#if EX2
struct SInchFeet{
	int feet;
	float inch;
};
struct SInchFeet SInchFeetTaker(void);
void SInchFeetAdder(struct SInchFeet SInchFeet1,struct SInchFeet SInchFeet2);
#endif
#if EX3
struct SComplex
{
	float real;
	float imaginary;
};
struct SComplex SComplexTaker(void);
void SComplexAdder(struct SComplex SComplex1,struct SComplex SComplex2);
#endif
#if EX4
struct SInfo{
	char Name[50];
	int roll;
	float marks;

}SI1[10];

void SInfoArrayFiller();

void SInfoArrayDisplay();
#endif


int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
#if EX1
	SInfoDisplayer(SInfoTaker());
#endif
#if EX2
	SInchFeetAdder(SInchFeetTaker(),SInchFeetTaker());
#endif

#if EX3
	SComplexAdder(SComplexTaker(),SComplexTaker());
#endif
#if EX4

	SInfoArrayFiller();
	SInfoArrayDisplay();
#endif
#define EX5
	printf("Enter radius: ");
	float r;
	scanf("%f",&r);
	printf("Area: %.2f",area(r));
	return 0;

	/********EX6 Answer*******************
	 * size of union= 32
	 * size of structure = 40
	 */
}







#if EX1
struct SInfo SInfoTaker()
{
	struct SInfo SInfo_Temp;
	printf("Enter information of students: \n");
	printf("\nEnter name: ");
	scanf("%s",SInfo_Temp.Name);
	printf("\nEnter roll number: ");
	scanf("%d",&(SInfo_Temp.roll));
	printf("\nEnter Marks: ");
	scanf("%f",&(SInfo_Temp.marks));
	return SInfo_Temp;
}
void SInfoDisplayer(struct SInfo SInfoData)
{
	printf("\nDisplaying Information");
	printf("\n name: %s",SInfoData.Name);
	printf("\n Roll: %d",SInfoData.roll);
	printf("\n Marks: %f",SInfoData.marks);
}
#endif
#if EX2
struct SInchFeet SInchFeetTaker(void)
{
	struct SInchFeet SInchFeet_Temp;
	printf("\n Enter information for the distance");
	printf("\n Enter feet: ");
	scanf("%d",&(SInchFeet_Temp.feet));
	printf("\n Enter Inch: ");
	scanf("%f",&(SInchFeet_Temp.inch));
	return SInchFeet_Temp;
}
void SInchFeetAdder(struct SInchFeet SInchFeet1,struct SInchFeet SInchFeet2)
{
	int feet=SInchFeet1.feet+SInchFeet2.feet;
	float inch=SInchFeet1.inch+SInchFeet2.inch;
	feet+=inch/12;
	inch=inch-(int)inch;
	printf("Sum of distance= %d\'-%.1f\"",feet,inch);
}
#endif

#if EX3
struct SComplex SComplexTaker(void)
{
	struct SComplex SComplex_Temp;
	printf("\nEnter real and imaginary respectively: ");
	scanf("%f",&(SComplex_Temp.real));
	scanf("%f",&(SComplex_Temp.imaginary));
	return SComplex_Temp;

}
void SComplexAdder(struct SComplex SComplex1,struct SComplex SComplex2)
{
	printf("Sum:%.1f+%0.1fi",SComplex1.real+SComplex2.real,SComplex1.imaginary+SComplex2.imaginary);
}

#endif

#if EX4
void SInfoArrayFiller()
{
	printf("/Enter information of students");
	for(int index=0;index<10;index++)
	{
		printf("\nFor roll number %d",index+1);
		printf("\n Enter Name: ");
		scanf("%s",SI1[index].Name);
		printf("\n Enter marks: ");
		scanf("%f",&(SI1[index].marks));
		SI1[index].roll=index+1;
	}
}

void SInfoArrayDisplay()
{
	printf("/nDisplaying information of students");
	for(int index=0;index<10;index++)
	{
		printf("\n Information for roll number %d",index+1);
		printf("\n Name: %s",SI1[index].Name);

		printf("\n marks:%.f",SI1[index].marks);


	}

}
#endif

#endif

