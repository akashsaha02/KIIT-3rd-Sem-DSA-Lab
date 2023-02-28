// Binaet search tree

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *create(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}; 

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d \n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n", root->data);
    }
}

struct Node *insert(struct Node *n, int data)
{
    if (n == NULL)
    {
        return create(data);
    }
    if (data < n->data)
        n->left = insert(n->left, data);
    else if (data > n->data)
        n->right = insert(n->right, data);
    return n;
}

struct Node *search(struct Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (root->data < data)
    {
        return search(root->right, data);
    }

    return search(root->left, data);
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);
    insert(root, 8);
    inorder(root);
    printf("\n\n\n");
    preorder(root);
    printf("\n\n\n");
    postorder(root);
    struct Node *temp = NULL;
    printf("\n\n\n");
    temp = search(temp, 80);
    printf("%d" ,temp);
    return 0;
}