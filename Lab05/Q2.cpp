#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef, expo;
    struct node *next;
};

struct node *creation(struct node *thead, int c, int e)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coef = c;
    newnode->expo = e;
    if (thead == NULL)
    {
        newnode->next = NULL;
        return newnode;
    }
    else
    {
        newnode->next = thead;
        return newnode;
    }
}

void display(struct node *thead)
{
    struct node *temp = thead;
    if (temp == NULL)
    {
        printf("\nEmpty..");
    }
    else
    {
        while (temp->next != NULL)
        {
            printf(" %dx^%d +", temp->coef, temp->expo);
            temp = temp->next;
        }
        printf(" %dx^%d ", temp->coef, temp->expo);
    }
}

struct node *init(int n)
{
    int i;
    struct node *h = NULL, *p;
    for (i = 0; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->next = h;
        p->coef = 0;
        p->expo = 0;
        h = p;
    }
    return (h);
}

struct node *multiply(struct node *h1, struct node *h2, int k1)
{
    struct node *h3, *p, *q, *r;

    int i, j, k, coef, power;
    h3 = init(k1);

    for (p = h1, i = 0; p != NULL; p = p->next, i++)
        for (q = h2, j = 0; q != NULL; q = q->next, j++)
        {
            coef = p->coef * q->coef;
            power = p->expo + q->expo;
            for (r = h3, k = 0; k < power; k++)
                r = r->next;
            r->coef = r->coef + coef;
            r->expo = power;
        }
    return (h3);
}

int main()
{
    int a, b, n, n1, i;
    struct node *p1head = NULL;
    
    printf("Enter the no of terms of polynomial 1..");
    scanf("%d", &n);
    printf("\nEnter the polynomial in ascinding order of degree..");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the coefficient and exponent of the term..");
        scanf("%d%d", &a, &b);
        p1head = creation(p1head, a, b);
    }
    printf("\nThe polynomial 1 is..");
    display(p1head);

    struct node *p2head = NULL;

    printf("Enter the no of terms of polynomial 2..");
    scanf("%d", &n1);
    printf("\nEnter the polynomia2 in ascinding order of degree..");
    for (i = 0; i < n1; i++)
    {
        printf("\nEnter the coefficient and exponent of the term..");
        scanf("%d%d", &a, &b);
        p2head = creation(p2head, a, b);
    }
    printf("\nThe polynomial 2 is..");
    display(p2head);

    struct node *p3head = NULL;

    p3head = multiply(p1head, p2head, (n + n1) - 1);

    printf("\nThe polynomial 3 is..");
    display(p3head);
}