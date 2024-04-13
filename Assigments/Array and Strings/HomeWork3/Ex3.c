//
// Created by xcite on 4/13/2024.
//
#include <stdio.h>

int main() {
    int n, m;

    printf("Enter the number of rows and columns of matrix\n");
    scanf_s("%i %i", &n, &m);
    int a[n][m], b[m][n];
    printf("Enter the elements of the matrix\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("a[%i][%i] = ", i, j);
            fflush(stdout);
            scanf_s("%i", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {            b[j][i] = a[i][j];
        }
    }
    printf("The transpose of the matrix is\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%i ", b[i][j]);
        }
        printf("\n");
    }
    return 0;


}