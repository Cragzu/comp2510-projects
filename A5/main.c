#include <stdio.h>
#include <stdbool.h>

#define MAX_NUMBER_OF_LINES 20
#define MAX_NUMBER_OF_ELEMENTS_ON_EACH_LINE 50
#define MAX_NUMBER 100

void swap(int **p, int **q) {
    int *temp = *p;
    *p = *q;
    *q = temp;
}

void sortArray(int array[MAX_NUMBER_OF_ELEMENTS_ON_EACH_LINE], int arraySize) {
    bool isSorted = false;

    /*bubble sort*/
    while (!isSorted) {
        isSorted = true;
        for (int i = 0; i < arraySize - 1; i++) {
            if (array[i] > array[i + 1]) {
                isSorted = false;
                swap((int **) &array[i], (int **) &array[i + 1]);
            }
        }
    }
}

bool checkIfTwoArraysAreAnagrams(int array1[MAX_NUMBER_OF_ELEMENTS_ON_EACH_LINE],
        int array2[MAX_NUMBER_OF_ELEMENTS_ON_EACH_LINE], int arraySize) {
    sortArray(array1, arraySize);
    sortArray(array2, arraySize);

    for (int i = 0; i < arraySize; i++) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
    return true;
}

bool readFile(char *fileName) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Could not open file for reading.");
        return false;
    }

    int numOfRows, numOfDigits; /*scan first line to get values*/
    fscanf(file, "%d %d", &numOfRows, &numOfDigits);

    int currentNum;
    int storedLineArrays[numOfRows][numOfDigits]; /*2d array containing each line as an array*/
    for (int row = 0; row < numOfRows; row++) {
        for (int digit = 0; digit < numOfDigits; digit++) {
            fscanf(file, "%d", &currentNum);
            storedLineArrays[row][digit] = currentNum;
        }
    }

    for (int arr = 0; arr < numOfRows; arr++) { /*sort all arrays*/
        sortArray(storedLineArrays[arr], numOfDigits);
    }

    for (int firstArrToCompare = 1; firstArrToCompare <= numOfRows; firstArrToCompare++) { /*search for match*/
        for (int secondArrToCompare = firstArrToCompare + 1; secondArrToCompare <= numOfRows; secondArrToCompare++) {
            if (checkIfTwoArraysAreAnagrams(storedLineArrays[firstArrToCompare], storedLineArrays[secondArrToCompare],
                    numOfDigits)) {
                /*add 2 to print to account for starting at 0 and first line being number of rows & digits*/
                printf("Match found on lines %d and %d.", firstArrToCompare + 2, secondArrToCompare + 2);
                return true;

            }
        }
    }
    printf("No anagrams found in this file.");

    fclose(file);
    return true;
}

int main(int argc, char** argv) {

    readFile(argv[1]);

    return 0;
}
