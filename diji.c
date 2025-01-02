#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF INT_MAX

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int distance[MAX], visited[MAX] = {0}, pred[MAX];
    int count, minDistance, nextNode;

    // Initialization
    for (int i = 0; i < n; i++) {
        distance[i] = graph[start][i];
        pred[i] = start;
    }
    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        minDistance = INF;

        // Find the next node
        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;

        // Update the distances
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[nextNode][i] != INF && 
                distance[nextNode] + graph[nextNode][i] < distance[i]) {
                distance[i] = distance[nextNode] + graph[nextNode][i];
                pred[i] = nextNode;
            }
        }
        count++;
    }

    // Print the shortest path
    printf("Node\tDistance\tPath\n");
    for (int i = 0; i < n; i++) {
        if (i != start) {
            printf("%d\t%d\t\t%d", i, distance[i], i);
            int j = i;
            while (j != start) {
                j = pred[j];
                printf(" <- %d", j);
            }
            printf("\n");
        }
    }
}

int main() {
    int graph[MAX][MAX], n, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter the starting node: ");
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}
