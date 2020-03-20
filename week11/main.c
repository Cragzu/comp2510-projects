#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node* Link;

void printLinkedList(struct Node *head) {
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
    Link link = (Link) malloc(sizeof(struct Node));
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

// Lecture activity functions

void addElementAfterPosition(Link head, int data, int position) {
    // todo
}

int deleteNodeAtPosition(Link *head, int position) {
    // todo
}

// Lab functions

Link copyList(Link *head) {
    Link originalCurrent = *head;
    Link copiedHead = createNode((*head)->data); // copy the head

    while (originalCurrent->next) {
        originalCurrent = originalCurrent->next; // increment through original list
        addLast(&copiedHead, originalCurrent->data); // push new node to end of copied list
    }
    return copiedHead;
}

Link copyListReverse(Link *head) {
    Link originalCurrent = *head;
    Link copiedHead = createNode((*head)->data); // copy the head

    while (originalCurrent->next) {
        originalCurrent = originalCurrent->next; // increment through original list
        copiedHead = push(&copiedHead, originalCurrent->data); // push new node to front of copied list
    }
    return copiedHead;
}

int main() {
    Link head = NULL;
    addLast(&head, 1);
    addLast(&head, 2);
    addLast(&head, 3);
    addLast(&head, 4);

    printf("Initial List\n");
    printLinkedList(head); // 4 -> 20 -> 10
    printf("length = %d\n", getLinkedListLengthRecursively(head)); // 3

    printf("\nPushing new head...\n");
    printf("New head data = %d\n", push(&head, 5)->data);
    printLinkedList(head); // 5 -> 4 -> 20 -> 10
    printf("length = %d\n", getLinkedListLengthRecursively(head)); // 4

    printf("\nTail data = %d\n", getTail(head)->data); // 10

    printf("\nAdding new tail...\n");
    addLast(&head, 89);
    printLinkedList(head); // 5 -> 4 -> 20 -> 10 -> 89

    printf("\nRemoving the tail...\n");
    printf("Old tail's data = %d\n", removeTail(&head));
    printLinkedList(head); // 5 -> 4 -> 20 -> 10

    printf("\nRemoving the head...\n");
    printf("Old head's data = %d\n", pop(&head));
    printLinkedList(head); // 4 -> 20 -> 10

    printf("\nMaking a copy of the list...\n");
    Link copied = copyList(&head);
    printLinkedList(copied);

    printf("\nMaking a reversed copy of the list...\n");
    Link copiedReverse = copyListReverse(&head);
    printLinkedList(copiedReverse);

    return 0;
}
