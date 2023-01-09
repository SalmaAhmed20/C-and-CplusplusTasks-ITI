#include <iostream>

using namespace std;
class Base {
    int x;
protected:
    int y;
public :
     Base() {x=y=0; cout << "Base Constructor"<<endl;}
     Base(int x,int y) {this->x=x;this->y=y; cout << "Base Constructor"<<endl;}
     Base(int x) {this->x=x;this->y=0; cout << "Base Constructor"<<endl;}
     ~Base (){cout << "Base Destructor"<<endl;}
     void setx(int x){this->x=x;}
     int getx(){return x;}
     void sety(int y){this->y=y;}
     int gety(){return y;}
     int Sum(){cout <<"Base Sum\n";return x+y;}
};
class Derive:public Base{
    int z;
    public:
    Derive():Base() {z=0; cout << "Derive Constructor"<<endl;}
     Derive(int z,int x,int y):Base(x,y) {this->z=z; cout << "Derive Constructor"<<endl;}
     Derive(int z,int x):Base(x) {this->z=z; cout << "Derive Constructor"<<endl;}
     ~Derive (){cout << "Derive Destructor"<<endl;}
     void setz(int z){this->z=z;}
     int getz(){return z;}
     int Sum(){cout <<"Derive Sum\n";return Base::Sum()+z;}
};
int main()
{
    Base B (5,6);
    cout<<"Sum"<<B.Sum()<<endl;
    Derive D(5,10,20);
    cout<<"Sum"<<D.Sum()<<endl;

    return 0;
}
