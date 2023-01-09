#include <stdio.h>
#include <stdlib.h>

int main()
{
    char Str [100];
    int i,j, strlength,count =1;
    // get line included space
    printf("Enter a String : ");
    gets(Str);
    strlength = strlen (Str);
    printf("You entered: %s \n", Str);
    //Calculate frequency
    printf("---------------------\n");
    printf(" character | Frequency\n");
    printf("---------------------\n");
    for (i = 0 ; i < strlength ; i++)
    {
        count=1;
        // get a char from string
        // compare char with every other character in sentense
        if (Str[i])
        {
            for (j = i +1 ; j <strlength; j++)
            {
                // if i match char then add to count and make char '\0'  to avoid counting same char again
                if (Str[i]==Str[j])
                {
                    count++;
                    Str[j]='\0';
                }

            }
            //FrqCharInSentence[i] = count;
            printf("    %c", Str[i]);
            printf("    |  ");
            printf("  %d\n", count);

        }
    }

    return 0;
}
