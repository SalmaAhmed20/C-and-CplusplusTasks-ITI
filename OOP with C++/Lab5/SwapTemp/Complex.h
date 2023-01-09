#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
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
        //cout << "In Constructor" << endl;
    }
    Complex(int r)
    {
        this->Real = r;
        this->Imaginary = r;
        //cout << "In Constructor" << endl;
    }
    Complex()
    {
        //cout << "In Constructor" << endl;
    }
    Complex(const Complex &C)
    {
        //cout << "In Copy Constructor" << endl;
        this->Real = C.Real;
        this->Imaginary = C.Imaginary;
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

    ~Complex()   //cout << "In Destructor\n";
    {
    }
    Complex Addcopmlex(Complex C);
    Complex subComplex(Complex C);
    void printComplex();
    Complex operator - ( Complex const &C)
    {
        Complex re;
        re.Real = this->Real - C.Real;
        re.Imaginary = this->Imaginary - C.Imaginary;
        return re;
    }
    Complex operator - (int val)
    {
        Complex re;
        re.Real = this->Real - val;
        re.Imaginary = this->Imaginary;
        return re;
    }
    Complex operator -= ( Complex const &C)
    {
        this->Real -= C.Real;
        this->Imaginary -= C.Imaginary;
        return *this;
    }
    Complex operator --() //--c
    {
        this->Real--;
        return *this;
    }
    Complex operator --(int) // c--
    {
        Complex temp(*this);
        this->Real--;
        return temp;
    }
    Complex& operator = (Complex C)
    {
        this->Real = C.Real;
        this->Imaginary = C.Imaginary;
        return *this;
    }
    int operator == (Complex C)
    {
        return (this->Real == C.Real && this->Imaginary == C.Imaginary);
    }
    int operator!=(Complex C)
    {
        return (this->Real != C.Real || this->Imaginary != C.Imaginary);
    }
    int operator>(Complex C)
    {
        return (this->Real > C.Real && this->Imaginary > C.Imaginary);
    }
    int operator < (Complex C)
    {
        return (this->Real < C.Real && this->Imaginary < C.Imaginary);
    }
    int operator >= (Complex C)
    {
        return (this->Real >= C.Real && this->Imaginary >= C.Imaginary);
    }
    int operator <= (Complex C)
    {
        return (this->Real <= C.Real && this->Imaginary <= C.Imaginary);
    }
    operator int ()
    {
        return this->Real + this->Imaginary;
    }
    int operator [] (char c)
    {
        if (c=='R'||c=='r')
            return this->Real;
        else if (c=='I'||c=='i')
            return this->Imaginary;
        else
        {
            cout<<"Wrong Option\n";
            return -1;
        }

    }
};
Complex operator-(int N, Complex &C)
{
    Complex re;
    re.setReal(7 - C.getReal());
    re.setImaginary(C.getImaginary());
    return re;
}

void Complex ::printComplex()
{
    if(Imaginary < 0)
        if(Imaginary == -1)
            cout << "The complex number is: "<< Real << "-i" << endl;
        else
            cout << "The complex number is: "<< Real << Imaginary << "i" << endl;
    else if(Imaginary == 1)
        cout << "The complex number is: "<< Real << " + i"<< endl;
    else
        cout << "The complex number is: "<< Real << " + " << Imaginary << "i" <<endl;
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


#endif // COMPLEX_H_INCLUDED
