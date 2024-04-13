//
// Created by xcite on 4/13/2024.
//
#include <stdio.h>

int main() {


    float a[6], avg = 0;
    printf("Enter the elements of the array \n ");
    for (int i = 0; i < 6; ++i) {
        printf("%i.  = ", i + 1);
        fflush(stdout);
        scanf_s("%f", &a[i]);
        avg += a[i];
    }
    printf("Avg = %.3f", avg / 6.0f);


}