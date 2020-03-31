#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void printPreOrder(TreeNode root) {
    if (!root) {
        return;
    }

    // Pre-order traversal
    printNode(root);
    printPreOrder(root->left);
    printPreOrder(root->right);
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

void printPostOrder(TreeNode root) {
    if (!root) {
        return;
    }

    // Post-order traversal
    printPostOrder(root->left);
    printPostOrder(root->right);
    printNode(root);
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

bool equals(TreeNode firstRoot, TreeNode secondRoot) {
    if (!firstRoot && !secondRoot) { // both trees are empty, base case
        return true;
    }

    if (firstRoot && secondRoot) { // both trees are non-empty
        // call recursively on subtrees
        return (firstRoot->data == secondRoot->data)
        && equals(firstRoot->left, secondRoot->left)
        && equals(firstRoot->right, secondRoot->right);
    }

    return false; // one tree is empty
}

bool containsPathWithSum(TreeNode root, int sum) {
    if (!root) {
        return (sum == 0);
    }

    bool result = false;
    sum -= root->data; // subtract node data from sum, trying to get to 0

    if (sum == 0 && root->left == 0 && root->right == 0) { // base case, reached leaf node with path equal to sum
        return true;
    }

    // recurse down the tree
    if (root->left) {
        result = result || containsPathWithSum(root->left, sum);
    }
    if (root->right) {
        result = result || containsPathWithSum(root->right, sum);
    }
    return result;
}

void mirror(TreeNode root) {
    if (!root) {
        return;
    }

    // swap left and right subtrees
    TreeNode temp = root->left;
    root->left = root->right;
    root->right = temp;

    // recurse downwards
    mirror(root->left);
    mirror(root->right);
}

int main() {
    printf("\n----------- Testing equals function ------------\n\n");

    TreeNode testEqualsNull1 = NULL;
    TreeNode testEqualsNull2 = NULL;
    printf("Two null trees: %s\n", equals(testEqualsNull1, testEqualsNull2) ? "true" : "false"); // true


    TreeNode testEqualsSameData1 = createTreeNode(5);
    insert(testEqualsSameData1, 4);
    insert(testEqualsSameData1, 10);
    insert(testEqualsSameData1, -8);

    TreeNode testEqualsSameData2 = createTreeNode(5);
    insert(testEqualsSameData2, 4);
    insert(testEqualsSameData2, 10);
    insert(testEqualsSameData2, -8);

    printf("Two non-null equal trees: %s\n", equals(testEqualsSameData1, testEqualsSameData2)
    ? "true" : "false"); // true


    TreeNode testEqualsDifferentData = createTreeNode(12);
    insert(testEqualsDifferentData, 6);
    insert(testEqualsDifferentData, 1);
    insert(testEqualsDifferentData, -3);

    printf("Two non-null non-equal trees: %s\n", equals(testEqualsSameData1, testEqualsDifferentData)
    ? "true" : "false"); // false


    printf("\n----------- Testing containsPathWithSum function ------------\n\n");

    TreeNode testContains = createTreeNode(5);
    insert(testContains, 4);
    insert(testContains, 10);
    insert(testContains, -8);

    printf("Tree to check for sums:\n");
    printInOrder(testContains);
    printf("\n");


    printf("Tree contains a path adding up to 1?: %s\n", containsPathWithSum(testContains, 1)
    ? "true" : "false"); // true

    printf("Tree contains a path adding up to 15?: %s\n", containsPathWithSum(testContains, 15)
    ? "true" : "false"); // true

    printf("Tree contains a path adding up to 9?: %s\n", containsPathWithSum(testContains, 9)
    ? "true" : "false"); // false


    printf("\n----------- Testing mirror function ------------\n\n");


    TreeNode testMirrorNull = NULL;
    printf("Null tree before mirror (should print nothing):\n");
    printInOrder(testMirrorNull);
    mirror(testMirrorNull);
    printf("Null tree after mirror (should print nothing):\n");
    printInOrder(testMirrorNull);


    TreeNode testMirrorNotNull = createTreeNode(5);
    insert(testMirrorNotNull, 4);
    insert(testMirrorNotNull, 10);
    insert(testMirrorNotNull, -8);

    printf("\nNon-null tree before mirror:\n");
    printInOrder(testMirrorNotNull);
    mirror(testMirrorNotNull);
    printf("\nNon-null tree after mirror:\n");
    printInOrder(testMirrorNotNull);

    return 0;
}
