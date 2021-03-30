#include <iostream>
using namespace std;

class Set
{
private:
    int *set;
    int num;

public:
    Set();
    ~Set();

    void add(int);
    void delete_(int);
    void display();

    void jiaoji(Set, Set);
    void binji(Set, Set);
    void chaji(Set, Set);
};

Set::Set()
{
    set = new int[10];
    num = 0;
}

Set::~Set()
{
    delete[] set;
}

void Set::add(int n)
{
    for (int i = 0; i < num; i++)
    {
        if (set[i] == n)
        {
            cout << "have same!" << endl;
            return;
        }
    }
    set[num] = n;
    num++;
}

void Set::delete_(int n)
{
    int flag = 0;
    for (int i = 0; i < num; i++)
        if (set[i] == n)
        {
            flag = 1;
            for (int j = i; j < num - 1; j++)
                set[j] = set[j + 1];
            set[num - 1] = '\0';
            num--;
            break;
        }
    if (flag == 0)
    {
        cout << "Cont find!" << endl;
        return;
    }
}

void Set::display()
{
    cout << "set = { ";
    for (int i = 0; i < num; i++)
        cout << set[i] << ' ';
    cout << "}"
         << " (" << num << ")" << endl;
}

void Set::jiaoji(Set a, Set b)
{
    int k = 0;
    for (int i = 0; i < a.num; i++)
        for (int j = 0; j < b.num; j++)
            if (a.set[i] == b.set[j])
            {
                set[k] = a.set[i];
                num++;
                k++;
            }
}

void Set::binji(Set a, Set b)
{
    int m = 0;
    for (int i = 0; i < a.num; i++)
    {
        set[m] = a.set[i];
        num++;
        m++;
    }
    for (int j = 0; j < b.num; j++)
    {
        int flag = 0;
        for (int k = 0; k < a.num; k++)
            if (b.set[j] == a.set[k])
                flag = 1;
        if (flag == 0)
        {
            set[m] = b.set[j];
            num++;
            m++;
        }
    }
}

void Set::chaji(Set a, Set b)
{
    int m = 0;
    for (int j = 0; j < a.num; j++)
    {
        int flag = 0;
        for (int k = 0; k < b.num; k++)
            if (a.set[j] == b.set[k])
                flag = 1;
        if (flag == 0)
        {
            set[m] = a.set[j];
            num++;
            m++;
        }
    }
}

int main(void)
{
    Set a, b, c;
    for (int i = 1; i < 5; i++)
        a.add(i);
    for (int j = 3; j < 7; j++)
    {
        b.add(j);
    }
    c.chaji(a, b);
    a.display();
    b.display();
    c.display();
    return 0;
}