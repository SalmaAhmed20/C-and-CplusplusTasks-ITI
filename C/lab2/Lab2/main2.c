#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"
int main()
{
    int i,charnum=0,numberno=0;
    char arr []="Welcome 2 intake 43";
    for(i= 0; i <strlen(arr);i++)
    {
        if ((arr[i] >= 'a' && arr[i] <= 'z')||(arr[i] >='A'&&arr[i]<='Z'))
            charnum++;
        else if (arr[i] >= '0' && arr[i]<='9')
            numberno++;

    }
    printf("Number of characters : %d \n ",charnum);
    printf("Number of Numbers : %d \n ",numberno);
}
