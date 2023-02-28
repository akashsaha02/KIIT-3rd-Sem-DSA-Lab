// 3
#include <stdio.h>
#include <stdlib.h>
#define new_node (struct node *)malloc(sizeof(struct node))
typedef struct node
{
    int vertex;
    struct node *next;
} s;

int dir_graph()
{
    s *a[10], *p;
    int n;
    int in_deg, out_deg, i, j;
    printf("\n How Many Vertices ? : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        a[i] = NULL;
    read_graph(a, n);
    printf("\n Vertex  In_Degree  Out_Degree  Total_Degree ");
    for (i = 1; i <= n; i++)
    {
        in_deg = out_deg = 0;
        p = a[i];
        while (p != NULL)
        {
            out_deg++;
            p = p->next;
        }
        for (j = 1; j <= n; j++)
        {
            p = a[j];
            while (p != NULL)
            {
                if (p->vertex == i)
                    in_deg++;
                p = p->next;
            }
        }
        printf("\n %5d\t\t%d\t%d\t%d\n", i, in_deg, out_deg, in_deg + out_deg);
    }
    return;
}

void read_graph(s *a[10], int n)
{
    int i, j;
    char reply;
    s *p, *c;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            printf("\n Vertices %d & %d are Adjacent ? (Y/N) :", i, j);
            scanf("%c", &reply);
            if (reply == 'y' || reply == 'Y')
            {
                c = new_node;
                c->vertex = j;
                c->next = NULL;
                if (a[i] == NULL)
                    a[i] = c;
                else
                {
                    p = a[i];
                    while (p->next != NULL)
                        p = p->next;
                    p->next = c;
                }
            }
        }
    }
}

int main()
{
    int x;
    do
    {
        printf("\n 1. Directed Graph ");
        printf("\n 2. Exit \n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            dir_graph();
            break;

        case 2:
            exit(0);
        }
    } while (1);

    return 0;
}