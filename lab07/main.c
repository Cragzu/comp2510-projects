#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define INITIAL_ARRAY_SIZE 16
#define MAX_NAME_SIZE 32

struct Student {
    char *name;
    double gpa;
};

bool readFile(char *fileName) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Could not open file for reading.");
        return false;
    }

    char readName[MAX_NAME_SIZE];
    double readGPA;
    fscanf(file, "%s %lf", readName, &readGPA);

    struct Student studentInfo = {readName, readGPA};

    printf("Name: %s", studentInfo.name);
    printf("\nGPA: %lf", studentInfo.gpa);

    fclose(file);
    return true;
}

int main(int argc, char** argv) {
    struct Student* studentData = (struct Student *) malloc(INITIAL_ARRAY_SIZE * sizeof(struct Student));

    readFile(argv[1]);

//    struct Student chloe = {"Chloe", 4.0};
//    struct Student clint = {"Clint", 5.0};
//    printf("%s, %f\n", chloe.name, chloe.gpa);
//    printf("%s, %f", clint.name, clint.gpa);

    return 0;
}
