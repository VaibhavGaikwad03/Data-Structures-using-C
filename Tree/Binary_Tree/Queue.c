#include "Queue.h"

int count_nodes(struct qnode *head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void display(struct qnode *head)
{
    while (head != NULL)
    {
        printf("|%p|->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
 
bool is_empty(struct qnode *head)
{
    if (head == NULL)
        return true;
    return false;
}

void enqueue(struct qnode **head, struct node *data)
{
    struct qnode *temp = NULL;
    struct qnode *new_node = NULL;

    new_node = (struct qnode *)malloc(sizeof(struct qnode));

    if (new_node == NULL)
        return;

    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        new_node = NULL;
        return;
    }

    temp = *head;

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

struct node *dequeue(struct qnode **head)
{
    struct qnode *temp = NULL;
    struct node *deleted_data = NULL;

    if (*head == NULL)
        return NULL;

    deleted_data = (*head)->data;

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return deleted_data;
    }

    temp = *head;
    *head = (*head)->next;
    free(temp);
    temp = NULL;
    return deleted_data;
}
