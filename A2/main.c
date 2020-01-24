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

//    char array[MAX_WORD_LENGTH][MAX_NUMBER_OF_WORDS];
//    tokenize(beginningOfFirstToken, array);

    return 0;
}
