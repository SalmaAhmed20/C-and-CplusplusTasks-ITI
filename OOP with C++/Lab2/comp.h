#include <iostream>
using namespace std;
class Complex
{
private:
    int Real;
    int Imaginary;
public:
    Complex(int r, int i)
    {
        this->Real = r;
        this->Imaginary = i;
        cout << "In Constructor" << endl;
    }
    Complex(int r)
    {
        this->Real = r;
        this->Imaginary = 0;
        cout << "In Constructor" << endl;
    }
    Complex()
    {
        cout << "In Constructor" <<endl;
    }
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

    ~Complex() { cout << "In Destructor\n";}
    Complex Addcopmlex(Complex C);
    Complex subComplex(Complex C);
    void printComplex();
};

void Complex ::printComplex()
{
    int r = this->getReal();
    int i = this->getImaginary();
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
Complex Complex::Addcopmlex(Complex C)
{
    Complex CR;
    CR.setReal(this->getReal() + C.getReal());
    CR.setImaginary(this->getImaginary() + C.getImaginary());
    return CR;
}
Complex Complex::subComplex(Complex C)
{
    Complex CR;
    CR.setReal(this->getReal() - C.getReal());
    CR.setImaginary(this->getImaginary() - C.getImaginary());
    return CR;
}