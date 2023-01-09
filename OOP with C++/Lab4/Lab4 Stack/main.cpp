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
    int Peak()
    {
        return this->Stk[this->Tos - 1];
    }

    Stack Reverse() // return new Stack "with reversed internal array of original Stack"
    {
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
        delete[] Stk;
        this->Stk = new int[this->Size];
        for (int i = 0; i < Tos; i++)
            this->Stk[i] = s1.Stk[i];
        return *this;
    }
    Stack operator+(Stack &St)
    {
        int i = 0;
        Stack re;
        re.Size = this->Size + St.Size;
        re.Tos = this->Tos +St.Tos;
        delete[] re.Stk;
        re.Stk = new int[re.Size];
        for (i = 0; i < this->Tos; i++)
        {
            re.Stk[i] = this->Stk[i];
        }
        for(int j =0 ; j <St.Tos; j++)
        {
            re.Stk[j+this->Tos] = St.Stk[j];
        }
        return re;
    }
    int& operator [] (int c)
    {
        if ( c > this->Tos || c >this->Size)
        {
            cout<<"Exceed Bound\n";
           //return ;
        }
        else
            return this->Stk[c];

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
    Stack S3 (3);
    S3.Push(5);
    S3.Push(7);
    S3.Push(9);
    viewContent(S3);

    Stack S4;
    S4= S1+S3;
    viewContent(S4);
    cout<< endl<<S1[1];
    S1[1] = 6;
    cout<< endl<<S1[1];
    return 0;


}
