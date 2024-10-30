#include <stdio.h>

int main()
{
    char grid[100][100] = {};
    int i = 4, j = 0;
    int up = 1;
    int spaces = 1;
    int count = 0;

    printf("CALCING....\n");
    while (count != 3)
    {
        printf("%d %d %d\n", i, j, spaces);
        grid[i][j] = '*';

        if (up)
        {
            i--;
            j += spaces;
            spaces++;
        }
        else
        {
            i++;
            j += spaces;
            spaces--;
        }
        if (i == 0 && up == 1)
        {
            up = 0;
        }
        else if (i == 4 && up == 0)
        {
            up = 1;
            if (count != 0)
            {
                grid[i][j] = '*';
            }
            count++;
        }
    }

    printf("GRID:\n");
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (grid[i][j] == '*')
                printf("%c", grid[i][j]);
            else
                printf(" ");
        }
        printf("\n");
    }
}