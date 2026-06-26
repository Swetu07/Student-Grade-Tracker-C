#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main()
{
    int choice;

    while(1)
    {
        printf("\n=====================================\n");
        printf("      STUDENT GRADE TRACKER\n");
        printf("=====================================\n");

        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student Marks\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nThank you for using Student Grade Tracker!\n");
                exit(0);

            default:
                printf("\nInvalid Choice! Please try again.\n");
        }
    }

    return 0;
}