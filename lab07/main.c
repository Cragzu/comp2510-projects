#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_ARRAY_SIZE 2 // changed to test for realloc
#define MAX_NAME_SIZE 32
#define GPA_CUTOFF 3.9

struct Student {
    char *name;
    double gpa;
};

void swap(struct Student *p, struct Student *q) {
    struct Student temp = *p;
    *p = *q;
    *q = temp;
}

void sortArrayByGPA(struct Student *array, int arraySize) {
    bool isSorted = false;

    // bubble sort
    while (!isSorted) {
        isSorted = true;
        for (int i = 0; i < arraySize - 1; i++) { // logic error in bubble sort - needed to stop at 1 before last index
            if (array[i].gpa < array[i + 1].gpa) {
                isSorted = false;
                swap(&array[i], &array[i + 1]);
            }
        }
    }
}

struct Student *resizeArrayIfNeeded(struct Student *array, int usedLength, int *arraySize) {
    if (usedLength <= *arraySize) {
        return array;
    }
    printf("Oops, need to resize!\n");
    *arraySize *= 2;

    // error with sizeof - should just be struct Student instead of using double and adding the character offset
    struct Student* data = (struct Student *) realloc(array, *arraySize * (sizeof(struct Student)));

    if (data == NULL) {
        perror("resizing error message");
        exit(1);
    }
    return data;
}

// changed this function to return a struct Student* (array of student structs) to be reassigned in main
struct Student* readFilePopulateStructArray(char *fileName, struct Student *studentInfo, int size, int *numOfElements) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Could not open file for reading.");
        return NULL;
    }

    while (!feof(file)) {
        // scan line of file for name and GPA
        char readName[MAX_NAME_SIZE];
        double readGPA;
        fscanf(file, "%s %lf", readName, &readGPA);

        // assign to struct
        char *duplicatedName = strdup(readName);

        // add to number of elements and check if array needs to be resized
        (*numOfElements)++;
        studentInfo = resizeArrayIfNeeded(studentInfo, *numOfElements, &size);

        // create struct and assign to array index
        struct Student newStudent = {duplicatedName, readGPA};
        studentInfo[*numOfElements - 1] = newStudent;
    }

    fclose(file);
    return studentInfo;
}

int main(int argc, char** argv) {
    int size = INITIAL_ARRAY_SIZE;
    int numOfElements = 0;

    // initialize array of structs
    struct Student* studentData = (struct Student *) malloc(size * (sizeof(struct Student)));

    if (studentData == NULL) {
        perror("main error message");
        exit(1);
    }

    // needed to reassign studentData to the return value instead of just calling the function
    studentData = readFilePopulateStructArray(argv[1], studentData, size, &numOfElements);
    sortArrayByGPA(studentData, numOfElements);

    // print all students with GPA above the cutoff in descending order
    for (int i = 0; i < numOfElements; i++) {
        if (studentData[i].gpa > GPA_CUTOFF) {
            printf("%s - GPA %.3f\n", studentData[i].name, studentData[i].gpa);
        }
    }

    // free memory at end of program
    free(studentData);

    return 0;
}
