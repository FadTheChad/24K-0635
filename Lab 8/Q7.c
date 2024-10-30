#include <stdio.h>

int main()
{
    char grid[105][105] = {};
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
            spaces--;
        }
        else if (i == 4 && up == 0)
        {
            spaces = 1;
            up = 1;
            count++;
            if (count != 0)
            {
                grid[i][j] = '*';
                j++;
                if (count != 3)
                    grid[i][j] = '*';
            }
        }
    }

    printf("GRID:\n");
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j < 105; j++)
        {
            if (grid[i][j] == '*')
            {
                printf("%c", grid[i][j]);
            }
            else
                printf(" ");
        }
        printf("\n");
    }
}