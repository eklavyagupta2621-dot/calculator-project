#ifndef MATRIX_H
#define MATRIX_H

int** createMatrix(int rows, int cols);
void  inputMatrix(int **mat, int rows, int cols);
void  printMatrix(int **mat, int rows, int cols);

int** addMatrix(int **A, int **B, int rows, int cols);
int** subtractMatrix(int **A, int **B, int rows, int cols);
int** multiplyMatrix(int **A, int **B, int r1, int c1, int c2);
int** divideMatrix(int **A, int **B, int rows, int cols);

void  freeMatrix(int **mat, int rows);

#endif