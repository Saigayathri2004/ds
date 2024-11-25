#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Structure for representing a graph
struct Graph {
    int vertices;
    int adj[MAX][MAX];
};

// Stack data structure for iterative DFS
int stack[MAX];
int top = -1;

// Function to initialize the graph
void initGraph(struct Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;  // Initialize adjacency matrix to 0
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* g, int start, int end) {
    g->adj[start][end] = 1;  // Directed edge from start to end
    g->adj[end][start] = 1;   // Since it's an undirected graph
}

// Function to perform DFS using recursion
void DFSRecursive(struct Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1;  // Mark the current node as visited
    printf("%d ", vertex);  // Print the current node

    // Recur for all the adjacent vertices
    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[vertex][i] == 1 && !visited[i]) {
            DFSRecursive(g, i, visited);
        }
    }
}

// Function to perform DFS using an iterative approach (using stack)
void DFSIterative(struct Graph* g, int start) {
    int visited[MAX] = {0};
    stack[++top] = start;  // Push start vertex onto the stack

    while (top != -1) {
        int vertex = stack[top--];  // Pop a vertex from the stack

        if (!visited[vertex]) {
            visited[vertex] = 1;
            printf("%d ", vertex);  // Print the vertex

            // Push all unvisited adjacent vertices onto the stack
            for (int i = 0; i < g->vertices; i++) {
                if (g->adj[vertex][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}

int main() {
    struct Graph g;
    int vertices, edges, startVertex;

    // Take input for graph
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (start and end vertex of each edge):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(&g, start, end);
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    int visited[MAX] = {0};
    printf("\nDFS (Recursive) traversal starting from vertex %d:\n", startVertex);
    DFSRecursive(&g, startVertex, visited);

    printf("\n\nDFS (Iterative) traversal starting from vertex %d:\n", startVertex);
    DFSIterative(&g, startVertex);

    return 0;
}

