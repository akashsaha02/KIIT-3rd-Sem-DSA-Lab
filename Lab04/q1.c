#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *newn, *top = NULL;
void create()
{

    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d", &n->info);
    newn = n;
}
void Insert_Beg(struct node *newnode, struct node *head)
{

    if (newnode == NULL)
    {
        printf("No node is created\n");
    }
    else
    {
        if (head == NULL)
        {
            top = newnode;
        }
        else
        {
            newnode->next = head;
            top = newnode;
        }
    }

    newn = NULL;
}
void Insert_End(struct node *newnode, struct node *head)
{

    if (newnode == NULL)
    {
        printf("No node is created\n");
    }
    else
    {
        if (head == NULL)
        {
            top = newnode;
        }
        else
        {
            struct node *t;
            for (t = head; t->next != NULL; t = t->next)
    
            t->next = newnode;
        }
    }

    newn = NULL;
}
void Insert_At_k(struct node *newnode, struct node *head, int p)
{

    if (newnode == NULL)
    {
        printf("No node is created\n");
    }
    else
    {
        if (head == NULL)
        {
            top = newnode;
        }
        else
        {
            int ps = 0;
            struct node *t;
            for (t = head; t != NULL; t = t->next)
            {
                ps++;
                if (ps == p)
                {
                    newnode->next = t->next;
                    t->next = newnode;
                }
            }
        }
    }

    newn = NULL;
}
void Display(struct node *head)
{

    if (head == NULL)
    {
        printf("No node is created\n");
    }
    else
    {
        struct node *t;
        int i = 1;

        for (t = head; t != NULL; t = t->next)
        {
            printf("------------------------\n");
            printf("Node :%d\n", i);
            printf("Node data :%d\n", t->info);
            printf("------------------------\n");
            i++;
        }
    }
}

int main()
{
    int ch = 0;
    int pos = 0;
    printf("Enter your choice:\n");
    printf("1. Create Node\n");
    printf("2. Add to Begin\n");
    printf("3. Add to End\n");
    printf("4. Add to a Point\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    while (1)
    {
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            Insert_Beg(newn, top);
            break;
        case 3:
            Insert_End(newn, top);
            break;
        case 4:
            printf("Enter Position Afert which node will be added:\n");
            scanf("%d", &pos);
            Insert_At_k(newn, top, pos);
            break;
        case 5:
            Display(top);
            break;
        case 6:
            return 0;
        default:
            printf("Good Day !!!\n");
        }
    }

    return 0;
}