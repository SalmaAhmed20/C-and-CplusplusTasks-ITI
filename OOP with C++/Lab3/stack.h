#include <iostream>
using namespace std;
class Stack
{
private:
    int *Stk;
    int Tos, Size;

public:
    Stack(int size)
    {
        this->Stk = new int[size];
        this->Size = size;
        this->Tos = 0;
        // cout << "Constructor" << endl;
    }
    Stack()
    {
        this->Stk = new int[5];
        this->Size = 5;
        this->Tos = 0;
        // cout << "Constructor" << endl;
    }
    Stack( Stack &s)
    {
        this->Stk = new int[s.Size];
        this->Size = s.Size;
        this->Tos = s.Tos;
        for (int i = 0; i < this->Tos; i++)
        {
            this->Stk[i] = s.Stk[i];
        }
        // cout << "Copy Constructor" << endl;
    }
    int Push(int data)
    {
        if (this->Tos >= this->Size)
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
        {
            cout << "Empty" << endl;
            return -400;
        }
        else
        {
            int data = this->Stk[this->Tos - 1];
            this->Tos--;
            return data;
        }
    }
    int Peak() { return this->Stk[this->Tos - 1]; }

    Stack Reverse() // return new Stack "with reversed internal array of original Stack"
    {
        int data;
        Stack reversed(this->Size);
        reversed.Tos = 0;
        for (int i = 0; i < this->Tos; i++)
        {
            reversed.Push(this->Stk[i]);
        }
        return reversed;
    }
    int isEmpty()
    {
        return this->Tos == 0;
    }
    int isFull()
    {
        return this->Tos >= this->Size;
    }
    Stack operator=(const Stack &s1)
    {
        this->Size = s1.Size;
        this->Tos = s1.Tos;
        delete[] this->Stk;
        this->Stk = new int[this->Size];
        for (int i = 0; i < Tos; i++)
            this->Stk[i] = s1.Stk[i];
        return *this;
    }
    Stack &operator+(Stack &St)
    {
        int i = 0;
        Stack re;
        re.Size = this->Size + St.Size;
        delete[] re.Stk;
        re.Stk = new int[re.Size];
        for (i = 0; i < this->Tos; i++){
            re.Stk[i] = this->Stk[i];
            re.Tos++;
        }
        for(int j =0 ; j <St.Tos;j++)
        {
             re.Stk[i] = this->Stk[i];
            re.Tos++;
            i++;
        }
    }
    ~Stack()
    {
        for (int i = 0; i < this->Tos; i++)
            this->Stk[i] = -1;
        delete[] Stk;
        // cout << "Destructor" << endl;
    }
    friend void viewContent(Stack);
};
void viewContent(Stack s)
{
    cout << "\nin print\n";
    for (int i = 0; i < s.Tos; i++)
    {
        cout << s.Stk[i] << " " << endl;
    }
}