#include<iostream>
#include "queue.h"
using namespace std;
int main()
{
    queue *Q =new queue(5);
    Q->enqueue(6);
    Q->enqueue(7);
    Q->enqueue(8);
    Q->enqueue(9);
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
