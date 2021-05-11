#include <iostream>
using namespace std;

class Set
{
private:
    int count;
    int set[10];

public:
    Set();
    int find(int);
    void del(int);

    Set operator+(Set);
    Set operator-(Set);
    Set operator*(Set);
    Set operator<<(int);
    Set operator>>(int);
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

Set Set::operator<<(int x)
{
}

Set Set::operator>>(int x)
{
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
    return 0;
}