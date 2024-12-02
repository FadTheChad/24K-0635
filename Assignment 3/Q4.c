#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *ratings;
    int totalScore;
} Employee;

void inputEmployees(int **ratings, int numEmployees, int numPeriods)
{
    for (int i = 0; i < numEmployees; i++)
    {
        printf("Enter ratings for Employee %d (1-10):\n", i + 1);
        for (int j = 0; j < numPeriods; j++)
        {
            int rating;
            do
            {
                printf("Period %d: ", j + 1);
                scanf("%d", &rating);
                if (rating < 1 || rating > 10)
                {
                    printf("Invalid rating. Please enter a value between 1 and 10.\n");
                }
            } while (rating < 1 || rating > 10);
            ratings[i][j] = rating;
        }
    }
}

void displayPerformance(int **ratings, int numEmployees, int numPeriods)
{
    for (int i = 0; i < numEmployees; i++)
    {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++)
        {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int **ratings, int numEmployees, int numPeriods)
{
    int topEmployee = 0;
    double highestAverage = 0.0;
    for (int i = 0; i < numEmployees; i++)
    {
        int total = 0;
        for (int j = 0; j < numPeriods; j++)
        {
            total += ratings[i][j];
        }
        double average = (double)total / numPeriods;
        if (average > highestAverage)
        {
            highestAverage = average;
            topEmployee = i;
        }
    }
    return topEmployee;
}

int findHighestRatedPeriod(int **ratings, int numEmployees, int numPeriods)
{
    int bestPeriod = 0;
    double highestAverage = 0.0;
    for (int j = 0; j < numPeriods; j++)
    {
        int total = 0;
        for (int i = 0; i < numEmployees; i++)
        {
            total += ratings[i][j];
        }
        double average = (double)total / numEmployees;
        if (average > highestAverage)
        {
            highestAverage = average;
            bestPeriod = j;
        }
    }
    return bestPeriod;
}

int findWorstPerformingEmployee(int **ratings, int numEmployees, int numPeriods)
{
    int worstEmployee = 0;
    double lowestAverage = 11.0;
    for (int i = 0; i < numEmployees; i++)
    {
        int total = 0;
        for (int j = 0; j < numPeriods; j++)
        {
            total += ratings[i][j];
        }
        double average = (double)total / numPeriods;
        if (average < lowestAverage)
        {
            lowestAverage = average;
            worstEmployee = i;
        }
    }
    return worstEmployee;
}

int main()
{
    int numEmployees, numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);

    Employee *employees = (Employee *)malloc(numEmployees * sizeof(Employee));
    int **ratings = (int **)malloc(numEmployees * sizeof(int *));

    for (int i = 0; i < numEmployees; i++)
    {
        employees[i].ratings = (int *)malloc(numPeriods * sizeof(int));
        employees[i].totalScore = 0;
        ratings[i] = employees[i].ratings;
    }

    inputEmployees(ratings, numEmployees, numPeriods);

    for (int i = 0; i < numEmployees; i++)
    {
        for (int j = 0; j < numPeriods; j++)
        {
            employees[i].totalScore += ratings[i][j];
        }
    }

    printf("\nPerformance Ratings:\n");
    displayPerformance(ratings, numEmployees, numPeriods);

    int topEmployee = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("\nEmployee of the Year is Employee %d\n", topEmployee + 1);

    int highestRatedPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated Evaluation Period: %d\n", highestRatedPeriod + 1);

    int worstEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst Performing Employee is Employee %d\n", worstEmployee + 1);

    for (int i = 0; i < numEmployees; i++)
    {
        free(employees[i].ratings);
    }
    free(ratings);
    free(employees);

    return 0;
}
