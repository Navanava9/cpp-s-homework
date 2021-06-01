#include <iostream>
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

    Set operator+(Set);
    Set operator-(Set);
    Set operator*(Set);
    friend ostream &operator<<(ostream &, Set<T> &);
    friend istream &operator>>(istream &, Set<T> &);
    void operator()(int);
};

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
    for (int i = 0; i < s.count; i++)
        os << s.set[i] << " ";
    os << "}";
    return os;
}

template <typename T>
istream &operator>>(istream &is, Set<T> &s)
{
    s.count = 5;
    for (int i = 0; i < 5; i++)
        is >> s.set[i];
    return is;
}

template <typename T>
void Set<T>::operator()(int x)
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