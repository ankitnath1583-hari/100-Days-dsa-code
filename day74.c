#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX] = {0};

    // Input edges (undirected)
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int source;
    scanf("%d", &source);

    int dist[MAX], visited[MAX] = {0};

    // Initialize distances
    for(int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // Dijkstra
    for(int i = 1; i <= n; i++) {
        int min = INT_MAX, u = -1;

        // Find minimum distance unvisited node
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        // Relax edges
        for(int v = 1; v <= n; v++) {
            if(adj[u][v] && !visited[v] && dist[u] != INT_MAX &&
               dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    // Output
    for(int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}