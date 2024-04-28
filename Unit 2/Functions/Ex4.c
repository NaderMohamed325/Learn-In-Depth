//
// Created by xcite on 4/16/2024.
//
#include <stdio.h>

long long power(int base, int pow) {
    if (pow == 1)
        return base;
    else if (pow == 0) {
        return 1;
    } else {
        return base * power(base, --pow);
    }
}

int main() {
    int n, m;
    printf("Enter base and power\r\n");
    fflush(stdin);
    fflush(stdout);
    scanf_s("%i%i", &n, &m);
    printf("Output  = %lld", power(n,m));
}