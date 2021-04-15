#include <iostream>
#include <ctime>
#include <string>

using namespace std;

string change(int, char);

class Date
{
protected:
    int year, month, day;

public:
    Date()
    {
        year = 2018;
        month = 4;
        day = 14;
    };
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    };
    void print();
};

class ShortE : public Date
{
public:
    ShortE(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    };
    void print();
};

class MediumDate : public Date
{
public:
    MediumDate(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    };
    void print();
};

class LongDate : public Date
{
public:
    LongDate(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    };
    void print();
};

void Date::print()
{
    cout << month << '-' << day << '-' << year << endl;
}

void ShortE::print()
{
    cout << day << '-' << month << '-' << year << endl;
}

void MediumDate::print()
{
    cout << change(month, 's') << '.' << day << ',' << year << endl;
}

void LongDate::print()
{
    cout << change(month, 'l') << ' ' << day << ", " << year << endl;
}

string change(int num, char c)
{
    string l[12] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    };
    string s[12] = {
        "Jan",
        "Feb",
        "Mar",
        "Apr",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sep",
        "Oct",
        "Nov",
        "Dec",
    };
    if (c == 's')
        return s[num - 1];
    else if (c == 'l')
        return l[num - 1];
    else
        return "error type!";
}

int main(void)
{
    time_t nowtime;
    nowtime = time(NULL);
    struct tm *local;
    local = localtime(&nowtime);

    LongDate now(1900 + local->tm_year, 1 + local->tm_mon, local->tm_mday);
    now.print();
    return 0;
}