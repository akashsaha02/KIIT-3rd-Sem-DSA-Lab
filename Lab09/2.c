
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item) // it is used to create every new node
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root) // Inorder traversal of BST always produces sorted output.
{
    if (root != NULL)
    { //
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

struct node *insert(struct node *node, int key) // as returing a node of struct node type so dont
{                                               // write int insert .
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 22);
    insert(root, 20);
    insert(root, 11);
    insert(root, 33);
    insert(root, 13);
    insert(root, 44);
    insert(root, 14);
    insert(root, 55);
    insert(root, 15);

    inorder(root);
    return 0;
}