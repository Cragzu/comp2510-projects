#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

void printLinkedList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main() {
    struct Node node = {10, NULL};
    struct Node node2 = {20, &node};
    struct Node node3 = {4, &node2};
    // 4 -> 20 -> 10

    printLinkedList(&node3);
    return 0;
}
