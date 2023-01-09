#include <iostream>
#include "stack.h"
using namespace std;
int main()
{
    Stack *S1 = new Stack(5);

    S1->Push(10);
    S1->Push(20);
    S1->Push(30);

    cout << S1->Peak()<<endl; // 30
    cout << S1->Peak()<<endl; // 30

    cout << S1->Pop()<<endl; // 30
    cout << S1->Pop()<<endl; // 20

    Stack *S2= new Stack(5);

    S2->Push(3);
    S2->Push(4);
    S2->Push(5);
    S2->Push(6);

    //cout << S2->Reverse();
    Stack *s3 = S2->Reverse();
    s3->PrintStack();
    cout<<"Pop\n";
    cout<< s3->Pop() ;
    s3->PrintStack();
    return 0;
}

