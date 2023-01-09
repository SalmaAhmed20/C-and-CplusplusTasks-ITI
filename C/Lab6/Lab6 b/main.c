#include <stdio.h>
#include <stdlib.h>
int SummationArrNotation (int [],int);
int SummationPointerNotation (int*,int);

int main()
{

    int Arr1[100],Arr2[100],Size=3,i,Sum;
    int* ArrPtr1;
    int* ArrPtr2;
    printf("---------- Array Notation --------- ");
    do
    {
        printf("\nEnter No of integers you will enter: ");
        scanf("%d",&Size);
    }
    while(Size  <= 0 );
    for (i=0; i<Size; i++)
    {
        printf("\nArr[%d] = ",i);
        scanf("%d",&Arr1[i]);
    }
    Sum=SummationArrNotation(Arr1,Size);
    printf("\n Sum Of Array = %d",Sum);
    printf("\n---------- Pointer Notation --------- ");
    ArrPtr1 = Arr2;
    for (i=0; i<Size; i++)
    {
        printf("\nArrPtr + %d = ",i);
        scanf("%d",ArrPtr1+i);

    }
    Sum =SummationPointerNotation(ArrPtr1,Size);
    printf("\n Sum Of Array = %d",Sum);
    printf("\n---------- Array  using (pointer notation)--------- ");
    Sum=0;
    for (i=0; i<Size; i++)
    {
        printf("\nArr2+%d = ",i);
        scanf("%d",Arr2+i);
    }
    for(i =0 ; i < Size; i++)
    {
        printf("\n ArrPtr + %d = %d ",i,*(Arr2+i));
        Sum+=*(Arr2+i);

    }
    printf("\n Sum Of Array = %d",Sum);
    printf("\n---------- Pointer  using (Array notation)--------- ");
    ArrPtr2=Arr2;
    Sum=0;
    for (i=0; i<Size; i++)
    {
        printf("\nArrPtr2[%d] = ",i);
        scanf("%d",&ArrPtr2[i]);
    }
    for(i =0 ; i < Size; i++)
    {
        printf("\n ArrPtr2[%d] = %d ",i,ArrPtr2[i]);
        Sum+=ArrPtr2[i];

    }
    printf("\n Sum Of Array = %d",Sum);

    return 0;
}
int SummationArrNotation (int Arr[],int Size)
{
    printf("\n --Summation Function Array Notation-- ");
    int i,sum=0;
    for(i =0 ; i < Size; i++)
    {
        printf("\nArr[%d] = %d ",i,Arr[i]);
        sum+=Arr[i];

    }
    return sum;

}
int SummationPointerNotation (int*ptr,int size)
{
    int i, sum = 0 ;
    for(i =0 ; i < size; i++)
    {
        printf("\n ArrPtr + %d = %d ",i,*(ptr+i));
        sum+=*(ptr+i);

    }
    return sum;
}

