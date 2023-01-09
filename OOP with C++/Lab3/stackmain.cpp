#include <iostream>
#include "stack.h"
using namespace std;
int main()
{
    cout << "Case 1" << endl;
    Stack S1;
    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);
    cout << endl;
    viewContent(S1);
    Stack S2 = S1;
    S2.Pop();//40
    cout << endl;
    viewContent(S2);
     cout << endl;
    viewContent(S1);
    S2.Pop();//30
    S2.Pop();//20
    S2.Pop();//10
    S2.Push(2);
    S2.Push(55);
    
    Stack S3 = S1+S2;
    viewContent(S3);

    

}
