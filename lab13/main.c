#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node *DLink; // doubly linked list

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

DLink getTail(DLink head) {
    if (!head) {
        return NULL;
    }
    if (!head->next) {
        return head;
    }
    return getTail(head->next);
}

DLink sum(DLink firstNumber, DLink secondNumber) {
    if (!firstNumber || !secondNumber) {
        perror("Empty list passed to sum function!");
        exit(1);
    }

    DLink sumHead = NULL;

    int remainder = 0;
    int sum = 0;

    DLink firstTail = getTail(firstNumber);
    DLink secondTail = getTail(secondNumber);

    while (firstTail || secondTail) {
        int firstData = firstTail ? firstTail->data : 0;
        int secondData = secondTail ? secondTail->data : 0;

        sum = remainder + firstData + secondData;
        if (sum > 9) {
            remainder = 1;
            sum %= 10;
        } else {
            remainder = 0;
        }

        push(&sumHead, sum);

        if (firstTail) {
            firstTail = firstTail->prev;
        }
        if (secondTail) {
            secondTail = secondTail->prev;
        }
    }

    if (remainder == 1) {
        push(&sumHead, remainder);
    }

    return sumHead;

}


int main() {

//    DLink head1 = NULL;
//    push(&head1, 0);
//    push(&head1, 1);
//
//    DLink head2 = NULL;
//    push(&head2, 3);

    DLink head1 = NULL;
    push(&head1, 1);
    push(&head1, 0);
    push(&head1, 9);

    DLink head2 = NULL;
    push(&head2, 9);
    push(&head2, 9);

    printf("First list: ");
    printLinkedList(head1);

    printf("Second list: ");
    printLinkedList(head2);

    DLink sumList = sum(head1, head2);
    printf("Sum list: ");
    printLinkedList(sumList);

    return 0;
}
