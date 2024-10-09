#include <stdio.h>

int main()
{
    int n;
    int sum = 0;

    scanf("%d", &n);

    int og_n = n;

    while (n != 0)
    {
        int ld = n % 10;
        sum += ld * ld * ld;
        n /= 10;
    }

    if (sum == og_n)
        printf("Armstrong");
    else
        printf("Not armstrong");

    return 0;
}