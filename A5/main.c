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

    for (int i = 0; i < 4; i++) {
        printf("%d ", array[i]);
    }

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

    printf("\n");

    for (int i = 0; i < 4; i++) {
        printf("%d ", array[i]);
    }

}

int main() {
    int arr[MAX_NUMBER_OF_ELEMENTS_ON_EACH_LINE] = {4, 3, 2, 1};
    sortArray(arr);

    return 0;
}
