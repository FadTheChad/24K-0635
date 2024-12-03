#include <stdio.h>
#include <stdlib.h> 

int main() 
{
    int n, sum = 0, i;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);


    int *arr = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }


    for (i = 0; i < n; i++) 
    {
        printf("Enter %d: ", i + 1);
        scanf("%d", &arr[i]);
    }


    for (i = 0; i < n; i++) 
    {
        sum += arr[i];
    }

    printf("Sum is %d\n", sum);


    free(arr);

    return 0;
}
