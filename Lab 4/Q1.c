#include <stdio.h>

int main() 
{
    int n;
    
    printf("Enter n: ");
    scanf("%d", &n);

    printf("\n Number is");
    
    if (n % 3 != 0) printf(" NOT ");

    printf("a multiple of 3");

    return 0;
}