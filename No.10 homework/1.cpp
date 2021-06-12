#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Set
{
private:
    int count;
    T set[100];

public:
    Set() { count = 0; }
    int find(T);
    void del(T);

    int getCount(void);
    T getSeti(int);
    void setCount(int);

    Set operator+(Set);
    Set operator-(Set);
    Set operator*(Set);

    void operator()(T);
};

template <typename T>
void Set<T>::setCount(int a)
{
    count = a;
}

template <typename T>
int Set<T>::getCount()
{
    return count;
}

template <typename T>
T Set<T>::getSeti(int i)
{
    return set[i];
}

template <typename T>
void Set<T>::del(T x)
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

template <typename T>
int Set<T>::find(T x)
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

template <typename T>
Set<T> Set<T>::operator+(Set c)
{
    Set s = c;
    for (int i = 0; i < count; i++)
        if (c.find(set[i]) == -1)
            s(set[i]);
    return s;
}

template <typename T>
Set<T> Set<T>::operator-(Set c)
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

template <typename T>
Set<T> Set<T>::operator*(Set c)
{
    Set s;
    for (int i = 0; i < count; i++)
        if (this->find(c.set[i]) != -1)
            s(c.set[i]);
    return s;
}

template <typename T>
ostream &operator<<(ostream &os, Set<T> &s)
{
    os << "{ ";
    for (int i = 0; i < s.getCount(); i++)
        os << s.getSeti(i) << " ";
    os << "}" << endl;
    return os;
}

template <typename T>
istream &operator>>(istream &is, Set<T> &s)
{
    T x;
    for (int i = 0; i < 5; i++)
    {
        is >> x;
        s(x);
    }
    return is;
}

template <typename T>
void Set<T>::operator()(T x)
{
    if (find(x) == -1)
    {
        set[count] = x;
        count++;
    }
}

int main(void)
{
    Set<int> s1;
    Set<int> s2;
    Set<int> s;
    cin >> s1 >> s2;
    s = s1 + s2;
    cout << s;
    s = s1 - s2;
    cout << s;
    s = s1 * s2;
    cout << s;
    return 0;
}