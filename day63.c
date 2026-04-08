#include <stdlib.h>
#include <stdbool.h>

#define MAX 2000

// DFS function
bool dfs(int node, int** adj, int* adjSize, int* state, int* result, int* index) {
    if (state[node] == 1) return false; // cycle detected
    if (state[node] == 2) return true;  // already processed

    state[node] = 1; // mark as visiting

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if (!dfs(neighbor, adj, adjSize, state, result, index))
            return false;
    }

    state[node] = 2; // mark as visited
    result[(*index)--] = node; // fill from back
    return true;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {

    // Create adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int)); // max possible
    }

    // Build graph (b → a)
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][adjSize[b]++] = a;
    }

    int* state = (int*)calloc(numCourses, sizeof(int));
    int* result = (int*)malloc(numCourses * sizeof(int));

    int index = numCourses - 1;

    // Run DFS
    for (int i = 0; i < numCourses; i++) {
        if (state[i] == 0) {
            if (!dfs(i, adj, adjSize, state, result, &index)) {
                *returnSize = 0;
                return (int*)malloc(0); // cycle → empty array
            }
        }
    }

    *returnSize = numCourses;
    return result;
}