#include <stdio.h>
#include <stdlib.h>

#include "algebra.h"
#include "matrix.h"
#include "trig.h"

int main(void) {
    int choice;

    printf("1. Algebra operations\n");
    printf("2. Matrix addition\n");
    printf("3. Matrix subtraction\n");
    printf("4. Matrix multiplication\n");
    printf("5. Matrix division\n");
    printf("6. Trigonometric operations\n");
    printf("Enter your choice for calculator: ");
    scanf("%d", &choice);

    if (choice == 1) {
        algebra();
    }
    else if (choice >= 2 && choice <= 5) {
        int r1, c1, r2, c2;

        /* --- Addition / Subtraction / Division: same-size matrices --- */
        if (choice == 2 || choice == 3 || choice == 5) {
            printf("Enter rows and cols of the matrices: ");
            scanf("%d %d", &r1, &c1);

            int **A = createMatrix(r1, c1);
            int **B = createMatrix(r1, c1);

            printf("Matrix A:\n");
            inputMatrix(A, r1, c1);

            printf("Matrix B:\n");
            inputMatrix(B, r1, c1);

            int **C = NULL;
            if (choice == 2)
                C = addMatrix(A, B, r1, c1);
            else if (choice == 3)
                C = subtractMatrix(A, B, r1, c1);
            else
                C = divideMatrix(A, B, r1, c1);

            printMatrix(C, r1, c1);

            freeMatrix(A, r1);
            freeMatrix(B, r1);
            freeMatrix(C, r1);
        }
        /* --- Multiplication: dimensions must be compatible --- */
        else { /* choice == 4 */
            printf("Enter rows and cols of Matrix A: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter rows and cols of Matrix B: ");
            scanf("%d %d", &r2, &c2);

            if (c1 != r2) {
                printf("Multiplication not possible (cols of A must equal rows of B).\n");
                return 0;
            }

            int **A = createMatrix(r1, c1);
            int **B = createMatrix(r2, c2);

            printf("Matrix A:\n");
            inputMatrix(A, r1, c1);

            printf("Matrix B:\n");
            inputMatrix(B, r2, c2);

            int **C = multiplyMatrix(A, B, r1, c1, c2);
            printMatrix(C, r1, c2);

            freeMatrix(A, r1);
            freeMatrix(B, r2);
            freeMatrix(C, r1);
        }
    }
    else if (choice == 6) {
        int degrees;
        printf("Enter angle in degrees: ");
        scanf("%d", &degrees);
        printf("Your output = %.3f\n", trigonometry(degrees));
    }
    else {
        printf("Invalid choice\n");
    }

    return 0;
}