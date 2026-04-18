#include <stdio.h>
#include <stdlib.h>

int visited[1001];
int adj[1001][1001];

void dfs(int node, int n) {
    visited[node] = 1;
    
    for (int i = 1; i <= n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    dfs(1, n);

    // check if all nodes are visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}