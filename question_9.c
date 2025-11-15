// PROGRAM TO IMPLEMENT BFS AND DFS TRAVERSAL OF A GRAPH
// WRITTEN BY:  MANISH  KUMAR

#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

// Function to add to queue
void enqueue(int v)
{
    if (rear == MAX - 1)
        printf("QUEUE OVERFLOW\n");
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = v;
    }
}

// Function to remove from queue
int dequeue()
{
    int v = -1;
    if (front == -1 || front > rear)
        printf("QUEUE UNDERFLOW\n");
    else
        v = queue[front++];
    return v;
}

// BFS traversal
void bfs(int start, int n)
{
    int i, v;
    for (i = 1; i <= n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS TRAVERSAL: ");
    while (front <= rear)
    {
        v = dequeue();
        if (v == -1)
            break;
        printf("%d ", v);
        for (i = 1; i <= n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS traversal
void dfs(int v, int n)
{
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for (i = 1; i <= n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
            dfs(i, n);
    }
}

int main()
{
    int n, i, j, choice, start;

    printf("ENTER NUMBER OF VERTICES: ");
    scanf("%d", &n);

    printf("ENTER ADJACENCY MATRIX:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. BFS TRAVERSAL\n");
        printf("2. DFS TRAVERSAL\n");
        printf("3. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("ENTER START VERTEX: ");
            scanf("%d", &start);
            front = rear = -1;
            bfs(start, n);
            break;

        case 2:
            printf("ENTER START VERTEX: ");
            scanf("%d", &start);
            for (i = 1; i <= n; i++)
                visited[i] = 0;
            printf("DFS TRAVERSAL: ");
            dfs(start, n);
            printf("\n");
            break;
        case 3:
            printf("EXITING PROGRAM.\n");
            break;
        default:
            printf("INVALID CHOICE! TRY AGAIN.\n");
        }
    } while (choice != 3);
    return 0;
}
