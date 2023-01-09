#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
void clrscr()
{
    system("cls");
}
//function definition //#include<windows.h>
void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
int noOfChar(char* p)
{
    return (strlen(p)/sizeof(char));
}
char* Arr()
{
    char* pa=malloc(20*(sizeof(char)));
    pa = "Hello world";
    return pa;
}
void dChar(char* p, char* temp ,int pos)
{
    int i;
    strncpy(temp, p, pos);
    temp[pos] = '\0';
    strcat(temp, p + pos+1);

}
int main()
{

    char* p=malloc(20*(sizeof(char)));
    //char* newArr[20];
    int n=0,Flag=0;;
    int pos,i;
    char c;
    char* temp=malloc(20*(sizeof(char)));
    strcpy(p,"Hello world");
    p[strlen(p)]='\0';
    //p=Arr();
    puts(p);


    n=noOfChar(p);
    pos=n-1;
    gotoxy(pos,0);

    do
    {



        c=getch();
        if(c==0 || c==-32 || c==224)
        {
            c=getch();
            if(c==77 && pos!=n-1)
            {

                pos++;
                gotoxy(pos,0);


            }
            else if(c==75 && pos>0)
            {
                pos--;
                gotoxy(pos,0);
            }
        }
        else if(c==8)
        {



            dChar(p,temp,pos);
            n--;
            clrscr();
            strcpy(p,temp);
            printf("%s",p);


            getch();
            //return 0;
        }

    }
    while(Flag == 0);

    free(p);
    return 0;
}
