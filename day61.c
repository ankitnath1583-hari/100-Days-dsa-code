#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
bool dfs(int node, int parent, int *visited, int **adj, int *adjSize) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj, adjSize))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }
    }
    return false;
}

// Function to check cycle
void detectCycle(int V, int **adj, int *adjSize) {
    int *visited = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, adjSize)) {
                printf("YES\n");
                free(visited);
                return;
            }
        }
    }

    printf("NO\n");
    free(visited);
}