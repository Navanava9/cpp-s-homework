#include <iostream>
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
    int max = 0, N = -1, list[1000];
    cout << "How much you want:";
    cin >> N;
    cout << "please enter " << N << " inter:" << endl;
    for (int i = 0; i <= N - 1; i++)
        cin >> list[i];
    max = Largest(list, N);
    cout << "Largest num:" << max << endl;
    return 0;
}