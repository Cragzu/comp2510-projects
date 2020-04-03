#include <stdio.h>
#include <stdlib.h>

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

void printSumTestCase(DLink firstList, DLink secondList, int caseNumber) {
    printf("\n\n------------ Test case %d ------------\n\n", caseNumber);

    printf("First list: ");
    printLinkedList(firstList);

    printf("Second list: ");
    printLinkedList(secondList);

    DLink sumList = sum(firstList, secondList);
    printf("Sum list: ");
    printLinkedList(sumList);
}

int main() {
    DLink head1 = NULL;
    push(&head1, 0);
    push(&head1, 1);

    DLink head2 = NULL;
    push(&head2, 3);

    printSumTestCase(head1, head2, 1);


    head1 = NULL;
    push(&head1, 1);
    push(&head1, 0);
    push(&head1, 9);

    head2 = NULL;
    push(&head2, 9);
    push(&head2, 9);

    printSumTestCase(head1, head2, 2);


    head1 = NULL;
    push(&head1, 3);
    push(&head1, 2);
    push(&head1, 1);

    head2 = NULL;
    push(&head2, 1);
    push(&head2, 2);
    push(&head2, 3);

    printSumTestCase(head1, head2, 3);


    head1 = NULL;
    push(&head1, 9);
    push(&head1, 9);
    push(&head1, 9);

    head2 = NULL;
    push(&head2, 7);
    push(&head2, 0);
    push(&head2, 0);
    push(&head2, 1);

    printSumTestCase(head1, head2, 4);

    return 0;
}
