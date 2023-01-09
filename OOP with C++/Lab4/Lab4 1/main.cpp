#include <iostream>
#include <string>
#include <sstream>
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
    int getReal() const
    {
        return this->Real;
    }
    void setReal(int Real)
    {
        this->Real = Real;
    }
    int getImaginary() const
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
    Complex operator = (Complex C)
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
    if(Real >0 ||Real <0)
    {
        if(Imaginary < 0)
            if(Imaginary == -1)
                cout << "The complex number is: "<< Real << "-i" << endl;
            else
                cout << "The complex number is: "<< Real << Imaginary << "i" << endl;
        else if(Imaginary == 1)
            cout << "The complex number is: "<< Real << " + i"<< endl;
        else if (Imaginary ==0) cout<< "The complex number is: "<< Real<<endl;
        else
            cout << "The complex number is: "<< Real<<  " + " << Imaginary << "i" <<endl;
    }
    else
    {
        if(Imaginary < 0)
            if(Imaginary == -1)
                cout << "The complex number is: "<<  "-i" << endl;
            else
                cout << "The complex number is: "<< Imaginary << "i" << endl;
        else if(Imaginary == 1)
            cout << "The complex number is: "<< " + i"<< endl;
        else if (Imaginary ==0) cout<<0<<endl;
        else
            cout << "The complex number is: "<<  Imaginary << "i" <<endl;
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
int SUM(int x = 4, int y = 5, int z = 6)
{
    return x + y + z;
}
ostream & operator << (ostream &out, const Complex &c)
{
    if(c.getReal() >0 ||c.getReal() <0)
    {
        if(c.getImaginary() < 0)
            if(c.getImaginary() == -1)
                out << "The complex number is: "<< c.getReal() << "-i" << endl;
            else
                out << "The complex number is: "<< c.getReal() << c.getImaginary() << "i" << endl;
        else if(c.getImaginary() == 1)
            out << "The complex number is: "<<  c.getReal() << " + i"<< endl;
        else if (c.getImaginary() ==0) out<< "The complex number is: "<<  c.getReal()<<endl;
        else
            out << "The complex number is: "<<  c.getReal()<<  " + " << c.getImaginary() << "i" <<endl;
    }
    else
    {
        if(c.getImaginary() < 0)
            if(c.getImaginary() == -1)
                out << "The complex number is: "<<  "-i" << endl;
            else
                out << "The complex number is: "<< c.getImaginary() << "i" << endl;
        else if(c.getImaginary() == 1)
            out << "The complex number is: "<< " + i"<< endl;
        else if (c.getImaginary() ==0) out<<0<<endl;
        else
            out << "The complex number is: "<<  c.getImaginary() << "i" <<endl;
    }
    return out;
}

istream & operator >> (istream &in,  Complex &c)
{
    int r,i;
    string s;
    in >>s;
    int idx=s.find('+');
    if (idx==-1)
    {
        idx= s.find('-');
        if(idx !=-1 && idx !=0)
        {
            int idx2=s.find('i');
            if (idx2 !=-1)
            {
                stringstream geek(s.substr(0,idx));
                geek>>r;
                c.setReal(r);
                stringstream geek2(s.substr(idx,idx2-1));
                geek2>>i;
                c.setImaginary(i);
            }
            else
            {
                stringstream geek(s.substr(0,idx));
                geek>>r;
                c.setReal(r);
            }
        }
        else
        {

            stringstream geek(s);
            geek>>r;
            c.setReal(r);
            c.setImaginary(0);
        }
    }
    else
    {
        int idx2=s.find('i');
        int r1=0,i1=0;
        stringstream geek(s.substr(0,idx));
        geek>>r1;
        //string s2=s.substr(0,idx);
        //cout<<"rrrr "<<s2;
        c.setReal(r1);
        stringstream geek2(s.substr(idx+1,idx2-1));
        geek2>>i1;
        c.setImaginary(i1);

    }
    //cout<<"In overload"<<endl;
    //c.printComplex();
    return in;
}

int main()
{
    cout << "\nDefault Arg x,y,z: " << SUM();
    cout << "\nDefault Arg y,z: " << SUM(5);
    cout << "\nDefault Arg z: " << SUM(5, 9) << endl;
    cout << "Default Arg : " << SUM(5, 9, 11) << endl;
    Complex C1(3, 4), C2(5,10), C3,C10;
    C3 = C1 - C2;
    cout << "C3 =  C1 - C2 " << endl;

    C3.printComplex();
    C3 = 7 - C2;
    cout << "\nC3 =  7 - C2" << endl;
    C3.printComplex();
    C3 = C2 - 7;
    cout << "\nC3 = C2 - 7" << endl;
    C3.printComplex();
    C1 -= C2;
    cout << "\nC2 = -=C1:" << endl;
    C1.printComplex();
    C2 = --C1;
    cout << "\nC2 = --C1:" << endl;
    C2.printComplex();
    cout << "C1:";
    C1.printComplex();
    C2 = C1--;
    cout << "\nC2 = C1--:" << endl;
    C2.printComplex();
    cout << "C1:";
    C1.printComplex();
    cout << "C1 == C2: " << (C1 == C2) << "\nC1 != C2: " << (C1 != C2) << endl;
    cout << "C1 > C2: " << (C1 > C2) << "\nC1 >= C2: " << (C1 >= C2) << endl;
    cout << "C1 < C2: " << (C1 < C2) << "\nC1 <= C2: " << (C1 <= C2) << endl;
    cout << "(int) C1: " << (int)C1 << endl;
    cout << "C1['R']: " << C1['R'] << endl;

    cin >>C10;
    cout<<C10;
    return 0;
}
