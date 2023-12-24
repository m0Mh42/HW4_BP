#ifndef TOEPLITZ_MATRIX_H
#define TOEPLITZ_MATRIX_H

void allocateMatrix(int*** matrix, int rows, int cols);
void fillToeplitz(int** matrix, int n, int* ptr);
int checkMatrix(int** matrix, int i, int j);
void printMatrix(int** matrix, int rows, int cols);
int determinantMatrix(int** matrix, int n);
void freeMatrix(int** matrix, int rows);


#endif