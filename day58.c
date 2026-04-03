#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Create adjacency matrix
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;  // initialize with 0
        }
    }

    int type;
    printf("Enter 1 for Directed graph, 0 for Undirected graph: ");
    scanf("%d", &type);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        matrix[u][v] = 1;

        if (type == 0) {
            matrix[v][u] = 1;  // for undirected graph
        }
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}