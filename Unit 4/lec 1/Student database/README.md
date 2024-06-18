## Report on the Student Database Program Using Dynamic Linked List in C

### Introduction

This report details the design, implementation, and functionality of a Student Database program written in C. The program utilizes a dynamic linked list to manage student records efficiently. The linked list allows dynamic memory allocation, ensuring that the program can handle an arbitrary number of student records without predefined limits.

### Objective

The primary objective of this project is to create a simple, interactive, and efficient student database management system that supports the following operations:
1. Adding a student.
2. Deleting a student.
3. Displaying all students.
4. Searching for a student by ID.

### Design and Implementation

#### 1. Data Structure

The program uses a linked list to store student records. Each node in the linked list represents a student and contains the following information:
- `id`: The student's unique identifier.
- `name`: The student's name.
- `age`: The student's age.
- `next`: A pointer to the next student in the list.

The `Student` structure is defined as follows:

```c
typedef struct Student {
    int id;
    char name[50];
    int age;
    struct Student *next;
} Student;
```

#### 2. Function Prototypes

The following functions are declared in the `student.h` header file:
- `void addStudent(Student **head, int id, char name[], int age);`
- `void deleteStudent(Student **head, int id);`
- `void displayStudents(Student *head);`
- `Student* searchStudent(Student *head, int id);`

These functions are responsible for adding, deleting, displaying, and searching for students, respectively.

#### 3. Function Implementations

The function implementations are provided in the `student.c` file.

**Adding a Student**
This function creates a new student record and adds it to the beginning of the linked list.
```c
void addStudent(Student **head, int id, char name[], int age) {
    Student *newStudent = (Student *)malloc(sizeof(Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = *head;
    *head = newStudent;
}
```

**Deleting a Student**
This function removes a student record from the linked list based on the student's ID.
```c
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
```

**Displaying Students**
This function traverses the linked list and prints out the details of each student.
```c
void displayStudents(Student *head) {
    Student *current = head;
    while (current != NULL) {
        printf("ID: %d\n", current->id);
        printf("Name: %s\n", current->name);
        printf("Age: %d\n\n", current->age);
        current = current->next;
    }
}
```

**Searching for a Student**
This function searches for a student by ID and returns the student record if found.
```c
Student* searchStudent(Student *head, int id) {
    Student *current = head;
    while (current != NULL) {
        if (current->id == id)
            return current;
        current = current->next;
    }
    return NULL;
}
```

#### 4. Main Program

The `main.c` file contains the main function, which provides an interactive menu for the user to manage the student database. The menu allows the user to add, delete, display, and search for students.

```c
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
```
### Conclusion

This Student Database program demonstrates how to use a dynamic linked list to manage student records in C. The linked list allows for efficient memory usage and dynamic resizing, making it suitable for applications where the number of records is not known in advance. The program provides basic functionalities to add, delete, display, and search for student records, offering a practical example of linked list operations in C.
