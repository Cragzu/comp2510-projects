#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

TreeNode findLowestCommonAncestorBST(TreeNode root, TreeNode first, TreeNode second) {
    if (!root || !first || !second) {
        return NULL;
    }

    if ((first->data < root->data) && (second->data < root->data)) { // both are less than root
        return findLowestCommonAncestorBST(root->left, first, second); // call again with root->left
    }

    if ((first->data > root->data) && (second->data > root->data)) { // both are greater than root
        return findLowestCommonAncestorBST(root->right, first, second); // call again with root->right
    }

    return root; // if one is greater and one is less than root, the LCA is the root
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

void duplicateNodeToLeft(TreeNode root) {
    if (!root) {
        return;
    }



}

int main() {

    printf("\n----------- Testing duplicateNodeToLeft function ------------\n\n");

    TreeNode node_20 = createTreeNode(20);
    TreeNode node_40 = createTreeNodeWithChildren(40, node_20, NULL);
    TreeNode node_30 = createTreeNodeWithChildren(30, NULL, node_40);

    printf("\nIn-order:\n");
    printInOrder(node_30);

    return 0;
}
