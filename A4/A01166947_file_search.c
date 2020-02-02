// Created by Chloe Glave (A01166947) on 2/2/2020.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "A01166947_file_search.h"

#define MAX_LINE_SIZE 1000

/*
 * find a word in a line - function
 * have another function that reads lines from file one at a time, calls the function
 * if word isn't found, repeat til end of file
 */

int findWordInLine(char* word, char* line) {
    char* beginningOfWord = word;
    int charCount = 1;
    int positionOfWord = -1; /*default value for word not existing in line*/

    while (*line) {
        charCount++;
        if (*line == *word) {

            word++;
            if (!*word) {
                positionOfWord = charCount - strlen(beginningOfWord); /*position of first char of word*/
                return positionOfWord;
            }

        } else {
            word = beginningOfWord;
        }

        line++;
    }
    return positionOfWord;
}

bool findWordInFile(char *fileName, char *content, char* word) {
    FILE *file = fopen(fileName, "r");
    int lineCount = 0;

    if (file == NULL) {
        printf("Could not open file for reading.");
        return false;
    }

    strcpy(content, "");
    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        lineCount++;
        strcat(content, line);
        int wordPosition = findWordInLine(word, line);
        if (wordPosition != -1) {
            printf("Word found!\nLine: %d\nPosition: %d", lineCount, wordPosition);
        }
    }
    printf("Could not find that word in that file.");

    fclose(file);
    return true;
}

void searchForWordInFile(char fileName[], char *wordToSearchFor) {
    char fileContent[MAX_LINE_SIZE];

    findWordInFile(fileName, fileContent, wordToSearchFor);
}
