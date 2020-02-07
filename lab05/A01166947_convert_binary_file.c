// Created by Chloe Glave (A01166947) on 2/7/2020.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "A01166947_convert_binary_file.h"

#define MAX_COLUMNS 10

int fromBinary(int *binaryArray, int size) {
    if (size == 0) {
        return 0;
    }
    int number = fromBinary(binaryArray, size - 1);
    return 2 * number + binaryArray[size - 1];
}

bool readFile(char *fileName, char content[MAX_COLUMNS]) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Could not open file for reading.");
        return false;
    }

    strcpy(content, "");
    char line[MAX_COLUMNS];

    while (fgets(line, MAX_COLUMNS, file) != NULL) {
        strcat(content, line);
        printf("%s", line);
    }

    fclose(file);
    return true;
}

void processFile(char *fileName) {
    char fileContent[MAX_COLUMNS];
    readFile(fileName, fileContent);
}