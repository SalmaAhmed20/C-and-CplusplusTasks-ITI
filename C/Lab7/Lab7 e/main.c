#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"
void insertIndicator(char*,char*,int);
void delete_char(char *str,char*temp, int i)
{
    int len = strlen(str);
    str[i] = str[i+1];
    for (; i < len - 1 ; i++)
    {
        str[i] = temp[i+1];
    }
    str[i] = '\0';
}
int main()
{
    int NoChar=50,CursorPos;
    char* ptr= malloc(NoChar*sizeof(char));
    char* tmpPtr=malloc(NoChar*sizeof(char));
    char* Ptrtxt=malloc(NoChar*sizeof(char));
    char Choice;
    printf("------- Line Editor-----\n");
    _flushall();
    gets(ptr);
    //puts(ptr); //check
    CursorPos=strlen(ptr);
    insertIndicator(ptr,tmpPtr,CursorPos);
    do
    {
        Choice = getch();
        switch(Choice)
        {
        case 0:         //Extended key
        case -32:
        case 224:
            Choice = getch();
            switch(Choice)
            {
            case 75: //Left
                clrscr();
                if ( CursorPos > 0 )
                {
                    CursorPos --;
                    insertIndicator(ptr,tmpPtr,CursorPos);
                }
                else if (CursorPos == 0)
                {
                    strcpy(tmpPtr,ptr);
                    CursorPos = strlen(ptr);
                    insertIndicator(ptr,tmpPtr,CursorPos);
                }
                break;
            case 77: //Right
                clrscr();

                CursorPos++;
                if(CursorPos == strlen(tmpPtr))
                    CursorPos=0;
                insertIndicator(ptr,tmpPtr,CursorPos);

                break;
            case 71://case Home:
                clrscr();
                CursorPos=0;
                insertIndicator(ptr,tmpPtr,CursorPos);
                break;
            case 79://case End:
                clrscr();
                CursorPos = strlen(ptr);
                insertIndicator(ptr,tmpPtr,CursorPos);
                break;
            case 83://case Delete
                clrscr();
                printf("-------Your Line Deleted Successfully-----\n");
                printf("> ");
                _flushall();
                gets(ptr);
                CursorPos=strlen(ptr);
                insertIndicator(ptr,tmpPtr,CursorPos);
                break;

            }
            break;
        case 13: //Enter
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
            CursorPos = strlen(tmpPtr);
            //println("%")
            insertIndicator(ptr,tmpPtr,CursorPos);
            break;
        case 8 : // backspace
            clrscr();
            delete_char(tmpPtr,ptr,CursorPos-1);
            CursorPos=strlen(tmpPtr);
            printf("%s\n",tmpPtr);
            strcpy(ptr,tmpPtr);
            *(ptr+CursorPos+1) = '\0';
            insertIndicator(ptr,tmpPtr,CursorPos);

            break;
        case 27: //Esc
            free(ptr);
            free(tmpPtr);
            free(Ptrtxt);
            return 0;

        }

    }
    while(Choice != 27);
    return 0;
}
void insertIndicator(char*string,char* temp,int cursorPos)
{
    strncpy(temp, string, cursorPos);
    temp[cursorPos] = '\0';
    strcat(temp, "|");
    strcat(temp, string + cursorPos);
    //printf("\n%s",string);
    printf("%s\n", temp);
    printf("\n");
}
