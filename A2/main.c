#include <stdio.h>
#include "justify_string.h"
#define MAX_WORD_LENGTH 20
#define MAX_NUMBER_OF_WORDS 100

int main() {
    char originalString[50] = "      Hello there! How is it      going?  ";\

    char * beginningOfFirstToken = moveToBeginningOfNextToken(originalString);
    printf("pointer moved to beginning: \n%s\n", beginningOfFirstToken);

    int tokenSize = getCurrentTokenSize(beginningOfFirstToken);
    printf("size of token (first word): \n%d\n", tokenSize);

    printf("tokenize output:\n");
    char array[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];

    int numOfWordsInArray = tokenize(beginningOfFirstToken, array);

    int wordsForNextLine = getNumberOfWordsForNextLine(array, 0,
            numOfWordsInArray, 15);
    printf("number of words for line: %d\n", wordsForNextLine);


//    printWordAndSpaces(originalString, 4);



    return 0;
}
