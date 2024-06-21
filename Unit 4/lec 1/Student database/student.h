#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_LEN 50
#define MAX_COURSE_LEN 50

typedef struct Student {
    int roll_number;
    char first_name[MAX_NAME_LEN];
    char last_name[MAX_NAME_LEN];
    char course[MAX_COURSE_LEN];
    struct Student* next;
} Student;

void add_student_from_file(Student** head);
void add_student_manually(Student** head);
void find_student_by_roll_number(Student* head);
void find_student_by_first_name(Student* head);
void find_students_by_course(Student* head);
void count_students(Student* head);
void delete_student(Student** head);
void update_student(Student* head);
void display_student(Student* student);

#endif // STUDENT_H
