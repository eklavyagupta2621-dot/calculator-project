#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int** createMatrix(int rows, int cols) {
    int **mat = (int**)malloc(rows * sizeof(int*));
    if (mat == NULL) return NULL;
    for (int i = 0; i < rows; i++) {
        mat[i] = (int*)malloc(cols * sizeof(int));
        if (mat[i] == NULL) return NULL;
    }
    return mat;
}

void inputMatrix(int **mat, int rows, int cols) {
    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int **mat, int rows, int cols) {
    printf("Result:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int** addMatrix(int **A, int **B, int rows, int cols) {
    int **C = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

int** subtractMatrix(int **A, int **B, int rows, int cols) {
    int **C = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

int** multiplyMatrix(int **A, int **B, int r1, int c1, int c2) {
    int **C = createMatrix(r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int** divideMatrix(int **A, int **B, int rows, int cols) {
    int **C = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (B[i][j] == 0) {
                printf("Division by zero at position [%d][%d]\n", i, j);
                C[i][j] = 0;
            } else {
                C[i][j] = A[i][j] / B[i][j];
            }
        }
    }
    return C;
}

void freeMatrix(int **mat, int rows) {
    if (mat == NULL) return;
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);
}