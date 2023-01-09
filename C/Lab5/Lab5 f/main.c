#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
typedef struct
{
    int ID;
    char Name[10];
    float salary;
    float Bonus;
    float Deduction; // an amount of money that is taken by an employer from an employee's pay, for income tax
} Employee;
Employee AddNewEmployee()
{
    Employee emp;
    printf("\nEmployee ID: ");
    scanf("%d",&emp.ID);
    printf("\nEmployee Name: ");
    _flushall();
    gets(emp.Name);
    printf("\nEmployee Salary: ");
    scanf("%f",&emp.salary);
    printf("\nEmployee Bonus: ");
    scanf("%f",&emp.Bonus);
    printf("\nEmployee Deduction: ");
    scanf("%f",&emp.Deduction);
    return emp;
}
int getIndexOfEmp(int j,int index[]);
void DisplayEmployee (Employee empp);
int main()
{
    Employee emp[10];
    int indexes[10]= {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},idx,i,j,NoEmployee=0,temp;
    do
    {
        system("cls");

        if (NoEmployee ==0)
        {
            for(i=0; i<10; i=i+2)
            {
                printf("%d- \t\n",i);
                printf("%d- \t\n",i+1);
            }
            printf("Enter Index to Store Employee : ");
            _flushall();
            scanf("%d",&idx);
            if (idx !=-1)
            {
                printf("\t----------Enter Employee Details -----------\n");
                emp[idx]=AddNewEmployee();
                indexes[NoEmployee]=idx;
                NoEmployee++;
            }
        }
        else if (NoEmployee > 0 )
        {
            for(i=0; i<10; i++)
            {
                temp = getIndexOfEmp(i,indexes);
                if (indexes[temp] == i )
                {
                    printf("%d- %s \t\n",i,emp[indexes[temp]].Name);
                }
                else
                {
                    printf("%d- \t\n",i);
                }


            }
            printf("\nEnter Index to Store Employee : ");
            _flushall();
            scanf("%d",&idx);
            if (idx !=-1)
            {
                printf("\t----------Enter Employee Details -----------\n");
                emp[idx]=AddNewEmployee();

                indexes[NoEmployee]=idx;
                NoEmployee++;
            }
            else
            {
                for(i=0; i<10; i++)
                {
                    temp = getIndexOfEmp(i,indexes);
                    if (indexes[temp] == i )
                    {
                        printf("%d- %s\t\n",i,emp[indexes[temp]].Name);
                    }
                    else
                        printf("%d- \t\n",i);
                }
                printf("\nEnter Index to Print out Employee : ");
                scanf("%d",&idx);
                DisplayEmployee(emp[idx]);
                getch();
            }
        }
    }
    while(idx != -1);
    return 0;
}
int getIndexOfEmp(int j,int index[])
{
    int i;
    for (i = 0 ; i < 10 ; i++)
    {
        if (index[i]==j)
        {
            return i;
            break;
        }
    }
    return -1;
}
void DisplayEmployee (Employee empp)
{
    printf("\nEmployee Code: \t %d",empp.ID);
    printf("\nEmployee Name: \t %s",empp.Name);
    printf("\nEmployee Salary:\t%f",empp.salary);
    printf("\nEmployee Bonus:\t%f",empp.Bonus);
    printf("\nEmployee Deduction:\t%f",empp.Deduction);
    printf("\nEmployee Net Salary:  %f\n",(empp.salary+empp.Bonus-empp.Deduction));
}
