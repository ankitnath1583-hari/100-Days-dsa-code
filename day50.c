#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct Queue {
    struct TreeNode** data;
    int front, rear, capacity;
};

// Queue implementation
struct Queue* createQueue(int cap) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->data = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * cap);
    q->front = q->rear = 0;
    q->capacity = cap;
    return q;
}

void resizeQueue(struct Queue* q) {
    int newCapacity = q->capacity * 2;
    q->data = (struct TreeNode**)realloc(q->data, sizeof(struct TreeNode*) * newCapacity);
    q->capacity = newCapacity;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->rear >= q->capacity) {
        resizeQueue(q);
    }
    q->data[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->data[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void freeQueue(struct Queue* q) {
    free(q->data);
    free(q);
}

// Build tree from level order input
struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) {
        return NULL;
    }
    
    struct Queue* q = createQueue(n);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = arr[0];
    root->left = NULL;
    root->right = NULL;
    enqueue(q, root);
    
    int i = 1;
    while (!isEmpty(q) && i < n) {
        struct TreeNode* current = dequeue(q);
        
        // Left child
        if (i < n && arr[i] != -1) {
            struct TreeNode* leftNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            leftNode->val = arr[i];
            leftNode->left = NULL;
            leftNode->right = NULL;
            current->left = leftNode;
            enqueue(q, leftNode);
        }
        i++;
        
        // Right child
        if (i < n && arr[i] != -1) {
            struct TreeNode* rightNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            rightNode->val = arr[i];
            rightNode->left = NULL;
            rightNode->right = NULL;
            current->right = rightNode;
            enqueue(q, rightNode);
        }
        i++;
    }
    
    freeQueue(q);
    return root;
}

// Zigzag level order traversal
void zigzagLevelOrder(struct TreeNode* root) {
    if (!root) {
        return;
    }
    
    struct Queue* q = createQueue(1000);
    enqueue(q, root);
    
    int* result = (int*)malloc(sizeof(int) * 10000);
    int resultIndex = 0;
    int leftToRight = 1;
    
    while (!isEmpty(q)) {
        int size = q->rear - q->front;
        int* level = (int*)malloc(sizeof(int) * size);
        
        // Store current level in temporary array
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(q);
            level[i] = node->val;
            
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        
        // Add to result based on direction
        if (leftToRight) {
            for (int i = 0; i < size; i++) {
                result[resultIndex++] = level[i];
            }
        } else {
            for (int i = size - 1; i >= 0; i--) {
                result[resultIndex++] = level[i];
            }
        }
        
        free(level);
        leftToRight = !leftToRight;
    }
    
    // Print result
    for (int i = 0; i < resultIndex; i++) {
        printf("%d", result[i]);
        if (i < resultIndex - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    free(result);
    freeQueue(q);
}

// Free tree memory
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int* arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct TreeNode* root = buildTree(arr, N);
    zigzagLevelOrder(root);
    
    freeTree(root);
    free(arr);
    
    return 0;
}