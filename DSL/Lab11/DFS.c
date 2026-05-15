#include <stdio.h>
#define MAX 10

int visited[MAX];

void DFS(int adj[MAX][MAX], int n, int start) {
    int i;
    printf("%d ", start);
    visited[start] = 1;

    for (i = 0; i < n; i++) {
        if (adj[start][i] == 1 && visited[i] == 0)
            DFS(adj, n, i);
    }
}

int main() {
    int n, adj[MAX][MAX], start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(adj, n, start);

    return 0;
}
