#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} s;

s *create()
{
    s *node = (s *)malloc(sizeof(s));
    printf("Enter value: \n");
    scanf("%d", &node->data);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorder(s *n)
{
    if (n != NULL)
    {
        printf("%d ", n->data);
        preorder(n->left);
        preorder(n->right);
    }
}

void postorder(s *n)
{
    if (n != NULL)
    {

        preorder(n->left);
        preorder(n->right);
        printf("%d ", n->data);
    }
}

void inorder(s *n)
{
    if (n != NULL)
    {

        preorder(n->left);
        printf("%d ", n->data);
        preorder(n->right);
    }
}

int main()
{
    s *root = create();
    root->left = create();
    root->right = create();
    root->left->right = create();
    root->left->right->left = create();
    root->right->left = create();
    root->right->right = create();
    root->right->right->left = create();
    root->right->right->left->left = create();
    root->right->right->right->right = create();

    preorder(root);
    postorder(root);
    inorder(root);
    return 0;
}