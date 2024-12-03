#include <stdio.h>

void swap(int *aPtr, int *bPtr, int *cPtr) 
{
    int temp = *bPtr;
    *bPtr = *aPtr;
    *aPtr = *cPtr;
    *cPtr = temp;
}

int main() 
{
    int a, b, c;
    
    printf("Enter value for a: ");
    scanf("%d", &a);
    printf("Enter value for b: ");
    scanf("%d", &b);
    printf("Enter value for c: ");
    scanf("%d", &c);

    printf("Before swapping:\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);

    swap(&a, &b, &c);

    printf("After swapping:\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    
    return 0;
}
