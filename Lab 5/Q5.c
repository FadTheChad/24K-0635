#include <stdio.h>

int main()
{
    float gpa;

    printf("Enter GPA: ");
    scanf("%f", &gpa);

    printf("MSG: %s",
        gpa < 1.0 
        ? "Failed semester" 
        : gpa < 2.0
        ? "On probation for next semester"
        : gpa < 3.0
        ? "(no message)"
        : gpa < 3.5 
        ? printf("Dean's list")
        : printf("Highest honors")
    );

    return 0;
}