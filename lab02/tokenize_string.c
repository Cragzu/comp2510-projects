// Created by Chloe Glave (A01166947) on 1/17/2020.

#include <stdio.h>
#include <string.h>
#include "tokenize_string.h"

void printTokens(char *inputString) {
    /* iterate through the string
     * separate string into words
     * when we encounter a space, the word is finished
     * account for more than one space
     */

    while(*inputString == ' ') { // exception for leading whitespace
        inputString++;
    }

    while(*inputString) { // continue looping while there are characters in the string
        printf("%c", *inputString);

        if(*inputString == ' ') { // check for space
            while(*inputString == ' ') { // account for multiple spaces in a row
                *inputString++;
            }
            printf("\n"); // start a newline when a space is encountered
        }

        else { // continue as usual
            *inputString++;
        }
    }
}
