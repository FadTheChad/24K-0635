#include <stdio.h>

int is_prime(int n)
{
    if (n <= 1)
        return 0;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("%d is %s", n, is_prime(n) ? "Prime" : "Not Prime");
}