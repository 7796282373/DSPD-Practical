//Write a program which accepts undirected graph and a starting node, 
// determine the lengths of the shortest paths from the starting node to all other nodes in the graph. 
// If a node is unreachable, its distance is -1. Nodes will be numbered consecutively from 1 to n, and edges will have varying distances or lengths.
//  Find the sub tree using Dijikstra algorithm.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure to represent an edge in the shortest path tree
typedef struct {
    int parent;
    int vertex;
    int weight;
} Edge;

int n;  // Number of nodes

// Function to find the vertex with the minimum distance value that is not yet processed
int minDistance(int dist[], int processed[]) {
    int min = INT_MAX, min_index = -1;
    for (int v = 1; v <= n; v++) {
        if (processed[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int src) {
    int dist[MAX];    // shortest distance from src
    int processed[MAX]; // whether node is included in shortest path tree
    Edge parentEdges[MAX]; // to store shortest path tree edges

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        processed[i] = 0;
        parentEdges[i].parent = -1;
        parentEdges[i].vertex = i;
        parentEdges[i].weight = 0;
    }

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 1; count <= n - 1; count++) {
        int u = minDistance(dist, processed);
        if (u == -1) break; // All reachable nodes processed
        processed[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!processed[v] && graph[u][v] > 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parentEdges[v].parent = u;
                parentEdges[v].weight = graph[u][v];
            }
        }
    }

    // Print distances
    printf("Node\tDistance from Source\n");
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\t-1\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }

    // Print shortest path tree edges
    printf("\nShortest Path Tree Edges (Parent -> Child : Weight):\n");
    for (int i = 1; i <= n; i++) {
        if (parentEdges[i].parent != -1) {
            printf("%d -> %d : %d\n", parentEdges[i].parent, parentEdges[i].vertex, parentEdges[i].weight);
        }
    }
}

int main() {
    int edges, src;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges in format: node1 node2 weight\n");
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        // Since undirected graph
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("Enter starting node: ");
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}
