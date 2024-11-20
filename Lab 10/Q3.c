#include <stdio.h>

const int MAX_TEMP = 30;

int checktemp(int temp)
{
    static int count = 0;
    if (temp > MAX_TEMP)
    {
        count++;
    }
}

int main()
{
    int n;
    int count = 0;

    printf("Num of temperatures: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int temp;
        printf("\nEnter temp %d >", i + 1);
        scanf("%d", temp);
        count = checktemp(temp);
    }

    printf("\nCount: %d", count);

    return 0;
}