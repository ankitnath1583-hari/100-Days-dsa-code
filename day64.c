#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void kahnTopologicalSort(int V, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    int i, j;

    // Calculate indegree
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // Add nodes with indegree 0 to queue
    for(i = 0; i < V; i++) {
        if(indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;

    printf("Topological Order: ");

    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        // Reduce indegree of neighbors
        for(i = 0; i < V; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    // Check for cycle
    if(count != V) {
        printf("\nGraph has a cycle!\n");
    }
}

int main() {
    int V = 4;

    int adj[MAX][MAX] = {
        {0,1,1,0},
        {0,0,0,1},
        {0,0,0,1},
        {0,0,0,0}
    };

    kahnTopologicalSort(V, adj);

    return 0;
}