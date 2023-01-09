#include <stdio.h>
#include <stdlib.h>

int main()
{
    int NoStd,NoSubj,i,j,subjsum;
    printf("\nEnter Number of Students : ");
    scanf("%d",&NoStd);
    printf("\nEnter Number of Subjects : ");
    scanf("%d",&NoSubj);
    int** Marks ;
    Marks =  malloc (sizeof(int*)*NoStd);
    int* Sum= malloc(sizeof(int)*NoStd);
    float* Avg= malloc(sizeof(float)*NoSubj);

    if (Marks)
    {
        for (i = 0; i < NoStd; i++ )
        {
            Marks[i] = malloc( sizeof(int)*NoSubj);
        }
    }
    for(i=0; i <NoStd; i++)
    {
        Sum[i]=0;
        printf("\nEnter For Student No %d :",i+1);
        for(j=0; j <NoSubj; j++)
        {
            printf("\n\tSubject No %d :",j+1);
            scanf("%d",&Marks[i][j]);
            Sum[i]+=Marks[i][j];
        }

    }
    for(j=0; j<NoSubj; j++)
    {
        subjsum=0;
        for(i=0; i < NoStd; i++)
        {
            subjsum+=Marks[i][j];
        }
        Avg[j]=subjsum/(float)NoStd;
    }
    for(i=0; i <NoStd; i++)
    {
        printf("\n Student No %d :",i+1);
        for(j=0; j <NoSubj; j++)
        {
            printf("\n\tSubject No %d Mark :",j+1,Marks[i][j]);
        }
        printf("\nTotal Sum = %d",Sum[i]);
        printf("\n-------------------------\n");
    }
    for(i=0; i<NoSubj; i++)
    {
        printf("Average For Subject No %d = %f",i+1,Avg[i]);
        printf("\n-------------------------\n");
    }
    return 0;
}
