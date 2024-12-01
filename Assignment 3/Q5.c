#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct
{
    char *name;
    char **speciesSupplies;
    int numOfSupplies;
} Pet;

// Assuming that there cannot be duplicate supplies
// Returns the index inside the supplies array if it exists (else it returns -1)
int checkIfSupplyExists(Pet *inv, int i, char *supply)
{
    for (int j = 0; j < inv[i].numOfSupplies; j++)
    {
        if (strcmp(inv[i].speciesSupplies[j], supply) == 0)
            return j;
    }
    return -1;
}

int checkIfPetExists(Pet *inv, int numOfPets, char *name)
{
    for (int i = 0; i < numOfPets; i++)
    {
        if (strcmp(inv[i].name, name) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void addSupplies(Pet *inv, int numOfPets, char *name, char *supply)
{
    for (int i = 0; i < numOfPets; i++)
    {
        if (strcmp(inv[i].name, name) == 0)
        {
            if (checkIfSupplyExists(inv, i, supply) != -1)
            {
                printf("Supply '%s' already exists!\n", supply);
                return;
            }
            inv[i].numOfSupplies++;
            inv[i].speciesSupplies = (char **)realloc(inv[i].speciesSupplies, inv[i].numOfSupplies * sizeof(char *));
            inv[i].speciesSupplies[inv[i].numOfSupplies - 1] = (char *)malloc(strlen(supply) + 1);
            strcpy(inv[i].speciesSupplies[inv[i].numOfSupplies - 1], supply);
            printf("Added supply '%s'!\n", supply);
            return;
        }
    }
    printf("Pet not found!\n");
}

void updateSupplies(Pet *inv, int numOfPets, char *name, char *oldSupply, char *newSupply)
{
    for (int i = 0; i < numOfPets; i++)
    {
        if (strcmp(inv[i].name, name) == 0)
        {
            if (checkIfSupplyExists(inv, i, newSupply) != -1)
            {
                printf("Supply '%s' already exists!\n", newSupply);
                return;
            }

            int j = checkIfSupplyExists(inv, i, oldSupply);

            if (j == -1)
            {
                printf("Supply '%s' does not exist!\n", oldSupply);
                return;
            }

            inv[i].speciesSupplies[j] = realloc(inv[i].speciesSupplies[j], strlen(newSupply) + 1);
            strcpy(inv[i].speciesSupplies[j], newSupply);

            printf("Updated supply '%s' to '%s'!\n", oldSupply, newSupply);
            return;
        }
    }
    printf("Pet not found!\n");
}

void removeSpecies(Pet *inv, int *numOfPets, char *name)
{
    for (int i = 0; i < *numOfPets; i++)
    {
        if (strcmp(inv[i].name, name) == 0)
        {
            free(inv[i].name);
            for (int j = 0; j < inv[i].numOfSupplies; j++)
            {
                free(inv[i].speciesSupplies[j]);
            }
            free(inv[i].speciesSupplies);

            for (int j = i; j < *numOfPets - 1; j++)
            {
                inv[j] = inv[j + 1];
            }

            (*numOfPets)--;
            inv = (Pet *)realloc(inv, *numOfPets * sizeof(Pet));
            printf("Species '%s' removed from inventory.\n", name);
            return;
        }
    }
    printf("Pet not found!\n");
}

void displayInventory(Pet *inv, int numOfPets)
{
    for (int i = 0; i < numOfPets; i++)
    {
        printf("\nSpecies: %s\nSupplies (%d):\n", inv[i].name, inv[i].numOfSupplies);

        for (int j = 0; j < inv[i].numOfSupplies; j++)
        {
            printf("%d. %s\n", j, inv[i].speciesSupplies[j]);
        }
    }
    printf("\n");
}

void freeInventory(Pet *inv, int numOfPets)
{
    for (int i = 0; i < numOfPets; i++)
    {
        for (int j = 0; j < inv[i].numOfSupplies; j++)
        {
            free(inv[i].speciesSupplies[j]);
        }
        free(inv[i].speciesSupplies);
        free(inv[i].name);
    }
    free(inv);
}

int main()
{
    Pet *inv; // Inventory

    int numOfPets;
    printf("Number of Pets: ");
    scanf("%d", &numOfPets);

    if (numOfPets <= 0)
        return 1;

    inv = (Pet *)malloc(numOfPets * sizeof(Pet));

    for (int i = 0; i < numOfPets; i++)
    {
        char name[100];
        printf("Enter Species: ");
        scanf("%s", name);

        inv[i].name = malloc(strlen(name) + 1);
        strcpy(inv[i].name, name);

        inv[i].numOfSupplies = 0;
        inv[i].speciesSupplies = (char **)malloc(1 * sizeof(char *));
    }

    while (1)
    {
        int choice;

        printf("\n\t\t[Pets In Heart]\n");
        printf("\t===== INVENTORY MANAGER =====\n");
        printf("\n\tChoose an option:\n");
        printf("\t\t0 -> Display Inventory\n");
        printf("\t\t1 -> Add Supplies\n");
        printf("\t\t2 -> Update Supplies\n");
        printf("\t\t3 -> Remove Species\n");
        printf("\t\t4 -> End Program\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 0)
        {
            displayInventory(inv, numOfPets);
        }
        else if (choice == 1)
        {
            char petName[100], supply[100];
            printf("Enter the name of the pet: ");
            scanf("%s", petName);

            if (!checkIfPetExists(inv, numOfPets, petName))
            {
                printf("Pet not Found!\n");
            }
            else
                while (1)
                {
                    printf("Enter the supply to add (Enter 'end' to stop adding): ");
                    scanf("%s", supply);

                    if (strcmp(supply, "end") == 0)
                        break;

                    addSupplies(inv, numOfPets, petName, supply);
                }
        }
        else if (choice == 2)
        {
            char petName[100];
            printf("Enter the name of the pet: ");
            scanf("%s", petName);

            if (!checkIfPetExists(inv, numOfPets, petName))
            {
                printf("Pet not Found!\n");
            }
            else
            {
                char oldSupply[100], newSupply[100];

                printf("Enter the supply to update");
                scanf("%s", oldSupply);

                printf("Enter the new supply to replace it with");
                scanf("%s", newSupply);

                updateSupplies(inv, numOfPets, petName, oldSupply, newSupply);
            }
        }
        else if (choice == 3)
        {
            char petName[100];
            printf("Enter the name of the pet to remove: ");
            scanf("%s", petName);

            removeSpecies(inv, &numOfPets, petName);
        }
        else if (choice == 4)
        {
            printf("Ending program...\n");
            break;
        }
        else
        {
            printf("Invalid choice! Please enter a valid option!\n");
        }
    }

    freeInventory(inv, numOfPets);
    return 0;
}