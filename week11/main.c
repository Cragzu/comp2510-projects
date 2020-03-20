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

void push(Link *head, int newData) {
    Link newHead = createNodeWithNextNode(newData, *head);
    *head = newHead;
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
    }
    Link currentTail = getTail(*head);
    currentTail->next = newTail;
}

int main() {
    Link node = createNode(10); // tail
    Link node2 = createNodeWithNextNode(20, node);
    Link node3 = createNodeWithNextNode(4, node2); // initial head

    printLinkedList(node3); // 4 -> 20 -> 10
    printf("length = %d\n", getLinkedListLengthRecursively(node3)); // 3

    printf("\nPushing new head...\n");
    push(&node3, 5);
    printLinkedList(node3); // 5 -> 4 -> 20 -> 10
    printf("length = %d\n", getLinkedListLengthRecursively(node3)); // 4

    printf("Tail data = %d\n", getTail(node3)->data); // 10

    printf("\nAdding new tail...\n");
    addLast(&node3, 89);
    printLinkedList(node3); // 5 -> 4 -> 20 -> 10

    return 0;
}
