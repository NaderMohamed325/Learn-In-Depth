//
// Created by xcite on 4/13/2024.
//
#include <stdio.h>
#include <string.h>

int main() {
    char str[60];
    char Hello[] = " Enter your string = ";
    printf("%s", Hello);
    fgets(str, 60, stdin);
    fflush(stdin);
    unsigned len = strlen(str);
    char a[len];
    for (int i = 0; i < len; ++i) {
        if (str[len - 1 - i] != '\n') {
            a[i] = str[len - 1 - i];
        } else{
            a[i]=' ';
        }
    }
    a[len] = '\0';
    char bye[] = "the reversed string = ";
    printf("%s", bye);
    printf("%s", a);

}
