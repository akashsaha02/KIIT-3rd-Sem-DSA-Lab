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
void Insert_Beg(struct node *newnode, struct node **head)
{

    if (newnode == NULL)
    {
        printf("No node is created\n");
    }
    else
    {
        if (*head == NULL)
        {
            *head = newnode;
        }
        else
        {
            newnode->next = *head;
            *head = newnode;
        }
    }

    newn = NULL;
}
void Insert_End(struct node *newnode, struct node **head)
{

    if (newnode == NULL)
    {
        printf("No node is created\n");
    }
    else
    {
        if (*head == NULL)
        {
            *head = newnode;
        }
        else
        {
            struct node *t;
            for (t = *head; t->next != NULL; t = t->next)
                ;
            t->next = newnode;
        }
    }

    newn = NULL;
}
void Insert_At_k(struct node *newnode, struct node **head, int p)
{

    if (newnode == NULL)
    {
        printf("No node is created\n");
    }
    else
    {
        if (*head == NULL)
        {
            *head = newnode;
        }
        else
        {
            int ps = 0;
            struct node *t;
            t = *head;
            for (int ps = 0; ps < p - 1; ps++)
            {
                t = t->next;
            }
            newnode->next = t->next;
            t->next = newnode;
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

void Count(struct node *head)
{

    if (head == NULL)
    {
        printf("No node is 0\n");
    }
    else
    {
        struct node *t;
        int i = 0;

        for (t = head; t != NULL; t = t->next)
        {

            i++;
        }

        printf("Count of  node is %d\n", i);
    }
}

void Search(struct node *head, int search)
{

    if (head == NULL)
    {
        printf("No node is created\n");
    }
    else
    {
        struct node *t;
        int i = 1;
        int flag = 0;

        for (t = head; t != NULL; t = t->next)
        {
            if (t->info == search)
            {
                printf("------------------------\n");
                printf("Node :%d\n", i);
                printf("Node data :%d\n", t->info);
                printf("------------------------\n");
                flag = 1;
            }
            i++;
        }
        if (flag == 0)
        {
            printf("No info found.\n");
        }
    }
}

void reverse(struct node **head_ref)
{
    struct node *prev = NULL;
    struct node *current = *head_ref;
    struct node *next = NULL;
    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void Del_Beg(struct node **head)
{

    if (*head == NULL)
    {
        printf("No node to delete\n");
    }
    else
    {
        *head = (*head)->next;
        printf("Node is Deleted\n");
    }
}

void Del_End(struct node **head)
{

    if (*head == NULL)
    {
        printf("No node is created\n");
    }
    else
    {
        struct node *t;
        for (t = *head; t->next->next != NULL; t = t->next)
            ;
        t->next = NULL;
        printf("Node is Deleted\n");
    }
}
void Del_At(struct node **head, int p)
{

    if (*head == NULL)
    {
        printf("No node is created\n");
    }
    else
    {
        if (p == 0)
        {
            *head = (*head)->next;
            printf("node is deleted\n");
        }
        else
        {
            struct node *temp;
            temp = *head;
            for (int i = 0; i < p - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            printf("node is deleted\n");
        }
    }
}

int main()
{
    int ch = 0;
    int pos = 0;
    int search_t = 0;
    while (1)
    {
        printf("Enter your choice:\n");
        printf("1. Create Node\n");
        printf("2. Add to Begin\n");
        printf("3. Add to End\n");
        printf("4. Add to a Point\n");
        printf("5. Display\n");
        printf("6. Count\n");
        printf("7. Search\n");
        printf("8. Reverse\n");
        printf("9. Delete to Begin\n");
        printf("10. Delete to End\n");
        printf("11. Delete to a Point\n");
        printf("12. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            Insert_Beg(newn, &top);
            break;
        case 3:
            Insert_End(newn, &top);
            break;
        case 4:
            printf("Enter Position after which node will be added:\n");
            scanf("%d", &pos);
            Insert_At_k(newn, &top, pos);
            break;
        case 5:
            Display(top);
            break;
        case 6:
            Count(top);
            break;
        case 7:
            printf("Enter info to Search:\n");
            scanf("%d", &search_t);
            Search(top, search_t);
            break;
        case 8:
            reverse(&top);
            break;

        case 9:
            Del_Beg(&top);
            break;
        case 10:
            Del_End(&top);
            break;
        case 11:
            printf("Enter Position which node will be deleted:\n");
            scanf("%d", &pos);
            Del_At(&top, pos - 1);
            break;

        case 12:
            return 0;
        default:
            printf("Good Day !!!\n");
        }
    }

    return 0;
}