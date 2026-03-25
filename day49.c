#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue Node for BFS
struct QNode {
    struct Node* treeNode;
    int hd;
};

// Create new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue implementation
struct QNode queue[100];
int front = 0, rear = 0;

void enqueue(struct Node* node, int hd) {
    queue[rear].treeNode = node;
    queue[rear].hd = hd;
    rear++;
}

struct QNode dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Function for vertical order traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    // Map using arrays (HD range -100 to 100)
    int map[200][100]; 
    int count[200] = {0};

    enqueue(root, 0);

    while (!isEmpty()) {
        struct QNode temp = dequeue();
        struct Node* curr = temp.treeNode;
        int hd = temp.hd + 100; // shift index to avoid negative

        map[hd][count[hd]++] = curr->data;

        if (curr->left)
            enqueue(curr->left, temp.hd - 1);
        if (curr->right)
            enqueue(curr->right, temp.hd + 1);
    }

    // Print result
    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* q[100];
    int front = 0, rear = 0;

    q[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = q[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}