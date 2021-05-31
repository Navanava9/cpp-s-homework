#include <iostream>
using namespace std;

class Set;
ostream &operator<<(ostream &, Set &);
istream &operator>>(istream &, Set &);

class Set
{
private:
    int count;
    int set[100];

public:
    Set();
    int find(int);
    void del(int);

    Set operator+(Set);
    Set operator-(Set);
    Set operator*(Set);
    friend ostream &operator<<(ostream &, Set &);
    friend istream &operator>>(istream &, Set &);
    void operator()(int);
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
    Set s = c;
    for (int i = 0; i < count; i++)
        if (c.find(set[i]) == -1)
            s(set[i]);
    return s;
}

Set Set::operator-(Set c)
{
    Set s = *this;
    for (int i = 0; i < c.count; i++)
    {
        if (s.find(c.set[i]) != -1)
            s.del(c.set[i]);
        else if (s.find(c.set[i]) == -1)
            s(c.set[i]);
    }
    return s;
}

Set Set::operator*(Set c)
{
    Set s;
    for (int i = 0; i < count; i++)
        if (this->find(c.set[i]) != -1)
            s(c.set[i]);
    return s;
}

ostream &operator<<(ostream &os, Set &s)
{
    os << "{ ";
    for (int i = 0; i < s.count; i++)
        os << s.set[i] << " ";
    os << "}";
    return os;
}

istream &operator>>(istream &is, Set &s)
{
    s.count = 5;
    for (int i = 0; i < 5; i++)
        is >> s.set[i];
    return is;
}

void Set::operator()(int x)
{
    if (find(x) == -1)
    {
        set[count] = x;
        count++;
    }
}

int main(void)
{
    Set s1;
    Set s2;
    Set s;
    cin >> s1 >> s2;
    s = s1 + s2;
    cout << s;
    s = s1 - s2;
    cout << s;
    s = s1 * s2;
    cout << s;
    return 0;
}