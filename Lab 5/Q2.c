#include <stdio.h>

int main()
{
    int week_day, vacation;

    printf("Enter week day and vacation: ");
    scanf("%d %d", &week_day, &vacation);

    if (week_day && !vacation)
        printf("Sleep");
    else printf("Do not sleep");

    return 0;
}