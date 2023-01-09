#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

    char str1 [20]="Hello World",cpyedStr[20];
    //gets(str1);
    int i = 0 ;
    while ( str1[i] != '\0')
    {
        cpyedStr [i] = str1[i];
        i++;
    }
    cpyedStr [i]= '\0';
    i = 0 ;
    printf("Copyed String : ");
    while ( cpyedStr[i] != '\0')
    {
       printf("%c",cpyedStr[i]);
       i++;
    }
    //printf("\n");
    return 0;
}
