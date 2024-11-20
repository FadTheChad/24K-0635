#include <stdio.h>

int linearSearch(int arr[], int size, int target, int index)
{
    if (index == size)
        return -1;

    if (arr[index] == target)
        return index;

    return linearSearch(arr, size, target, index + 1);
}

int main()
{
    int arr[999];
    int size, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");

    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target, 0);

    if (result != -1)
        printf("Element %d found at index %d.\n", target, result);

    else
        printf("Element %d not found.\n", target);

    return 0;
}
