#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;

    printf("\nEnter Char to Get Normal / Extend Ascii: ");

    ch = getche();
    if(ch == 0 || ch == -32 || ch == 224)
    {
        printf("c: %d",ch);
        ch = getch();
        printf("\nExtended Ascii Key  = %d ", ch);
    }
    else
    {
        printf("\nNormal Asccii Key  = %d ", ch);
    }
    return 0;
}
