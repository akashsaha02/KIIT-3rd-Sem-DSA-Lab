/*WAP in c to create an un-directed graph using adjacency matrix
method and add options for the depth-first traversal and breadth-first
traversal

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 25
#define INITIAL 1
#define WAITING 2
#define VISITED 3

int n;
int adj[MAX_VERTICES][MAX_VERTICES];

void create_graph();
void insert_edge(int origin, int destin, int directed);
void display();
void dft();
void bft();
int is_connected();

int front = -1, rear = -1;
int queue[MAX_VERTICES];

int state[MAX_VERTICES];

int main()
{
    int ch;
    while (1)
    {
        printf("\n\tImplementation of Graph using Adjacency Matrix\n");
        printf("\n\t1 - Create Graph");
        printf("\n\t2 - Add edge");
        printf("\n\t3 - Display Graph");
        printf("\n\t4 - Depth First Traversal");
        printf("\n\t5 - Breadth First Traversal");
        printf("\n\t6 - Check Connectivity");
        printf("\n\t7 - Exit");
        printf("\n\n\tEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create_graph();
            break;
        case 2:
            insert_edge(0, 1, 1);
            break;
        case 3:
            display();
            break;
        case 4:
            dft();
            break;
        case 5:
            bft();
            break;

        case 6:
            if (is_connected())
            {
                printf("\n\n\tGraph is connected");
            }
            else
            {
                printf("\n\n\tThe graph is not connected");
            }
            break;
        case 7:
            exit(1);
            break;

        default:
            printf("\n\n\tInvalid Choice");
            break;
        }
    }

    return 0;
}

void create_graph()
{
    int i, max_edges, origin, destin;

    printf("\n\n\tEnter number of vertices : ");
    scanf("%d", &n);

    max_edges = n * (n - 1);

    for (i = 1; i <= max_edges; i++)
    {
        printf("\n\tEnter edge %d(0 0 to quit) : ", i);
        scanf("%d %d", &origin, &destin);

        if ((origin == 0) && (destin == 0))
        {
            break;
        }

        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            printf("\n\tInvalid edge");
            i--;
        }
        else
        {
            insert_edge(origin, destin, 1);
        }
    }
}

void insert_edge(int origin, int destin, int directed)
{
    if (origin > n || destin > n || origin <= 0 || destin <= 0)
    {
        printf("\n\tVertex out of range");
        return;
    }

    if (adj[origin][destin] == 1)
    {
        printf("\n\tEdge already present");
    }
    else
    {
        adj[origin][destin] = 1;
    }

    if (directed == 0)
    {
        insert_edge(destin, origin, 1);
    }
}

void display()
{
    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%4d", adj[i][j]);
        }
        printf("\n");
    }
}

void dft()
{
    int v;

    for (v = 1; v <= n; v++)
    {
        state[v] = INITIAL;
    }

    printf("\n\tEnter starting vertex for Depth First Search : ");
    scanf("%d", &v);

    dfs(v);
}

void dfs(int v)
{
    int I;

    printf("%d ", v);
    state[v] = VISITED;

    for (I = 1; I <= n; I++)
    {
        if (adj[v][I] == 1 && state[I] == INITIAL)
        {
            dfs(I);
        }
    }
}

void bft()
{
    int v, i;

    for (v = 1; v <= n; v++)
    {
        state[v] = INITIAL;
    }

    printf("\n\tEnter starting vertex for Breadth First Search : ");
    scanf("%d", &v);
    bfs(v);
}

void bfs(int v)
{
    int I;

    insert_queue(v);
    state[v] = WAITING;

    while (!empty_queue())
    {
        v = delete_queue();
        printf("%d ", v);
        state[v] = VISITED;

        for (I = 1; I <= n; I++)
        {
            if (adj[v][I] == 1 && state[I] == INITIAL)
            {
                insert_queue(I);
                state[I] = WAITING;
            }
        }
    }

    empty_queue();
}

int is_connected()
{
    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (adj[i][j] == 1 && i != j)
            {
                dfs(i);
                break;
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        if (state[i] == INITIAL)
        {
            return 0;
        }
    }

    return 1;
}

void insert_queue(int v)
{
    if (rear == MAX_VERTICES - 1)
    {
        printf("\n\tOverflow in queue");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear = rear + 1;
    queue[rear] = v;
}

int delete_queue()
{
    int del_item;

    if (front == -1 || front > rear)
    {
        printf("\n\tUnderflow in queue");
        return;
    }

    del_item = queue[front];
    front = front + 1;
    return del_item;
}

int empty_queue()
{
    if (front == -1 || front > rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}