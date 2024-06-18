#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
    Student *head = NULL;
    int choice, id, age;
    char name[50];

    while (1) {
        printf("Student Database Menu\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Search Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                addStudent(&head, id, name, age);
                break;
            case 2:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteStudent(&head, id);
                break;
            case 3:
                displayStudents(head);
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student *found = searchStudent(head, id);
                if (found) {
                    printf("Student found!\n");
                    printf("ID: %d\n", found->id);
                    printf("Name: %s\n", found->name);
                    printf("Age: %d\n\n", found->age);
                } else {
                    printf("Student not found!\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

