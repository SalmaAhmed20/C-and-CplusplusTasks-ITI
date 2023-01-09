#include <stdio.h>
#include <stdlib.h>
#include"MyLibrary.h"
#define size 100
int main()
{
    char Choice,i,x=0,c,cur=0,line=1,l=0,j;
    char** str;
    int* len;
    str = malloc(size * sizeof(char*));
    len = malloc(size * sizeof(int));
    for(i=0; i<size; i++)
    {
        len[i] = 0;
        str[i] = malloc( size * sizeof(char));
    }
    clrscr();
    do
    {
        Choice = getch();
        switch(Choice)
        {
        case 0:         //Extended key
        case -32:
        case 224:
            Choice = getch();
            switch(c)
            {
            case 75: //left
                cur--;
                if(cur<0)
                {
                    l--;
                    cur = len[l];
                }
                gotoxy(cur,l);
                break;

            case 77: ///right;
                cur++;
                if(cur>len[l])
                {
                    cur = 0;
                    l++;
                }
                gotoxy(cur,l);
                break;

            case 72:///up
                l--;
                cur = len[l];
                gotoxy(cur,l);
                break;

            case 80:///down
                l++;
                cur = len[l];
                gotoxy(cur,l);
                break;

            case 71: ///Home
                cur=0;
                gotoxy(cur,l);
                break;
            case 79: ///End
                cur=len[l];
                gotoxy(cur,l);
                break;
            case 73: ///pg up
                l=0;
                cur=0;
                gotoxy(cur,l);
                break;

            case 81: ///pg down
                l=line-1;
                cur=len[l];
                gotoxy(cur,l);
                break;
            case 83: ///delete
                for(i=0; i<size; i++)
                {
                    len[i]=0;
                }
                clrscr();
                gotoxy(0,0);
                cur  = 0;
                break;


            }


            break; ///break of Extended keys case



        case 13: ///Enter
            line++;
            l++;
            cur=0;
            gotoxy(cur,l);
            break;

        case 27: //Esc
            free(str);
            free(len);
           return 0;

        case 83: ///delete
            for(i=0; i<size; i++)
            {
                len[i]=0;
            }
            clrscr();
            gotoxy(0,0);
            cur  = 0;
            break;

        case 8: ///backspace
            len[l]--;
            for(i=cur; i<=len[l]; i++)
            {
                str[l][i-1]=str[l][i];
            }
            clrscr();
            for(i=0; i<line; i++)
            {
                for(j=0; j<len[i]; j++)
                {
                    printf("%c",str[i][j]);
                }
                printf("\n");
            }
            cur--;
            gotoxy(cur,l);
            break;

        default:
            len[l]++;
            for(i=len[l]-1; i>cur; i--)
            {
                str[l][i]=str[l][i-1];
            }
            str[l][cur]=Choice;
            gotoxy(0,l);
            for(i=0; i<len[l]; i++)
            {
                printf("%c",str[l][i]);
            }
            cur++;
            gotoxy(cur,l);
            //printf("%c",ch);
        }
    }
    while(Choice !=27);
        return 0;
}
