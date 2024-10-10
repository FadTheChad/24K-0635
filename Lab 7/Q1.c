#include <stdio.h>

int main()
{
    int arr[6];

    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &arr[i]);
    }

    int last = arr[5];
    for (int i = 5; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = last;

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
}