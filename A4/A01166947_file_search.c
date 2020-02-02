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

void findWordInLine(char* word, char* line) {
    char* beginningOfWord = word;
    while (*line) {
        if (word == line) {
            word++;
            if (!word) {
                printf("Word found!");
                return;
            }
        } else {
            word = beginningOfWord;
        }
        line++;
    }
    return;
}

bool readLineOfFile(char *fileName, char content[MAX_LINE_SIZE], int lineNumber) {
    FILE *file = fopen(fileName, "r");
    int lineCount = 0;

    if (file == NULL) {
        printf("Could not open file for reading.");
    }

    strcpy(content, "");
    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        lineCount++;
        if (lineCount == lineNumber) {
            strcat(content, line);
            printf("in function: %s", line);
            return content;
        }
    }

    fclose(file);
    return true;
}

void searchForWordInFile(char fileName[], char *wordToSearchFor) {
    char fileContent[MAX_LINE_SIZE];

    readLineOfFile(fileName, fileContent, 2);



    printf("%s", fileContent);

    //readFile(fileName, fileContent, wordToSearchFor);

}
