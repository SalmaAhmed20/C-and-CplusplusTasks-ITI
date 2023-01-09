#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,charnum=0,numberno=0;
    char arr []="Welcome 2 intake 43";
    printf("\n--------Question 7-------\n");
    printf("%s\n",arr);
    for(i= 0; i <strlen(arr); i++)
    {
        if ((arr[i] >= 'a' && arr[i] <= 'z')||(arr[i] >='A'&&arr[i]<='Z'))
            charnum++;
        else if (arr[i] >= '0' && arr[i]<='9')
            numberno++;

    }
    printf("# of characters : %d \n ",charnum);
    printf("# of Numbers : %d \n ",numberno);
    return 0;
}
