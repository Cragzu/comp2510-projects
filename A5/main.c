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

void sortArray(int array[MAX_NUMBER_OF_ELEMENTS_ON_EACH_LINE]) {
    bool isSorted = false;

    /*bubble sort*/
    while (!isSorted) {
        isSorted = true;
        for (int i = 0; i < 4-1; i++) {
            if (array[i] > array[i + 1]) {
                isSorted = false;
                swap((int **) &array[i], (int **) &array[i + 1]);
            }
        }
    }
}

bool checkIfTwoArraysAreAnagrams(int array1[MAX_NUMBER_OF_ELEMENTS_ON_EACH_LINE],
        int array2[MAX_NUMBER_OF_ELEMENTS_ON_EACH_LINE], int arraySize) {
    sortArray(array1);
    sortArray(array2);

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

    int numOfRows, numOfColumns;
    fscanf(file, "%d %d", &numOfRows, &numOfColumns);
    printf("Number of rows: %d\n", numOfRows);
    printf("Number of columns: %d\n", numOfColumns);

    fclose(file);
    return true;
}

int main(int argc, char** argv) {
    printf("%s\n", argv[1]);
    int arr1[MAX_NUMBER_OF_ELEMENTS_ON_EACH_LINE] = {4, 3, 2, 1};
    int arr2[MAX_NUMBER_OF_ELEMENTS_ON_EACH_LINE] = {1, 3, 3, 4};

    for (int i = 0; i < 4; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    sortArray(arr1);

    for (int i = 0; i < 4; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    checkIfTwoArraysAreAnagrams(arr1, arr2, 4);

    readFile(argv[1]);

    return 0;
}
