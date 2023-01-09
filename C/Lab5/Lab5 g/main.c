#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct
//{
//    int ID;
//    char Name[10];
//    float salary;
//    float Bonus;
//    float Deduction; // an amount of money that is taken by an employer from an employee's pay, for income tax
//
//} Employee;
typedef struct
{
    int DeptID;
    char DeptName[10];
    struct Employee
    {
        int ID;
        char Name[10];
        float salary;
        float Bonus;
        float Deduction; // an amount of money that is taken by an employer from an employee's pay, for income tax

    } emp[5];

} Department;
int main()
{
    Department Dp1 ;
    int i;
    Dp1.DeptID = 1;
    strcpy(Dp1.DeptName,"Cloud PD");
    for (i =0 ; i<3; i++)
    {
        Dp1.emp[i].ID=i+1;
        _flushall();
        printf("\nEnter Employee Name : ");
        scanf("%s",Dp1.emp[i].Name);
        printf("\nEnter Employee Salary : ");
        scanf("%f",&Dp1.emp[i].salary);
        printf("\nEnter Employee Bonus : ");
        scanf("%f",&Dp1.emp[i].Bonus);
        printf("\nEnter Employee Deduction : ");
        scanf("%f",&Dp1.emp[i].Deduction);
    }
    printf("\n--Department Details --\n");
    printf("Department ID : %d \n",Dp1.DeptID);
    printf("Department Name : %s \n",Dp1.DeptName);
    printf("\nEmployee ID | Employee Name | Net Salary \n");
    for (i =0 ; i<3; i++)
    {
        printf("\n\t %d  |  %s\t    |%f\n",Dp1.emp[i].ID,Dp1.emp[i].Name,Dp1.emp[i].salary+Dp1.emp[i].Bonus-Dp1.emp[i].Deduction);

    }
    return 0;
}
