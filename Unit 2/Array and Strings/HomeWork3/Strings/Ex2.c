//
// Created by xcite on 4/13/2024.
//
#include <stdio.h>

int main() {
    char str[60];
    printf(" Enter your string = ");
    fgets(str, 60, stdin);
    fflush(stdin);

    int i = 0;
    while (*(str + i)){
        i++;
    }
    printf("String len = %i",i-1);

}
