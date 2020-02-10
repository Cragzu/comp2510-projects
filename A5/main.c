#include <stdio.h>

#define MAX_NUMBER_OF_LINES 20
#define MAX_NUMBER_OF_ELEMENTS_ON_EACH_LINE 50
#define MAX_NUMBER 100

void swap(int **p, int **q) {
    int *temp = *p;
    *p = *q;
    *q = temp;
}

void sortArray(int array[MAX_NUMBER_OF_ELEMENTS_ON_EACH_LINE]) {

    for (int i = 0; i < MAX_NUMBER_OF_ELEMENTS_ON_EACH_LINE; i++) {
        printf("%d ", array[i]);
    }

}

int main() {
    int arr[MAX_NUMBER_OF_ELEMENTS_ON_EACH_LINE] = {1, 2, 3, 4};
    sortArray(arr);

    int firstNumber = 1;
    int secondNumber = 2;
    int *firstPointer = &firstNumber;
    int *secondPointer = &secondNumber;
    swap(&firstPointer, &secondPointer);
    printf("\n*firstPointer = %d, *secondPointer = %d\n", *firstPointer, *secondPointer);
    return 0;
}
