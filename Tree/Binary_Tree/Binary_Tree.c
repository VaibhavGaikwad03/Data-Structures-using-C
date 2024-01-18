#include <stdio.h>
#include "Queue.h"

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

void create(struct node **root)
{
    int x;
    struct qnode *q = NULL;
    struct node *p = NULL, *new_node = NULL;

    printf("\nEnter the root value: ");
    scanf("%d", &x);

    *root = (struct node *)malloc(sizeof(struct node));
    if (*root == NULL)
        return;

    (*root)->data = x;
    (*root)->left = (*root)->right = NULL;

    enqueue(&q, *root);

    while (!is_empty(q))
    {
        p = dequeue(&q);

        printf("\nEnter left child of %d: ", p->data);
        scanf("%d", &x);

        if (x != -1)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            if (new_node == NULL)
                return;

            new_node->data = x;
            new_node->left = new_node->right = NULL;
            p->left = new_node;
            enqueue(&q, new_node);
        }

        printf("\nEnter right child of %d: ", p->data);
        scanf("%d", &x);

        if (x != -1)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            if (new_node == NULL)
                return;

            new_node->data = x;
            new_node->left = new_node->right = NULL;
            p->right = new_node;
            enqueue(&q, new_node);
        }
    }
}

int main(void)
{
    struct node *root = NULL;

    create(&root);

    return 0;
}
