#include <stdio.h>
#include "justify_string.h"

int main() {
    char testSentence[50] = "      Hello there! How is it      going?  ";
    moveToBeginningOfNextToken(testSentence);

    getCurrentTokenSize(testSentence);
    return 0;
}
