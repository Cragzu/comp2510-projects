#include <stdio.h>
#include "A01166947_file_search.h"

/*
 * Write a program that takes two command line arguments.
 * The first one is the name of a file. The second one is a word.
 * Your program should search for the word in the file specified.
*/

int main(int argc, char** argv) {
    searchForWordInFile(argv[1], argv[2]);

    return 0;
}
