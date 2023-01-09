#include <iostream>
using namespace std;

class GeoShape
{
private:
    float Dim1;
    float Dim2;
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
    float CalcArea()
    {
        return 0.0;
    }
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
        cout <<"Rectangle Area: ";
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
        cout <<"Square Area: ";
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
        cout <<"Triangle Area: ";
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
        cout <<"Circle Area: ";
        return 3.14*this->GetDim1()*this->GetDim2();
    }
};
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
    // Wrong logic
    cout <<"\n-----Wrong Logic----\n";
    S1.SetDim2(7);
    cout << S1.CalcArea()<<endl;
    return 0;
}
