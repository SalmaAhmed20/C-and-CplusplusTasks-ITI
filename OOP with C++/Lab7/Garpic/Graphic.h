#ifndef GRAPHIC_H_INCLUDED
#define GRAPHIC_H_INCLUDED
#include <iostream>
#include <graphics.h>
using namespace std;
class Shape{
    protected:
    int color;
public:
    Shape(){color=15;}
    Shape(int c){color=c;}
    void setShapeColor(int c){color=c;}
    virtual void Draw()=0;

};
class Point
{
    int x;
    int y;
public:
    Point()
    {
        cout <<"Point Constructor\n";
        x=y=0;
    }
    Point(int L)
    {

        cout <<"Point Constructor\n";
        x=y=L;
    }
    Point (int _x,int _y)
    {

        cout <<"Point Constructor\n";
        x=_x;
        y=_y;
    }
    void setX(int x)
    {
        this->x=x;
    }
    void sety(int y)
    {
        this->y=y;
    }
    int getX()
    {
        return this->x;
    }
    int getY()
    {
        return this->y;
    }
    ~Point(){cout<<"\nPoint Dest\n";}
};
class Line :public Shape
{
    Point Start;
    Point End;
public:
    Line() {}
    Line(int x1,int y1,int x2,int y2,int c=15):Shape(c),Start(x1,y1),End(x2,y2)
    {

        cout <<"Line Constructor\n";
        /*Start.setX(x1);
        Start.sety(y1);
        End.setX(x2);
        End.sety(y2);*/
    }
    Line(Point P1,Point P2,int c=15):Shape(c),Start(P1.getX(),P1.getY()),End(P2.getX(),P2.getY())
    {
        cout <<"Line Constructor\n";
    }
    void Draw()
    {
        setcolor(color);
        line(Start.getX(),Start.getY(),End.getX(),End.getY());
    }
    ~Line()
    {
        cout<<"Line Dest\n";
    }


};
class Rec :public Shape
{
    Point UL;
    Point LR;
public:
    Rec() {}
    Rec(int x1,int y1,int x2,int y2,int c=15):Shape(c),UL(x1,y1),LR(x2,y2)
    {
        cout <<"Rectangle Constructor\n";
        /*Start.setX(x1);
        Start.sety(y1);
        End.setX(x2);
        End.sety(y2);*/
    }
    Rec(Point P1,Point P2,int c):Shape(c),UL(P1.getX(),P1.getY()),LR(P2.getX(),P2.getY())
    {
        cout <<"Rectangle Constructor\n";
    }
    void Draw()
    {
        setcolor(color);
        rectangle(UL.getX(),UL.getY(),LR.getX(),LR.getY());
    }
};
class Circle:public Shape
{
    Point P;
    int radius;
public:
    Circle()
    {
        cout <<"Circle Constructor\n";
    }
    Circle(int x1,int y1,int r,int c=15):Shape(c),P(x1,y1)
    {
        cout <<"Circle Constructor\n";
        radius=r;
    }
    void setR(int _r)
    {
        radius= _r;
    }

    int getR()
    {
        return radius;
    }
    void Draw()
    {
        setcolor(color);
        circle(P.getX(),P.getY(),getR());
    }
    ~Circle(){cout<<"\nCircle Des";}
};
class elipse:public Shape
{
    Point P;
    int startengle,endangle;
    int y_red,x_red;
public:
    elipse(int x1,int y1,int x_r,int y_r,int start,int enda,int c=15):P(x1,y1)
    {
        this->startengle=start;
        this->endangle=enda;
        this->x_red=x_r;
        this->y_red=y_r;
    }
    void Draw()
    {
        ellipse(P.getX(),P.getY(), startengle,
                endangle, x_red, y_red);
    }

};
class Picture
{
   Shape** ShapesArray;
   int ShapesNumber;
public:
    Picture()
    {
        this->ShapesNumber=0;
    }
    Picture(Shape** arr,int ShN)
    {
        this->ShapesArray=arr;
        this->ShapesNumber=ShN;
    }
    void DrawPic()
    {
        for (int i =0 ; i<ShapesNumber; i++)
        {
          ShapesArray[i]->Draw();
        }
    }
};
#endif // GRAPHIC_H_INCLUDED
