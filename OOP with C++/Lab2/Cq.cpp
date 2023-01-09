#include <iostream>
#include "CirculerQ.h"
using namespace std;
int main()
{
     Queue *Q =new Queue();
    Q->enqueue(6);
    Q->enqueue(7);
    Q->enqueue(8);
    Q->enqueue(9);
    Q->Display();
    cout<<"\n\n";
    int data;
    Q->dequeue(&data);
    cout<<data<<endl;
    Q->dequeue(&data);
    cout<<data<<endl;
    Q->dequeue(&data);
    cout<<data<<endl;
    Q->dequeue(&data);
    cout<<data<<endl;
    return 0;
}
