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

// Pointer comparison of chars
bool charCompare(void *a, void *b) {
    char *firstValue = *(char **) a;
    char *secondValue = *(char **) b;
    return strcmp(firstValue, secondValue) > 0;
}

// Bubble sorts array of any data type
void genericBubbleSort(void **array, size_t arrSize, size_t datatypeSize, bool (*compare)(void *, void *)) {
    while (true) {
        bool swapped = false;
        for (int i = 1; i < arrSize; i++) {
            if (compare(&array[i - 1], &array[i])) {
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
    // Test with ints
    int intArray[5] = {10, 1, -2, 5, 7};
    genericBubbleSort((void *) intArray, 5, sizeof(int), intCompare);
    for (int i = 0; i < 5; i++) {
        printf("A[%d] = %d\n", i, intArray[i]);
    }

    // Test with chars
//    char charArray[5] = {'d', 'a', 'c', 'b', 'e'};
//    genericBubbleSort((void *) charArray, 5, sizeof(char), charCompare);
//    for (int i = 0; i < 5; i++) {
//        printf("A[%d] = %c\n", i, charArray[i]);
//    }

    return 0;
}
