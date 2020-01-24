// Created by Chloe Glave (A01166947) on 1/21/2020.

#include <stdio.h>
#include <stdbool.h>
#include "justify_string.h"

#define MAX_WORD_LENGTH 20
#define MAX_NUMBER_OF_WORDS 100
const char SPACE_CHARACTER = ' ';

/*Takes a string and moves the pointer to the first non-blank character
* (or end of the string if there is no non-blank character).*/
char *moveToBeginningOfNextToken(char *inputString) {
    while(*inputString == SPACE_CHARACTER) { // move pointer forward as long as space is encountered
        inputString++;
    }
    return inputString;
}

/*given a string with no leading spaces, returns the size of the first word.
* For example, if the string is “Hello world”, it should return 5.*/
int getCurrentTokenSize(char *inputString) {
    int tokenSize = 0;
    while (*inputString) { // continue looping through the string
        if (*inputString == SPACE_CHARACTER) { // break once space is encountered
            break;
        }
        tokenSize++;
        inputString++;
    }
    return tokenSize;
}

/*given the paragraph, it breaks it down into words. Stores the words in the given tokens array of string.
 * For example, for paragraph = “Hi.   How is it going?    Thanks.”
 * This function would fill the tokens array to be like this:
 * tokens[0] = “Hi.”, tokens[1] = “How”, tokens[3] = “is” and so on.*/
int tokenize(char *paragraph, char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH]) {
    char *startOfCurrentToken = moveToBeginningOfNextToken(paragraph);
    while (*startOfCurrentToken) {
        printf("%c.", *startOfCurrentToken);
        startOfCurrentToken++;
    }
    for (int i = 0; i <= 3; i++) {
        printf("%s", tokens[i]);
    }

    return 0;
}


