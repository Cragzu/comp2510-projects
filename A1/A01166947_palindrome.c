// Created by Chloe Glave (A01166947) on 1/13/2020.
#include "A01166947_palindrome.h"
#include <stdbool.h>

bool isPalindrome(int elements[], int size) {
    /*Determine whether a given array of ints is a palindrome; the same read forwards and backwards.*/

    int backwardsIndex = size - 1;  /*keep track of the end of array*/
    for(int index = 0; index < size/2; index++) {
        if(elements[index] != elements[backwardsIndex]) { /*check mirrored elements halfway through array*/
            return false;
        }
        --backwardsIndex; /*decrement through the array*/
    }
    return true; /*if the loop completes without returning false, array is a palindrome*/
}
