#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1 [20]="Hello World";
    //gets(str1);
    int len=0,i=0;
    while ( str1[i] != '\0')
    {
        len++;
        i++;
    }

    printf("Length of string = %d ",len);
    return 0;
}
