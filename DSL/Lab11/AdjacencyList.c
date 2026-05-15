#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[10]; // adjacency list array
int n;

void addEdge(int src, int dest, int type) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = adj[src];
    adj[src] = newNode;

    if (type == 2) { // undirected graph
        newNode = malloc(sizeof(struct Node));
        newNode->vertex = src;
        newNode->next = adj[dest];
        adj[dest] = newNode;
    }
}

void display() {
    for (int i = 0; i < n; i++) {
        struct Node* temp = adj[i];
        printf("%d -> ", i);
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n,e, src, dest, type;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter 1 for Directed or 2 for Undirected graph: ");
    scanf("%d", &type);

    for (int i = 0; i < e; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d%d", &src, &dest);
        addEdge(src, dest, type);
    }

    printf("\nAdjacency List:\n");
    display();
    return 0;
}
