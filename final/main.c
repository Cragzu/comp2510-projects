#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//<editor-fold desc="Linked List Functions">

struct LLNode {
    int data;
    struct LLNode *next;
};

typedef struct LLNode *Link;

void printLinkedList(struct LLNode *head) {
    if (!head) {
        printf("\n");
        return;
    }
    printf("%d", head->data);
    if (head->next) {
        printf(" -> ");
    }

    printLinkedList(head->next);
}

Link createNode(int data) {
    Link link = (Link) malloc(sizeof(struct LLNode));
    if (link == NULL) {
        perror("memory issues!");
        exit(1);
    }
    link->data = data;
    link->next = NULL;
    return link;
}

Link createNodeWithNextNode(int data, Link next) {
    Link link = createNode(data);
    link->next = next;
    return link;
}

int getLinkedListLength(Link head) {
    int length = 0;
    Link current = head;
    while (current) {
        current = current->next;
        length++;
    }
    return length;
}

void split(Link firstHalfHead, Link *secondHalfHead) {
    if (!firstHalfHead || firstHalfHead->next == NULL) {
        return;
    }

    int listMidpoint = ceil(getLinkedListLength(firstHalfHead) / 2.0); // round up if odd number of elements

    int currentPosition = 1;
    Link currentLink = firstHalfHead;
    while (currentLink && currentPosition < listMidpoint) { // traverse to midpoint
        currentLink = currentLink->next;
        currentPosition++;
    }

    *secondHalfHead = currentLink->next; // split lists, assign second half to given address
    currentLink->next = NULL; // sever connection
}

//</editor-fold>

//<editor-fold desc="Binary Tree Functions">

struct TNode {
    int data;
    struct TNode *left;
    struct TNode *right;
};

typedef struct TNode *TreeNode;

TreeNode createTreeNode(int data) {
    TreeNode treeNode = (TreeNode) malloc(sizeof(struct TNode));
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

void printInOrder(TreeNode root) {
    if (!root) {
        return;
    }

    // In-order traversal
    printInOrder(root->left);
    printNode(root);
    printInOrder(root->right);
}

void duplicateNodeToLeft(TreeNode root) { // todo: double check it works
    if (!root) {
        return;
    }

    duplicateNodeToLeft(root->left);
    duplicateNodeToLeft(root->right);

    TreeNode newNode = createTreeNode(root->data);
    if (root->left != NULL) {
        TreeNode temp = root->left;
        root->left = newNode;
        newNode->left = temp;
    } else {
        root->left = newNode;
    }
}
//</editor-fold>








int main() { // todo: test cases and remove unused functions

    printf("\n----------- Testing duplicateNodeToLeft function ------------\n\n");

    TreeNode node_20 = createTreeNode(20);
    TreeNode node_40 = createTreeNodeWithChildren(40, node_20, NULL);
    TreeNode node_30 = createTreeNodeWithChildren(30, NULL, node_40);

    printf("\nBefore:\n");
    printInOrder(node_30);

    duplicateNodeToLeft(node_30);

    printf("\nAfter:\n");
    printInOrder(node_30);


    printf("\n----------- Testing split function ------------\n\n");

    Link split_4 = createNode(4);
    Link split_3 = createNodeWithNextNode(3, split_4);
    Link split_2 = createNodeWithNextNode(2, split_3);
    Link split_1 = createNodeWithNextNode(1, split_2);

    Link splitSecondHalf = NULL; // Link to assign second half of list to, should be NULL or will be overwritten

    printf("\nBefore:\n");
    printLinkedList(split_1);

    split(split_1, &splitSecondHalf);

    printf("\nAfter:\n");
    printLinkedList(split_1);
    printLinkedList(splitSecondHalf);


//    printf("\n----------- Testing filter function ------------\n\n"); // todo

    printf("\n----------- Testing stringFun function ------------\n\n"); // todo

    char testString[] = "I * Seyed Javadi **";

//    printf("\n----------- Testing topStudents function ------------\n\n"); // todo

//    printf("\n----------- Testing printDigits function ------------\n\n"); // todo





    return 0;
}
