#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    int id;
    char name[50];
    int age;
    struct Student *next;
} Student;

void addStudent(Student **head, int id, char name[], int age);
void deleteStudent(Student **head, int id);
void displayStudents(Student *head);
Student* searchStudent(Student *head, int id);

#endif

