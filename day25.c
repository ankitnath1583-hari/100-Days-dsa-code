#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node* create_node(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
void insert_end(struct node **head, int value) {
    struct node* new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
}

void traverse_forward(struct node *head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, value;
    struct node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert_end(&head, value);
    }

    traverse_forward(head);

    return 0;
}