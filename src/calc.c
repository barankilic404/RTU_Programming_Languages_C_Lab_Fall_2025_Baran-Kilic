// Baran Kilic 231ADB113
// https://github.com/barankilic404/RTU_Programming_Languages_C_Lab_Fall_2025_Baran-Kilic
// Compile with: gcc -O2 -Wall -Wextra -std=c17 -o calc calc.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main(int argc, char *argv[]) {
    FILE *file;
    char line[200];
    int i = 0;
    long long result = 0;
    int number = 0;
    int sign = 1;
    int expect_number = 1; // true: sayı bekleniyor
    int pos = 1;           // karakter pozisyonu (1-based)

    if (argc < 2) {
        printf("Usage: %s input.txt\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    if (fgets(line, sizeof(line), file) == NULL) {
        printf("ERROR:1\n");
        fclose(file);
        return 0;
    }
    fclose(file);

    while (line[i] != '\0' && line[i] != '\n') {
        if (isspace(line[i])) {
            i++;
            pos++;
            continue;
        }

        if (expect_number) {
            if (line[i] == '+' || line[i] == '-') {
                printf("ERROR:%d\n", pos);
                return 0;
            }
            if (!isdigit(line[i])) {
                printf("ERROR:%d\n", pos);
                return 0;
            }

            number = 0;
            while (isdigit(line[i])) {
                number = number * 10 + (line[i] - '0');
                i++;
                pos++;
            }
            result += sign * number;
            expect_number = 0;
        } else {
            if (line[i] == '+') {
                sign = 1;
                expect_number = 1;
                i++;
                pos++;
            } else if (line[i] == '-') {
                sign = -1;
                expect_number = 1;
                i++;
                pos++;
            } else {
                printf("ERROR:%d\n", pos);
                return 0;
            }
        }
    }

    if (expect_number) {
        printf("ERROR:%d\n", pos - 1);
        return 0;
    }

    printf("%lld\n", result);
    return 0;
}
