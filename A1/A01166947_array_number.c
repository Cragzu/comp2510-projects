// Created by Chloe Glave (A01166947) on 1/13/2020.
#include "A01166947_array_number.h"

int getNumbersWithDigits(int digits[], int numberOfDigits) {
    /*Concatenate an array of ints into the single int it represents (by putting the numbers together in order).*/

    int unitFactor = 1; /*the number to multiply by*/
    int finalNum = 0;
    for(int index = numberOfDigits - 1; index >= 0; index--) { /*start with the smallest value*/
        finalNum += digits[index]*unitFactor;
        unitFactor *= 10; /*move to the next digit up*/
    }
    return finalNum;
}
