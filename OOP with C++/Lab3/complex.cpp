#include <iostream>
#include "comp.h"
using namespace std;
int SUM(int x = 4, int y = 5, int z = 6) { return x + y + z; }
int main()
{
    cout << "\nDefault Arg x,y,z: " << SUM();
    cout << "\nDefault Arg y,z: " << SUM(5);
    cout << "\nDefault Arg z: " << SUM(5, 9) << endl;
    cout << "Default Arg : " << SUM(5, 9, 11) << endl;
    Complex C1(3, 4), C2(5,10), C3;
    C3 = C1 - C2;
            cout << "C3 =  C1 - C2 " << endl;

    C3.printComplex();
    C3 = 7 - C2;
    cout << "\nC3 =  7 - C2" << endl;
    C3.printComplex();
    C3 = C2 - 7;
    cout << "\nC3 = C2 - 7" << endl;
    C3.printComplex();
    C1 -= C2;
    cout << "\nC2 = -=C1:" << endl;
    C1.printComplex();
    C2 = --C1;
    cout << "\nC2 = --C1:" << endl;
    C2.printComplex();
    cout << "C1:";
    C1.printComplex();
    C2 = C1--;
    cout << "\nC2 = C1--:" << endl;
    C2.printComplex();
    cout << "C1:";
    C1.printComplex();
    cout << "C1 == C2: " << (C1 == C2) << "\nC1 != C2: " << (C1 != C2) << endl;
    cout << "C1 > C2: " << (C1 > C2) << "\nC1 >= C2: " << (C1 >= C2) << endl;
    cout << "C1 < C2: " << (C1 < C2) << "\nC1 <= C2: " << (C1 <= C2) << endl;
    cout << "(int) C1: " << (int)C1 << endl;

    return 0;
}
