#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char FirstName [10],LastName[10],FullName[12];
    printf("Please Enter Your First Name : ");
    scanf("%s",FirstName);

    printf("\nPlease Enter Your Last Name : ");
    scanf("%s",LastName);

    strcpy (FullName,FirstName);
    strcat (FullName, " ");
    strcat (FullName,LastName);

    printf("\nFull Name: %s", FullName);

    return 0;
}
