#include <stdio.h>
#include <stdlib.h>
void SwapINT(int*,int*);
int main()
{
    int Num1,Num2;
    printf("Enter Number 1: ");
    scanf("%d",&Num1);
    printf("\nEnter Number 2: ");
    scanf("%d",&Num2);
    printf("\nBefore Swapping Num1 = %d , Num2 = %d",Num1,Num2);
    SwapINT(&Num1,&Num2);
    printf("\nAfter Swapping Num1 = %d , Num2 = %d",Num1,Num2);
    return 0;
}
void SwapINT(int*Num1,int*Num2)
{
    int temp = *Num1;
    *Num1 = *Num2;
    *Num2= temp;
}
