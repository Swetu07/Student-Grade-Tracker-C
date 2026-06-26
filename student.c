#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void addStudent()
{
    struct Student s;

    FILE *fp = fopen("students.dat", "ab");

    if(fp == NULL)
    {
        printf("\nError Opening File!\n");
        return;
    }

    printf("\n========== ADD STUDENT ==========\n");

    printf("Enter Roll Number : ");
    scanf("%d", &s.rollNo);

    printf("Enter Student Name : ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks (Out of 100) : ");
    scanf("%f", &s.marks);

    s.percentage = s.marks;

    if(s.percentage >= 90)
        s.grade = 'A';
    else if(s.percentage >= 75)
        s.grade = 'B';
    else if(s.percentage >= 60)
        s.grade = 'C';
    else if(s.percentage >= 40)
        s.grade = 'D';
    else
        s.grade = 'F';

    fwrite(&s, sizeof(struct Student), 1, fp);

    fclose(fp);

    printf("\nStudent Added Successfully!\n");
}
void displayStudents()
{
    struct Student s;

    FILE *fp = fopen("students.dat", "rb");

    if(fp == NULL)
    {
        printf("\nNo Student Records Found!\n");
        return;
    }

    printf("\n==============================================================\n");
    printf(" Roll No\tName\t\tMarks\tPercentage\tGrade\n");
    printf("==============================================================\n");

    while(fread(&s, sizeof(struct Student), 1, fp))
    {
        printf(" %d\t\t%-15s\t%.2f\t%.2f\t\t%c\n",
               s.rollNo,
               s.name,
               s.marks,
               s.percentage,
               s.grade);
    }

    printf("==============================================================\n");

    fclose(fp);
}
void searchStudent()
{
    int roll;
    struct Student s;

    FILE *fp = fopen("students.dat", "rb");

    if(fp == NULL)
    {
        printf("\nNo Student Records Found!\n");
        return;
    }

    printf("\nEnter Roll Number to Search : ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(struct Student), 1, fp))
    {
        if(s.rollNo == roll)
        {
            printf("\nStudent Found!\n");
            printf("Roll No    : %d\n", s.rollNo);
            printf("Name       : %s\n", s.name);
            printf("Marks      : %.2f\n", s.marks);
            printf("Percentage : %.2f\n", s.percentage);
            printf("Grade      : %c\n", s.grade);

            fclose(fp);
            return;
        }
    }

    printf("\nStudent Not Found!\n");

    fclose(fp);
}
void updateStudent()
{
    int roll;
    struct Student s;

    FILE *fp = fopen("students.dat", "rb+");

    if(fp == NULL)
    {
        printf("\nNo Student Records Found!\n");
        return;
    }

    printf("\nEnter Roll Number to Update : ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(struct Student), 1, fp))
    {
        if(s.rollNo == roll)
        {
            printf("Enter New Marks : ");
            scanf("%f", &s.marks);

            s.percentage = s.marks;

            if(s.percentage >= 90)
                s.grade='A';
            else if(s.percentage >=75)
                s.grade='B';
            else if(s.percentage >=60)
                s.grade='C';
            else if(s.percentage >=40)
                s.grade='D';
            else
                s.grade='F';

            fseek(fp, -(long)sizeof(struct Student), SEEK_CUR);

            fwrite(&s, sizeof(struct Student), 1, fp);

            printf("\nStudent Updated Successfully!\n");

            fclose(fp);
            return;
        }
    }

    printf("\nStudent Not Found!\n");

    fclose(fp);
}
void deleteStudent()
{
    int roll;
    struct Student s;

    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if(fp == NULL)
    {
        printf("\nNo Student Records Found!\n");
        return;
    }

    printf("\nEnter Roll Number to Delete : ");
    scanf("%d", &roll);

    int found = 0;

    while(fread(&s, sizeof(struct Student), 1, fp))
    {
        if(s.rollNo == roll)
        {
            found = 1;
            continue;
        }

        fwrite(&s, sizeof(struct Student), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if(found)
        printf("\nStudent Deleted Successfully!\n");
    else
        printf("\nStudent Not Found!\n");
}