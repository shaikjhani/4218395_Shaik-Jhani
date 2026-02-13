    scanf("%f", &s.gpa);

    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);
    printf("Student record added successfully!\n");
}

void displayAll() {
    FILE *fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }
    struct Student s;
    printf("\nID\tName\t\tGPA\n");
    printf("------------------------------\n");
    while (fread(&s, sizeof(struct Student), 1, fp)) {
        printf("%d\t%-15s\t%.2f\n", s.id, s.name, s.gpa);
    }
    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }
    int searchId, found = 0;
    struct Student s;
    printf("Enter ID to search: ");
    scanf("%d", &searchId);

    while (fread(&s, sizeof(struct Student), 1, fp)) {
        if (s.id == searchId) {
            printf("\nRecord Found:");
            printf("\nID: %d\nName: %s\nGPA: %.2f\n", s.id, s.name, s.gpa);
            found = 1;
            break;
        }
    }
    if (!found) printf("Student with ID %d not found.\n", searchId);
    fclose(fp);
}
