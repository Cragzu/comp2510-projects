// Created by Chloe Glave (A01166947) on 1/21/2020.

#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUMBER_OF_WORDS 100
const char SPACE_CHARACTER = ' ';

/**
 * Takes a string and moves the pointer to the first non-blank character
 * (or end of the string if there is no non-blank character).
 *
 * @param inputString the given string.
 * @return the pointer to the first non-blank char in the string.
 */
char *moveToBeginningOfNextToken(char *inputString) {
    while(*inputString == SPACE_CHARACTER) { // move pointer forward as long as space is encountered
        inputString++;
    }
    return inputString;
}

/**
 * Returns the size of the first word in a given string (with no leading spaces).
 *
 * @param inputString the given string.
 * @return the size of the first word in the string.
 */
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

/**
 * Populates the given array with individual words from the paragraph.
 *
 * @param paragraph the string to be broken up into words.
 * @param tokens the array to populate with words.
 * @return the total number of words placed in the array.
 */
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
    return wordCount; // number of words in the tokens array
}

/**
 * Calculates the number of words that need to be printed on the next line.
 *
 * @param tokens the 2d array containing the words.
 * @param numberOfWordsProcessedSoFar the number of words in the sentence that have already been printed.
 * @param totalNumberOfWords the total number of words in the array.
 * @param lineLength the given length each line should be.
 * @return the number of words to print on the next line.
 */
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

    } while (wordsForNextLine + numberOfWordsProcessedSoFar < totalNumberOfWords);

    return wordsForNextLine;
}

/**
 * Prints a string followed by some number of spaces (no new line).
 * @param word the string to be printed.
 * @param numberOfSpaces the number of spaces to print after the word.
 */
void printWordAndSpaces(char word[MAX_WORD_LENGTH], int numberOfSpaces) {
    while (*word) {
        printf("%c", *word);
        word++;
    }
    for (int spaceCounter = 0; spaceCounter < numberOfSpaces; spaceCounter++) {
        printf(" ");
    }
}

/**
 * Prints one line of properly formatted output.
 *
 * @param tokens the 2d array containing the words.
 * @param numberOfWordsProcessedSoFar the number of words in the sentence that have already been printed.
 * @param numberOfWordsOnNextLine the number of words to be printed in the current line.
 * @param lineLength the given length each line should be.
 */
void formatAndPrintCurrentLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int numberOfWordsProcessedSoFar,
        int numberOfWordsOnNextLine, int lineLength) {

    int subtotal = 0;
    for (int i = numberOfWordsProcessedSoFar; i < numberOfWordsProcessedSoFar + numberOfWordsOnNextLine; i++) {
        subtotal += strlen(tokens[i]);
    }

    int numOfSpaces = lineLength - subtotal;

    int evenlyDividedSpaces = numOfSpaces / (numberOfWordsOnNextLine - 1); // amount of spaces to go after each word

    int remainderSpaces = numOfSpaces % (numberOfWordsOnNextLine - 1);

    int spacesForCurrentWord;

    int wordsToGo = numberOfWordsProcessedSoFar + numberOfWordsOnNextLine;

    while (numberOfWordsProcessedSoFar != wordsToGo) {
        spacesForCurrentWord = evenlyDividedSpaces;
        if (remainderSpaces > 0) {
            spacesForCurrentWord++;
            remainderSpaces--;
        }
        printWordAndSpaces(tokens[numberOfWordsProcessedSoFar], spacesForCurrentWord);
        numberOfWordsProcessedSoFar++;
    }
}

/**
 * Formats words in a string array (tokens) on lines of length lineLength.
 *
 * @param tokens the 2d array containing the words.
 * @param totalNumberOfWords the total number of words in the array.
 * @param lineLength the given length each line should be.
 */
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
    char * beginningOfFirstToken = moveToBeginningOfNextToken(paragraph);

    char array[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
    int numOfWordsInArray = tokenize(beginningOfFirstToken, array);

    formatAndPrintWords(array, numOfWordsInArray, lineLength);
    return 0;
}
