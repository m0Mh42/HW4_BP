#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// allocate enough memory for matrix
void allocateMatrix(int ***matrix, int rows, int cols)
{
    // allocating rows
    *matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        // allocating cols
        (*matrix)[i] = (int *)malloc(cols * sizeof(int));
    }
}

// free the memory
void freeMatrix(int **matrix, int rows)
{
    // free cols
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    // free rows
    free(matrix);
}

// fill our matrix in order to be a Toeplitz matrix
void fillToeplitz(int **matrix, int n, int *ptr)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
            {
                matrix[i][j] = ptr[j - i];
            }
            else
            {
                matrix[i][j] = ptr[n + i - j - 1];
            }
        }
    }
}

// check elements f matrix
int checkMatrix(int **matrix, int i, int j)
{
    return matrix[i - 1][j - 1];
}

// printMatrix
void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// calculate determinant of our matrix
int determinantMatrix(int **matrix, int n)
{
    if (n == 1)
        return **matrix;
    if (n == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    int y = 1;
    int det = 0;

    for (int i = 0; i < n; i++)
    {
        int **submatrix;
        allocateMatrix(&submatrix, n - 1, n - 1);
        int sub_i = 0, sub_j = 0;
        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (k == i)
                    continue;
                submatrix[sub_i][sub_j++] = matrix[j][k];
            }
            sub_i++;
            sub_j = 0;
        }
        det += y * matrix[0][i] * determinantMatrix(submatrix, n - 1);
        y *= -1;
        freeMatrix(submatrix, n - 1);
    }
    return det;
}
// oh plz
