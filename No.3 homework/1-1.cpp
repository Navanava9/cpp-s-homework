#include <iostream>
#include <string>
using namespace std;

void print(string s, int n = 10)
{
    string s1(s, 0, n);
    cout << s1 << endl;
}

int main(void)
{
    string str;
    int n;
    char x;
    cout << "Type ur string:";
    getline(cin, str);
    cout << "Do u want a n?(Y/N):";
    cin >> x;
    if (x == 'Y' || x == 'y')
    {
        cout << "Type ur n:";
        cin >> n;
        print(str, n);
    }
    else
        print(str);
}