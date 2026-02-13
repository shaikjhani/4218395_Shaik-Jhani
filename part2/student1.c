#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold student data
struct Student {
    int id;
    char name[50];
    float gpa;
};

// Function prototypes
void addStudent();
void displayAll();
void searchStudent();

int main() {
    int choice;
    while (1) {
        printf("\n--- STUDENT RECORD SYSTEM ---");
        printf("\n1. Add Student\n2. Display All\n3. Search by ID\n4. Exit");
        printf("\nChoose an option: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void addStudent() {
    FILE *fp = fopen("students.dat", "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    struct Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    getchar(); // Clear newline
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove newline
    printf("Enter GPA: ");
