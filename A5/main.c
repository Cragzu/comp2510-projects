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

    int numOfRows, numOfDigits;
    fscanf(file, "%d %d", &numOfRows, &numOfDigits);
    printf("Number of rows: %d\n", numOfRows);
    printf("Number of columns: %d\n", numOfDigits);

    int currentNum;
    int storedLineArrays[numOfRows][numOfDigits]; /*2d array containing each line as an array*/
    for (int row = 0; row < numOfRows; row++) {
        for (int digit = 0; digit < numOfDigits; digit++) {
            fscanf(file, "%d", &currentNum);
            storedLineArrays[row][digit] = currentNum;
        }
    }

    for (int arr = 0; arr < numOfRows; arr++) { /*todo: printing, remove later*/
        for (int i = 0; i < numOfDigits; i++) {
            printf("%d ", storedLineArrays[arr][i]);
        }
        printf("\n");
    }

    for (int arr = 0; arr < numOfRows; arr++) { /*todo: printing, remove later*/
        sortArray(storedLineArrays[arr], numOfDigits);
    }

    printf("\n\n");

    for (int arr = 0; arr < numOfRows; arr++) { /*todo: printing, remove later*/
        for (int i = 0; i < numOfDigits; i++) {
            printf("%d ", storedLineArrays[arr][i]);
        }
        printf("\n");
    }

    fclose(file);
    return true;
}

int main(int argc, char** argv) {

    readFile(argv[1]);
    int doubleArray[2][4] = {{1, 2, 3, 4}, {4, 3, 2, 1}};



    return 0;
}
