#include <iostream>
using namespace std;

class Rnum
{
public:
    Rnum(int, int);
    void display(void);
    Rnum operator+(Rnum);
    Rnum operator-(Rnum);
    Rnum operator*(Rnum);
    Rnum operator/(Rnum);
    bool operator==(Rnum);
    Rnum simplification(Rnum);

private:
    int numerator;
    int denominator;
};

Rnum::Rnum(int n = 1, int d = 1)
{
    if (d == 0)
    {
        cout << "Denominator cont be 0!" << endl;
        return;
    }
    numerator = n;
    denominator = d;
}

void Rnum::display(void)
{
    cout << numerator << "/" << denominator << endl;
}

Rnum Rnum::operator+(Rnum c)
{
    Rnum temp;
    temp.denominator = c.denominator * denominator;
    if (temp.denominator == 0)
    {
        cout << "Denominator is 0!" << endl;
        return;
    }
    temp.numerator = denominator * c.numerator + numerator * c.denominator;
    return simplification(temp);
}

Rnum Rnum::operator-(Rnum c)
{
    Rnum temp;
    temp.denominator = c.denominator * denominator;
    if (temp.denominator == 0)
    {
        cout << "Denominator is 0!" << endl;
        return;
    }
    temp.numerator = numerator * c.denominator - denominator * c.numerator;
    return simplification(temp);
}

Rnum Rnum::operator*(Rnum c)
{
    Rnum temp;
    temp.denominator = denominator * c.denominator;
    temp.numerator = numerator * c.numerator;
    return simplification(temp);
}

Rnum Rnum::operator/(Rnum c)
{
    Rnum temp;
    if (c.numerator = 0)
    {
        cout << "Divisor cont be 0!" << endl;
        return;
    }
    temp.denominator = denominator * c.numerator;
    temp.numerator = numerator * c.denominator;
    return simplification(temp);
}

bool Rnum::operator==(Rnum c)
{
    Rnum temp1 = *this;
    Rnum temp2 = c;
    temp1 = simplification(temp1);
    temp2 = simplification(temp2);
    if (temp1.denominator == temp2.denominator && temp1.numerator == temp2.denominator)
        return true;
    else
        return false;
}

int main(void)
{
    return 0;
}