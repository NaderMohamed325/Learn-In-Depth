# Student Management System

This is a simple student management system implemented in C using a linked list. The system allows you to add, update, find, delete, and count students, as well as load student data from a file.

## Features

1. **Add Student Details From File**: Load student details from a specified file.
2. **Add Student Details Manually**: Add a new student manually.
3. **Find Student by Roll Number**: Find a student using their roll number.
4. **Find Student by First Name**: Find a student using their first name.
5. **Find Students by Course**: Find all students registered in a specified course.
6. **Count of Students**: Display the total number of students.
7. **Delete a Student**: Delete a student using their roll number.
8. **Update Student**: Update the details of a student using their roll number.

## File Structure

- `student.h`: Header file containing the structure definition and function prototypes.
- `student.c`: Source file containing the implementation of student-related functions.
- `main.c`: Source file containing the main function and menu logic.

## Compilation and Execution

### Requirements

- GCC or any C compiler




---

## Student Management System Report

### Introduction

The Student Management System is a command-line interface (CLI) application developed in C, designed to efficiently manage student records using a linked list. This system allows users to perform various operations such as adding, updating, finding, deleting, and counting students. It also supports loading student data from an external file.

### Objectives

The primary objectives of this project are:
1. To develop a simple and efficient system for managing student records.
2. To demonstrate the use of linked lists in managing dynamic data structures.
3. To provide functionalities for adding, updating, finding, deleting, and counting student records.
4. To enable loading student details from an external file for easier data management.

### Features

1. **Add Student Details From File**: Allows users to load student records from a specified file.
2. **Add Student Details Manually**: Enables users to manually add a new student record.
3. **Find Student by Roll Number**: Searches for a student using their roll number.
4. **Find Student by First Name**: Searches for students using their first name.
5. **Find Students by Course**: Finds all students registered in a specified course.
6. **Count of Students**: Displays the total number of students in the system.
7. **Delete a Student**: Removes a student record using their roll number.
8. **Update Student**: Updates the details of a student using their roll number.

### Implementation

#### Structure Definition

A `Student` structure is defined to store individual student details, including roll number, first name, last name, course, and a pointer to the next student node in the linked list.

```c
typedef struct Student {
    int roll_number;
    char first_name[MAX_NAME_LEN];
    char last_name[MAX_NAME_LEN];
    char course[MAX_COURSE_LEN];
    struct Student* next;
} Student;
```

#### Function Implementations

Several functions are implemented to manage student records, including:

- `add_student_from_file`: Loads student details from a specified file.
- `add_student_manually`: Manually adds a new student record.
- `find_student_by_roll_number`: Finds a student by roll number.
- `find_student_by_first_name`: Finds students by first name.
- `find_students_by_course`: Finds all students in a specified course.
- `count_students`: Counts the total number of students.
- `delete_student`: Deletes a student by roll number.
- `update_student`: Updates student details.
- `display_student`: Displays student details.

### Usage

The system is interactive and menu-driven. Users are presented with a menu to select various options for managing student records. Each option guides the user through the required steps to perform the desired operation.

### Example

1. **Adding Students from File**:
   - Prepare a file (`students.txt`) with student details.
   - Run the program and select option 1.
   - Enter the filename when prompted.

2. **Manually Adding a Student**:
   - Run the program and select option 2.
   - Enter the student details as prompted.

3. **Finding and Displaying Students**:
   - Run the program and select the appropriate option (3, 4, or 5) for finding students by roll number, first name, or course.

4. **Counting Students**:
   - Run the program and select option 6 to display the total number of students.

5. **Deleting and Updating Students**:
   - Select option 7 or 8 and follow the prompts to delete or update student records.

### Conclusion

The Student Management System provides a straightforward and efficient way to manage student records using linked lists. It demonstrates practical use of dynamic data structures in C and offers a robust solution for handling various student-related operations. This system can be further extended with additional features and improvements based on user requirements.

---

