/*Write a C program to create a structure with the name student, which contains the fields name, rollno, and gender. 
Use a pointer to read and display the student details.

Input format:

First line Prompt the user to enter the student name.
Second line Prompt the user to enter the student roll number.
Third line Prompt the user to enter the student gender ('M' for male, 'F' for female).


Output format:
Output the student's name, roll number, and gender on separate lines.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the student structure
struct student {
    char name[50];
    int rollno;
    char gender;
};

int main() {
    // Declare a student structure and a pointer to it
  //  struct student *ptr;
    struct student *ptr = (struct student *)malloc(sizeof(struct student));
   // struct student s;

    // Point the pointer to the student structure
  //  ptr = &s;

    // Read student details using the pointer
    printf("Enter student name: ");
    scanf(" %49[^\n]", ptr->name);  // Reads full name with spaces

    printf("Enter student roll number: ");
    scanf("%d", &ptr->rollno);
    printf("Enter student gender (M/F): ");
    scanf(" %c", &ptr->gender);

    // Display student details using the pointer
	printf("Student Details:\n");
    printf("Name: %s\n", ptr->name);
    printf("Roll Number: %d\n", ptr->rollno);
    printf("Gender: %c\n", ptr->gender);

    return 0;
}
