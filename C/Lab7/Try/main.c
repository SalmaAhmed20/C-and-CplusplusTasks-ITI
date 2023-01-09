#include <stdio.h>
#include <stdlib.h>
#include "Mylibrary.h"
int main()
{
    char** Paragraph;
    int* LenofLine,i,j;
    char Choice,c;
    int CursorPos=0,CurrLine=0,NumLines=1;
    Paragraph = malloc(sizeof(char*)*10); //pointer to 10 lines(pointers)
    LenofLine = malloc(sizeof(int)*10);
    //memory alloc for each line
    for(i=0; i<10; i++)
    {
        Paragraph[i]=malloc(sizeof(char)*50);
        LenofLine[i]=0;
    }
    do
    {
        Choice = getch();
        switch(Choice)
        {
        case 0:
        case -32:
        case 224:
            Choice = getch();
            switch(Choice)
            {
            case 72: // Up
                CurrLine--;
                if(CurrLine < 0)
                    CurrLine=NumLines-1;
                CursorPos = LenofLine[CurrLine];
                gotoxy(CursorPos,CurrLine);
                break;
            case 80://Down
                CurrLine++;
                if (CurrLine > NumLines )
                    CurrLine=0;
                CursorPos = LenofLine[CurrLine];
                gotoxy(CursorPos,CurrLine);
                break;
            case 75: //left
                CursorPos--;
                if(CursorPos <0) // when i reach start of line go to pervious
                {
                    CurrLine--;
                    CursorPos = LenofLine[CurrLine];
                }
                gotoxy(CursorPos,CurrLine);
                break;

            case 77: //right;
                CursorPos++;
                if(CursorPos>LenofLine[CurrLine])  // when i reach end of line go to next line
                {
                    CursorPos = 0;
                    CurrLine++;
                }
                gotoxy(CursorPos,CurrLine);
                break;
            case 73://case PgUp
                CurrLine=0;
                CursorPos=0;
                gotoxy(CursorPos,CurrLine);
                break;
            case 81://case PgDown
                CurrLine=NumLines-1;
                CursorPos=LenofLine[CurrLine];
                gotoxy(CursorPos,CurrLine);
                break;
            case 83://case Delete
                for(i=0; i<10; i++)//all lines don't contain any character
                    LenofLine[i]=0;
                clrscr();
                printf("> ");
                gotoxy(0,0);
                CursorPos  = 0;
                break;
            }
            break;
        case 8: //backspace
            LenofLine[CurrLine]--;
            for(i=CursorPos; i<=LenofLine[CurrLine]; i++) // shift character
                Paragraph[CurrLine][i-1]=Paragraph[CurrLine][i];

            clrscr();
            for(i=0; i<NumLines; i++)
            {
                for(j=0; j<LenofLine[i]; j++)
                    printf("%c",Paragraph[i][j]);
                printf("\n");
            }
            CursorPos--;
            gotoxy(CursorPos,CurrLine);
            break;
        case 13: //Enter
            NumLines++;
            CurrLine++;
            CursorPos=0;
            gotoxy(CursorPos,CurrLine);
            break;
        case 27: //Esc
            gotoxy(0,NumLines+1);
            for(i=0; i<NumLines; i++)
            {
                for(j=0; j<LenofLine[i]; j++)
                    printf("%c",Paragraph[i][j]);
                printf("\n");
            }

            free(Paragraph);
            free(LenofLine);
            return 0;
            break;
        default: // if i get character i add it
            LenofLine[CurrLine]++;
            for(i=LenofLine[CurrLine]-1; i>CursorPos; i--)
                Paragraph[CurrLine][i]=Paragraph[CurrLine][i-1];
            Paragraph[CurrLine][CursorPos]=Choice;
            gotoxy(0,CurrLine);
            for(i=0; i<LenofLine[CurrLine]; i++)
                printf("%c",Paragraph[CurrLine][i]);
            CursorPos++;
            gotoxy(CursorPos,CurrLine);
        }
    }
    while(Choice!=27);
    return 0;
}
