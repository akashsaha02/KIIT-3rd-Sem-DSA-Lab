#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef;
    int expo;
    struct node *next;
};

struct node *create(struct node *head, int a, int b)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coef = a;
    newnode->expo = b;
    newnode->next = head;
    return newnode;
}

void display(struct node *head)
{
    struct node *temp;
    for (temp = head; temp->next != NULL; temp = temp->next)
    {
        printf("%dx^%d + ", temp->coef, temp->expo);
    }
    printf("%dx^%d\n", temp->coef, temp->expo);
}

int main()
{

    struct node *phead = NULL;

    struct node *phead1 = NULL;
    int co;
    int ex;
    int t;
    printf("how many terms");
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        printf("Enter co :");
        scanf("%d", &co);
        printf("Enter ex :");
        scanf("%d", &ex);
        phead = create(phead, co, ex);
    }

    printf("how many terms");
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        printf("Enter co :");
        scanf("%d", &co);
        printf("Enter ex :");
        scanf("%d", &ex);
        phead1 = create(phead1, co, ex);
    }
    display(phead);
    display(phead1);
    return 0;
}