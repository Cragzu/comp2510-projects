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

DLink createLinkedListFromNumber(int num) { // needed?
    while (num > 0) {
        int digit = num % 10;
        printf("%d\n", digit);
        num /= 10;
    }
    return NULL;
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

    DLink sumList = NULL;
    DLink firstTail = getTail(firstNumber);
    DLink secondTail = getTail(secondNumber);

    bool isFirstFinished = false;
    bool isSecondFinished = false;

    while (!isFirstFinished || !isSecondFinished) {

        if (!isFirstFinished && !isSecondFinished) {
            push(&sumList, (firstTail->data + secondTail->data));
        } else if (!isFirstFinished) {
            push(&sumList, firstTail->data);
        } else {
            push(&sumList, secondTail->data);
        }

        if (!firstTail->prev) {
            isFirstFinished = true;
        } else {
            firstTail = firstTail->prev;
        }

        if (!secondTail->prev) {
            isSecondFinished = true;
        } else {
            secondTail = secondTail->prev;
        }
    }

    return sumList;
}


int main() {
    DLink head1 = NULL;
    push(&head1, 0);
    push(&head1, 1);

    DLink head2 = NULL;
    push(&head2, 3);

    printf("\nFirst list: ");
    printLinkedList(head1);

    printf("\nSecond list: ");
    printLinkedList(head2);

    DLink sumList = sum(head1, head2);
    printf("\nSum list: ");
    printLinkedList(sumList);


}
