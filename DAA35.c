#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool isSafe(int v, int graph[MAX][MAX], int color[], int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[MAX][MAX], int m, int color[], int v, int V) {
    if (v == V) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return true;
            }

            color[v] = 0;
        }
    }
    return false;
}

void printSolution(int color[], int V) {
    printf("Solution Exists: Following are the assigned colors\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Color %d\n", i + 1, color[i]);
    }
}

int main() {

    int V, m;
    int graph[MAX][MAX];
    int color[MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    if (graphColoringUtil(graph, m, color, 0, V)) {
        printSolution(color, V);
    } else {
        printf("No solution exists\n");
    }

    return 0;
}