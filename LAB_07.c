//Consider the undirected graph G, consisting of n nodes laid out in a 3 -by- 3 grid: 
// Start searching at node 1, and break ties for exploring the next node based on lower numerical order 
// (i.e. add nodes to a queue low to high, add nodes to a stack high to low).
//  (a) In what order are nodes marked as explored by BFS? 
// (b) In what order are nodes marked as explored by DFS?
#include <stdio.h>
#include <stdlib.h>

#define NODES 9

// Adjacency list structure
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    Node* adjLists[NODES + 1];
    int visited[NODES + 1];
} Graph;

// Queue structure for BFS
typedef struct Queue {
    int items[NODES];
    int front;
    int rear;
} Queue;

// Stack structure for DFS
typedef struct Stack {
    int items[NODES];
    int top;
} Stack;

// Function to create node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Initialize Graph
void initGraph(Graph* graph) {
    for (int i = 1; i <= NODES; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
}

// Add edge (undirected)
void addEdge(Graph* graph, int src, int dest) {
    // Add dest to src list, keep in ascending order
    Node* newNode = createNode(dest);
    if (graph->adjLists[src] == NULL || graph->adjLists[src]->vertex > dest) {
        newNode->next = graph->adjLists[src];
        graph->adjLists[src] = newNode;
    } else {
        Node* temp = graph->adjLists[src];
        while (temp->next && temp->next->vertex < dest) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    // Add src to dest list similarly
    newNode = createNode(src);
    if (graph->adjLists[dest] == NULL || graph->adjLists[dest]->vertex > src) {
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    } else {
        Node* temp = graph->adjLists[dest];
        while (temp->next && temp->next->vertex < src) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Queue functions
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}
int isQueueEmpty(Queue* q) {
    return q->front == -1;
}
void enqueue(Queue* q, int value) {
    if (q->rear == NODES - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}
int dequeue(Queue* q) {
    if (isQueueEmpty(q))
        return -1;
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Stack functions
void initStack(Stack* s) {
    s->top = -1;
}
int isStackEmpty(Stack* s) {
    return s->top == -1;
}
void push(Stack* s, int value) {
    if (s->top == NODES -1)
        return;
    s->items[++s->top] = value;
}
int pop(Stack* s) {
    if (isStackEmpty(s))
        return -1;
    return s->items[s->top--];
}

// BFS traversal
void BFS(Graph* graph, int start) {
    Queue q;
    initQueue(&q);
    for (int i = 1; i <= NODES; i++)
        graph->visited[i] = 0;

    enqueue(&q, start);
    graph->visited[start] = 1;
    printf("BFS order: ");

    while (!isQueueEmpty(&q)) {
        int vertex = dequeue(&q);
        printf("%d ", vertex);

        // Traverse neighbors in ascending order (already sorted in adj lists)
        Node* temp = graph->adjLists[vertex];
        while (temp) {
            if (!graph->visited[temp->vertex]) {
                enqueue(&q, temp->vertex);
                graph->visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// DFS traversal
void DFS(Graph* graph, int start) {
    Stack s;
    initStack(&s);
    for (int i = 1; i <= NODES; i++)
        graph->visited[i] = 0;

    push(&s, start);

    printf("DFS order: ");

    while (!isStackEmpty(&s)) {
        int vertex = pop(&s);
        if (!graph->visited[vertex]) {
            printf("%d ", vertex);
            graph->visited[vertex] = 1;

            // Push neighbors in descending order (to explore smallest first)
            // We traverse linked list to stack neighbors high to low for correct order
            // So first store neighbors and then push in reverse order
            int neighbors[10], count = 0;
            Node* temp = graph->adjLists[vertex];
            while (temp) {
                if (!graph->visited[temp->vertex]) {
                    neighbors[count++] = temp->vertex;
                }
                temp = temp->next;
            }
            for (int i = count -1; i >= 0; i--) {
                push(&s, neighbors[i]);
            }
        }
    }

    printf("\n");
}

int main() {
    Graph graph;
    initGraph(&graph);

    // Add edges for 3x3 grid nodes
    // Manually adding edges for adjacency based on neighbors above
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 2, 5);
    addEdge(&graph, 3, 6);
    addEdge(&graph, 4, 5);
    addEdge(&graph, 4, 7);
    addEdge(&graph, 5, 6);
    addEdge(&graph, 5, 8);
    addEdge(&graph, 6, 9);
    addEdge(&graph, 7, 8);
    addEdge(&graph, 8, 9);

    BFS(&graph, 1);
    DFS(&graph, 1);

    return 0;
}
