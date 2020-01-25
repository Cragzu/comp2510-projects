// Created by Chloe Glave (A01166947) on 1/21/2020.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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
    int wordCount = 0;
    paragraph = moveToBeginningOfNextToken(paragraph);
    int currentWordSize = getCurrentTokenSize(paragraph);

    while(*paragraph) {

        for (int i = 0; i < currentWordSize; i++) { // place characters in initial word array
            tokens[wordCount][i] = *paragraph;

            paragraph++;
        }

        tokens[wordCount][currentWordSize] = *"\0"; // to ensure strlen works properly
        wordCount++;
        paragraph = moveToBeginningOfNextToken(paragraph);
        currentWordSize = getCurrentTokenSize(paragraph);
    }
    return wordCount + 1; // number of words in the tokens array
}

/*Given the array of tokens (words), number of words that we have processed so far,
 * total number of words (size of the string array) and line length (from the formatAndPrintParagraph function):
 * It returns the number of words that needs to be printed on the next line.*/
int getNumberOfWordsForNextLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH],
        int numberOfWordsProcessedSoFar, int totalNumberOfWords, int lineLength) {

    int subtotal = 0; // total number of chars so far
    int wordsForNextLine = 0;
    int currentWordLength;

    do {
        currentWordLength = strlen(tokens[numberOfWordsProcessedSoFar + wordsForNextLine]);

        if (subtotal + currentWordLength + (wordsForNextLine - 1) > lineLength) {
            break;
        }

        subtotal += currentWordLength;
            wordsForNextLine++;

    } while (wordsForNextLine < totalNumberOfWords);

    return wordsForNextLine;
}

/*This function simply prints a string followed by some number of spaces (no new line).*/
void printWordAndSpaces(char word[MAX_WORD_LENGTH], int numberOfSpaces) {
    while (*word) {
        printf("%c", *word);
        word++;
    }
    for (int spaceCounter = 0; spaceCounter < numberOfSpaces; spaceCounter++) {
        printf(" ");
    }
}

/*Given the tokens/words, number of words printed so far, number of words that needs to be printed on the next line
 * and line length, this function basically prints one line of the output.*/
void formatAndPrintCurrentLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int numberOfWordsProcessedSoFar,
        int numberOfWordsOnNextLine, int lineLength) {

    int subtotal = 0;
    for (int i = numberOfWordsProcessedSoFar; i < numberOfWordsOnNextLine; i++) {
        subtotal += strlen(tokens[i]);
    }

    int numOfSpaces = lineLength - subtotal;

    int evenlyDividedSpaces = numOfSpaces / (numberOfWordsOnNextLine - 1); // amount of spaces to go after each word

    int remainderSpaces = numOfSpaces % (numberOfWordsOnNextLine - 1);

    int spacesForCurrentWord;

    while (numberOfWordsProcessedSoFar != numberOfWordsOnNextLine) {
        spacesForCurrentWord = evenlyDividedSpaces;
        if (remainderSpaces > 0) {
            spacesForCurrentWord++;
            remainderSpaces--;
        }
        printWordAndSpaces(tokens[numberOfWordsProcessedSoFar], spacesForCurrentWord);
        numberOfWordsProcessedSoFar++;
    }
}

/*This function formats words in a string array (tokens) on lines of length lineLength.*/
void formatAndPrintWords(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int totalNumberOfWords, int lineLength) {
    int numberOfWordsProcessedSoFar = 0;

    while (numberOfWordsProcessedSoFar <= totalNumberOfWords) {
        int wordsForNextLine = getNumberOfWordsForNextLine(tokens, numberOfWordsProcessedSoFar,
                totalNumberOfWords, lineLength);
        formatAndPrintCurrentLine(tokens, numberOfWordsProcessedSoFar, wordsForNextLine, lineLength);

        numberOfWordsProcessedSoFar += wordsForNextLine;

        printf("\n");
    }
}

/**
 * Gets the input and prints the paragraph using helper functions.
 *
 * @param paragraph the sentence to be formatted.
 * @param lineLength the number of characters per line.
 * @return program code (0) to indicate successful execution.
 */
int formatAndPrintParagraph(char * paragraph, int lineLength) {
    // linelength = 25
    char * beginningOfFirstToken = moveToBeginningOfNextToken(paragraph);

    char array[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
    int numOfWordsInArray = tokenize(beginningOfFirstToken, array);

    int wordsForNextLine = getNumberOfWordsForNextLine(array, 0,
            numOfWordsInArray, lineLength);
    printf("Words for next line: %d\n", wordsForNextLine);

    printf("Final formatted paragraph:\n");
    formatAndPrintWords(array, numOfWordsInArray, lineLength);

}
