#include<stdio.h>
#include<malloc.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

#define MAX 5

struct node 
{
    int iData;
    struct node *pNext;
};

int countNodes(struct node *pHead)
{
    int iCount = 0;

    while(pHead != NULL)
    {
        iCount++;
        pHead = pHead->pNext;
    }

    return iCount;
}

void display(struct node *pHead)
{
    printf("Data from the stack : \n");

    while(pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

BOOL isFull(struct node *pHead)
{
    if(MAX == countNodes(pHead))
        return TRUE;
    return FALSE;
}

void push(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    if(isFull(*ppHead))
    {
        printf("Stack Overflow.\n");
        return;
    }

    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;

    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}

int main()
{
    struct node *pStack = NULL;

    push(&pStack, 60);
    push(&pStack, 50);
    push(&pStack, 40);
    push(&pStack, 30);
    push(&pStack, 20);
    push(&pStack, 10);

    display(pStack);

    return 0;
}