#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    void *data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node *TreeNode;

TreeNode createTreeNode(void *data) {
    TreeNode treeNode = (TreeNode) malloc(sizeof(struct Node));
    if (treeNode == NULL) {
        perror("Memory issues!");
        exit(1);
    }
    treeNode->data = data;
    treeNode->left = NULL;
    treeNode->right = NULL;
    return treeNode;
}

// Pointer comparison of doubles
bool doubleCompare(void *a, void *b) {
    double firstValue = *(double *) a;
    double secondValue = *(double *) b;
    return (firstValue < secondValue);
}

void printDouble(void *data) {
    printf("%.2lf", *(double *)data);
}

// Pointer comparison of strings
bool stringCompare(void *data1, void *data2) {
    return strcmp(*(char **) data1, *(char **) data2) < 0;
}

void printString(void *data) {
    printf("%s", *(char **) data);
}

void printInOrder(TreeNode root, void (*print)(void *)) {
    if (!root) {
        return;
    }

    // In-order traversal
    printInOrder(root->left, print);

    print(root->data);
    printf("\n");

    printInOrder(root->right, print);
}

TreeNode insert(TreeNode root, void *newData, bool (*compare)(void *, void *)) {
    if (!root) {
        return createTreeNode(newData);
    }

    if (compare(newData, root->data)) {
        root->left = insert(root->left, newData, compare);
    } else {
        root->right = insert(root->right, newData, compare);
    }

    return root;
}

TreeNode createSortedTree(void *array, int arrSize, size_t datatypeSize, bool (*compare)(void *, void *)) {
    TreeNode root = NULL;

    for (int i = 0; i < arrSize; i++) {
        root = insert(root, (char *) array + (i * datatypeSize), compare);
    }
    return root;
}

int main() {
    // Test with doubles
    double doubleArray[5] = {10.0, 1.0, 2.0, 5.0, 7.0};

    TreeNode doubleRoot = createSortedTree((void *) doubleArray, 5, sizeof(double), doubleCompare);
    printInOrder(doubleRoot, printDouble);

    printf("\n");

    // Test with strings
    char *stringArray[5] = {"Seyed", "Jack", "Adam", "Michael", "Chloe"};

    TreeNode stringRoot = createSortedTree((void *) stringArray, 5, sizeof(char *), stringCompare);
    printInOrder(stringRoot, printString);

    return 0;
}
