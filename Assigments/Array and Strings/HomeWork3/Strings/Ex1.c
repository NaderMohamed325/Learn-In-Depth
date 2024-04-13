//
// Created by xcite on 4/13/2024.
//
#include <stdio.h>

int main() {
    char str[60];
    printf(" Enter your string = ");
    fgets(str, 60, stdin);
    fflush(stdin);
    int a[52] = {0};
    int i = 0;
    while (*(str + i)) {
        char c = *(str + i);
        if (c >= 'a' && c <= 'z') {
            a[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            a[c - 'A' + 26]++;
        }
        i++;
    }
    printf("Enter the frequency char = ");
    char c;
    scanf_s("%c",&c);
    if (c >= 'a' && c <= 'z') {
        printf("%c has appeared %i  times" ,c,a[c-'a']);

    } else if (c >= 'A' && c <= 'Z') {
        printf("%c has appeared %i  times" ,c,a[c-'A'+26]);
    }


}