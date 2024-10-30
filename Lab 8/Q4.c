#include <stdio.h>

int main()
{
    int matrix_a[3][3], matrix_b[3][3], result_matrix[3][3], subtracted_matrix[3][3];

    printf("Enter elements of Matrix A (3x3):\n");
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            scanf("%d", &matrix_a[row][col]);
        }
    }

    printf("Enter elements of Matrix B (3x3):\n");
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            scanf("%d", &matrix_b[row][col]);
        }
    }

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            result_matrix[row][col] = 0;
            for (int k = 0; k < 3; k++)
            {
                result_matrix[row][col] += matrix_a[row][k] * matrix_b[k][col];
            }
        }
    }

    printf("Resultant Matrix (R = A x B):\n");
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf("%d ", result_matrix[row][col]);
        }
        printf("\n");
    }

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            subtracted_matrix[row][col] = matrix_a[row][col] - result_matrix[row][col];
        }
    }

    printf("Subtracted Matrix (S = A - R):\n");
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf("%d ", subtracted_matrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}
