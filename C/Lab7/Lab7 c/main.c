#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "MyLibrary.h"
#define NormalPen 0X07
#define HighlightedPen 0X70
typedef struct
{
    int ID;
    char Name[10];
    float salary;
    float Bonus;
    float Deduction; // an amount of money that is taken by an employer from an employee's pay, for income tax

} Employee;
int NoEmployee = 0 ;
//Function Declaration
Employee AddNewEmployee(); //Add New Employee
void DisplayEmployee (Employee); //Display Employee details
int getIndexOfEmp(int,Employee*); //Get index of employee have id
int main()
{


    int Capacity,tempcap;
    printf("Enter The Total Number Of Employee :");
    scanf("%d",&Capacity);
    tempcap=Capacity;
    clrscr();
    // Arr Contain All Employee
    Employee* Emp = malloc(Capacity*sizeof(Employee)) ;
    //Number of current employee in system
    char Option[6][15] = {{"New"}, {"Display"},{"Display All"},{"Delete"},{"Delete All"}, {"Exit"}};
    int i, Default = 0,EmpID,founded=-1;
    Employee SearchedEmp;
    char Choice;
    do
    {
        //print menu
        gotoxy(35,1);
        textattr(NormalPen);
        printf("------- Menu Array Of Struct  -----\n");
        for(i = 0; i <6 ; i++)
        {
            gotoxy(35, i+3*(i+1));
            if(Default == i)
                textattr(HighlightedPen);
            else
                textattr(NormalPen);

            printf("%s", Option[i]);
        }

        Choice = getch();
        switch(Choice)
        {
        case 0:         //Extended key
        case -32:
            Choice = getch();
            switch(Choice)
            {
            case 72: //UP
                if ( Default > 0 )
                    Default --;
                else if (Default == 0)
                    Default = 5;
                break;
            case 80: //Down Arrow
                Default++;
                if(Default > 5)
                    Default=0;
                break;
            case 71://case Home:
                Default=0;
                break;
            case 79://case End:
                Default = 5;
                break;

            }
            break; //break of Extended keys case
        case 9 : //Tap
            if (Default >= 0 && Default < 5 )
                Default ++;
            else if ( Default == 5)
                Default = 0;
            break ;
        case 13: //Enter
            clrscr();
            gotoxy(35,2);
            if(Default == 0) // Add New Employee
            {
                if(NoEmployee <Capacity)
                {
                    textattr(HighlightedPen);
                    printf("\t----------Enter Employee Details -----------\n");
                    textattr(NormalPen);
                    Emp [NoEmployee]=AddNewEmployee();
                    textattr(HighlightedPen);
                    printf("\n------Your Employee Added Successfully--------\n");
                    NoEmployee++;
                    Capacity--;
                    textattr(NormalPen);
                    getch();
                    clrscr();
                }
                else
                    printf("No Space in The system \n");
            }
            else if (Default == 1) //Display by id
            {
                clrscr();
                if (NoEmployee >0 )
                {
                    printf("Enter Employee ID:");
                    scanf("%d",&EmpID);
                    founded = getIndexOfEmp(EmpID,Emp);
                    if (founded != -1 )
                        DisplayEmployee(Emp[founded]);
                    else printf("Employee Not Founded");
                    getch();
                    clrscr();
                }
                else
                {
                    clrscr();
                    gotoxy(45,5);
                    textattr(HighlightedPen);
                    printf("No Employee in System");
                    textattr(NormalPen);
                    getch();
                    clrscr();
                }
            }
            else if (Default == 2) //display all employee
            {


                if (NoEmployee >0 )
                {
                    clrscr();
                    for (i = 0 ; i < NoEmployee ; i++)
                        DisplayEmployee(Emp[i]);
                    getch();
                    clrscr();
                }
                else
                {
                    clrscr();
                    gotoxy(45,5);
                    textattr(HighlightedPen);
                    printf("No Employee in System");
                    textattr(NormalPen);
                    getch();
                    clrscr();
                }
            }
            else if (Default == 3) //delete employee by id
            {
                if (NoEmployee >0 )
                {
                    printf("Enter Employee ID:");
                    scanf("%d",&EmpID);
                    founded = getIndexOfEmp(EmpID,Emp);
                    SearchedEmp=Emp[founded];
                    if (founded !=-1)
                    {
                        for (i = founded ; i < NoEmployee ; ++i)
                        {
                            NoEmployee--;
                            Capacity++;
                            Emp[i]=Emp[i+1];
                        }
                        DisplayEmployee(SearchedEmp);
                        textattr(HighlightedPen);
                        printf("\n-----------Employee Deleted Successfully ------\n");
                        textattr(NormalPen);
                    }
                    else printf("Employee Not Founded");
                    getch();
                    clrscr();
                }
                else
                {
                    clrscr();
                    gotoxy(45,5);
                    textattr(HighlightedPen);
                    printf("No Employee in System");
                    textattr(NormalPen);
                    getch();
                    clrscr();
                }
            }
            else if (Default == 4) // delete all emp
            {
                clrscr();
                NoEmployee=0;
                Capacity= tempcap;
                textattr(HighlightedPen);
                printf("\n-----------All Employees Deleted Successfully ------\n");
                textattr(NormalPen);
                getch();
                clrscr();
            }
            else if (Default == 5)// exit
            {
                system("COLOR 07");
                printf("Your Choice is \"Exit\"");
                return 0 ;
            }
            break;
        case 27:
            return 0 ;

        }
    }
    while (Choice != 27);
    return 0;
}

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
int getIndexOfEmp(int ID,Employee*Emp)
{
    int i;
    for (i = 0 ; i < NoEmployee ; i++)
    {
        if (Emp[i].ID == ID)
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
