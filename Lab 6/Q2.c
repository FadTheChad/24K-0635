#include <stdio.h>

int main()
{
    int n;
    int is_prime = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    int i = 2;

    while(i <= n)
    {
        if (n % i == 0 && i != 1 && i != n)
        {
            is_prime = 0;
            break;
        }
        is_prime = 1;

        i++;
    }

    if (is_prime) printf("Prime");
    else printf("Not Prime");
    return 0;
}