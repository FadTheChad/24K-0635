#include <stdio.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

int isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int daysInMonth(int month, int year)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
        return 29;

    return days[month - 1];
}

int isValidDate(Date d)
{
    if (d.year < 1 || d.month < 1 || d.month > 12 || d.day < 1 || d.day > daysInMonth(d.month, d.year))
        return 0;

    return 1;
}

int calculateDaysBetween(Date d1, Date d2)
{
    int totalDays = 0;
    while (d1.year < d2.year || (d1.year == d2.year && d1.month < d2.month) || (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day))
    {
        d1.day++;
        if (d1.day > daysInMonth(d1.month, d1.year))
        {
            d1.day = 1;
            d1.month++;
            if (d1.month > 12)
            {
                d1.month = 1;
                d1.year++;
            }
        }
        totalDays++;
    }
    return totalDays;
}

int dayOfWeek(Date d)
{
    int m = d.month;
    int y = d.year;
    if (m < 3)
    {
        m += 12;
        y--;
    }
    int k = y % 100;
    int j = y / 100;
    return (d.day + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
}

int main()
{
    Date d1, d2;

    printf("Enter first date (day month year): ");
    scanf("%d %d %d", &d1.day, &d1.month, &d1.year);

    printf("Enter second date (day month year): ");
    scanf("%d %d %d", &d2.day, &d2.month, &d2.year);

    if (!isValidDate(d1) || !isValidDate(d2))
    {
        printf("One of the dates is invalid.\n");
        return 0;
    }

    printf("Days between: %d\n", calculateDaysBetween(d1, d2));
    printf("Day of the week for the first date: %d\n", dayOfWeek(d1));
    printf("Day of the week for the second date: %d\n", dayOfWeek(d2));
    return 0;
}
