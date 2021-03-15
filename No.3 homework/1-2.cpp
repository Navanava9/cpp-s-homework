#include <iostream>
#include <string>
using namespace std;

void BubbleSort(string a[])
{
    int i, j;
    string temp;
    for (j = 0; j < 9; j++)
    {
        for (i = 0; i < 9 - j; i++)
            if (a[i] < a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
    }
}

int main(void)
{
    string str[10];
    cout << "Type 10 names :" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << ":";
        cin >> str[i];
    }
    BubbleSort(str);
    cout << " --------------------- " << endl
         << "result is follow:" << endl;
    for (int j = 0; j < 10; j++)
        cout << str[j] << endl;
    cout << " --------------------- ";
    return 0;
}