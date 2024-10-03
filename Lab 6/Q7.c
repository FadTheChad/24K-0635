#include <stdio.h>

int main()
{
    for (int i = 0; i < 6; i++)
    {
        if (i == 0 || i == 5)
            printf("%c %c %c %c %c\n", i + 65, i + 66, i + 67, i + 68, i + 69);
        else
            printf("%c       %c\n", i + 65, i + 69);
    }
}