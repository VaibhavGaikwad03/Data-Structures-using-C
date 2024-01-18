#include <malloc.h>
#include <stdbool.h>

struct qnode
{
    struct node *data;
    struct qnode *next;
};

int count_nodes(struct qnode *head);
void display(struct qnode *head);
bool is_empty(struct qnode *head);
void enqueue(struct qnode **head, struct node *data);
struct node *dequeue(struct qnode **head);
