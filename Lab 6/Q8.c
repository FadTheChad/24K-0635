#include <stdio.h>

int main()
{
    for (int i = 0; i < 5; i++)
    {
        if (i == 0 || i == 4)
            printf("* * * * *\n");
        else if (i == 1 || i == 3)
            printf("  *   *  \n");
        else
            printf("    *    \n");
    }
}