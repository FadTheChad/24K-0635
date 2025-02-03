#include <iostream>

using namespace std;

class Calendar
{
private:
    string *months[12];

    bool verifyDate(int day, int month)
    {
        if (month < 1 || month > 12)
        {
            return false;
        }

        int daysInMonth;

        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            daysInMonth = 31;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            daysInMonth = 30;
        }
        else
        {
            daysInMonth = 28;
        }

        if (day < 1 || day > daysInMonth)
        {
            return false;
        }

        return true;
    }

public:
    Calendar()
    {
        for (int i = 0; i < 12; i++)
        {
            int daysInMonth;

            if (i == 1) // February
            {
                daysInMonth = 28;
            }
            else if (i == 3 || i == 5 || i == 8 || i == 10) // Months with 30 days
            {
                daysInMonth = 30;
            }
            else // Months with 31 days
            {
                daysInMonth = 31;
            }

            months[i] = new string[daysInMonth];
        }
    }

    void addTask(string details, int day, int month)
    {
        if (!verifyDate(day, month))
            return;

        months[month - 1][day - 1] = details;
        cout << "Added details: " << details << endl;
    }

    void removeTask(int day, int month)
    {
        if (!verifyDate(day, month))
            return;

        months[month - 1][day - 1] = "";
        cout << "Removed task on Month " << month << ", Day " << day << endl;
    }

    void showTasks()
    {
        for (int i = 0; i < 12; i++)
        {
            int daysInMonth = (i == 1) ? 28 : (i == 3 || i == 5 || i == 8 || i == 10) ? 30
                                                                                      : 31;
            for (int j = 0; j < daysInMonth; j++)
            {
                if (!months[i][j].empty())
                {
                    cout << "Month " << i + 1 << ", Day " << j + 1 << ": " << months[i][j] << endl;
                }
            }
        }
    }
};

int main()
{
    Calendar cal;

    cal.addTask("Eating shawarma", 2, 9);
    cal.addTask("Meeting with friend", 29, 12);
    cal.addTask("Planning to do assignment", 1, 4);
    cal.addTask("Sleep", 2, 4);
    cal.addTask("Wake up, and realize you forgot to do the assignment", 3, 4);

    cout << endl;

    cal.showTasks();

    cout << endl;

    cal.removeTask(29, 12);

    cout << endl;
    cal.showTasks();
}
