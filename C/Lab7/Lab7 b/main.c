#include <stdio.h>
#include <stdlib.h>
int* WrongIncrementArr();
int* RightIncrementArr();
int main()
{
    int* wrongArr=WrongIncrementArr();
    int i ;
    printf("Wrong result because of the Arr in function is now out of scope");
    for (i=0; i<5; i++)
        printf("\nArr[%d] = %d :",i,wrongArr[i]);
    int* RightArr=RightIncrementArr();
    printf("Right result ");
    for (i=0; i<5; i++)
        printf("\nArr[%d] = %d :",i,RightArr[i]);

    return 0;
}
int* WrongIncrementArr()
{
    int Arr[5] ;
    int i ;
    for (i=0; i<5; i++)
    {
        printf("\nEnter Arr[%d] :",i);
        scanf("%d",&Arr[i]);
        Arr[i]+=5;
    }
    return Arr;//it gives a warning  function returns address of local variable
}
int* RightIncrementArr()
{
    int *Arr= malloc(5*sizeof(int)) ;
    int i ;
    for (i=0; i<5; i++)
    {
        printf("\nEnter Arr[%d] :",i);
        scanf("%d",&Arr[i]);
        Arr[i]+=5;
    }
    return Arr;
}
