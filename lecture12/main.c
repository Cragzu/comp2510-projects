#include <stdio.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node *TreeNode;

int main() {
    printf("Hello, World!\n");
    return 0;
}
