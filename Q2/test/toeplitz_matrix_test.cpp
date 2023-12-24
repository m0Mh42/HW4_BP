#include <gtest/gtest.h>
#include "../include/toeplitz_matrix.h"

TEST(toeplitz_matrixTest, CheckMatrix) {
    int** matrix;
    int rows = 5, cols = 5;
    allocateMatrix(&matrix, rows, cols);

    int elements[] = {1,2,3,4,5,6,7,8,9};
    int* ptr = elements;
    fillToeplitz(matrix, 5, ptr);

    int res = checkMatrix(matrix, 2, 3);
    EXPECT_EQ(res, 2);
}

TEST(toeplitz_matrixTest, CheckMatrix2) {
    int** matrix;
    int rows = 5, cols = 5;

    allocateMatrix(&matrix, rows, cols);

    int elements[] = {1,2,3,4,5,6,7,8,9};
    int* ptr = elements;

    fillToeplitz(matrix, 5, ptr);

    int res = checkMatrix(matrix, 5, 4);
    EXPECT_EQ(res, 6);
}

TEST(toeplitz_matrixTest, Determinant) {
    int** matrix;
    int rows = 5, cols = 5;

    allocateMatrix(&matrix, rows, cols);

    int elements[] = {1,2,3,4,5,6,7,8,9};
    int* ptr = elements;

    fillToeplitz(matrix, 5, ptr);

    printf("Matrix:\n");
    printMatrix(matrix, rows, cols);

    int det = determinantMatrix(matrix, rows);
    printf("%d\n", det);

    freeMatrix(matrix, rows);
    
    EXPECT_EQ(det, 4928);
}

