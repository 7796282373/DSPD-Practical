//Write a program which creates a structure Student which must have the attribute 
// Avg Marks with 3 more attributes sort the list of the student in descending order using Bubble sort.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNumber;
    int age;
    float avgMarks;
};

void bubbleSort(struct Student arr[], int n) {
    int i, j;
    struct Student temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            if (arr[j].avgMarks < arr[j+1].avgMarks) { // Descending order
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    struct Student *students = (struct Student *) malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter details of student %d:\n", i+1);
        printf("Name: ");
        getchar(); // Clear newline from buffer
        fgets(students[i].name, sizeof(students[i].name), stdin);
        // Remove trailing newline from fgets if present
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Average Marks: ");
        scanf("%f", &students[i].avgMarks);
    }

    bubbleSort(students, n);

    printf("\nStudents sorted by Average Marks (Descending):\n");
    printf("Name\tRoll No.\tAge\tAvg Marks\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t%.2f\n", students[i].name, students[i].rollNumber, students[i].age, students[i].avgMarks);
    }

    free(students);
    return 0;
}
