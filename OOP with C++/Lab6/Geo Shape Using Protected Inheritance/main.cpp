#include <iostream>
using namespace std;

class GeoShape
{
private:
    float Dim1;
    float Dim2;
protected:
    int GetDim1()
    {
        return Dim1;
    }
    void SetDim1(float val)
    {
        Dim1 = val;
    }
    float GetDim2()
    {
        return Dim2;
    }
    void SetDim2(float val)
    {
        Dim2 = val;
    }
public:
    GeoShape()
    {
        cout<<"GeoShape Parameterless Constructor\n";
    }
    GeoShape(float d)
    {
        this->Dim1=this->Dim2=d;
        cout<<"GeoShape 1 Parameter Constructor\n";
    }
    GeoShape(float d1,float d2)
    {
        this->Dim1=d1;
        this->Dim2=d2;
        cout<<"GeoShape 2 Parameter Constructor\n";
    }
    virtual float CalcArea()=0;
    ~GeoShape()
    {
        cout <<"GeoShape Destructor\n";
    }
};
class Rectangle : public GeoShape
{
public:
    Rectangle(float d1,float d2):GeoShape(d1,d2)
    {
        cout <<"Rectangle Constructor\n";
    }
    ~Rectangle()
    {
        cout <<"Rectangle Destructor\n";
    }
    float CalcArea()
    {
        cout <<"\nRectangle Area: ";
        return this->GetDim1()*this->GetDim2();
    }
};
class Square : public GeoShape
{
public:
    Square(float d1):GeoShape(d1)
    {
        cout <<"Square Constructor\n";
    }
    ~Square()
    {
        cout <<"Square Destructor\n";
    }
    float CalcArea()
    {
        cout <<"\nSquare Area: ";
        return this->GetDim1()*this->GetDim2();
    }
};
class Triangle : public GeoShape
{
public:
    Triangle(float d1,float d2):GeoShape(d1,d2)
    {
        cout <<"Triangle Constructor\n";
    }
    ~Triangle()
    {
        cout <<"Triangle Destructor\n";
    }
    float CalcArea()
    {
        cout <<"\nTriangle Area: ";
        return 0.5*this->GetDim1()*this->GetDim2();
    }
};
class Circle : public GeoShape
{
public:
    Circle(float d1):GeoShape(d1)
    {
        cout <<"Circle Constructor\n";
    }
    ~Circle()
    {
        cout <<"Circle Destructor\n";
    }
    float CalcArea()
    {
        cout <<"\nCircle Area: ";
        return 3.14*this->GetDim1()*this->GetDim2();
    }
};
float sumOfAllShapesArea(Rectangle r,Circle c,Triangle t, Square s)
{
    return r.CalcArea()+c.CalcArea()+t.CalcArea()+s.CalcArea();
}
float sumOfAllShapesArea(GeoShape* arr[],int s)
{
    float sum =0;
    for (int i =0 ; i < s; i++)
    {
        sum+=arr[i]->CalcArea();
    }
    return sum;
}

int main()
{
    Rectangle R1 (5,4);
    cout <<endl;
    cout << R1.CalcArea()<<endl;
    cout <<endl;
    Square S1 (6);
    cout <<endl;
    cout << S1.CalcArea()<<endl;
    cout <<endl;
    Triangle T1 (5,4);
    cout <<endl;
    cout << T1.CalcArea()<<endl;
    cout <<endl;
    Circle C1 (6);
    cout <<endl;
    cout << C1.CalcArea()<<endl;
    GeoShape** arr=new GeoShape* [4];
    arr[0]=&R1;
    arr[1]=&C1;
    arr[2]=&S1;
    arr[3]=&T1;
    cout << "\nSum of all shapes=  " <<sumOfAllShapesArea(R1,C1,T1,S1)<<endl;
    cout << "\nLate +inheritance Sum of all shapes=  " <<sumOfAllShapesArea(arr,4)<<endl;
    cout <<"------------------------------------"<<endl;
    return 0;
}
