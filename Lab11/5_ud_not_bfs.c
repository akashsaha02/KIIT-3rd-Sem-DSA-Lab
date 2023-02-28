#include <stdio.h>
#include <stdlib.h>
int n;
int **adj;
int *vis;
int *p;
int *dis;
int *cl;

void read_graph()
{
    printf("Enter the graph:\n");
    adj = (int **)malloc(n * sizeof(int *));
    vis = (int *)malloc(n * sizeof(int));
    p = (int *)malloc(n * sizeof(int));
    dis = (int *)malloc(n * sizeof(int));
    cl = (int *)malloc(n * sizeof(int));
    int i, j;
    for (i = 0; i < n; i++)
        vis[i] = 0;
    for (i = 0; i < n; i++)
    {
        adj[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
}

int *bfs(int s)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        vis[i] = 0;
        p[i] = -1;
        dis[i] = __INT_MAX__;
        cl[i] = -1;
    }
    vis[s] = 1;
    p[s] = -1;
    dis[s] = 0;
    cl[s] = 1;

    int q[n];
    int front = 0, rear = 0;
    q[rear++] = s;
    while (front != rear)
    {
        int u = q[front++];
        for (i = 0; i < n; i++)
        {
            if (adj[u][i] == 1 && vis[i] == 0)
            {
                vis[i] = 1;
                q[rear++] = i;
                p[i] = u;
                dis[i] = dis[u] + 1;
                cl[i] = (cl[u] + 1) % 2;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (adj[i][j] == 1 && cl[i] == cl[j])
            {
                printf("Not a tree\n");
                exit(0);
            }
        }
    }
    printf("Tree\n");
}

int main()
{
    printf("Enter the vertices number:");
    scanf("%d", &n);
    read_graph();
    bfs(0);
    return 0;
}