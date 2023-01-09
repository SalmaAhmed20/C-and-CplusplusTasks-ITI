#include <iostream>
#include "comp.h"
using namespace std;

int main()
{
    Complex C1(3, 4), C2(5), C3;
    C3 = C1.Addcopmlex(C2);
    C3.printComplex();
    return 0;
}
