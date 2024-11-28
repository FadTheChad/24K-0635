#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Event
{
    char event_name[50];
    struct Date date;
    char location[100];
};

int main()
{
    struct Event event;

    printf("Enter event name: ");
    gets(event.event_name);
    printf("Enter event date (day month year): ");
    scanf("%d %d %d", &event.date.day, &event.date.month, &event.date.year);
    printf("Enter event location: ");
    getchar();
    gets(event.location);

    printf("\n[Event Details]\n");
    printf("Event Name: %s\n", event.event_name);
    printf("Date: %d/%d/%d\n", event.date.day, event.date.month, event.date.year);
    printf("Location: %s\n", event.location);

    return 0;
}
