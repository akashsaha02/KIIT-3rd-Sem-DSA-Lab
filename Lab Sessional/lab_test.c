#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data)
{

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int recursive_count(struct Node *head)
{

    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + recursive_count(head->next);
    }
}

int main()
{

    struct Node *head = NULL;
    push(&head, 3344);
    push(&head, 3532);
    push(&head, 8131);
    push(&head, 9982);
    push(&head, 7641);
    push(&head, 9938);
    push(&head, 5555);

    printf("number of nodes is %d\n", recursive_count(head));
    return 0;
}