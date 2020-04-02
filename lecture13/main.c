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


int main() {
    DLink node_1 = createNode(1, NULL, NULL);
    DLink node_2 = createNode(2, NULL, NULL);
    DLink node_3 = createNode(3, NULL, NULL);

    node_1->next = node_2;

    node_2->prev = node_1;
    node_2->next = node_3;

    node_3->prev = node_2;

    printLinkedList(node_1);
}
