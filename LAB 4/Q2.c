#include <stdio.h>

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    // if n is a multiple of 10, then it is a multiple of 2, as 10 is a multiple of 2 itself
    // hence % 2 is not necessary
    if ((n % 10 == 0) && (n > 0)) 
        printf("ACCEPTED");
    else
        printf("DENIED");

    return 0;
}