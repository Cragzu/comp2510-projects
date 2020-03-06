#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Generic swap function
void swap(void *first, void *second, size_t numberOfBytes) {
    char temp[numberOfBytes];
    memcpy(temp, first, numberOfBytes);
    memcpy(first, second, numberOfBytes);
    memcpy(second, temp, numberOfBytes);
}

// Pointer comparison of ints
bool intCompare(void *a, void *b) {
    int firstValue = *(int *) a;
    int secondValue = *(int *) b;
    return (firstValue > secondValue);
}

void genericBubbleSort(int *array, size_t arrSize, size_t datatypeSize) {
    while (true) {
        bool swapped = false;
        for (int i = 1; i < arrSize; i++) {
            if (array[i - 1] > array[i]) {
                swapped = true;
                swap(&array[i - 1], &array[i], datatypeSize);
            }
        }
        if (!swapped) {
            return;
        }
    }
}

int main() {
    int array[5] = {10, 1, -2, 5, 7};
    genericBubbleSort(array, 5, sizeof(int));
    for (int i = 0; i < 5; i++) {
        printf("A[%d] = %d\n", i, array[i]);
    }
    return 0;
}
