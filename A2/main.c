#include <stdio.h>
#include "justify_string.h"
#define MAX_WORD_LENGTH 20
#define MAX_NUMBER_OF_WORDS 100

int main() {
    char originalString[MAX_NUMBER_OF_WORDS*MAX_WORD_LENGTH] = "Hi everyone. This is the 2nd assignment. "
                                                               "Please make sure you start early as this "
                                                               "is going to take some time!";

    printf("Final sentence looks like:\n");
    formatAndPrintParagraph(originalString, 25);

    return 0;
}
