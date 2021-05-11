#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
public:
    Complex(double r = 0.0, double i = 0.0)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator*(Complex);
    Complex operator/(Complex);
    double operator!(void);
    Complex operator~(void);
    bool operator==(Complex);
    void display();

private:
    double real, imag;
};

Complex Complex::operator+(Complex c)
{
    Complex temp;
    temp.real = real + c.real;
    temp.imag = imag + c.imag;
    return temp;
}

Complex Complex::operator-(Complex c)
{
    Complex temp;
    temp.real = real - c.real;
    temp.imag = imag - c.imag;
    return temp;
}

Complex Complex::operator*(Complex c)
{
    Complex temp;
    temp.real = real * c.real - imag * c.imag;
    temp.imag = imag * c.real + real * c.imag;
    return temp;
}

Complex Complex::operator/(Complex c)
{
    Complex temp;
    temp.real = (real * c.real + imag * c.imag) / (imag * imag + c.imag * c.imag);
    temp.imag = (imag * c.real - real * c.imag) / (imag * imag + c.imag * c.imag);
    return temp;
}

double Complex::operator!(void)
{
    return sqrt(real * real + imag * imag);
}

Complex Complex::operator~(void)
{
    Complex temp;
    temp.real = real;
    temp.imag = 0.0 - imag;
    return temp;
}

bool Complex::operator==(Complex c)
{
    if (real == c.real && imag == c.imag)
        return true;
    else
        return false;
}

void Complex::display()
{
    string str;
    str = (imag < 0) ? "" : "+";
    if (imag != 0.0)
        cout << real << str << imag << "i" << endl;
    else if (imag == 0.0)
        cout << real << endl;
}

int main(void)
{
    Complex c;
    Complex c1(3, 4);
    Complex c2(6, 8);
    Complex c3(6, 8);
    Complex c4(6, 8);
    c = c1 + c2;
    c.display();
    c = c1 - c2;
    c.display();
    c = c1 * c2;
    c.display();
    c = c1 / c2;
    c.display();
    cout << !c3 << endl;
    c = ~c3;
    c.display();
    cout << (c4 == c2) << endl;
    return 0;
}