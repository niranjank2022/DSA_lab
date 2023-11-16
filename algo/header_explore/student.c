#include "student.h"
#include <stdio.h>

struct student {
    int rollno;
    float cgpa;
};

// typedef struct student Student;

void getData(struct student *student) {
    printf("Enter Roll No: ");
    scanf("%d", student->rollno);

    printf("Enter cgpa: ");
    scanf("%f", student->cgpa);
}

void displayData(struct student *student) {
    printf("Student's details:\n"
            "Roll   No: %d\n"
            "CGPA: %.2f\n", student->rollno, student->cgpa);
}