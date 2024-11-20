#include <stdio.h>
#include <string.h>

typedef struct
{
    char package_name[50];
    char destination[50];
    int duration;
    float cost;
    int seats;
} Package;

void displayPackages(Package packages[], int n)
{
    printf("\nAvailable Travel Packages:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Package %d:\n", i + 1);
        printf("  > Name: %s\n", packages[i].package_name);
        printf("  Destination: %s\n", packages[i].destination);
        printf("  Duration: %d days\n", packages[i].duration);
        printf("  Cost: $%.2f\n", packages[i].cost);
        printf("  Seats: %d\n\n", packages[i].seats);
    }
}

void bookPackage(Package packages[], int n)
{
    char package_name[50];
    printf("\nEnter the package name you want to book: ");
    gets(package_name);

    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(packages[i].package_name, package_name) == 0)
        {
            found = 1;
            if (packages[i].seats > 0)
            {
                packages[i].seats--;
                printf("\nBooking confirmed for package: %s\n", packages[i].package_name);
            }
            else
            {
                printf("\nSorry, no seats available for package: %s\n", packages[i].package_name);
            }
            break;
        }
    }

    if (!found)
    {
        printf("\nPackage not found.\n");
    }
}

int main()
{
    Package packages[999];

    int n;
    printf("Enter the number of travel packages: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for package %d:\n", i + 1);

        printf("Package name: ");
        gets(packages[i].package_name);

        printf("Destination: ");
        gets(packages[i].destination);

        printf("Duration (in days): ");
        scanf("%d", &packages[i].duration);
        getchar();

        printf("Cost: ");
        scanf("%f", &packages[i].cost);
        getchar();

        printf("Seats available: ");
        scanf("%d", &packages[i].seats);
        getchar();
    }

    printf("\nWelcome to the Travel Booking System!\n");
    displayPackages(packages, n);
    bookPackage(packages, n);

    printf("\nUpdated Package List After Booking:\n");
    displayPackages(packages, n);

    return 0;
}
