#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Check mirror
int isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL)
        return 1;

    if (left == NULL || right == NULL)
        return 0;

    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Check symmetric
int isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return 1;
    return isMirror(root->left, root->right);
}

// Example main (manual tree)
int main() {
    // Example: 1 2 2 3 4 4 3
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);

    root->left->left = newNode(3);
    root->left->right = newNode(4);

    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}