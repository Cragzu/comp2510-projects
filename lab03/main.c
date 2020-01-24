#include <stdio.h>

void recursivePrintSubsets(int newStart, int original) {
    if (newStart == original) {
        printf("[ ]\n");
    }

    int stop = newStart;
    while (stop <= original) {
        printf("[ ");
        for (int i = newStart; i <= stop; i++) {
            printf("%d ", i);
        }
        printf("]\n");
        stop++;
    }
    if (newStart == 1) {
        return;
    } else {
      return recursivePrintSubsets(newStart - 1, original);
    }
}

/*Given an int between 0 and 15, print all array subsets leading up to that number.*/
void printAllSubsets(int number) {
    recursivePrintSubsets(number, number);
}

int main() {
    printAllSubsets(5);
    return 0;
}
