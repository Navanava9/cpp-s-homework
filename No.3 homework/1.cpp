#include <iostream>
using namespace std;

#define PI 3.14

class Circle
{
private:
    float radius;

public:
    Circle();
    Circle(float);
    ~Circle();
    float area()
    {
        return radius * radius * PI;
    }
    void displayarea()
    {
        cout << endl
             << "Area is " << area() << endl;
    }
    void setR(float r)
    {
        radius = r;
    }
};

Circle::Circle()
{
    cout << "Constructor is called! ";
    radius = 0;
}

Circle::Circle(float r)
{
    radius = r;
    cout << "Constructor is called! ";
    cout << "( r = " << radius << " )" << endl;
    cout << "Area is " << area() << endl;
}

Circle::~Circle()
{
    cout << "Destructor is called! ";
}

int main(void)
{
    Circle p;
    p.setR(5);
    p.displayarea();
    return 0;
}