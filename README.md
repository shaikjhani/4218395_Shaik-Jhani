# 4218395\_Shaik-Jhani 



\#include <stdio.h>

\#include <stdlib.h>

\#include <string.h>



// Define a structure for student data

struct Student {

&nbsp;   int id;

&nbsp;   char name\[50];

&nbsp;   float gpa;

};



// Function to add a new student

void addStudent(FILE \*fp) {

&nbsp;   struct Student s;

&nbsp;   printf("Enter student ID: ");

&nbsp;   scanf("%d", \&s.id);

&nbsp;   printf("Enter student name: ");

&nbsp;   scanf("%s", s.name);

&nbsp;   printf("Enter student GPA: ");

&nbsp;   scanf("%f", \&s.gpa);



&nbsp;   fwrite(\&s, sizeof(struct Student), 1, fp);

&nbsp;   printf("Student added successfully.\\n");

}



// Function to display all students

void displayStudents(FILE \*fp) {

&nbsp;   struct Student s;

&nbsp;   rewind(fp); // Go to the beginning of the file



&nbsp;   printf("\\n--- Student List ---\\n");

&nbsp;   while (fread(\&s, sizeof(struct Student), 1, fp) == 1) {

&nbsp;       printf("ID: %d, Name: %s, GPA: %.2f\\n", s.id, s.name, s.gpa);

&nbsp;   }

&nbsp;   printf("--------------------\\n");

}



// Function to search for a student by ID

void searchStudent(FILE \*fp) {

&nbsp;   int searchId;

&nbsp;   struct Student s;

&nbsp;   int found = 0;



&nbsp;   printf("Enter student ID to search: ");

&nbsp;   scanf("%d", \&searchId);



&nbsp;   rewind(fp);

&nbsp;   while (fread(\&s, sizeof(struct Student), 1, fp) == 1) {

&nbsp;       if (s.id == searchId) {

&nbsp;           printf("\\nStudent found:\\n");

&nbsp;           printf("ID: %d, Name: %s, GPA: %.2f\\n", s.id, s.name, s.gpa);

&nbsp;           found = 1;

&nbsp;           break;

&nbsp;       }

&nbsp;   }



&nbsp;   if (!found) {

&nbsp;       printf("Student with ID %d not found.\\n", searchId);

&nbsp;   }

}



int main() {

&nbsp;   FILE \*fp;

&nbsp;   int choice;



&nbsp;   // Open file in append and read mode (creates if not exists)

&nbsp;   fp = fopen("students.dat", "ab+"); 

&nbsp;   if (fp == NULL) {

&nbsp;       perror("Error opening file");

&nbsp;       return 1;

&nbsp;   }



&nbsp;   do {

&nbsp;       printf("\\n--- Student Database Menu ---\\n");

&nbsp;       printf("1. Add Student\\n");

&nbsp;       printf("2. Display All Students\\n");

&nbsp;       printf("3. Search Student by ID\\n");

&nbsp;       printf("4. Exit\\n");

&nbsp;       printf("Enter your choice: ");

&nbsp;       scanf("%d", \&choice);



&nbsp;       switch (choice) {

&nbsp;           case 1:

&nbsp;               addStudent(fp);

&nbsp;               break;

&nbsp;           case 2:

&nbsp;               displayStudents(fp);

&nbsp;               break;

&nbsp;           case 3:

&nbsp;               searchStudent(fp);

&nbsp;               break;

&nbsp;           case 4:

&nbsp;               printf("Exiting program.\\n");

&nbsp;               break;

&nbsp;           default:

&nbsp;               printf("Invalid choice. Please try again.\\n");

&nbsp;       }

&nbsp;   } while (choice != 4);



&nbsp;   fclose(fp);

&nbsp;   return 4;

}

