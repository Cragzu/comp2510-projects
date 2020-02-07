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

bool readFile(char *fileName) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Could not open file for reading.");
        return false;
    }
    
    int numOfRows, numOfColumns;
    fscanf(file, "%d %d", &numOfRows, &numOfColumns);
    printf("Number of rows: %d\n", numOfRows);
    printf("Number of columns: %d\n", numOfColumns);

    int currentNum;
    int currentBinaryLine[numOfColumns];
    for (int row = 0; row < numOfRows; row++) {
        for (int digit = 0; digit < numOfColumns; digit++) {
            fscanf(file, "%d", &currentNum);
            currentBinaryLine[digit] = currentNum;
        }
        printf("Decimal value of line %d: %d\n", row+1, fromBinary(currentBinaryLine, numOfColumns));
    }

    fclose(file);
    return true;
}

void processFile(char *fileName) {
    readFile(fileName);
}