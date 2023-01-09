#include <stdio.h>
#include <stdlib.h>

int main()
{
//    // Question 1

    int Arr1D [100], NoRow,NoColumnsEachRaw [100],jaggedArr[100];
    float Arr2D[3][4],Sum[3]= {},sum=0,Arr2D1[2][2],Arr2D2[2][2],Arr2D3[2][2];
    int NoElement,i,j;
    int min, max,temp=0;
    printf("\n -----Question 1------ ");
    do
    {
        printf("\nEnter No of Elements : ");
        scanf("%d",&NoElement);
        if (NoElement < 0)
            printf("\n -----Please enter positive number------ ");
    }
    while (NoElement < 0);
    for (i =0 ; i < NoElement ; i++)
    {
        printf("\nEnter Element No %d ",i+1);
        scanf("%d",&Arr1D[i]);
    }
    for (i =0 ; i < NoElement ; i++)
    {
        printf("\nElement No %d = % d",i+1,Arr1D[i]);
    }
    // Question 2

    printf("\n -----Question 2------ ");
    min = max = Arr1D[0];
    for (i =1 ; i < NoElement ; i++)
    {
        if (Arr1D[i] < min)
            min = Arr1D[i];
        if (Arr1D[i] > max)
            max = Arr1D[i];
    }
    printf("\nMin value in Array = %d \nMax Value in Array = %d ",min,max);

    printf("\n -----Question 3------ \n");
    for (i =0 ; i < 3 ; i++)
    {
        printf("Enter Grades of Student No %d \n",i+1);
        for(j=0; j <4; j++)
        {
            printf("\t Subject No %d ",j+1);
            scanf("%f",&Arr2D[i][j]);
            printf("\n");
            Sum[i]+= Arr2D[i][j];
        }
    }
    for (i =0 ; i < 3 ; i++)
    {
        for(j=0; j <4; j++)
        {
            printf("Student No %d , Subject No %d = %f",i+1,j+1,Arr2D[i][j]);
            printf("\n");
        }
        printf("\n----Total Grades for Student No %d = %f \n",i+1,Sum[i]);
    }
    printf("\n -----Question 4 ------ \n");
    for(j=0; j <4; j++)
    {

        for(i=0; i<3; i++)
        {
            sum+=Arr2D[i][j];
        }
        printf("Average grades in Subject No %d = %f \n",j+1,sum/3);
    }

    printf("\n -----Question 5 ------ \n");
    printf("----Enter Values in Matrix 1 ----\n");
    for (i =0 ; i < 2 ; i++)
    {
        for(j=0; j <2; j++)
        {
            printf("Matrix [%d] [%d]",i,j);
            scanf("%f",&Arr2D1[i][j]);
            printf("\n");
        }
    }
    printf("----\n Enter Values in Matrix 2----\n");
    for (i =0 ; i < 2 ; i++)
    {
        for(j=0; j <2; j++)
        {
            printf("Matrix [%d] [%d]",i,j);
            scanf("%f",&Arr2D2[i][j]);
            printf("\n");
        }
    }

    for (i =0 ; i < 2 ; i++)
    {
        for(j=0; j <2; j++)
        {
            Arr2D3 [i][j] = Arr2D1 [i][j] + Arr2D2 [i][j];

        }
    }
    printf("---- Summation Matrix 3 ----\n");
    for (i =0 ; i < 2 ; i++)
    {
        for(j=0; j <2; j++)
        {
            printf(" \t %f ",Arr2D3 [i][j]);

        }
        printf("\n");
    }
    printf("------ Questions 6------\n");
    printf("------Enter No Rows------\n");
    scanf("%d",&NoRow);
    printf("------Enter No of Column for Each Row------\n");
    for (i = 0 ; i < NoRow; i++)
    {
        printf("Enter No . Columns for Row No %d ",i+1);
        scanf("%d",&NoColumnsEachRaw[i]);
        printf("\n");
    }
    printf("------Enter Values------\n");
    for (i = 0 ; i < NoRow; i++)
    {

        for(j =temp; j < NoColumnsEachRaw[i]+temp; j++)
        {
            printf("enter value row [%d], column [%d] ",i,j-temp);
            printf("%d \n ",i*NoColumnsEachRaw[i]+j);
            scanf("%d",&jaggedArr[i*NoColumnsEachRaw[i]+j]);
            printf("\n");
        }
        temp=j;

    }
    printf("------Values------\n");
    temp=0;
    for (i = 0 ; i < NoRow; i++)
    {
        for(j =temp; j < NoColumnsEachRaw[i]+temp; j++)
        {
            printf("row [%d], column [%d]= %d",i,j-temp,jaggedArr[i*NoColumnsEachRaw[i]+j]);
            printf("\n");
        }
        temp=j;

    }

    return 0;
}
