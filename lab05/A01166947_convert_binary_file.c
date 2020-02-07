// Created by Chloe Glave (A01166947) on 2/7/2020.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "A01166947_convert_binary_file.h"

#define MAX_COLUMNS 10

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
    }

    fclose(file);
    return true;
}