#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_student_from_file(Student** head) {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file.\n");
        return;
    }
    Student* temp = NULL;
    while (!feof(file)) {
        temp = (Student*)malloc(sizeof(Student));
        fscanf(file, "%d %s %s %s", &temp->roll_number, temp->first_name, temp->last_name, temp->course);
        temp->next = *head;
        *head = temp;
    }
    fclose(file);
    printf("Student details added from file.\n");
}

void add_student_manually(Student** head) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    printf("Enter roll number: ");
    scanf("%d", &new_student->roll_number);
    printf("Enter first name: ");
    scanf("%s", new_student->first_name);
    printf("Enter last name: ");
    scanf("%s", new_student->last_name);
    printf("Enter course: ");
    scanf("%s", new_student->course);
    new_student->next = *head;
    *head = new_student;
    printf("Student added successfully.\n");
}

void find_student_by_roll_number(Student* head) {
    int roll_number;
    printf("Enter roll number: ");
    scanf("%d", &roll_number);
    Student* current = head;
    while (current != NULL) {
        if (current->roll_number == roll_number) {
            display_student(current);
            return;
        }
        current = current->next;
    }
    printf("Student not found.\n");
}

void find_student_by_first_name(Student* head) {
    char first_name[MAX_NAME_LEN];
    printf("Enter first name: ");
    scanf("%s", first_name);
    Student* current = head;
    while (current != NULL) {
        if (strcmp(current->first_name, first_name) == 0) {
            display_student(current);
        }
        current = current->next;
    }
}

void find_students_by_course(Student* head) {
    char course[MAX_COURSE_LEN];
    printf("Enter course: ");
    scanf("%s", course);
    Student* current = head;
    while (current != NULL) {
        if (strcmp(current->course, course) == 0) {
            display_student(current);
        }
        current = current->next;
    }
}

void count_students(Student* head) {
    int count = 0;
    Student* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    printf("Total number of students: %d\n", count);
}

void delete_student(Student** head) {
    int roll_number;
    printf("Enter roll number of the student to delete: ");
    scanf("%d", &roll_number);
    Student* current = *head;
    Student* prev = NULL;
    while (current != NULL) {
        if (current->roll_number == roll_number) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Student deleted successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Student not found.\n");
}

void update_student(Student* head) {
    int roll_number;
    printf("Enter roll number of the student to update: ");
    scanf("%d", &roll_number);
    Student* current = head;
    while (current != NULL) {
        if (current->roll_number == roll_number) {
            printf("Enter new first name: ");
            scanf("%s", current->first_name);
            printf("Enter new last name: ");
            scanf("%s", current->last_name);
            printf("Enter new course: ");
            scanf("%s", current->course);
            printf("Student updated successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Student not found.\n");
}

void display_student(Student* student) {
    printf("Roll Number: %d\n", student->roll_number);
    printf("First Name: %s\n", student->first_name);
    printf("Last Name: %s\n", student->last_name);
    printf("Course: %s\n", student->course);
}
