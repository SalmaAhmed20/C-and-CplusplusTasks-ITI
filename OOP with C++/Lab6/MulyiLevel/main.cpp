#include <iostream>

using namespace std;
class Parent
{
public :
    virtual void Method()
    {
        cout <<"Parent Method\n";
    }
};
class Child :public Parent
{
public:
    void Method()
    {
        cout <<"Child Method\n";
    }
};
class GrandChild:public Child
{
public:
    void Method()
    {
        cout <<"GrandChild Method\n";
    }
};
int main()
{
    Child c1;
    Parent * Pptr=&c1;
    Pptr->Method();
    GrandChild gc1;
    Child * Cptr=&gc1;
    Cptr->Method();

    return 0;
}
