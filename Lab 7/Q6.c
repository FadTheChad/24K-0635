#include <stdio.h>

int main()
{
    int arr[10];
    int visited[10];

    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        if (visited[i] == 1)
            continue;
        int freq = 1;
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[i] == arr[j])
            {
                freq++;
                visited[j] = 1;
            }
        }
        printf("%d: %d\n", arr[i], freq);
    }

    return 0;
}
