#include <stdio.h>
#include <limits.h>

#define INF 1000000000
#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    int dist[MAX][MAX];

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);

            if(dist[i][j] == -1 && i != j) {
                dist[i][j] = INF;
            }
        }
    }

    // Floyd-Warshall
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] != INF && dist[k][j] != INF &&
                   dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Convert INF back to -1
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INF) {
                dist[i][j] = -1;
            }
        }
    }

    // Output
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}