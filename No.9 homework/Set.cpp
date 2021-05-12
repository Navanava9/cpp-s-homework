#include <iostream>
using namespace std;

class Set
{
private:
    int count;
    int set[5];

public:
    Set();
    int find(int);
    void del(int);

    Set operator+(Set);
    Set operator-(Set);
    Set operator*(Set);
    void operator()(int);
    friend ostream &operator<<(ostream &, Set &);
    friend istream &operator>>(istream &, Set &);
};

Set::Set()
{
    count = 0;
}

void Set::del(int x)
{
    int pos;
    pos = find(x);
    if (pos != -1)
    {
        for (int i = pos; i < count - 1; i++)
            set[i] = set[i + 1];
        count--;
    }
}

int Set::find(int x)
{
    int pos = -1;
    for (int i = 0; i < count; i++)
        if (x == set[i])
        {
            pos = i;
            break;
        }
    return pos;
}

Set Set::operator+(Set c)
{
    Set s;
    for (int i = 0; i < count; i++)
        if (c.find(set[i]) != -1)
            s(set[i]);
    return s;
}

Set Set::operator-(Set c)
{
    Set s;
    for (int i = 0; i < count; i++)
        s(set[i]);
    for (int j = 0; j < count; j++)
        if (c.find(set[j]) != -1)
            s.del(c.set[c.find(set[j])]);
    return s;
}

Set Set::operator*(Set c)
{
    Set s;
    for (int i = 0; i < count; i++)
        s(set[i]);
    for (int j = 0; j < count; j++)
        s(c.set[j]);
    return s;
}

void Set::operator()(int x)
{
    if (find(x) == -1)
    {
        set[count] = x;
        count++;
    }
}

ostream &operator<<(ostream &os, Set &s)
{
    os << "set = { ";
    for (int i = 0; i < s.count; i++)
        os << s.set[i] << " ";
    os << "}";
    return os;
}

istream &operator>>(istream &is, Set &s)
{
    for (int i = 0; i < 5; i++)
        is >> s.set[i];
    s.count = 5;
    return is;
}

int main(void)
{
    Set s1;
    Set s2;

    cin >> s1;
    cout << s1;
    return 0;
}