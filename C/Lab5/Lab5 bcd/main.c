#include <stdio.h>
#include <stdlib.h>
typedef struct Employee
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
void DisplayEmployee (Employee emp)
{
    printf("\nEmployee Code: \t %d",emp.ID);
    printf("\nEmployee Name: \t %s",emp.Name);
    printf("\nEmployee Salary:\t%f",emp.salary);
    printf("\nEmployee Bonus:\t%f",emp.Bonus);
    printf("\nEmployee Deduction:\t%f",emp.Deduction);
    printf("\nEmployee Net Salary:  %f\n",(emp.salary+emp.Bonus-emp.Deduction));
}
int main()
{

    Employee emp;
    Employee employees1 [5];
    int i ;
//    //Question 2
//    printf("\n------------Question2---------------\n");
//    printf("------Enter Employee Details ----------");
//    printf("\nEmployee ID: ");
//    scanf("%d",&emp.ID);
//    printf("\nEmployee Name: ");
//    _flushall();
//    gets(emp.Name);
//    printf("\nEmployee Salary: ");
//    scanf("%f",&emp.salary);
//    printf("\nEmployee Bonus: ");
//    scanf("%f",&emp.Bonus);
//    printf("\nEmployee Deduction: ");
//    scanf("%f",&emp.Deduction);
//
//    printf("\n------Employee Details ----------");
//    printf("\nEmployee Code: \t %d",emp.ID);
//    printf("\nEmployee Name: \t %s",emp.Name);
//    printf("\nEmployee Net Salary:  %f\n",(emp.salary+emp.Bonus-emp.Deduction));
//    // Question 3
//    printf("\n------------Question3---------------\n");
//    for(i=0; i<5; i++)
//    {
//        printf("------Enter Employee No %d Details ----------",i+1);
//        printf("\nEmployee ID: ");
//        scanf("%d",&emp.ID);
//        printf("\nEmployee Name: ");
//        _flushall();
//        gets(emp.Name);
//        printf("\nEmployee Salary: ");
//        scanf("%f",&emp.salary);
//        printf("\nEmployee Bonus: ");
//        scanf("%f",&emp.Bonus);
//        printf("\nEmployee Deduction: ");
//        scanf("%f",&emp.Deduction);
//        employees1 [i] = emp;
//
//    }
//    for(i=0; i<5; i++)
//    {
//
//        printf("\n------Employee No %d Details ----------",i+1);
//        printf("\nEmployee Code: \t %d",employees1[i].ID);
//        printf("\nEmployee Name: \t %s",employees1 [i].Name);
//        printf("\nEmployee Salary:\t%f",employees1 [i].salary);
//        printf("\nEmployee Bonus:\t%f",employees1 [i].Bonus);
//        printf("\nEmployee Deduction:\t%f",employees1 [i].Deduction);
//        printf("\nEmployee Net Salary:  %f\n",(employees1 [i].salary+employees1 [i].Bonus-employees1 [i].Deduction));
//
//    }
    //Question  4
    printf("\n------------Question4---------------\n");
    for (i = 0 ; i <2 ; i++ )
    {
        printf("------Enter Employee Details No %d----------\n",i+1);
        employees1[i] = AddNewEmployee();
    }
    for (i = 0 ; i <2 ; i++ )
    {
        printf("\n------Employee No %d Details ----------",i+1);
        DisplayEmployee(employees1[i]);
    }
    return 0;
}
