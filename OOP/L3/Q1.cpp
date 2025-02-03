#include <iostream>

using namespace std;

class Time
{
private:
    int hours, minutes, seconds;

public:
    Time()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    Time(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void display()
    {
        cout << hours << ":" << minutes << ":" << seconds;
    }

    Time add(Time t1, Time t2)
    {
        int totalSeconds = t1.seconds + t2.seconds;
        int totalMinutes = t1.minutes + t2.minutes + (totalSeconds / 60);
        int totalHours = t1.hours + t2.hours + (totalMinutes / 60);

        totalSeconds %= 60;
        totalMinutes %= 60;
        totalHours %= 24;

        return Time(totalHours, totalMinutes, totalSeconds);
    }
};

int main()
{
    Time t1(1, 50, 30);
    Time t2(2, 20, 40);
    Time t3;

    t3 = t3.add(t1, t2);
    t3.display();

    return 0;
}