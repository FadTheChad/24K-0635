#include <stdio.h>

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Last digit is ");
    (n % 10 == 0)
    ? printf("zero")
    : printf("non-zero");

    return 0;
}