#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Node* createNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* node = createNode(v);
    node->next = graph->adj[u];
    graph->adj[u] = node;
}

// DFS-based topological sort
void topologicalSortUtil(struct Graph* graph, int v, int* visited, int* stack, int* top) {
    visited[v] = 1;
    struct Node* temp = graph->adj[v];
    while (temp) {
        int adj = temp->vertex;
        if (!visited[adj])
            topologicalSortUtil(graph, adj, visited, stack, top);
        temp = temp->next;
    }
    stack[++(*top)] = v; // Push vertex to stack after visiting all neighbors
}

void topologicalSort(struct Graph* graph) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    int* stack = (int*)malloc(graph->V * sizeof(int));
    int top = -1;

    for (int i = 0; i < graph->V; i++) visited[i] = 0;

    for (int i = 0; i < graph->V; i++)
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, stack, &top);

    printf("Topological Sort (DFS): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

// Example usage
int main() {
    int V, E, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    struct Graph* graph = createGraph(V);

    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter edges (u v) where u -> v:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topologicalSort(graph);

    return 0;
}

