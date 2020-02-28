#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_ARRAY_SIZE 16
#define MAX_NAME_SIZE 32

struct Student {
    char *name;
    double gpa;
};

struct Student *resizeArrayIfNeeded(struct Student *array, int usedLength, int *arraySize) {
    if (usedLength <= *arraySize) {
        return array;
    }
    printf("Oops, need to resize!\n");
    *arraySize *= 2;

    struct Student* data = (struct Student *) realloc(array, *arraySize * (sizeof(double) + MAX_NAME_SIZE));

    if (data == NULL) {
        perror("resizing error message");
        exit(1);
    }
    return data;
}

bool readFile(char *fileName, struct Student *studentInfo, int size, int *numOfElements) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Could not open file for reading.");
        return false;
    }

    while (!feof(file)) {
        // scan line of file for name and GPA
        char readName[MAX_NAME_SIZE];
        double readGPA;
        fscanf(file, "%s %lf", readName, &readGPA);

        // assign to struct
        char *duplicatedName = strdup(readName);

        (*numOfElements)++;
        studentInfo = resizeArrayIfNeeded(studentInfo, *numOfElements, &size);

        struct Student newStudent = {duplicatedName, readGPA};
        *studentInfo = newStudent;

        // increment pointer in array of structs
        studentInfo++;
    }

    fclose(file);
    return true;
}

int main(int argc, char** argv) {
    int size = INITIAL_ARRAY_SIZE;
    int numOfElements = 0;

    // initialize array of structs
    struct Student* studentData = (struct Student *) malloc(size * (sizeof(double) + MAX_NAME_SIZE));

    if (studentData == NULL) {
        perror("main error message");
        exit(1);
    }

    readFile(argv[1], studentData, size, &numOfElements);

    for (int i = 0; i < numOfElements; i++) {
        printf("Name: %s\n", studentData[i].name);
        printf("GPA: %lf\n", studentData[i].gpa);
    }

    return 0;
}
