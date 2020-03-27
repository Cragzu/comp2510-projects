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
 
    // instantiate tree, could also be done with insert function
    
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

    printPreOrder(root);
    printf("Height = %d\n", getTreeHeight(root));

    TreeNode foundNode = findNodeWithData(root, 4);
    printNode(foundNode);

    root = insert(root, 10);

    printf("\nPre-order:\n");
    printPreOrder(root);
    printf("\nIn-order:\n");
    printInOrder(root);
    printf("\nPost-order:\n");
    printPostOrder(root);

    return 0;
}
