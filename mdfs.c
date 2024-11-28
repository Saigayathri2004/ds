#include <stdio.h>

#define MAX_SIZE 100

int n;
int graph[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int nodevalues[MAX_SIZE];

void dfs(int node) {
    // Mark the current node as visited
    visited[node] = 1;
    
    // Print the value of the current node
    printf("%d \t", nodevalues[node]);
    
    // Explore all adjacent nodes that are not visited
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(i);  // Recursively visit the adjacent node
        }
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input node values
    printf("Enter the values of each node: \n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i + 1);
        scanf("%d", &nodevalues[i]);
    }

    // Initialize visited array to 0 (all nodes are unvisited)
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Input adjacency matrix (edges between nodes)
    printf("Enter 0 or 1 if there is an edge between the vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("Is there an edge between node %d and node %d? Enter 1 for yes, 0 for no: ", nodevalues[i], nodevalues[j]);
            int edge;
            scanf("%d", &edge);
            if (edge == 1) {
                graph[i][j] = graph[j][i] = 1;  // Since the graph is undirected
            } else {
                graph[i][j] = graph[j][i] = 0;
            }
        }
    }

    int startNode;
    printf("Enter the value of the starting node: ");
    scanf("%d", &startNode);

    // Find the index of the starting node
    int startIndex = -1;
    for (int i = 0; i < n; i++) {
        if (startNode == nodevalues[i]) {
            startIndex = i;
            break;
        }
    }

    if (startIndex == -1) {
        printf("Invalid starting node value\n");
    } else {
        printf("The visited nodes are:\n");
        dfs(startIndex);  // Start DFS from the given node
    }

    printf("\n");
    return 0;
}
