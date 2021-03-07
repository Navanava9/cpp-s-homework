#include <iostream>
#include <fstream>
using namespace std;

int Largest(int list[], int length)
{
    int i, max = list[0];
    for (i = 0; i < length; i++)
        if (list[i] > max)
            max = list[i];
    return max;
}

int main(void)
{
    int x, count = 0, max = 0, list[1000];
    ifstream in;
    in.open("1.txt");
    if (!in)
        exit(0);
    while (in >> x)
        count++;
    in.close();
    in.open("1.txt");
    if (!in)
        exit(0);
    for (int i = 0; i < count; i++)
        in >> list[i];
    max = Largest(list, count);
    cout << "Largest num:" << max << endl;
    in.close();
    return 0;
}