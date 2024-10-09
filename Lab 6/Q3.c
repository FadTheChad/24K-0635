#include <stdio.h>

// up to 'n' numbers
void fib(int n)
{
    int l = 0;
    int r = 1;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", l);
        int temp = r;
        r = l + r;
        l = temp;
    }
}

int main()
{
    int n;
    int is_prime = 1;
    scanf("%d", &n);

    if (n <= 1)
        is_prime = 0;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            is_prime = 0;
            break;
        }
    }

    if (is_prime)
    {
        printf("Prime\n");
        fib(n);
    }
    else
    {
        printf("Not prime");
    }

    return 0;
}