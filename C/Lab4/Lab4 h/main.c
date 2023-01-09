#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    //"H1ello @ Wo456rld."
    char str1 [20];
    int i,j ;
    printf("Enter string :");
    gets(str1);
    for(i = 0; str1[i] != '\0'; ++i)
    {
        while (!( (str1[i] >= 'a' && str1[i] <= 'z')
                  || (str1[i] >= 'A' && str1[i] <= 'Z') ||
                  str1[i] == '\0') )
        {
            for(j = i; str1[j] != '\0'; ++j)
            {
                str1[j] = str1[j+1];
            }
            str1[j] = '\0';
        }
    }
    printf("\nResultant String  : %s",str1);
    return 0;

}
