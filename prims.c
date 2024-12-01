#include<stdio.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

void main() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999;  // Represent non-edges with a large value
            }
        }
    }

    visited[1] = 1;  // Start from the first node
    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (ne < n) {  // Repeat until n-1 edges are added
        min = 999;

        // Find the minimum weight edge from visited to unvisited nodes
        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if (!visited[v]) {
            printf(" Edge %d: (%d -> %d) cost: %d\n", ne++, u, v, min);
            mincost += min;
            visited[v] = 1;
        }

        cost[a][b] = cost[b][a] = 999;  // Remove the edge from consideration
    }

    printf("\nMinimum cost = %d\n", mincost);
}

