#include <stdio.h>
#include <stdlib.h>

int main()
{
    char Str [100];
    int NoChar,i;
    do{
    printf("Please Enter Number of Charaters: ");
    scanf("%d",&NoChar);
    }while (NoChar < 0 );
    for (i = 0 ; i < NoChar ; i++)
    {
        printf("\nChar No. %d: ",i+1);
        Str[i]= getche();
    }
    Str[NoChar] = '\0';
    printf("\nYou Entered %s",Str);
    return 0;
}
