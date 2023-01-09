#include <iostream>
#include "Complex.h"
using namespace std;
template <typename T>
Swap(T &x,T &Y)
{
    T temp= x;
    x=Y;
    Y=temp;
}
int main()
{
    int a=3, b = 5;
    Swap<int>(a,b);
    cout<<"\nAfter Swap: "<<a<<", "<<b<<endl;

    char Ch1='Z', Ch2='O';
    Swap<char>(Ch1, Ch2);
    cout<<"\nAfter Swap: "<<Ch1<<", "<<Ch2<<endl;

    Complex C1(5), C2(2,7);
    Swap<Complex>(C1, C2);

    cout<<"\nComplex1 After Swap: "<<endl;
    C1.printComplex();
    cout<<"\nComplex2 After Swap: "<<endl;
    C2.printComplex();
    return 0;
}
