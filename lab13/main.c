#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node* DLink; // doubly linked list

DLink createNode(int data, DLink next, DLink prev) {
    DLink link = (DLink) malloc(sizeof(struct Node));
    if (link == NULL) {
        perror("Memory issues!");
        exit(1);
    }

    link->data = data;
    link->next = next;
    link->prev = prev;
    return link;
}

void printLinkedList(DLink head) {
    if (!head) {
        printf("\n");
        return;
    }
    printf("%d", head->data);
    if (head->next) {
        printf("<->");
    }

    printLinkedList(head->next);
}

void push(DLink *head, int data) {
    DLink newHead = createNode(data, *head, NULL);
    if (*head) {
        (*head)->prev = newHead;
    }
    *head = newHead;
}

int pop(DLink *head) {
    if (!*head) {
        perror("Empty list passed to pop function!\n");
        exit(1);
    }

    int data = (*head)->data;
    DLink oldHead = *head;
    *head = (*head)->next;

    if (*head) {
        (*head)->prev = NULL;
    }
    free(oldHead);
    return data;
}

int removeNode(DLink *node) {
    if (!*node) {
        perror("Empty node passed to removeNode function!");
        exit(1);
    }

    if (!(*node)->prev) { // passed node is first in list
        return pop(node);
    }

    if (!(*node)->next) { // passed node is last in list
        (*node)->prev->next = NULL;
        int removedData = (*node)->data;
        free(*node);
        return removedData;
    }

    // passed node is in the middle of the list
    int removedData = (*node)->data;
    DLink prevNode = (*node)->prev;
    DLink nextNode = (*node)->next;
    free(*node);
    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    return removedData;

}


int main() {
    DLink head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printLinkedList(head);
    int data = removeNode(&(head->next));
    printf("Removed %d\n", data);
    printLinkedList(head);


}
