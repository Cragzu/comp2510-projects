#include <stdio.h>
#include <stdbool.h>

void integerSwap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void integerBubbleSort(int *array, size_t size) {
    while (true) {
        bool swapped = false;
        for (int i = 1; i < size; i++) {
            if (array[i - 1] > array[i]) {
                swapped = true;
                integerSwap(&array[i - 1], &array[i]);
            }
        }
        if (!swapped) {
            return;
        }
    }
}

int main() {
    int array[5] = {10, 1, -2, 5, 7};
    integerBubbleSort(array, 5);
    for (int i = 0; i < 5; i++) {
        printf("A[%d] = %d\n", i, array[i]);
    }
    return 0;
}

