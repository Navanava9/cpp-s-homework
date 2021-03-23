#include <iostream>
using namespace std;

#define PI 3.14

class Circle
{
private:
    int radius;

public:
    Circle(int);
    ~Circle();
    inline float area(int r)
    {
        return r * r * 2 * PI;
    }
};

Circle::Circle(int r)
{
    radius = r;
    cout << "Constructor is called! ";
    cout << "( r = " << radius << " )" << endl;
    cout << "Area is " << area(radius) << endl;
}

Circle::~Circle()
{
    cout << "Destructor is called! ";
}

int main(void)
{
    Circle p(2);
    return 0;
}