#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void addStudent(Student **head, int id, char name[], int age) {
    Student *newStudent = (Student *)malloc(sizeof(Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = *head;
    *head = newStudent;
}

void deleteStudent(Student **head, int id) {
    Student *temp = *head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void displayStudents(Student *head) {
    Student *current = head;
    while (current != NULL) {
        printf("ID: %d\n", current->id);
        printf("Name: %s\n", current->name);
        printf("Age: %d\n\n", current->age);
        current = current->next;
    }
}

Student* searchStudent(Student *head, int id) {
    Student *current = head;
    while (current != NULL) {
        if (current->id == id)
            return current;
        current = current->next;
    }
    return NULL;
}

