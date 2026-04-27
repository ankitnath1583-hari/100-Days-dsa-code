









int dequeue() {
    if (rear == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    struct Node* temp;
    int value;

    if (rear->next == rear) {  // only one node
        temp = rear;
        value = temp->data;
        rear = NULL;
        free(temp);
    } else {
        temp = rear->next; // front node
        value = temp->data;
        rear->next = temp->next;
        free(temp);
    }

    return value;
}













