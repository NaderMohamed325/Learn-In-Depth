//
// Created by xcite on 4/13/2024.
//

#include <stdio.h>

int main(){

    float a[4],b[4];
    printf("Enter the elements of array 1\n ");
    for (int i = 0; i < 4; ++i) {
        printf("a[%i] = ",i);
        fflush(stdout);
        scanf_s("%f",&a[i]);
    }
    printf("Enter the elements of array 2\n ");
    for (int i = 0; i < 4; ++i) {
        printf("b[%i] = ",i);
        fflush(stdout);
        scanf_s("%f",&b[i]);
        a[i]+=b[i];
    }
    printf("Sum ...... \n %.2f %.2f \n %.2f %.2f",a[0],a[1],a[2],a[3]);



}