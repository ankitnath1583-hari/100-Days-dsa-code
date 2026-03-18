#include <stdio.h>
#include <stdlib.h>

// Tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * n);
    int front = 0, rear = 0;

    struct TreeNode* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct TreeNode* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Level order traversal
void levelOrder(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            printf("%d ", node->val);

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        printf("\n"); // new level
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}