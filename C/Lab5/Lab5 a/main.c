#include <stdio.h>
#include <stdlib.h>
#define  INT_MIN -2147483648
int LargestNumber(int,int,int);
int main()
{
    int Num1, Num2,Num3,Result;
    printf("Enter 1st Number : ");
    scanf("%d", &Num1);
    printf("\nEnter 2nd Number : ");
    scanf("%d", &Num2);
    printf("\nEnter 3rd Number : ");
    scanf("%d", &Num3);
    Result =LargestNumber(Num1,Num2,Num3);
    if (Result == INT_MIN )
        printf("\nThey Are Equal %d ",Num1 );
    else
        printf("\nLargest Number is = %d ", Result);

    return 0;
}
int LargestNumber(int Num1,int Num2,int Num3)
{
    if ( Num1 > Num2 && Num1 > Num3)
        return Num1;
    else if ( Num2 > Num3 && Num2 > Num3)
        return Num2;
    else if (Num3 > Num1 && Num3 > Num2)
        return Num3;

    return INT_MIN ;

}
