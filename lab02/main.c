#include <stdio.h>
#include "tokenize_string.h"

int main() {
    char testSentence[50] = "      Hi there! How is it      going?  ";
    printTokens(testSentence);
    return 0;
}
