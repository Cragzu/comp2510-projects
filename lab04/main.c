#include <stdio.h>
#include "A01166947_file_copy.h"

/*
 * Write a C program that makes a copy of a file. The source (existing file) and the destination are given as command arguments:
 *
 * filecopy path_to_existing_file path_to_new_file
 *
 * get command args, store as strings
 * copy all text in first file
 * write to second file
 * handle errors
 *
 */

int main(int argc, char** argv) {

    if (argc < 2) { // error check for command-line args not given
        printf("Error: two filenames must be given on the command line.");
        return 1;
    }

    fileCopy(argv[1], argv[2]);

    return 0;
}
