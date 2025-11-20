
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}

struct Node* createNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* node = createNode(v);
    node->next = graph->adj[u];
    graph->adj[u] = node;

    node = createNode(u); // undirected graph
    node->next = graph->adj[v];
    graph->adj[v] = node;
}

bool biconnectedUtil(struct Graph* graph, int u, int parent, int* disc, int* low, int* time, bool* visited, bool* isBiconnected) {
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++(*time);

    struct Node* temp = graph->adj[u];
    while (temp) {
        int v = temp->vertex;

        if (!visited[v]) {
            children++;
            if (!biconnectedUtil(graph, v, u, disc, low, time, visited, isBiconnected))
                return false;

            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            // u is articulation point
            if ((parent != -1 && low[v] >= disc[u]) || (parent == -1 && children > 1)) {
                *isBiconnected = false;
            }
        }
        else if (v != parent) {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
        temp = temp->next;
    }
    return *isBiconnected;
}

bool isBiconnected(struct Graph* graph) {
    int* disc = (int*)malloc(graph->V * sizeof(int));
    int* low = (int*)malloc(graph->V * sizeof(int));
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));

    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
        disc[i] = -1;
        low[i] = -1;
    }

    bool isBiconnected = true;

    if (!biconnectedUtil(graph, 0, -1, disc, low, &(int){0}, visited, &isBiconnected))
        return false;

    // Check if all vertices were visited (graph is connected)
    for (int i = 0; i < graph->V; i++)
        if (!visited[i])
            return false;

    return isBiconnected;
}

// Example usage
int main() {
    int V, E, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V);
    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (isBiconnected(graph))
        printf("The graph is biconnected.\n");
    else
        printf("The graph is NOT biconnected.\n");

    return 0;
}
