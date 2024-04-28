//
// Created by xcite on 4/28/2024.
//
#include <stdio.h>

typedef struct {
    float real;
    float imaginary;
} complex_t;

int main() {
    complex_t n1, n2;
    printf("Enter 1 real part then imaginary\r\n");
    scanf("%f%f", &n1.real, &n1.imaginary);
    printf("Enter 2 real part then imaginary\r\n");
    scanf("%f%f", &n2.real, &n2.imaginary);

    printf("%f  +%fi", n1.real + n2.real, n1.imaginary + n2.imaginary);
}