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

int main() {
    Link head = NULL;
    addLast(&head, 1);
    addLast(&head, 2);
    addLast(&head, 3);
    addLast(&head, 4);

    printf("Initial List\n");
    printLinkedList(head);

    printf("\nMaking a copy of the list...\n");
    Link copied = copyList(&head);
    printLinkedList(copied);

    printf("\nMaking a reversed copy of the list...\n");
    Link copiedReverse = copyListReverse(&head);
    printLinkedList(copiedReverse);

    return 0;
}
