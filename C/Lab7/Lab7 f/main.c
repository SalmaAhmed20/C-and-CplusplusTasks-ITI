#include <stdio.h>
#include <stdlib.h>

int main()
{
    int NoRow,NoColumnForEachRow,i,j;
    printf("Please Enter Number of Students : ");
    scanf("%d",&NoRow);
    float**  JaggedArr;
    int* ColumnNo,*Sum ;
    JaggedArr= malloc(sizeof(int*)*NoRow);
    ColumnNo= malloc(sizeof(int*)*NoRow);
    Sum= malloc(sizeof(int*)*NoRow);


    for(i = 0 ; i < NoRow; i++)
    {
        printf("\nEnter Number of Subjects for student # %d ",i+1);
        scanf("%d",&NoColumnForEachRow);
        JaggedArr[i]= malloc(sizeof(float)* NoColumnForEachRow);
        ColumnNo[i]=NoColumnForEachRow;


    }
    for(i=0; i <NoRow; i++)
    {
        printf("\nEnter Grades for Student #%d ",i+1);
        Sum[i]=0;

        for(j=0 ; j<ColumnNo[i];j++)
        {
            printf("\nSubject # %d: ",j+1);
            scanf("%f",&JaggedArr[i][j]);
            Sum[i]+=JaggedArr[i][j];

        }
    }

    for(i=0; i <NoRow; i++)
    {
        printf("\nGrades for Student #%d  ",i+1);
        for(j=0 ; j<ColumnNo[i];j++)
        {
            printf("\nSubject # %d: %f",j,JaggedArr[i][j]);
        }
        printf("\nSum of Grades %d",Sum[i]);
        printf("\n----------------------------\n");
    }
    return 0;
}
