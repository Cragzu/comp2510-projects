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

int main() {
    // 4 -> 20 -> 10
    Link node = createNode(10);
    Link node2 = createNode(20);
    Link node3 = createNode(4);

    node3->next = node2;
    node2->next = node;

    printLinkedList(node3);
    return 0;
}
