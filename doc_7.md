# DOCUMENTATION (prog_7.c)

## Logic

Dijkstra's algorithm is used to find the shortest distance from a given source vertex to all other vertices in a weighted graph with non-negative edge weights.

The algorithm works by repeatedly selecting the unvisited vertex with the minimum known distance from the source and updating (relaxing) the distances of its adjacent vertices. A `visited` array is maintained to ensure that each vertex is processed only once.

The graph is represented using an adjacency matrix, where a non-zero value indicates the weight of the edge between two vertices.

---

## Data Structure Implementation

A weighted graph is implemented using an adjacency matrix.

### Graph Structure

The graph contains:
- A 2D matrix to store edge weights between vertices
- An integer representing the number of vertices

```c
    typedef struct{
        int matrix[MAX][MAX];
        int n;
    } Graph;
```

---

## Functions Used

1. `findMinDistance(int dist[], int visited[], int n):`
    Finds and returns the index of the unvisited vertex with the minimum distance value from the source. If no such vertex exists, it returns `-1`.

2. `dijkstra(Graph* g, int start):`
    Implements Dijsktra's algorithm to calculate the shortest distance from the given source vertex to all other vertices in the graph.
    It initializes distance and visited arrays, repeatedly selects the nearest unvisited vertex, performs relaxation on adjacent vertices, and finally prints the shortest distances.

---

## main() Function

The `main()` function demonstrates the working of Dijkstra's algorithm on a weighted graph:
1. Initializes a graph with 5 vertices.
2. Sets all values in the adjacency matrix to `0`.
3. Adds weighted edges between vertices to form a sample graph.
4. Calls `dijkstra()` with source vertex `0`.
5. Displays the shortest distance from the source to all other vertices.

```c
    dijkstra(&g, 0);
```

---

## Sample Output

```c
    Dijkstra Result (Source: Vertex 0)
    Vertex      Distance from Source
    0           0
    1           3
    2           2
    3           8
    4           10
```