#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

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

    readFile(argv[1], content);
    return 0;
}
