#include <stdio.h>

int main() {
    int n, e, i, j, src, dest;
    int graph[10][10] = {0};
    int type;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter 1 for Directed or 2 for Undirected graph: ");
    scanf("%d", &type);

    printf("Enter edges (source destination):\n");
    for (i = 0; i < e; i++) {
        scanf("%d%d", &src, &dest);
        graph[src][dest] = 1;
        if (type == 2)  // if undirected
            graph[dest][src] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    return 0;
}
