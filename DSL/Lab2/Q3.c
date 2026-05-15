#include <stdio.h>
#include <stdlib.h>

int** allocMat(int r, int c) {
    int** m = malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
        *(m + i) = malloc(c * sizeof(int));
    return m;
}

void readMat(int** m, int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", (*(m + i) + j));
}

void printMat(int** m, int r, int c) {
    for (int i = 0; i < r; i++, printf("\n"))
        for (int j = 0; j < c; j++)
            printf("%d ", *(*(m + i) + j));
}

int** multiply(int** a, int r1, int c1, int** b, int r2, int c2) {
    if (c1 != r2) return NULL;
    int** res = allocMat(r1, c2);
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            *(*(res + i) + j) = 0;
            for (int k = 0; k < c1; k++)
                *(*(res + i) + j) += *(*(a + i) + k) * *(*(b + k) + j);
        }
    return res;
}

int main() {
    int r1, c1, r2, c2;
    printf("Enter size of Matrix 1: ");
    scanf("%d%d", &r1, &c1);
    printf("Enter size of Matrix 2: ");
    scanf("%d%d", &r2, &c2);

    int** A = allocMat(r1, c1);
    int** B = allocMat(r2, c2);

    printf("Enter Matrix 1:\n");
    readMat(A, r1, c1);
    printf("Enter Matrix 2:\n");
    readMat(B, r2, c2);

    printf("Matrix 1:\n");
    printMat(A, r1, c1);
    printf("Matrix 2:\n");
    printMat(B, r2, c2);

    int** C = multiply(A, r1, c1, B, r2, c2);
    if (C) {
        printf("Product:\n");
        printMat(C, r1, c2);
    } else {
        printf("Matrix multiplication not possible.\n");
    }

    return 0;
}
