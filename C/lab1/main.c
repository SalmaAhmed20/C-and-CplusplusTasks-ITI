#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Var declaration
    char Char2Ascii ;
    float FloatNumber,division;
    int Num1,Num2,Sum,NumtoHex,multi,Sub;
    //Question 1
    printf("Hello World\n");
    //Question 2
    printf("Enter char to get ASCII Code:");
    // get char from user
    scanf("%c",&Char2Ascii);
    // print
    printf("\nASCII Code for letter \" %c \" is %d",Char2Ascii,Char2Ascii);
    //Question 3
    printf("\nEnter Float Number: ");
    // get float number from user
    scanf("%f",&FloatNumber);
    // print
    printf("\nYou Enter Float Number %f",FloatNumber);
    //Question 4
    printf("\nEnter First Number: ");
    scanf("%d",&Num1);
    printf("\nEnter Second Number: ");
    scanf("%d",&Num2);
    Sum = Num1 + Num2 ;
    printf("\n%d + %d = %d ",Num1,Num2,Sum);

    //Question 5
    printf("\nEnter Number To Convert to Hex: ");
    scanf("%d",&NumtoHex);
    printf("\nNumber \" %d \" Converted to Hex: %x",NumtoHex,NumtoHex);

    //Question 6
    printf("\nEnter First Number: ");
    scanf("%d",&Num1);
    printf("\nEnter Second Number: ");
    scanf("%d",&Num2);
    Sum = Num1 + Num2 ;
    printf("\n%d + %d = %d ",Num1,Num2,Sum);
    Sub = Num1 - Num2 ;
    printf("\n%d - %d = %d ",Num1,Num2,Sub);
    multi = Num1 * Num2 ;
    printf("\n%d * %d = %d ",Num1,Num2,multi);
    division = Num1 / (float) Num2 ;
    printf("\n%d / %d = %f ",Num1,Num2,division);

    //Question 7
    printf("\nEnter First Number: ");
    scanf("%d",&Num1);
    printf("\nEnter Second Number: ");
    scanf("%d",&Num2);
    printf("\n Quotient %d / %d = %d",Num1,Num2,Num1/ Num2);
    printf("\n Reminder %d %% %d = %d",Num1,Num2,Num1%Num2);
    return 0;
}
