#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// DFS function to detect cycle
bool dfs(int node, int adj[MAX][MAX], int V, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) { // if edge exists
            if (!visited[i]) {
                if (dfs(i, adj, V, visited, recStack))
                    return true;
            }
            else if (recStack[i]) {
                return true; // cycle found
            }
        }
    }

    recStack[node] = false; // backtrack
    return false;
}

// Function to check cycle in graph
bool hasCycle(int adj[MAX][MAX], int V) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, V, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 4;

    int adj[MAX][MAX] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}  // creates a cycle
    };

    if (hasCycle(adj, V))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}