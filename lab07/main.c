#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

struct Student {
    char *name;
    double gpa;
};

bool readFile(char *fileName, char content[MAX_LINE_SIZE]) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Could not open file for reading.");
        return false;
    }

    strcpy(content, "");
    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        strcat(content, line);
        printf("%s", line);
    }

    fclose(file);
    return true;
}

int main(int argc, char** argv) {
    char content[MAX_LINE_SIZE];

    struct Student chloe = {"Chloe", 4.0};
    struct Student clint = {"Clint", 5.0};
    printf("%s, %f\n", chloe.name, chloe.gpa);
    printf("%s, %f", clint.name, clint.gpa);

    //readFile(argv[1], content);
    return 0;
}
