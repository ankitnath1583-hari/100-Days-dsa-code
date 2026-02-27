#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* createNode(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct node** head, int x) {
    struct node* newNode = createNode(x);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}
int getLength(struct node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
struct node* findIntersection(struct node* head1, struct node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);
    if (len1 > len2) {
        while (diff--)
            head1 = head1->next;
    } else {
        while (diff--)
            head2 = head2->next;
    }
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)   
            return head1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m, i, x;

    struct node* head1 = NULL;
    struct node* head2 = NULL;

    // First list
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&head1, x);
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        insertEnd(&head2, x);
    }

    struct node* temp1 = head1;
    for (i = 1; i < 3 && temp1 != NULL; i++)
        temp1 = temp1->next;

    if (temp1 != NULL) {
        struct node* temp2 = head2;
        while (temp2->next != NULL)
            temp2 = temp2->next;

        temp2->next = temp1;
    }
    struct node* result = findIntersection(head1, head2);

    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}