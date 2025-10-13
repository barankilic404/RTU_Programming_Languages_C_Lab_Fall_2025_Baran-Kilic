/*
 * week4_3_struct_database.c
 * Author: Baran Kilic
 * Student ID: 231ADB113
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Define struct Student with fields name, id, grade
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // TODO: Allocate memory for n Student structs using malloc
    students = malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // TODO: Read student data in a loop
    for (int i = 0; i < n; i++) {
        printf("\nEnter data for student %d:\n", i + 1);

        printf("Name: ");
        scanf("%49s", students[i].name); // boşluk desteklenmez, fgets istenmiyor kural gereği

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Grade: ");
        scanf("%f", &students[i].grade);
    }

    // TODO: Display all student records in formatted output
    printf("\n%-5s %-20s %-6s\n", "ID", "Name", "Grade");
    printf("-----------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-20s %-6.2f\n",
               students[i].id, students[i].name, students[i].grade);
    }

    // Optional: Compute average grade or find top student
    float total = 0.0f;
    for (int i = 0; i < n; i++) {
        total += students[i].grade;
    }
    printf("\nAverage grade: %.2f\n", total / n);

    // TODO: Free allocated memory
    free(students);

    return 0;
}
