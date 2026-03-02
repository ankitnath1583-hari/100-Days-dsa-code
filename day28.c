#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *last = NULL;

    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);

        temp = createNode(c, e);

        if (head == NULL) {
            head = temp;
        } else {
            last->next = temp;
        }
        last = temp;
    }

    // Printing polynomial
    temp = head;
    while (temp != NULL) {
        if (temp->exp == 0)
            printf("%d", temp->coeff);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}