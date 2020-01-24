// Created by Chloe Glave (A01166947) on 1/21/2020.

#ifndef A2_JUSTIFY_STRING_H
#define A2_JUSTIFY_STRING_H
#define MAX_WORD_LENGTH 20
#define MAX_NUMBER_OF_WORDS 100
char *moveToBeginningOfNextToken(char *inputString);
int getCurrentTokenSize(char *inputString);
int tokenize(char *paragraph, char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH]);
#endif //A2_JUSTIFY_STRING_H
