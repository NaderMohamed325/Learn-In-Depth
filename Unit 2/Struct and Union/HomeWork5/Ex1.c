//
// Created by xcite on 4/18/2024.
//

#include <stdio.h>

#define clean()  fflush(stdin);fflush(stdout);

int main() {

    typedef struct {
        char name[20];
        int role;
        int mark;
    } student;
    student n1;
    printf("Enter the name  \n");
    clean()
    scanf_s("%s", &n1.name);
    printf("Enter the role  \n");
    clean()
    scanf_s("%i", &n1.role);
    printf("Enter the mark  \n");
    clean()
    scanf_s("%i", &n1.mark);
    clean()
    printf("Displaying Information\r\n");
    printf(" Name= %s\r\n Role= %i\r\n Mark= %i\r\n",n1.name,n1.role,n1.mark);
}