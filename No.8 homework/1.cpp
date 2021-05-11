#include <iostream>
using namespace std;

class teacher
{
protected:
    int classHour;
    int fixWage;
    int classWage;

public:
    virtual int totalWage(void) = 0;
    virtual void display(void) = 0;
};

class professor : public teacher
{
protected:
    int level;

public:
    professor() {}
    professor(int Mlevel, int MclassHour)
    {
        classHour = MclassHour;
        level = Mlevel;
        classWage = 50;
        if (level == 1)
            fixWage = 8000;
        if (level == 2)
            fixWage = 7500;
    }

    int totalWage()
    {
        return fixWage + (classHour * classWage);
    }

    void display()
    {
        cout << "professor's total wage is " << totalWage() << endl;
    }
};

class associateProfessor : public teacher
{
protected:
    int level;

public:
    associateProfessor() {}
    associateProfessor(int Mlevel, int MclassHour)
    {
        classHour = MclassHour;
        level = Mlevel;
        classWage = 30;
        if (level == 1)
            fixWage = 7000;
        if (level == 2)
            fixWage = 6000;
        if (level == 3)
            fixWage = 5000;
    }

    int totalWage()
    {
        return fixWage + (classHour * classWage);
    }

    void display()
    {
        cout << "associate professor's total wage is " << totalWage() << endl;
    }
};

class lecturer : public teacher
{
public:
    lecturer() {}
    lecturer(int MclassHour)
    {
        classHour = MclassHour;
        fixWage = 4500;
        classWage = 20;
    }

    int totalWage()
    {
        return fixWage + (classHour * classWage);
    }

    void display()
    {
        cout << "lecturer's total wage is " << totalWage() << endl;
    }
};

int main(void)
{
    lecturer l1(20);
    l1.display();

    associateProfessor a1(1, 20);
    a1.display();

    professor p1(1, 20);
    p1.display();

    return 0;
}