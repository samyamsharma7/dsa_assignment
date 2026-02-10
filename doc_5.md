# DOCUMENTATION (prog_5.c)

## Logic

An undirected graph can be represented using an adjacency matrix, where a 2D array is used to store edge information between vertices.

If there is an edge between vertex `u` and vertex `v`, then both `matrix[u][v]` and `matrix[v][u]` are set to `1`. Otherwise, they remain `0`.

The program implements two fundamental graph traversal techniques:
- **Breadth First Search(BFS):** Traverses the graph by level using a queue.
- **Depth First Search (DFS):** Traverses the graph depth-wise using a stack.

Both traversals ensure that each vertex is visited only once by managing a `visited` array.

---

## Data Structure Implementation

### Graph Structure (Adjacency Matrix)

The graph is represented using a structure containing:
- A 2D matrix to store adjacency information
- An integer representing the number of vertices

```c
    typedef struct{
        int matrix[MAX][MAX];
        int n;
    } Graph;
```

### Queue Structure (For BFS)

A queue is used to support Breadth First Search traversal.

```c
    typedef struct{
        int items[MAX];
        int front, rear;
    } Queue;
```

### Stack Structure (For DFS)

A stack is used to support Depth First Search traversal.

```c
    typedef struct{
        int items[MAX];
        int top;
    } Stack;
```

---

## Functions Used

1. `initGraph(Graph* g, int vertices):`
    Initializes the graph by setting the number of vertices and assigning all values in the adjacency matrix to `0`, indicating that no edges exist initially.

2. `addEdge(Graph* g, int u, int v):`
    Adds an undirected edge between vertices `u` and `v` by setting both `matrix[u][v]` and `matrix[v][u]` to `1`.

3. `initQueue(Queue* q):`
    Initializes the queue by setting both `front` and `rear` to `-1`.

4. `enqueue(Queue* q, int val):`
    Inserts an element into the queue is space is available.

5. `dequeue(Queue* q):`
    Removes and returns the front element from the queue.

6. `initStack(Stack* s):`
    Initializes the stack by setting the top index to `-1`.

7. `push(Stack* s, int val):`
    Pushes an element onto the stack if space is available.

8. `pop(Stack* s):`
    Pops and returns the top element from the stack.

9. `BFS(Graph* g, int start):`
    Performs Breadth First Search traversal starting from the given vertex. It uses a queue to visit adjacent unvisited vertices level by level and prints the traversal order.

10. `DFS(Graph* g, int start):`
    Performs Depth First Search traversal starting from the given vertex. It uses a stack to explore as deep as possible before backtracking and prints the traversal order.

---

## main() Function

The `main()` function demonstrates the implementation of an undirected graph using an adjacency matrix and traversal techniques:
1. Initializes a graph with 5 vertices using `initGraph()`.
2. Adds edges between vertices using `addEdge()`.
3. Performs BFS traversal starting from vertex `0`.
4. Performs DFS traversal starting from vertex `0`.

```c
    initGraph(&g, 5);

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);

    BFS(&g, 0);
    DFS(&g, 0);
```

This represents the following graph structure:

```
    0 ---- 1 ---- 3
    |      |
    |      |
    |      |
    2      4
```

---

## Sample Output

```c
    BFS Traversal: 0 1 2 3 4
    DFS Traversal: 0 1 3 4 2
```

