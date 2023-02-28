#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void preorder(struct node *n)
{
    if (n != NULL)
    {
        if ((n->right == NULL && n->left != NULL) || (n->right != NULL && n->left == NULL))
        {
            printf("%d", n->data);
            preorder(n->left);
            preorder(n->right);
        }
    }
}


int main()
{
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    struct node *p5 = createNode(9);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p3->left = p5;

    preorder(p);
    return 0;
}