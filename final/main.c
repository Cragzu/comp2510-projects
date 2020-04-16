#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

int getLinkedListLengthRecursively(Link head) {
    if (!head) {
        return 0;
    }
    return 1 + getLinkedListLengthRecursively(head->next);
}

Link push(Link *head, int newData) {
    Link newHead = createNodeWithNextNode(newData, *head);
    *head = newHead;
    return newHead;
}

Link getTail(Link head) {
    if (!head) {
        return NULL;
    }
    if (!head->next) {
        return head;
    }
    return getTail(head->next);
}

void addLast(Link *head, int data) {
    Link newTail = createNode(data); // need not have next node
    if (!*head) {
        *head = newTail;
        return;
    }
    Link currentTail = getTail(*head);
    currentTail->next = newTail;
}

int removeTail(Link *head) {
    if (!*head) { // nothing in the list
        perror("Empty list was passed to removeTail function!");
        exit(1);
    }
    Link currentNode = *head;
    if (!currentNode->next) { // only one node in the list
        *head = NULL;
        int data = currentNode->data;
        free(currentNode);
        return data;
    }

    while (currentNode->next->next) { // check two nodes ahead
        currentNode = currentNode->next;
    }
    Link oldTail = currentNode->next;
    int oldTailData = oldTail->data;
    free(oldTail);
    currentNode->next = NULL;
    return oldTailData;
}

int pop(Link *head) {
    if (!head) {
        perror("Empty list passed to pop function!\n");
        exit(1);
    }

    int data = (*head)->data;
    Link oldHead = *head;
    *head = (*head)->next;
    free(oldHead);
    return data;
}

Link copyList(Link *head) {
    if (!*head) {
        perror("Empty list passed to copyList!");
        exit(1);
    }

    Link originalCurrent = *head;
    Link copiedHead = createNode((*head)->data); // copy the head

    while (originalCurrent->next) {
        originalCurrent = originalCurrent->next; // increment through original list
        addLast(&copiedHead, originalCurrent->data); // push new node to end of copied list
    }
    return copiedHead;
}

Link copyListReverse(Link *head) {
    if (!*head) {
        perror("Empty list passed to copyListReverse!");
        exit(1);
    }

    Link originalCurrent = *head;
    Link copiedHead = createNode((*head)->data); // copy the head

    while (originalCurrent->next) {
        originalCurrent = originalCurrent->next; // increment through original list
        copiedHead = push(&copiedHead, originalCurrent->data); // push new node to front of copied list
    }
    return copiedHead;
}

Link concatenateListWithItself(Link *head) {
    if (!head) {
        return NULL;
    }
    Link copiedListHead = copyList(head);
    Link originalTail = getTail(*head);
    originalTail->next = copiedListHead;
    return *head;
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



    return 0;
}
