#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
#include "Graphic.h"
using namespace std;
void task3()
{
    Shape *a[3];
    elipse e1(200,100,75,30,0,360);
    a[0]=&e1;
    Circle c1 (90,90,80);
    a[1]=&c1;
    Line l1(125,100,100,200);
    a[2]=&l1;
    Picture p(a,3);
    p.DrawPic();


}

int main()
{
    initwindow(1500,1500);

    /* Rec r(20,20,90,90);
     r.Draw();
     Line l(100,100,150,150);
     l.Draw();
     Circle c1(90,90,80);
     c1.Draw();*/
    bool flag=false;
    int i=0;
    task3();
    /*do
    {
        if (flag)setcolor(YELLOW);
        elipse e1(200,100,75,30,0,360);
        e1.Draw();
        if (flag)
        {
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(200,100,YELLOW);
            setcolor(WHITE);
        }
        else
        {
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(200,100,BLACK);
        }

        Line l(125,100,100,200);
        l.Draw();
        Line l2(275,100,300,200);
        l2.Draw();
        Line l3(99,200,300,200);
        l3.Draw();
        Line l4(180,200,180,320);
        l4.Draw();
        Line l5(220,200,220,320);
        l5.Draw();
        Rec r(100,380,300,320);
        r.Draw();
        Line l6(250,200,310,270);
        l6.Draw();
        Circle c1(320,270,10);
        c1.Draw();
        Line l7(330,270,390,220);
        l7.Draw();
        Line l8(390,170,390,320);
        l8.Draw();
        Line l9(390,320,350,390);
        l9.Draw();
        Line l10(390,320,430,390);
        l10.Draw();
        Line l11(390,220,450,290);
        l11.Draw();
        Circle c2(390,120,50);
        c2.Draw();
        cout.flush();
        Sleep(1000);
        cout<<"after sleep";
        flag=!flag;
        cleardevice();
        i++;
    }
    while(i!=4);*/

    getch();
    closegraph();
    return 0;
}
