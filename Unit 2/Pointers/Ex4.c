#include <stdio.h>

int main() {
    int n, i;
    int arr[15];

    printf("Input the number of elements to store in the array (max 15): ");
    scanf("%d", &n);

    if (n > 15) {
        printf("Number of elements exceeds the maximum limit of 15.\n");
        return 1;
    }

    printf("Input %d number of elements in the array:\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nThe elements of the array in reverse order are:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("element - %d : %d\n", i + 1, arr[i]);
    }

    return 0;
}

