#include <stdio.h>

struct Company
{
    char name[50];
    int yearEstablished;
    char departments[5][50];
};

int main()
{
    struct Company company;
    int numDepartments;

    printf("Enter company name: ");
    scanf("%s", company.name);
    printf("Enter year established: ");
    scanf("%d", &company.yearEstablished);

    do
    {
        printf("Enter number of departments (1 to 5): ");
        scanf("%d", &numDepartments);
    } while (numDepartments < 1 || numDepartments > 5);

    printf("Enter names of %d departments:\n", numDepartments);
    for (int i = 0; i < numDepartments; i++)
    {
        printf("Department %d: ", i + 1);
        scanf("%s", company.departments[i]);
    }

    printf("\n[Company Details]\n");
    printf("Name: %s\n", company.name);
    printf("Year Established: %d\n", company.yearEstablished);
    printf("Departments:\n");
    for (int i = 0; i < numDepartments; i++)
    {
        printf("%d > %s\n", i + 1, company.departments[i]);
    }

    return 0;
}
