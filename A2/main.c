#include <stdio.h>
#include "justify_string.h"

int main() {
    char originalString[50] = "      Hello there! How is it      going?  ";\

    char * beginningOfFirstToken = moveToBeginningOfNextToken(originalString);
    printf("pointer moved to beginning: \n%s\n", beginningOfFirstToken);

    int tokenSize = getCurrentTokenSize(beginningOfFirstToken);
    printf("size of token (first word): \n%d", tokenSize);

    return 0;
}
