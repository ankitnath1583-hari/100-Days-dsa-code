#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

typedef struct {
    int data[MAX];
    int top;
} Stack;

void enqueue(Queue *q, int val){
    q->data[++q->rear] = val;
}

int dequeue(Queue *q){
    return q->data[q->front++];
}

void push(Stack *s, int val){
    s->data[++s->top] = val;
}

int pop(Stack *s){
    return s->data[s->top--];
}

int main(){

    int n;
    scanf("%d",&n);

    Queue q;
    Stack s;

    q.front = 0;
    q.rear = -1;
    s.top = -1;

    int x;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(&q,x);
    }

    while(q.front <= q.rear){
        push(&s, dequeue(&q));
    }

    while(s.top != -1){
        enqueue(&q, pop(&s));
    }

    for(int i=q.front;i<=q.rear;i++){
        printf("%d ", q.data[i]);
    }

    return 0;
}