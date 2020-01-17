#include <stdio.h>
#include <stdbool.h>

void primeNumbers() {
    /*Prints all prime numbers up to 10,000.*/
    printf("Prime numbers up to 10,000:\n");

    for(int counter = 2; counter <= 10000; counter++) { /*start with 2 as 0 and 1 are special cases*/
        bool isPrime = true;
        /*divide each number by everything up to half of itself*/
        for(int divisor = 2; divisor <= counter/2; divisor++) {
            if(counter%divisor == 0) {
                isPrime = false; /*the number is divisible by something; not prime*/
                break;
            }
        }
        if(isPrime) {
            printf("%d\n", counter);
        }
    }
}

void triangles(int size) {
    /*Given the size, prints a right triangle with increasing numbers.*/
    int currentNumber = 1;
    printf("A triangle of size %d:", size);

    for(int height = 0; height < size; height++) { /*number of lines in the triangle*/
        for(int lengthCounter = 0; lengthCounter < height; lengthCounter++) { /*number of ints in the line*/
            printf("%d ", currentNumber);
            currentNumber++;
        }
        printf("\n");

    }
}

void printArray(int elements[], int size) {
    printf("[");
    for(int i = 0; i < size; i++) {
        if(i == size-1) {
            printf("%d", elements[i]); /*don't add comma and space for last element*/
        }
        else {
            printf("%d, ", elements[i]);
        }

    }
    printf("]");
}

int findEvenOccurrences(int elements[], int size) {
    for(int i = 0; i < size; i++) {
        int count = 1;
        for(int j = i; j < size; j++) {
            if(elements[j] == elements[i]) {
                count++;
            }
        }
        if(count % 2 == 0) {
            return elements[i];
        }
    }
}

int main() {
//    primeNumbers();
//    triangles(20);

//    int printedArr[] = {1, 2, 3};
//    printArray(printedArr, 3);

    int countedArr[] = {1, 1, 2, 3, 4, 4, 4};
    printf("%d", findEvenOccurrences(countedArr, 7));
    return 0;
}
