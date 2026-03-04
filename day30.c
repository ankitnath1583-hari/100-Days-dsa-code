#include <stdio.h>
#define MAX 1000

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

void pop() {
    if (top >= 0)
        top--;
}

int main() {
    int n, m, i, value;

    scanf("%d", &n);

    // Push elements
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    scanf("%d", &m);

    // Pop m elements
    for (i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack from top to bottom
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}