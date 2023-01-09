#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"
void insertIndicator(char*,char*,int);
int main()
{
    char string[100],temp[100],inserationText[100];
    char* ptr= string;
    char* tmpPtr=temp;
    char* Ptrtxt=inserationText;
    int CursorPos;
    char Choice;
    printf("------- Line Editor-----\n");
    gets(ptr);
    //puts(ptr); //check
    CursorPos= strlen(ptr);
    insertIndicator(ptr,tmpPtr,CursorPos);
    //printf("%s",tmpPtr);
    do
    {
        Choice = getch();
        switch(Choice)
        {
        case 0:         //Extended key
        case -32:
        case 224:
            Choice = getch();
            clrscr();
            switch(Choice)
            {
            case 75: //Left
                if ( CursorPos > 0 )
                {
                    CursorPos --;
                    insertIndicator(ptr,tmpPtr,CursorPos);
                }
                else if (CursorPos == 0)
                {
                    strcpy(temp,string);
                    CursorPos = strlen(temp);
                    insertIndicator(ptr,tmpPtr,CursorPos);
                }
                break;
            case 77: //Right
                clrscr();
                if(CursorPos >= strlen(ptr))
                {
                    CursorPos=0;
                    insertIndicator(ptr,tmpPtr,CursorPos);
                }
                else
                {
                    CursorPos ++;
                    insertIndicator(ptr,tmpPtr,CursorPos);
                }

                break;
            case 71://case Home:
                CursorPos=0;
                insertIndicator(ptr,tmpPtr,CursorPos);
                break;
            case 79://case End:
                CursorPos = strlen(temp)-1;
                insertIndicator(ptr,tmpPtr,CursorPos);
                break;

            }
            break;
        case 13: //Enter //bug
            printf("\n > ");
            gets(Ptrtxt);
            puts(Ptrtxt);
            strncpy(tmpPtr, ptr, CursorPos);
            *(tmpPtr+CursorPos) = '\0';
            strcat(tmpPtr,Ptrtxt );
            strcat(tmpPtr, ptr + CursorPos);
            //printf("%s\n", temp);
            strcpy(ptr, tmpPtr);
            printf("\n");
            CursorPos = strlen(ptr);
            //println("%")
            clrscr();
            insertIndicator(ptr,tmpPtr,CursorPos);


            break;
        case 27: //Esc
            return 0;

        }

    }
    while(Choice != 27);
    return 0;
}
void insertIndicator(char*string,char* temp,int cursorPos)
{
    strncpy(temp, string, cursorPos);
    *(temp+cursorPos) = '\0';
    //printf("%s",temp);
    strcat(temp, "|");
    strcat(temp, string + cursorPos);
    //printf("\n%s",string);
    printf("%s\n", temp);
    printf("\n");
}
