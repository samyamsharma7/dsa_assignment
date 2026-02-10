#include <stdio.h>

#define MAX 10
#define INF 99999

typedef struct{

    int matrix[MAX][MAX];
    int n;

} Graph;

// function to find the unvisited vertex with the minimum distance
int findMinDistance(int dist[], int visited[], int n){

    int min = INF;
    int min_index = -1;

    for (int v = 0; v < n; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;

}

void dijkstra(Graph* g, int start){

    int dist[MAX];    
    int visited[MAX]; 

    //initialization
    for (int i = 0; i < g->n; i++) {
        dist[i] = INF;
        visited[i] = 0; // 0 represents not visited
    }

    dist[start] = 0;

    for (int count = 0; count < g->n - 1; count++) {
        // find the "closest" vertex that hasn't been processed
        int u = findMinDistance(dist, visited, g->n);

        if (u == -1) break; // all remaining nodes are unreachable

        visited[u] = 1; // mark as processed

        //relaxation
        for (int v = 0; v < g->n; v++) {
            if (g->matrix[u][v] > 0 && visited[v] == 0 && dist[u] != INF) {
                if (dist[u] + g->matrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + g->matrix[u][v];
                }
            }
        }
    }

    printf("\nDijkstra Result (Source: Vertex %d)\n", start);
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < g->n; i++) {
        if (dist[i] == INF)
            printf("%d \t\t INF\n", i);
        else
            printf("%d \t\t %d\n", i, dist[i]);
    }

}

int main(){

    Graph g;
    int i, j;
    g.n = 5;

    // initialize matrix with 0
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++) {
            g.matrix[i][j] = 0;
        }
    }

    // Example Weighted Graph
    // Edges from 0
    g.matrix[0][1] = 4;  g.matrix[1][0] = 4;
    g.matrix[0][2] = 2;  g.matrix[2][0] = 2;
    // Edges from 2
    g.matrix[2][1] = 1;  g.matrix[1][2] = 1;
    g.matrix[2][3] = 8;  g.matrix[3][2] = 8;
    g.matrix[2][4] = 10; g.matrix[4][2] = 10;
    // Edges from 1
    g.matrix[1][3] = 5;  g.matrix[3][1] = 5;
    // Edges from 3
    g.matrix[3][4] = 2;  g.matrix[4][3] = 2;

    dijkstra(&g, 0);

    return 0;
    
}