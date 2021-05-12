#include <iostream>
using namespace std;

class Rnum
{
public:
    Rnum()
    {
        numerator = 1;
        denominator = 1;
    }
    Rnum(int, int);
    void display(void);
    Rnum operator+(Rnum);
    Rnum operator-(Rnum);
    Rnum operator*(Rnum);
    Rnum operator/(Rnum);
    bool operator==(Rnum);
    void simplification(void);

private:
    int numerator;
    int denominator;
};

Rnum::Rnum(int n, int d)
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
    if (numerator == 0)
        cout << 0 << endl;
    else
        cout << numerator << "/" << denominator << endl;
}

Rnum Rnum::operator+(Rnum c)
{
    Rnum temp;
    temp.denominator = c.denominator * denominator;
    if (temp.denominator == 0)
    {
        cout << "Denominator is 0!" << endl;
        exit(0);
    }
    temp.numerator = denominator * c.numerator + numerator * c.denominator;
    temp.simplification();
    return temp;
}

Rnum Rnum::operator-(Rnum c)
{
    Rnum temp;
    temp.denominator = c.denominator * denominator;
    if (temp.denominator == 0)
    {
        cout << "Denominator is 0!" << endl;
        exit(0);
    }
    temp.numerator = numerator * c.denominator - denominator * c.numerator;
    temp.simplification();
    return temp;
}

Rnum Rnum::operator*(Rnum c)
{
    Rnum temp;
    temp.denominator = denominator * c.denominator;
    temp.numerator = numerator * c.numerator;
    temp.simplification();
    return temp;
}

Rnum Rnum::operator/(Rnum c)
{
    Rnum temp;
    if (c.numerator == 0)
    {
        cout << "Divisor cont be 0!" << endl;
        exit(0);
    }
    temp.denominator = denominator * c.numerator;
    temp.numerator = numerator * c.denominator;
    temp.simplification();
    return temp;
}

bool Rnum::operator==(Rnum c)
{
    Rnum temp1 = *this;
    Rnum temp2 = c;
    temp1.simplification();
    temp2.simplification();
    if (temp1.denominator == temp2.denominator && temp1.numerator == temp2.numerator)
        return true;
    else
        return false;
}

void Rnum::simplification(void)
{
    for (int i = numerator; i > 1; i--)
    {
        if (denominator % i == 0 && numerator % i == 0)
        {
            denominator /= i;
            numerator /= i;
            return;
        }
    }
}

int main(void)
{
    Rnum r;
    Rnum r1(1, 2);
    Rnum r2(2, 3);
    Rnum r3(4, 6);
    Rnum r4(0, 3);

    r3.simplification();
    r3.display();

    r = r2 * r3;
    r.display();

    r = r2 + r3;
    r.display();

    r = r2 - r3;
    r.display();

    cout << "r2 == r3 ? " << (r2 == r3) << endl;

    r = r2 / r4;
    r.display();

    return 0;
}