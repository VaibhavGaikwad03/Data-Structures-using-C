#include<stdio.h>
#include<malloc.h>

typedef int BOOL;

#define TRUE 1
#define FALSE 0
#define MAX 5

struct Qnode
{
    struct node *pRoot;
    struct Qnode *pNext;
};

struct node 
{
    struct node *pLeft;
    int iData;
    struct node *pRight;
};

int countNodes(struct Qnode *);
void display(struct Qnode *);
BOOL isQueueFull(struct Qnode *);
BOOL isQueueEmpty(struct Qnode *);
void enQueue(struct Qnode **, struct node *);
struct node * deQueue(struct Qnode **);
