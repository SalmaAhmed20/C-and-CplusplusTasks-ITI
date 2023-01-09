#include <iostream>
using namespace std;
#define MaxSize 5
class Queue
{
private:
    int ArrData[MaxSize];
    int head;
    int tail;

public:
Queue(){
    this->head=this->tail=-1;
}
    int enqueue(int data)
    {
        if ((this->tail == MaxSize - 1 && this->head == 0)) // full queue
            return 0;
        else
        {
            if (this->head == -1) // empty Queue
                this->head = this->tail = 0;
            else if (this->tail == MaxSize - 1 && this->head != 0) // we have empty places at start of queue so add in start
                this->tail = 0;
            else
                this->tail++;
            this->ArrData[this->tail] = data;
            return 1;
        }
    }
    int dequeue(int *data)
    {

        if (this->head == -1)
            return 0;
        *data = this->ArrData[this->head];
        if (this->head == this->tail) // only one element left
        {
            this->head = this->tail = -1;
        }
        else if (this->head == MaxSize - 1)
            this->head = 0;
        else
            this->head++;
        return 1;
    }
    void Display()
    {
        int i = 0;
        if (this->head == -1)
        {
            return;
        }
        cout <<"\nElements : ";
        if (this->tail >= this->head)
        {
            for (i = this->head; i <= this->tail; i++)
                cout<<this->ArrData[i];
        }
        else
        {
            for (i = this->head; i < MaxSize-1; i++)
                cout << this->ArrData[i];

            for (i = 0; i <= this->tail; i++)
               cout<<this->ArrData[i];
        }
    }
};
