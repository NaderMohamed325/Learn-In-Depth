#include <stdio.h>
#include <stdlib.h>

int fac(int n) {

    if(n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * fac(n - 1);
    }
}

int main() {
    printf("Enter the number: ");
    int var;
    scanf("%i", &var);
    if(var < 0) {
        printf("Error: Factorial of a negative number doesn't exist.\n");
        return 0;
    }
    printf("Output = %i\n", fac(var));
    return 0;
}
