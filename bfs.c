#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int vertex_count = 0;

struct vertex
{
    char data;
    bool visited;
};

struct vertex *graph[MAX];
int adj_matrix[MAX][MAX];
int queue[MAX];
int rear = -1;
int front = 0;
int queue_count = 0;

void enqueue(int data) 
{
    if (rear < MAX - 1) 
    {
        queue[++rear] = data;
        queue_count++;
    }
}

int dequeue() 
{
    if (front <= rear) 
    {
        queue_count--;
        return queue[front++];
    }
    return -1; // Queue empty case
}

bool is_queue_empty() 
{
    return queue_count == 0;
}

void add_vertex(char data) 
{
    if (vertex_count >= MAX) 
    {
        printf("Graph is full, cannot add more vertices.\n");
        return;
    }
    struct vertex *new = (struct vertex*)malloc(sizeof(struct vertex));
    new->data = data;
    new->visited = false;
    graph[vertex_count] = new;
    vertex_count++;
}

void add_edge(int start, int end) 
{
    if (start >= vertex_count || end >= vertex_count || start < 0 || end < 0) {
        printf("Invalid vertex indices!\n");
        return;
    }
    adj_matrix[start][end] = 1;
    adj_matrix[end][start] = 1;
}

int adj_vertex(int vertex_get) {
    for (int i = 0; i < vertex_count; i++) 
    {
        if (adj_matrix[vertex_get][i] == 1 && !graph[i]->visited)
        {
            return i;
        }
    }
    return -1;
}

void display_vertex(int pos) 
{
    printf("%c -> ", graph[pos]->data);
}

void bfs(struct vertex *new, int start) 
{
    if (!new) {
        printf("\nNothing to display\n");
        return;
    }

    printf("\n|||||||||||||||||||||||||||||||\n");

    new->visited = true;
    display_vertex(start);
    enqueue(start);

    int unvisited; // Declare unvisited outside the loop

    while (!is_queue_empty()) 
    {
        int pop_vertex = dequeue();
        while ((unvisited = adj_vertex(pop_vertex)) != -1) { // Fixed parentheses here
            graph[unvisited]->visited = true;
            display_vertex(unvisited);
            enqueue(unvisited);
        }
    }
    printf("\n|||||||||||||||||||||||||||||||\n");

    // Reset visited for all vertices after traversal
    for (int i = 0; i < vertex_count; i++) {
        graph[i]->visited = false;
    }
}

void show() {
    printf("\n.................................\n");
    for (int i = 0; i < vertex_count; i++) 
    {
        printf("Edge position of '%c' is %d\n", graph[i]->data, i);
    }
    printf(".................................\n");
}

void print_adj_matrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertex_count; i++) 
    {
        for (int j = 0; j < vertex_count; j++) 
        {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int opt;
    char data;
    int edge_1, edge_2;
    int start;

    // Initialize adjacency matrix to 0 (no edges initially)
    for (int i = 0; i < MAX; i++) 
    {
        for (int j = 0; j < MAX; j++) 
        {
            adj_matrix[i][j] = 0;
        }
    }

    do {
        printf("\n1) Add vertex \n2) Create edge \n3) Traversal \n4) Display adjacency matrix \n0) Exit \nChoose option: ");
        scanf("%d", &opt);
        switch (opt) 
        {
            case 1:
                printf("\nEnter data to be added to vertex: ");
                scanf(" %c", &data);
                add_vertex(data);
                break;
            case 2:
                show();
                printf("\nEnter edge starting (vertex index): ");
                scanf("%d", &edge_1);
                printf("\nEnter edge ending (vertex index): ");
                scanf("%d", &edge_2);
                add_edge(edge_1, edge_2);
                break;
            case 3:
                printf("\nEnter starting vertex position: ");
                scanf("%d", &start);
                if (start < 0 || start >= vertex_count) 
                {
                    printf("\nInvalid vertex position!\n");
                } else 
                {
                    bfs(graph[start], start);
                }
                break;
            case 4:
                print_adj_matrix();
                break;
            default:
                printf("\nInvalid option, try again!\n");
        }
    } while (opt != 0);

    return 0;
}

