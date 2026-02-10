#include <stdio.h>

#define MAX 10

//graph structure
typedef struct {
    int matrix[MAX][MAX];
    int n; // number of vertices
} Graph;

//queue for bfs
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

//stack for dfs
typedef struct {
    int items[MAX];
    int top;
} Stack;


void initQueue(Queue* q){ 
    q->front = -1; q->rear = -1; 
}

void enqueue(Queue* q, int val){

    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++(q->rear)] = val;

}

int dequeue(Queue* q){

    int val = q->items[q->front];
    if (q->front >= q->rear) q->front = q->rear = -1;
    else q->front++;
    return val;

}

void initStack(Stack* s){ 
    s->top = -1; 
}

void push(Stack* s, int val){

    if (s->top == MAX - 1) return;
    s->items[++(s->top)] = val;

}

int pop(Stack* s) {
    return s->items[(s->top)--];
}


void initGraph(Graph* g, int vertices) {
    g->n = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            g->matrix[i][j] = 0; //initially, the graph has no vertices
}

void addEdge(Graph* g, int u, int v) {

    g->matrix[u][v] = 1;
    g->matrix[v][u] = 1;
    //edge between u and v exists now

}

//bfs using queue
void BFS(Graph* g, int start) {
    int visited[MAX] = {0};
    Queue q;
    initQueue(&q);

    visited[start] = 1; //starting with the given vertex
    enqueue(&q, start);

    printf("BFS Traversal: ");
    while (q.front != -1) {
        int curr = dequeue(&q);
        printf("%d ", curr);

        for (int i = 0; i < g->n; i++) {
            if (g->matrix[curr][i] == 1 && visited[i] == 0) { //checking if the vertex exists AND is NOT already visited
                //if so, enqueue the vertex
                visited[i] = 1; 
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

//dfs using stack
void DFS(Graph* g, int start) {
    int visited[MAX] = {0};
    Stack s;
    initStack(&s);

    push(&s, start);

    printf("DFS Traversal: ");
    while (s.top != -1) {
        int curr = pop(&s);

        if (visited[curr] == 0) {
            printf("%d ", curr);
            visited[curr] = 1;
        }

        // push neighbors in reverse to maintain order
        for (int i = g->n - 1; i >= 0; i--) {
            if (g->matrix[curr][i] == 1 && visited[i] == 0) {
                push(&s, i);
            }
        }
    }
    printf("\n");
}

int main() {
    Graph g;
    initGraph(&g, 5);

    // Example Graph: 0-1, 0-2, 1-3, 1-4
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);

    BFS(&g, 0);
    DFS(&g, 0);

    return 0;
}