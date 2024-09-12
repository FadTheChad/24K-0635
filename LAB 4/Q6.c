#include <stdio.h>

int main()
{
    int cost;
    float discount;

    printf("Enter cost: ");
    scanf("%d", &cost);

    if (cost >= 6000) discount == 0.35;
    else if (cost >= 4000) discount == 0.20;
    else if (cost >= 2000) discount == 0.10;
    else discount = 0.05;

    cost = cost * (1 - discount);

    printf("Cost: %f", cost);

    return 0;
}