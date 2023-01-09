#include <stdio.h>
#include <stdlib.h>
void insertIndicator(char*,char*,int);
int main()
{
    char string[100],temp[100],inserationText[100];
    char* ptr= string;
    char* tmpPtr=temp;
    char* Ptrtxt=inserationText;
    int NoChar,CursorPos;
    char Choice;
    printf("------- Line Editor-----\n");
    gets(ptr);
    puts(ptr); //check
    CursorPos=NoChar= strlen(ptr);
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
                    CursorPos = NoChar;
                    insertIndicator(ptr,tmpPtr,CursorPos);
                }
                break;
            case 77: //Right
                CursorPos++;
                insertIndicator(ptr,tmpPtr,CursorPos);
                if(CursorPos > NoChar)
                {
                    CursorPos=0;
                    insertIndicator(ptr,tmpPtr,CursorPos);
                }

                break;
            case 71://case Home:
                CursorPos=0;
                insertIndicator(ptr,tmpPtr,CursorPos);
                break;
            case 79://case End:
                CursorPos = NoChar;
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
            CursorPos = strlen(tmpPtr);
            //println("%")
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
    temp[cursorPos] = '\0';
    strcat(temp, "|");
    strcat(temp, string + cursorPos);
    //printf("\n%s",string);
    printf("%s\n", temp);
    printf("\n");
}
