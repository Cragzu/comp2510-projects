#include <stdio.h>
#include <stdbool.h>
#include "A01166947_convert_binary_file.h"
#define MAX_COLUMNS 10

int main(int argc, char** argv) {
    char fileContent[MAX_COLUMNS];
    readFile(argv[1], fileContent);
    printf("%s", argv[1]);

    return 0;
}
