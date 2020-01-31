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
 *
 */

int main(int argc, char** argv) {

    fileCopy(argv[1], argv[2]);

    return 0;
}
