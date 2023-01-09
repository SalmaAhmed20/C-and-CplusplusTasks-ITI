#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"
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
void removeFirst(char * str,  char toRemove)
{
    int i = 0;
    int len = strlen(str);

    while(i<len && str[i]!=toRemove)
        i++;

    while(i < len)
    {
        str[i] = str[i+1];
        i++;
    }
}
void delch(char *str,char*temp, int i)
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

    char * ptr = malloc(sizeof(char)*1000);
    char Choice;
    int CursorPos;
    int lineidx[20],linenumber=0,currline,templ,i;

    //printf("Enter lines and press ; to exit input \n");
    scanf("%[^;]s",ptr); // format specification act like gets it is stop when enter \n

    //printf("\n %s",str);
    currline,CursorPos=strlen(ptr);
    char* tmpPtr=malloc(CursorPos*sizeof(char));
    char* Ptrtxt=malloc(CursorPos*sizeof(char));
    for(i =0 ; i < strlen(ptr); i++)
    {

        if(ptr[i]== '\n')
        {
            templ=i;
            lineidx[i]=i;
            printf("%d \n",lineidx[i]);
            linenumber++;

        }
    }
    //templ=i;
    //currline;
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
            case 72://
                if(linenumber > 0 )
                {
                    currline=lineidx[linenumber-1];
                    //printf("%d",templ);
                    insertIndicator(ptr,tmpPtr,currline);
                    linenumber--;

                }
                else if ( linenumber == 0)
                {
                    linenumber=templ;
                    currline=lineidx[linenumber-1];
                    insertIndicator(ptr,tmpPtr,currline);


                }

                break;
            case 80:
                break;
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
                insertIndicator(ptr,tmpPtr,CursorPos);
                if(CursorPos > strlen(ptr))
                {
                    CursorPos=0;
                    insertIndicator(ptr,tmpPtr,CursorPos);
                }

                break;
            case 73://case PgUp:
                clrscr();
                CursorPos=1;
                insertIndicator(ptr,tmpPtr,CursorPos);
                break;
            case 81://case Pgdown:
                clrscr();
                CursorPos = strlen(ptr);
                insertIndicator(ptr,tmpPtr,CursorPos);
                break;
            case 83://case Delete
                clrscr();
                printf("-------Your Line Deleted Successfully-----\n");
                _flushall();
                printf("Enter lines and press ; to exit input \n");
                scanf("%[^;]s",ptr); // format specification act like gets it is stop when enter \n
                CursorPos=strlen(ptr);
                insertIndicator(ptr,tmpPtr,CursorPos);
                break;

            }
            break;
        case 8 : // backspace
            delch(tmpPtr,ptr,CursorPos-1);
            CursorPos=strlen(tmpPtr);
            printf("after Backspace \n %s\n",tmpPtr);
            strcpy(ptr,tmpPtr);
            *(ptr+CursorPos) = '\0';
            break;
        case 13: //Enter
            _flushall();
            printf("\n > ");
            gets(Ptrtxt);
            //puts(Ptrtxt);
            strcat(tmpPtr,"\n");
            strcat(tmpPtr,Ptrtxt);
            removeFirst(tmpPtr,'|');
            //printf("%s\n", temp);
            strcpy(ptr, tmpPtr);
            printf("\n");
            CursorPos = strlen(tmpPtr);
            //println("%")
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
