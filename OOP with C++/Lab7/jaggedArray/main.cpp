#include <iostream>
#include <graphics.h>
using namespace std;
class Shape
{
protected:
    int color;
public:
    Shape()
    {
        color=15;
    }
    Shape(int c)
    {
        color=c;
    }
    void setShapeColor(int c)
    {
        color=c;
    }
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
    Shape*** ShapesArray; // pointer to array pointers to array of pointers
    int*sizes;
    int ShapesNumber;
public:
    Picture()
    {
        this->ShapesNumber=0;
    }
    Picture(Shape*** arr,int ShN,int* s)
    {
        this->ShapesArray=arr;
        this->sizes=s;
        this->ShapesNumber=ShN;
    }
    void DrawPic()
    {
        for (int i =0 ; i<ShapesNumber; i++)
        {
            for(int j=0; j<sizes[i]; j++)
            {
                ShapesArray[i][j]->Draw();
            }
        }
    }
};
int main()
{
    initwindow(1500,1500);
    int sizes[3]= {2,3,1};
    Shape ***arr=new Shape**[3];
    Rec r1(200,100,275,150);
    Rec r2(300,100,320,150);
    Circle c1(300,300,60),c2(600,150,60),c3(100,320,40);
    Line ll(90,90,90,200);
    arr[0] = new Shape*[2] { &r1, &r2 };
    arr[1] = new Shape*[3] { &c1, &c2,&c3 };
    arr[2]=new Shape*[1] {&ll};
    Picture p(arr,3,sizes);
    p.DrawPic();
    getch();
    closegraph();
    return 0;
}
