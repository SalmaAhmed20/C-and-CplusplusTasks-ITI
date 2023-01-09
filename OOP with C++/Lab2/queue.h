#include <iostream>
using namespace std;
class queue
{
private:
    int *Q;
    int head; // front
    int tail;
    int s;

public:
    int *getQ()
    {
        return this->Q;
    }
    void setQ(int *Q)
    {
        this->Q = Q;
    }
    int getHead()
    {
        return this->head;
    }
    void setHead(int head)
    {
        this->head = head; // front
    }
    int getTail()
    {
        return this->tail;
    }
    void setTail(int tail)
    {
        this->tail = tail; // rear
    }
    queue(int s)
    {
        this->Q = new int[s];
        this->head = -1;
        this->tail = -1;
        this->s = s;
        cout << "In Constructor" << endl;
    }
    queue()
    {
        this->Q = new int[5];
        this->head = -1;
        this->tail = -1;
        this->s = 5;
        cout << "In Constructor" << endl;
    }
    int enqueue(int data)
    {
        if ((this->tail == this->s - 1 && this->head == 0)) // full queue
            return 0;
        else
        {
            if (this->head == -1) // empty Queue
                this->head = this->tail = 0;
            else
                this->tail++;
            this->Q[this->tail] = data;
            return 1;
        }
    }
    int dequeue(int *data)
    {
        int i;
        if (this->head == -1)
            return 0;
        else
        {
            *data = Q[this->head];
            for (i = 0; i < this->tail; i++)
            {
                this->Q[i] = this->Q[i + 1];
            }
            this->tail--;
        }
    }
    ~queue()
    {
        delete (Q);
        cout << "In destructor" << endl;
    }
    int isEmpty (){
        return this->tail==-1&& this->head==-1;
    }
    int isFull (){
        return this->tail==this->s-1&& this->head==0;
    }
};
