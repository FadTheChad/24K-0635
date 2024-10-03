#include <stdio.h>

int main()
{
    for (int i = 0; i < 6; i++)
    {
        if (i == 0 || i == 5)
            printf("*       *\n");
        else
            printf("* * * * *\n");
    }
}