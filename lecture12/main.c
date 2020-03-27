#include <stdio.h>
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


int main() {
 /* Diagram of the tree...
           5
          / \
        /     \
       3       8
      /\       /\
     /  \     /  \
    1    4   6    9
*/

    // function that takes the root of a tree and prints info

    // bottom "leaves" have no children
    TreeNode node_1 = createTreeNode(1);
    TreeNode node_4 = createTreeNode(4);
    TreeNode node_6 = createTreeNode(6);
    TreeNode node_9 = createTreeNode(9);

    // middle of the tree
    TreeNode node_3 = createTreeNodeWithChildren(3, node_1, node_4);
    TreeNode node_8 = createTreeNodeWithChildren(8, node_6, node_9);

    // root
    TreeNode root = createTreeNodeWithChildren(5, node_3, node_8);

    return 0;
}
