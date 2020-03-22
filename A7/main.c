#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int processID; // 0 represents a hole
    int base; // start index
    int limit; // size
    struct Node* next;
};

typedef struct Node* Link;

void printMemory(struct Node *head) {
    if (!head) {
        printf("\n");
        return;
    }
    int linkNumber = 1;
    Link current = head;
    while (current) {
        printf("Node %d: ", linkNumber);
        if (current->processID == 0) {
            printf("H (Hole)");
        }
        else {
            printf("P%d", current->processID);
        }
        printf(", Base = %d, Limit = %d\n", current->base, current->limit);

        current = current->next;
        linkNumber++;
    }
}

Link createNode(int processID, int base, int limit) {
    Link link = (Link) malloc(sizeof(struct Node));
    if (link == NULL) {
        perror("memory issues!");
        exit(1);
    }
    link->processID = processID;
    link->base = base;
    link->limit = limit;
    link->next = NULL;
    return link;
}

Link createNodeWithNextNode(int processID, int base, int limit, Link next) {
    Link link = createNode(processID, base, limit);
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
//
//int getLinkedListLengthRecursively(Link head) {
//    if (!head) {
//        return 0;
//    }
//    return 1 + getLinkedListLengthRecursively(head->next);
//}
//
//Link push(Link *head, int newData) {
//    Link newHead = createNodeWithNextNode(newData, *head);
//    *head = newHead;
//    return newHead;
//}
//
//Link getTail(Link head) {
//    if (!head) {
//        return NULL;
//    }
//    if (!head->next) {
//        return head;
//    }
//    return getTail(head->next);
//}
//
//void addLast(Link *head, int data) {
//    Link newTail = createNode(data); // need not have next node
//    if (!*head) {
//        *head = newTail;
//        return;
//    }
//    Link currentTail = getTail(*head);
//    currentTail->next = newTail;
//}
//
//int removeTail(Link *head) {
//    if (!*head) { // nothing in the list
//        perror("Empty list was passed to removeTail function!");
//        exit(1);
//    }
//    Link currentNode = *head;
//    if (!currentNode->next) { // only one node in the list
//        *head = NULL;
//        int data = currentNode->data;
//        free(currentNode);
//        return data;
//    }
//
//    while (currentNode->next->next) { // check two nodes ahead
//        currentNode = currentNode->next;
//    }
//    Link oldTail = currentNode->next;
//    int oldTailData = oldTail->data;
//    free(oldTail);
//    currentNode->next = NULL;
//    return oldTailData;
//}
//
//int pop(Link *head) {
//    if (!head) {
//        perror("Empty list passed to pop function!\n");
//        exit(1);
//    }
//
//    int data = (*head)->data;
//    Link oldHead = *head;
//    *head = (*head)->next;
//    free(oldHead);
//    return data;
//}
//
//// Lecture activity functions
//
//void addElementAfterPosition(Link head, int data, int position) {
//    // todo
//}
//
//int deleteNodeAtPosition(Link *head, int position) {
//    // todo
//}

int main() {
    // Test case: Mixed list, starts with procedure
    Link node7 = createNode(0, 26, 6);
    Link node6 = createNodeWithNextNode(3, 16, 10, node7);
    Link node5 = createNodeWithNextNode(0, 15, 1, node6);
    Link node4 = createNodeWithNextNode(0, 11, 4, node5);
    Link node3 = createNodeWithNextNode(0, 7, 4, node4);
    Link node2 = createNodeWithNextNode(2, 6, 1, node3);
    Link node1 = createNodeWithNextNode(1, 0, 6, node2);

    // printf("Length = %d\n", getLinkedListLength(node1));

    printMemory(node1);
    printf("\n");
//    node1 = compaction(node1);
//    printMemory(node1);
//
//    freeLinkedList(node1);
//    printf("-----\n");
//
//// Test case: Mixed list, starts with hole
//    node7 = createNode(0, 26, 6);
//    node6 = createNodeWithNextNode(3, 16, 10, node7);
//    node5 = createNodeWithNextNode(0, 15, 1, node6);
//    node4 = createNodeWithNextNode(0, 11, 4, node5);
//    node3 = createNodeWithNextNode(0, 7, 4, node4);
//    node2 = createNodeWithNextNode(2, 6, 1, node3);
//    node1 = createNodeWithNextNode(0, 0, 6, node2);
//
//    printMemory(node1);
//    printf("\n");
//    node1 = compaction(node1);
//    printMemory(node1);
//
//    freeLinkedList(node1);
//    printf("-----\n");
//
//// Test case: All-hole list
//    node7 = createNode(0, 26, 6);
//    node6 = createNodeWithNextNode(0, 16, 10, node7);
//    node5 = createNodeWithNextNode(0, 15, 1, node6);
//    node4 = createNodeWithNextNode(0, 11, 4, node5);
//    node3 = createNodeWithNextNode(0, 7, 4, node4);
//    node2 = createNodeWithNextNode(0, 6, 1, node3);
//    node1 = createNodeWithNextNode(0, 0, 6, node2);
//
//    printMemory(node1);
//    printf("\n");
//    node1 = compaction(node1);
//    printMemory(node1);
//
//    freeLinkedList(node1);
//    printf("-----\n");
//
//// Test case: All-procedure list
//    node7 = createNode(7, 26, 6);
//    node6 = createNodeWithNextNode(6, 16, 10, node7);
//    node5 = createNodeWithNextNode(5, 15, 1, node6);
//    node4 = createNodeWithNextNode(4, 11, 4, node5);
//    node3 = createNodeWithNextNode(3, 7, 4, node4);
//    node2 = createNodeWithNextNode(2, 6, 1, node3);
//    node1 = createNodeWithNextNode(1, 0, 6, node2);
//
//    printMemory(node1);
//    printf("\n");
//    node1 = compaction(node1);
//    printMemory(node1);
//
//    freeLinkedList(node1);

    return 0;
}
