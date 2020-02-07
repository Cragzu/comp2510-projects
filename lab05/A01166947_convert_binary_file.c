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

    int numOfRows, numOfColumns;
    fscanf(file, "%d %d", &numOfRows, &numOfColumns);
    printf("Number of rows: %d\n", numOfRows);
    printf("Number of columns: %d\n", numOfColumns);

    printf("Current array: ");
    int currentNum;
    int currentBinaryLine[numOfColumns];
    for (int i = 0; i < numOfColumns; i++) {
        fscanf(file, "%d", &currentNum);
        currentBinaryLine[i] = currentNum;
    }

    for (int i = 0; i < numOfColumns; i++) {
        printf("%d ", currentBinaryLine[i]);
    }
    printf("\nDecimal value of first line: %d\n", fromBinary(currentBinaryLine, numOfColumns));



    fclose(file);
    return true;
}

void processFile(char *fileName) {
    char fileContent[MAX_COLUMNS];
    readFile(fileName, fileContent);
}