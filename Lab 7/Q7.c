#include <stdio.h>

int main()
{
    int size;

    printf("Input the size of the array: ");
    scanf("%d", &size);

    int arr[100];
    int seen[100];

    printf("Input:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Element %d = ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        if (seen[arr[i]] == 1)
        {
            printf("Number %d occurs more than once.\n", arr[i]);
            return 0;
        }
        seen[arr[i]] = 1;
    }

    printf("No duplicates found.\n");
    return 0;
}
