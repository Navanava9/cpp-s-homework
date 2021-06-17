#include <iostream>
using namespace std;
const double PI = 3.14;

class Circle
{
protected:
    double r;

public:
    Circle() {}
    virtual double area() { return PI * r * r; }
    virtual double volume() { return 0.0; }
};

class Sphere : public Circle
{
protected:
public:
    Sphere(double mr) { r = mr; }
    double area() { return PI * 4 * r * r; }
    double volume() { return PI * 4 / 3 * r * r * r; }
};

class Column : public Circle
{
protected:
    double h;

public:
    Column(double mr, double mh)
    {
        r = mr;
        h = mh;
    }
    double area() { return (r * r * PI * 2) + h * 2 * PI * r; }
    double volume() { return r * r * PI * h; }
};

void print(Circle &C)
{
    cout << "Area = " << C.area() << "; Volume = " << C.volume() << endl;
}

int main(void)
{
    Sphere S1(5);
    print(S1);

    Column C1(6, 5);
    print(C1);

    return 0;
}
