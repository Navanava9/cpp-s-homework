#include <iostream>
#include <iomanip>
using namespace std;

void PrintCalendar(int day, int stop)
{
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
    cout << setw((1 + day) * 5) << 1;
    for (int i = 2; i <= stop; i++)
    {
        cout << setw(5) << i;
        if (i == 7 - day || i == 14 - day || i == 21 - day || i == 28 - day || i == 35 - day)
            cout << endl;
    }
}

int main(void)
{
    int day, stop;
    cout << "Type your day:";
    cin >> day;
    cout << "Type yout stop:";
    cin >> stop;
    PrintCalendar(day, stop);
    return 0;
}