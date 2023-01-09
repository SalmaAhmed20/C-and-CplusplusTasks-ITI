#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"
#include <conio.h>
#include <math.h>
int main()
{
    int column=1,row=0,Number,size,tsize,num1,num2,num3,i;
    int Sum = 0,Num,charnum=0,numberno=0;
    char choice='a' ;
    char arr []="Welcome 2 intake 43";

    //Question 1 while loop
    printf("--------Question 1-------\n");

    while (Sum < 100)
    {
        printf(" Enter Number to Summation:");
        scanf("%d",&Num);
        Sum +=Num;
    }
    printf("Total Sum = %d",Sum);
    getche();
    clrscr();
    //Question 2 Simple Menu with 3 choices.
    gotoxy(40,5);
    printf("--------Question 2-------\n");

    while(choice != 'c')
    {
        gotoxy(40,7);
        printf("A. New");
        gotoxy(40,10);
        printf("B. Save");
        gotoxy(40,13);
        printf("C. Exit");
        gotoxy(0,16);
        printf("Enter Your choice ");
        scanf("%c",&choice);

        switch (choice)
        {
        case 'a':
        case 'A':
        {
            clrscr();
            gotoxy(40,8);
            printf("Your choice is \" New\"");
            getche();
            break;
        }

        case 'b':
        case 'B':
        {
            clrscr();
            gotoxy(40,12);
            printf("Your choice is \" Save\"");
            getche();
            break;
        }
        case 'c':
        case 'C':
        {
            clrscr();
            gotoxy(40,14);
            printf("Your choice is \" Exit\"");
            getche();
            break;
        }
        }
        clrscr();

        if (choice == 'c' || choice == 'C' )
            break;


    }
    getche();
    clrscr();


    printf("--------Question 3-------\n");
    do
    {
        printf("Enter size");
        scanf("%d",&size);
        if (size%2 == 0)
        {
            printf("Please enter odd number");
            getche();
            clrscr();
        }
    }
    while(size%2 == 0);

    tsize =pow( size,2) ;
    clrscr();
    for(Number=1; Number<=tsize; Number++)
    {
        //first number is 1
        if(Number==1)
        {
            row =1;
            // to get middle column
            column=(size+1)/2;
        }
        else if(((Number-1)%size) == 0)
        {
            row++;
        }
        else
        {
            row--;
            column--;
            if(column == 0)
                column = size;
            if(row == 0)
                row = size;

        }

        gotoxy(column*7,row*7);
        printf("%d",Number);


    }
    getche();
    clrscr();

    printf("--------Question 4-------\n");
    printf("Enter 3 numbers\n");
    scanf(" %d %d %d",&num1,&num2,&num3);
    if( num1 > num2)
    {
        if (num1 > num3)
            printf("Number1  %d is greatest",num1);
    }
    else if (num2 > num3)
    {
        printf("Number2 %d is greatest",num2);

    }
    else if (num3 > num1)
    {
        if (num3 > num2)
            printf("Number3 %d is greatest",num3);
    }
    else
        printf("They are equal");

    printf("\n--------Question 5-------\n");
    printf("Enter base and limit of muliplier number\n");
    scanf(" %d %d",&num1,&num2);
    printf("----Multipler table ----\n");
    for(i=1; i <= num2; i++)
    {
        printf("%d * %d = %d \n",num1,i,num1*i);
    }
    getche();
    clrscr();

    printf("\n--------Question 6-------\n");
    printf("Enter character ");
    scanf("%c",&choice);
    if((choice >= 'A'&& choice <= 'Z')||(choice >= 'a'&& choice <= 'z'))
        printf("\n Alphabet");
    else
        printf("\n Not Alphabet");
    getche();
    clrscr();
    printf("\n--------Question 7-------\n");
    printf("%s\n",arr);
    for(i= 0; i <strlen(arr);i++)
    {
        if ((arr[i] >= 'a' && arr[i] <= 'z')||(arr[i] >='A'&&arr[i]<='Z'))
            charnum++;
        else if (arr[i] >= '0' && arr[i]<='9')
            numberno++;

    }
    printf("Number of characters : %d \n ",charnum);
    printf("Number of Numbers : %d \n ",numberno);
    return 0;
}
