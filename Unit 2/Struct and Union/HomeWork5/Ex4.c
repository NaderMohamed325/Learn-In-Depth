//
// Created by xcite on 4/28/2024.
//

#include <stdio.h>

typedef struct {
    char name[10];
    int marks;
    char role;
} student_t;

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    student_t a[n];


    for (int i = 0; i < n; ++i) {
        printf("Enter the data for student %d (name, role, marks): ", i + 1);
        fflush(stdin);
        fflush(stdout);
        scanf("%s", a[i].name);
        fflush(stdin);
        fflush(stdout);
        scanf("%c", &a[i].role);
        fflush(stdin);
        fflush(stdout);
        scanf("%d", &a[i].marks);
        fflush(stdin);
        fflush(stdout);
    }


    printf("\nStudent Data:\n");
    printf("Name\tRole\tMarks\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\t%c\t%d\n", a[i].name, a[i].role, a[i].marks);
    }

    return 0;
}
