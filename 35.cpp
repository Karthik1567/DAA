#include <stdio.h>
#include <stdbool.h>

#define V 5

bool isSafe(int graph[V][V], int color[], int c, int v) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, c, v)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            color[v] = 0;
        }
    }

    return false;
}

void printSolution(int color[]) {
    printf("Solution Exists: Following are the assigned colors\n");
    for (int i = 0; i < V; i++) {
        printf(" %d ", color[i]);
    }
    printf("\n");
}

void graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist\n");
        return;
    }

    printSolution(color);
}

int main() {
	         printf("192211572,S.rohith\n"); 
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    int m = 3;

    graphColoring(graph, m);

    return 0;
}
