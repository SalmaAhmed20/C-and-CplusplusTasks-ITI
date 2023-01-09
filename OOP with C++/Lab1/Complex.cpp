#include <iostream>
using namespace std;
class Complex
{
private:
    int Real;
    int Imaginary;

public:
    int getReal()
    {
        return this->Real;
    }
    void setReal(int Real)
    {
        this->Real = Real;
    }
    int getImaginary()
    {
        return this->Imaginary;
    }
    void setImaginary(int Imaginary)
    {
        this->Imaginary = Imaginary;
    }
    Complex Add(Complex C)
    {
        Complex CR;
        CR.setReal(this->getReal() + C.getReal());
        CR.setImaginary(this->getImaginary() + C.getImaginary());
        return CR;
    }
    Complex Subtract(Complex C);
};
Complex Complex::Subtract(Complex C)
{
    Complex CR;
    CR.setReal(this->getReal() - C.getReal());
    CR.setImaginary(this->getImaginary() - C.getImaginary());
    return CR;
}
Complex Add(Complex C1, Complex C2)
{
    Complex CR;
    CR.setReal(C1.getReal() + C2.getReal());
    CR.setImaginary(C1.getImaginary() + C2.getImaginary());
    return CR;
}
Complex Subtract(Complex C1, Complex C2)
{
    Complex CR;
    CR.setReal(C1.getReal() - C2.getReal());
    CR.setImaginary(C1.getImaginary() - C2.getImaginary());
    return CR;
}
void print(Complex C)
{
    int r = C.getReal();
    int i = C.getImaginary();
    if (r > 0)
    {
        if (i > 0)
            cout << r << "+" << i << "i\n";
        else
        {

            if (i == 0 && r != 0)
                cout << r << "\n";
            if (i < 0)
                cout << r << i << "i\n";
            if (r == 0 && i == 0)
                cout << 0;
        }
    }
    else
    {
        if (r == 0 && i != 0)
            cout << i << "i\n";
    }
}
int main()
{
    Complex C1;
    C1.setReal(5);
    C1.setImaginary(3);
    print(C1);
    cout << endl;
    Complex C2;
    C2.setReal(5);
    C2.setImaginary(5);
    print(C2);
    cout << endl;
    Complex C3;
    C3 = Add(C1, C2);
    cout << "Addition: ";
    print(C3);
    cout << endl;
    cout << "Subtract: ";
    C3 = Subtract(C1, C2);
    print(C3);
    cout << endl;
    C3 = C1.Add(C2);
    cout << "Addition one arg: ";
    print(C3);
    cout << endl;
    return 0;
}
