// Created by Chloe Glave (A01166947) on 1/17/2020.

#include <stdio.h>
#include <string.h>
#include "tokenize_string.h"

void printTokens(char *inputString) {
    /*Given a string, print it in "tokenized" form (one word on each line).*/
    const SPACE_CHARACTER = ' ';

    while(*inputString == SPACE_CHARACTER) { // exception for leading whitespace
        inputString++;
    }

    while(*inputString) { // continue looping while there are characters in the string
        printf("%c", *inputString);

        if(*inputString == SPACE_CHARACTER) { // check for space
            while(*inputString == SPACE_CHARACTER) { // account for multiple spaces in a row
                *inputString++;
            }
            printf("\n"); // start a newline when a space is encountered
        }

        else { // continue as usual
            *inputString++;
        }
    }
}
