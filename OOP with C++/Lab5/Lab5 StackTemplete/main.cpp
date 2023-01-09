#include <iostream>
#include "Complex.h"
using namespace std;
template <class T>
class Stack
{
private:
    T *Stk;
    int Tos, Size;
    static int counter;

public:
    Stack(int size)
    {
        this->Stk = new T[size];
        this->Size = size;
        this->Tos = 0;
        counter++;
        // cout << "Constructor" << endl;
    }
    Stack()
    {
        this->Stk = new T[5];
        this->Size = 5;
        this->Tos = 0;
        this->counter++;
        // cout << "Constructor" << endl;
    }
    Stack( Stack &s)
    {
        this->Stk = new T[s.Size];
        this->Size = s.Size;
        this->Tos = s.Tos;
        for (int i = 0; i < this->Tos; i++)
        {
            this->Stk[i] = s.Stk[i];
        }
        this->counter++;
        // cout << "Copy Constructor" << endl;
    }
    static int getCounter()
    {
        return counter;
    }
    int Push(T data)
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
    T Pop()
    {
        if (this->Tos == 0)
        {
            cout << "Empty" << endl;
            //return ;
        }
        else
        {
            T data = this->Stk[this->Tos - 1];
            this->Tos--;
            return data;
        }
    }
    T Peak()
    {
        return this->Stk[this->Tos - 1];
    }

    Stack<T> Reverse() // return new Stack "with reversed internal array of original Stack"
    {
        Stack <T> reversed(this->Size);
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
    Stack<T> operator=(const Stack &s1)
    {
        this->Size = s1.Size;
        this->Tos = s1.Tos;
        delete[] Stk;
        this->Stk = new int[this->Size];
        for (int i = 0; i < Tos; i++)
            this->Stk[i] = s1.Stk[i];
        return *this;
    }
    Stack<T> operator+(Stack &St)
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
    T& operator [] (int c)
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
        //for (int i = 0; i < this->Tos; i++)
        //  this->Stk[i] = -1;
        delete[] Stk;
        this->counter--;
        // cout << "Destructor" << endl;
    }
    friend void viewContent(Stack <T>);
};
template <class T>
int Stack<T>::counter=0;

template <typename T>
void viewContent(Stack <T> s)
{
    cout << "\nin print\n";
    for (int i = 0; i < s.Tos; i++)
    {
        cout << s.Stk[i] << " " << endl;
    }
}
int main()
{
    Stack<int> S;
    S.Push(10);
    S.Push(20);

    cout<< S.Pop();
    cout<<endl;
    Stack<char> S2(3);
    S2.Push('A');
    S2.Push('B');
    S2.Push('C');
    cout<< S2.Pop()<<endl;
    Complex C1(5), C2(2,7);
    Stack<Complex> S3(4);
    S3.Push(C1);
    S3.Push(C2);
    Complex C =S3.Pop();
    C.printComplex();
    return 0;
}
