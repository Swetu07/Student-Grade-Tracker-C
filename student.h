#ifndef STUDENT_H
#define STUDENT_H

struct Student
{
    int rollNo;
    char name[50];
    float marks;
    float percentage;
    char grade;
};

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

#endif