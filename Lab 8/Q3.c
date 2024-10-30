#include <stdio.h>

int main()
{
    int matrix[3][3];

    printf("Enter the elements of the 3x3 matrix:\n");
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            scanf("%d", &matrix[row][col]);
        }
    }

    for (int row = 0; row < 3; row++)
    {
        int min_element = matrix[row][0];
        int min_col_index = 0;

        // Ye minimum element in i'th row find karega
        for (int col = 1; col < 3; col++)
        {
            if (matrix[row][col] < min_element)
            {
                min_element = matrix[row][col];
                min_col_index = col;
            }
        }

        // Ab jis column mai hamay minimum element mila hai, uss hee column mai yeh
        int max_element = matrix[0][min_col_index];
        for (int k = 0; k < 3; k++)
        {
            if (matrix[k][min_col_index] > max_element)
            {
                max_element = matrix[k][min_col_index];
            }
        }

        if (min_element == max_element)
        {
            printf("Saddle point found: %d at position (%d, %d)\n", min_element, row, min_col_index);
        }
    }

    return 0;
}
