//
// Created by xcite on 4/13/2024.
//
#include <stdio.h>

int main() {

    int size;
    printf(" Enter the size: ");
    fflush(stdout);
    scanf_s("%i", &size);

    int a[size];

    printf("Enter the elements: ");
    for (int i = 0; i < size; ++i) {
        scanf_s("%i", &a[i]);
    }
    printf("Enter the wanted element");
    int element;
    scanf_s("%i",&element);
    for (int i = 0; i < size; ++i) {
        if(a[i]==element){
            printf(" Index = %i",i+1);
            return 0;
        }
    }
}