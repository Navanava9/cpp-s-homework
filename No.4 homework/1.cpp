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

    Set jiaoji(Set, Set);
    Set binji(Set, Set);
    Set chaji(Set, Set);
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
    for (int i = 0; i < num; i++)
    {
        int flag = 0;
        if (set[i] == n)
            flag++;
        if (flag == 1)
        {
            cout << "cant find!" << endl;
            return;
        }
    }
    for (int i = 0; i < num; i++)
    {
        if (set[i] == n)
        {
            for (int j = i; j < num - 1; j++)
                set[j] = set[j + 1];
            set[num - 1] = '\0';
        }
        num--;
    }
}

void Set::display()
{
    cout << "a = { ";
    for (int i = 0; i < num; i++)
        cout << i << ' ';
    cout << "}" << endl;
}

Set Set::jiaoji(Set a, Set b)
{
    Set c;
    for (int i = 0; i < a.num; i++)
        for (int j = 0; j < b.num; j++)
            if (a.set[i] == b.set[j])
                c.add(a.set[i]);
    return c;
}

Set Set::binji(Set a, Set b)
{
    Set c;
    for (int i = 0; i < a.num; i++)
        c.add(a.set[i]);
    for (int j = 0; j < b.num; j++)
    {
        int flag = 0;
        for (int k = 0; k < a.num; k++)
            if (b.set[j] == a.set[k])
                flag++;
        if (flag == 1)
            c.add(b.set[j]);
    }
    return c;
}

Set Set::chaji(Set a, Set b)
{
    Set c;
    for (int j = 0; j < a.num; j++)
    {
        int flag = 0;
        for (int k = 0; k < b.num; k++)
            if (a.set[j] == b.set[k])
                flag++;
        if (flag == 0)
            c.add(b.set[j]);
    }
    return c;
}

int main(void)
{
    Set a;
    int x[3] = {1, 3, 7};
    for (int i = 0; i < 3; i++)
        a.add(x[i]);
    a.display();
    return 0;
}