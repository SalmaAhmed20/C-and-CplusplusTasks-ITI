#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"
#include <string.h>
#define NormalPen 0X07
#define HighlightedPen 0X70

int main()
{

    char Option[3][8] = {{"New"}, {"Display"}, {"Exit"}};
    int i, Default = 0;
    char Choice;
    do
    {
        gotoxy(35,1);
        textattr(NormalPen);
        printf("------- Main Menu -----\n");
        for(i=0; i<3; i++)
        {
            gotoxy(35, i+3*(i+1));
            if(Default == i)
                textattr(HighlightedPen);
            else
                textattr(NormalPen);

            printf("%s", Option[i]);
        }

        Choice = getch();
        switch(Choice)
        {
        case 0:         //Extended key
        case -32:
        case 224:
            Choice = getch();
            switch(Choice)
            {
            case 72: //UP
                if ( Default > 0 )
                    Default --;
                else if (Default == 0)
                    Default = 2;
                break;
            case 80: //Down Arrow
                Default++;
                if(Default > 2)
                    Default=0;
                break;
            case 71://case Home:
                Default=0;
                break;
            case 79://case End:
                Default = 2;
                break;

            }
            break; //break of Extended keys case
        case 9 : //Tap
            if (Default >= 0 && Default < 2 )
                Default ++;
            else if ( Default == 2)
                Default = 0;
            break ;
        case 13: //Enter
            clrscr();
            gotoxy(35,2);
            if(Default == 0)
            {
                printf("Your Choice is \"New\"");
                getch();
                clrscr();
            }
            else if (Default == 1)
            {
                printf("Your Choice is \"Display\"");
                getch();
                clrscr();

            }
            else if (Default == 2)
            {
                system("COLOR 07");

                printf("Your Choice is \"Exit\"");
                return 0 ;
            }
            break;
        case 27:
            return 0 ;

        }
    }
    while(Choice != 27);
    return 0;
}
