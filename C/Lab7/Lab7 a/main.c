#include <stdio.h>
#include <stdlib.h>
int power(int,int);
int main()
{
    int base, exponent;
    printf("Enter base: ");
    scanf("%d",&base);
    printf("\nEnter exponent: ");
    scanf("%d",&exponent);

    printf("%d ^ %d = %d",base,exponent,power(base,exponent));
    return 0;
}
int power(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    else
        return base * power(base,exponent -1);
}
