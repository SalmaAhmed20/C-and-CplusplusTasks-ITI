#include <stdio.h>
#include <stdlib.h>
int a = 9;
int main()
{
    int e=3,i,b=2,r=1;
    float res=1.0;
    float e2 = -3;

    if(e >0)
    {
        for(i = e ; i > 0; i-- )
        {
            r*=b;
        }
        printf("%d",r);
    }
    if (e2 < 0)
    {

        for(i = e2 ; i < 0; i++ )
        {
            res*=1.0/b;
            printf("\n %f",res);
        }
        printf("\n %f",res);
    }
    return 0;
}
