#include <stdio.h>

int main()
{
    int cost;
    float discount = 0;

    printf("Enter cost: ");
    scanf("%d", &cost);

    if (cost >= 6000) discount == 0.35;
    else if (cost >= 4000) discount == 0.20;
    else if (cost >= 2000) discount == 0.10;
    else if (cost >= 500) discount = 0.05;

    cost = cost * (1 - discount);

    printf("Cost: %f", cost);

    return 0;
}
