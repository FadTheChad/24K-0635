#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int size, max = 0, i, newSize;
    int *array;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    array = (int *)malloc(size * sizeof(int));
    
    if (array == NULL) 
    {
        printf("Failed to allocate memory\n");
        return 1;
    }

    for (i = 0; i < size; i++) 
    {
        printf("Input value for element %d: \n", i + 1);
        scanf("%d", &array[i]);
        
        if (array[i] > max) 
        {
            max = array[i];
        }
    }

    printf("The largest number is %d\n", max);
    printf("Enter the new size for the array: \n");
    scanf("%d", &newSize);
    
    array = (int *)realloc(array, newSize * sizeof(int));
    
    if (array == NULL) 
    {
        printf("Failed to allocate memory\n");
        return 1;
    }

    if (newSize > size) 
    {
        printf("Please input %d additional values: \n", newSize - size);
        for (i = size; i < newSize; i++) 
        {
            printf("Element %d: ", i + 1);
            scanf("%d", &array[i]);
            
            if (array[i] > max) 
            {
                max = array[i];
            }
        }
    }

    printf("The largest number is %d\n", max);

    free(array);

    return 0;
}
