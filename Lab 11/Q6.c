#include <stdio.h>

struct Address
{
    char city[50];
    char zip_code[20];
};

struct Employee
{
    char name[50];
    int id;
    float salary;
    struct Address address;
};

int main()
{
    struct Employee employees[5];
    FILE *file;

    file = fopen("employees.dat", "wb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Enter details for employee %d\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        printf("City: ");
        scanf("%s", employees[i].address.city);
        printf("Zip Code: ");
        scanf("%s", employees[i].address.zip_code);
    }

    fwrite(employees, sizeof(struct Employee), 5, file);
    fclose(file);

    file = fopen("employees.dat", "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\n[Employee Details]\n");
    fread(employees, sizeof(struct Employee), 5, file);

    for (int i = 0; i < 5; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("ID: %d\n", employees[i].id);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("City: %s\n", employees[i].address.city);
        printf("Zip Code: %s\n", employees[i].address.zip_code);
    }

    fclose(file);

    return 0;
}
