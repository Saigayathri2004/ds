#include <stdio.h>

#define MAX 10

void topologicalSort(int graph[MAX][MAX], int n) {
    int indegree[MAX] = {0}, queue[MAX], front = 0, rear = 0, count = 0;
    int topoOrder[MAX];

    // Calculate indegree of each vertex
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (graph[j][i] == 1)
                indegree[i]++;

    // Enqueue vertices with indegree 0
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    // Process the queue
    while (front < rear) {
        int current = queue[front++];
        topoOrder[count++] = current;

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    // Check for cycles
    if (count != n) {
        printf("Cycle detected! Topological sorting not possible.\n");
        return;
    }

    // Print topological order
    printf("Topological Order: ");
    for (int i = 0; i < count; i++)
        printf("%d ", topoOrder[i]);
    printf("\n");
}

int main() {
    int graph[MAX][MAX], n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    topologicalSort(graph, n);

    return 0;
}
