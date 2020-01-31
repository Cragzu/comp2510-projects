// Created by Chloe Glave (A01166947) on 1/31/2020.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "A01166947_file_copy.h"

#define MAX_LINE_SIZE  1000

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
    }

    fclose(file);
    printf("%s", content);
    return true;
}

void fileCopy(char firstFileName[], char secondFileName[]) {
    char fileContent[MAX_LINE_SIZE];

    readFile(firstFileName, fileContent);

//    printf("%s\n", firstFileName);
//    printf("%s\n", secondFileName);
}
