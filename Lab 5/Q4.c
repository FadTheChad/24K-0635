#include <stdio.h>

int main()
{
    int pH;

    printf("Enter pH: ");
    scanf("%d", &pH);

    if (pH > 7)
    {
        if (pH < 12)
            printf("Alkaline");
        else
            printf("Really Alkaline");
    } else
    {
        if (pH == 7)
            printf("Neutral");
        else if (pH > 2)
            printf ("Acidic");
        else
            printf("Really Acidic");
    }
}