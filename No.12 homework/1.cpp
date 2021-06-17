#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void handler();

class TimeMistake
{
private:
    string message;

public:
    TimeMistake() {}
    TimeMistake(string s) { message = s; }
    string getMessage() { return message; }
};

class Time
{
private:
    string MoA;
    int hour;
    int min;

    bool is12;

public:
    Time()
    {
        time_t nowtime = time(NULL);
        struct tm *local;
        local = localtime(&nowtime);

        is12 = false;
        MoA = "null";
        hour = local->tm_hour;
        min = local->tm_min;
    }

    Time(int h, int m)
    {
        is12 = false;
        MoA = "null";
        hour = h;
        min = m;
    }

    void display()
    {
        if (is12 == false)
            cout << "Time: " << hour << ":" << min << endl;
        else if (is12 == true)
            cout << "Time: " << hour << ":" << min << " " << MoA << endl;
    }

    void conversion()
    {
        if (is12 == false)
        {
            if (hour > 12)
            {
                MoA = "PM";
                hour -= 12;
            }
            else if (hour <= 12)
                MoA = "AM";

            is12 = true;
        }
        else if (is12 == true)
        {
            MoA = "null";
            hour += 12;
            is12 = false;
        }
    }
};

int main(void)
{
    handler();
    return 0;
}

void text() throw(TimeMistake)
{
    int h, m;

    cout << "请输入小时,分钟的数值:";
    cin >> h >> m;

    if (h > 23)
        throw TimeMistake("小时");
    if (m > 59)
        throw TimeMistake("分钟");

    Time t(h, m);
    t.conversion();
    cout << "您输入的时间是: ";
    t.display();
}

void handler()
{
    try
    {
        text();
    }
    catch (TimeMistake e)
    {
        cout << e.getMessage() << "越界";
    }
}