#include <stdio.h>

int main() {
    double num1;

    printf("Enter the number: ");
    scanf("%lf", &num1);

    if (num1 > 0) {
        printf("%.2lf is positive number.\n", num1);
    }

    else if(num1==0) {
        printf("%.2lf is zero .\n", num1);
    }
    else{
        printf("%.2lf is negative number.\n", num1);
    }

    return 0;
}
