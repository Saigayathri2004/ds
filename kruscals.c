/*Kruskal's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a graph. It involves the following steps:

    Sort All Edges: Arrange all the edges of the graph in non-decreasing order of their weights.
    Initialize MST: Start with an empty MST and a forest where each vertex is a separate tree.
    Pick Edges: Iterate through the sorted edges and add an edge to the MST if it doesn't form a cycle. Use a union-find (disjoint-set) structure to check for cycles.
    Repeat Until MST is Complete: Stop when the MST contains exactly V−1V−1 edges, where VV is the number of vertices in the graph.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int parent, rank;
} Subset;

// Function prototypes
int compareEdges(const void *a, const void *b);
int find(Subset subsets[], int i);
void unionSets(Subset subsets[], int x, int y);
void kruskal(Edge edges[], int V, int E);

int main() {
    int V, E, i;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    Edge edges[E];
    printf("Enter the edges (src, dest, weight):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskal(edges, V, E);
    return 0;
}

int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

void kruskal(Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(Edge), compareEdges);

    Subset subsets[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    Edge result[V - 1];
    int edgeCount = 0, i = 0;

    while (edgeCount < V - 1 && i < E) {
        Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[edgeCount++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < edgeCount; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}
/* output
Enter the number of vertices and edges: 4 5
Enter the edges (src, dest, weight):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Edges in the Minimum Spanning Tree:
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10
*/
