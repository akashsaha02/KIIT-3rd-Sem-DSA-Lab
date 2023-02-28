// 4
#include <stdio.h>
int a[20][20], rch[20], n;
void dfs_tr(int v)
{
    int i;
    rch[v] = 1;
    for (i = 1; i <= n; i++)
        if (a[v][i] && !rch[i])
        {
            printf("\n %d->%d", v, i);
            dfs_tr(i);
        }
}
int main()
{
    int i, j, count = 0;
    printf("\n Enter vertices number:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        rch[i] = 0;
        for (j = 1; j <= n; j++)
            a[i][j] = 0;
    }
    printf("\n Enter the matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    dfs_tr(1);
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        if (rch[i])
            count++;
    }
    if (count == n)
        printf("\n Graph is connected");
    else
        printf("\n Graph is not connected");
    return 0;
}