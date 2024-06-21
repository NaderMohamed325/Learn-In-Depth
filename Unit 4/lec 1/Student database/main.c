#include "student.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Student* head = NULL;
    int choice;
    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student Details From File\n");
        printf("2. Add Student Details Manually\n");
        printf("3. Find the student by the given roll number\n");
        printf("4. Find the student by the given first name\n");
        printf("5. Find the students registered in a course\n");
        printf("6. Count of students\n");
        printf("7. Delete a student\n");
        printf("8. Update Student\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
            case 1:
                add_student_from_file(&head);
                break;
            case 2:
                add_student_manually(&head);
                break;
            case 3:
                find_student_by_roll_number(head);
                break;
            case 4:
                find_student_by_first_name(head);
                break;
            case 5:
                find_students_by_course(head);
                break;
            case 6:
                count_students(head);
                break;
            case 7:
                delete_student(&head);
                break;
            case 8:
                update_student(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
