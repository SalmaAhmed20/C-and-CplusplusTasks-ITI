#include<iostream>
using namespace std;
class Stack
{
private:
    int *Stk;
    int Tos, Size;

public:
    Stack(int size)
    {
        this->Stk = new int [size];
        this->Size = size;
        this->Tos = 0;
    }
    int Push(int data)
    {
        if (this->Tos == this->Size)
            return 0;
        else
        {
            this->Stk[this->Tos] = data;
            this->Tos++;
            return 1;
        }
    }
    int Pop()
    {
        if (this->Tos == 0)
            cout <<"Empty"<<endl;
        else
        {
            int data = this->Stk[this->Tos - 1];
            this->Tos--;
            return data;
        }
    }
    int Peak() { return this->Stk[this->Tos - 1]; }

    Stack* Reverse() // return new Stack "with reversed internal array of original Stack"
    {
        int data;
        Stack *reversed =new Stack(this->Size);
        while (this->Tos !=0)
        {
            data=this->Pop();
            reversed->Push(data);
        }
        return reversed;

    }

    void PrintStack()
    {
        cout<<"\nin print\n";
        for (int i = 0; i < this->Tos; i++)
        {
            cout <<this->Stk[i] <<" " << endl;
        }
    }
};