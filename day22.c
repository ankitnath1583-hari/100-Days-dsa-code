#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* merged = NULL;
    struct Node* tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        struct Node* temp;

        if (head1->data < head2->data) {
            temp = createNode(head1->data);
            head1 = head1->next;
        } else {
            temp = createNode(head2->data);
            head2 = head2->next;
        }

        if (merged == NULL) {
            merged = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    while (head1 != NULL) {
        tail->next = createNode(head1->data);
        tail = tail->next;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        tail->next = createNode(head2->data);
        tail = tail->next;
        head2 = head2->next;
    }

    return merged;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, value;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }

 
    struct Node* mergedHead = mergeLists(head1, head2);
    printList(mergedHead);

    return 0;
}