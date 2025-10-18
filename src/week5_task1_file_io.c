// Baran Kilic 231 ADB 113
// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char filename[100] = "data.txt";
    char line[256];

    // TODO: 1. Open file for writing (mode = "w")
    // TODO: 2. Check if file opened successfully
    // TODO: 3. Write 2–3 lines of text to the file using fprintf()
    // TODO: 4. Close the file

    // TODO: 5. Open file again for reading (mode = "r")
    // TODO: 6. Use fgets() in a loop to read and print each line to the console
    // TODO: 7. Close the file

    // BONUS: ask user for filename instead of using default "data.txt"
    // BONUS: count number of lines read

    main_solution();
    return 0;
}

int main_solution(void) {
    FILE *fp;
    char filename[100] = "data.txt";
    char line[256];
    int line_count = 0;

    fp = fopen(filename, "w");
    if (fp == NULL) return 1;

    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");
    fprintf(fp, "End of demo.\n");
    fclose(fp);

    fp = fopen(filename, "r");
    if (fp == NULL) return 1;

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        line_count++;
    }
    fclose(fp);

    printf("\nLines read: %d\n", line_count);
    return 0;
}
