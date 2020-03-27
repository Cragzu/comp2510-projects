#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node *TreeNode;

TreeNode createTreeNode(int data) {
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

TreeNode createTreeNodeWithChildren(int data, TreeNode left, TreeNode right) {
    TreeNode treeNode = createTreeNode(data);
    treeNode->left = left;
    treeNode->right = right;
    return treeNode;
}

void *findNthElement(void *array, int n, size_t sizeOfEachElementInBytes) {
    return (char *) array + (n - 1) * sizeOfEachElementInBytes;
}

// Generic swap function
void swap(void *first, void *second, size_t numberOfBytes) {
    char temp[numberOfBytes];
    memcpy(temp, first, numberOfBytes);
    memcpy(first, second, numberOfBytes);
    memcpy(second, temp, numberOfBytes);
}

// Pointer comparison of ints
bool intCompare(void *a, void *b) {
    int firstValue = *(int *) a;
    int secondValue = *(int *) b;
    return (firstValue > secondValue);
}

// Pointer comparison of doubles
bool doubleCompare(void *a, void *b) {
    double firstValue = *(double *) a;
    double secondValue = *(double *) b;
    return (firstValue >= secondValue);
}

// Pointer comparison of chars
bool charCompare(void *a, void *b) {
    char firstValue = *(char *) a;
    char secondValue = *(char *) b;
    return (firstValue > secondValue);
}

// Pointer comparison of strings
bool stringCompare(void *data1, void *data2) {
    return strcmp(data1, data2) >= 0;
}

void printString(void *data) {
    printf("%s", (char *)data);
}

void printDouble(void *data) {
    printf("%.2lf", *(double *)data);
}

void printNode(TreeNode node) {
    if (!node) {
        printf("NULL\n");
    }

    if (node->left && node->right) {
        printf("Node: %d, left = %d, right = %d\n", node->data, node->left->data, node->right->data);
        return;
    }
    if (node->left) {
        printf("Node: %d, left = %d, right = NULL\n", node->data, node->left->data);
        return;
    }
    if (node->right) {
        printf("Node: %d, left = NULL, right = %d\n", node->data, node->right->data);
        return;
    }

    printf("Node: %d, left = NULL, right = NULL\n", node->data);
}

void printInOrder(TreeNode root) {
    if (!root) {
        return;
    }

    // In-order traversal
    printInOrder(root->left);
    printNode(root);
    printInOrder(root->right);
}

int getTreeHeight(TreeNode root) {
    if (!root) {
        return 0;
    }

    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);

    int max = (leftHeight > rightHeight) ? leftHeight : rightHeight;
    return max + 1; // to account for the root
}

TreeNode findNodeWithData(TreeNode root, int targetData) {
    if (!root) {
        return NULL;
    }

    if (root->data == targetData) {
        return root;
    }

    if (root->data > targetData) {
        return findNodeWithData(root->left, targetData);
    }

    return findNodeWithData(root->right, targetData);
}

TreeNode insert(TreeNode root, int newData) {
    if (!root) {
        return createTreeNode(newData);
    }

    if (newData <= root->data) {
        root->left = insert(root->left, newData);
    } else {
        root->right = insert(root->right, newData);
    }

    return root;
}

//int main() {
//    /* Diagram of the tree...
//              5
//             / \
//           /     \
//          3       8
//         /\       /\
//        /  \     /  \
//       1    4   6    9
//   */
//
//    // instantiate tree, could also be done with insert function
//
//    // bottom "leaves" have no children
//    TreeNode node_1 = createTreeNode(1);
//    TreeNode node_4 = createTreeNode(4);
//    TreeNode node_6 = createTreeNode(6);
//    TreeNode node_9 = createTreeNode(9);
//
//    // middle of the tree
//    TreeNode node_3 = createTreeNodeWithChildren(3, node_1, node_4);
//    TreeNode node_8 = createTreeNodeWithChildren(8, node_6, node_9);
//
//    // root
//    TreeNode root = createTreeNodeWithChildren(5, node_3, node_8);
//
//    printPreOrder(root);
//    printf("Height = %d\n", getTreeHeight(root));
//
//    TreeNode foundNode = findNodeWithData(root, 4);
//    printNode(foundNode);
//
//    root = insert(root, 10);
//
//    printf("\nPre-order:\n");
//    printPreOrder(root);
//    printf("\nIn-order:\n");
//    printInOrder(root);
//    printf("\nPost-order:\n");
//    printPostOrder(root);
//
//    return 0;
//}


// Bubble sorts array of any data type
void genericBubbleSort(void *array, size_t arrSize, size_t datatypeSize, bool (*compare)(void *, void *)) {
    while (true) {
        bool swapped = false;
        for (int i = 1; i < arrSize; i++) {
            void * currentElement = findNthElement(array, i, datatypeSize);
            void * nextElement = findNthElement(array, i + 1, datatypeSize);
            if (compare(currentElement, nextElement)) {
                swapped = true;
                swap(currentElement, nextElement, datatypeSize);
            }
        }
        if (!swapped) {
            return;
        }
    }
}

int main() {

    printf("%d", stringCompare("Chloe", "Seyed"));
    double test = 3.3;
    printDouble(&test);

//    // Test with ints
//    int intArray[5] = {10, 1, -2, 5, 7};
//    genericBubbleSort((void *) intArray, 5, sizeof(int), intCompare);
//    for (int i = 0; i < 5; i++) {
//        printf("A[%d] = %d\n", i, intArray[i]);
//    }
//
//    // Test with doubles
//    double doubleArray[5] = {10.0, 1.0, 2.0, 5.0, 7.0};
//    genericBubbleSort((void *) doubleArray, 5, sizeof(double), doubleCompare);
//    for (int i = 0; i < 5; i++) {
//        printf("A[%d] = %f\n", i, doubleArray[i]);
//    }
//
//    // Test with chars
//    char charArray[5] = {'d', 'a', 'c', 'b', 'e'};
//    genericBubbleSort((void *) charArray, 5, sizeof(char), charCompare);
//    for (int i = 0; i < 5; i++) {
//        printf("A[%d] = %c\n", i, charArray[i]);
//    }

    return 0;
}
