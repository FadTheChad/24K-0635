#include <stdio.h>

int main()
{
    float a, b;
    char o;
    float r;

    printf("Enter a, b: ");
    scanf("%f %f", &a, &b);

    printf("Enter opp (+ - * /): ");
    scanf(" %c", &o);

    switch (o)
    {
    case '+':
        r = a + b;
        break;
    
    case '-':
        r = a - b;
        break;

    case '*':
        r = a * b;
        break;

    case '/':
        r = a / b;
        break;

    default:
        printf("INVALID OPP");
        return 0;
    }

    printf("RES: %.3f", r);
    
    return 0;
}