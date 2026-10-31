#include <stdio.h>
#include <string.h>

#define MAX 100
#define SUBJECTS 5

struct Student {
    int usn;
    char name[50];
    int marks[SUBJECTS];
    int total;
    float average;
};

void addStudent(struct Student s[], int *n) {
    if (*n >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter USN: ");
    scanf("%d", &s[*n].usn);

    printf("Enter name (no spaces): ");
    scanf("%49s", s[*n].name);

    s[*n].total = 0;

    for (int i = 0; i < SUBJECTS; i++) {
        printf("Enter marks for subject %d (0-100): ", i + 1);
        scanf("%d", &s[*n].marks[i]);

        if (s[*n].marks[i] < 0 || s[*n].marks[i] > 100) {
            printf("Invalid marks! Enter again.\n");
            i--;
            continue;
        }

        s[*n].total += s[*n].marks[i];
    }

    s[*n].average = s[*n].total / (float)SUBJECTS;
    (*n)++;

    printf("Student added successfully!\n");
}

void displayStudents(struct Student s[], int n) {
    if (n == 0) {
        printf("No student records found.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nUSN: %d\n", s[i].usn);
        printf("Name: %s\n", s[i].name);
        printf("Total Marks: %d\n", s[i].total);
        printf("Average: %.2f\n", s[i].average);

        if (s[i].average >= 35)
            printf("Result: Pass\n");
        else
            printf("Result: Fail\n");
    }
}

void searchStudent(struct Student s[], int n) {
    int usn, found = 0;

    printf("Enter USN to search: ");
    scanf("%d", &usn);

    for (int i = 0; i < n; i++) {
        if (s[i].usn == usn) {
            printf("Student found!\n");
            printf("Name: %s\n", s[i].name);
            printf("Total: %d\n", s[i].total);
            printf("Average: %.2f\n", s[i].average);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");
}

void highestScorer(struct Student s[], int n) {
    if (n == 0) {
        printf("No records available.\n");
        return;
    }

    int highest = 0;

    for (int i = 1; i < n; i++) {
        if (s[i].total > s[highest].total)
            highest = i;
    }

    printf("\nHighest Scorer\n");
    printf("Name: %s\n", s[highest].name);
    printf("USN: %d\n", s[highest].usn);
    printf("Total Marks: %d\n", s[highest].total);
}

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Display Highest Scorer\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                highestScorer(students, count);
                break;

            case 5:
                printf("Exiting program. Thank you!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
                continue;
        }

    } while (choice != 5);

    return 0;
}
