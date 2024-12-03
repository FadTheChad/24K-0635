#include <stdio.h>
#include <stdlib.h> 

int main() 
{
    int n;
    char *arr;

    printf("Enter total number of characters: ");
    scanf("%d", &n);
    n++;

    arr = (char*)malloc(n * sizeof(char));
    getchar();
    printf("Enter your full name: ");
    gets(arr);

    printf("Your name is: %s\n", arr);

    free(arr);

    return 0;
}
