

#include <stdio.h>

int main() {
    double a, b;

    printf("Enter value of a: ");
    scanf("%lf", &a);
    printf("Enter value of b: ");
    scanf("%lf", &b);

    printf("\nBefore swapping, value of a = %.2lf\n", a);
    printf("Before swapping, value of b = %.2lf\n", b);


    a = a + b;
    b = a - b;
    a = a - b;

    printf("\nAfter swapping, value of a = %.2lf\n", a);
    printf("After swapping, value of b = %.2lf\n", b);

    return 0;
}
