#include"Custom_Header.h"

int countNodes(struct Qnode *pHead)
{
    int iCount = 0;

    while(pHead != NULL)
    {
        iCount++;
        pHead = pHead->pNext;
    }

    return iCount;
}

void display(struct Qnode *pHead)
{
    printf("Data from the Queue : \n");
    while(pHead != NULL)
    {
        printf("|%d|<-", pHead->pRoot);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

BOOL isQueueFull(struct Qnode *pHead)
{
    if(countNodes(pHead) == MAX)
        return TRUE;
    return FALSE;
}

BOOL isQueueEmpty(struct Qnode *pHead)
{
    if(countNodes(pHead) == 0)
        return TRUE;
    return FALSE;
}

void enQueue(struct Qnode **ppHead, struct node *pRoot)
{
    struct Qnode *pNewNode = NULL;
    struct Qnode *pTemp = NULL;

    pNewNode = (struct Qnode*)malloc(sizeof(struct Qnode));
    pNewNode->pRoot = pRoot;
    pNewNode->pNext = NULL;

    if(isQueueFull(*ppHead))                                       //if queue is full
    {
        printf("Queue is full.\n");
        return;
    }

    if((*ppHead) == NULL)                                   //if queue is empty
    {
        *ppHead = pNewNode;
        pNewNode = NULL;

        return;
    }

    pTemp = *ppHead;                                        //if queue having at least one or more elements

    while(pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pNewNode;
}

struct node * deQueue(struct Qnode **ppHead)
{
    struct node *pDelRoot = NULL; 
    struct Qnode *pTemp = NULL;

    if(isQueueEmpty(*ppHead))
    {
        printf("Queue is empty.\n");
        return NULL;
    }

    pDelRoot = (*ppHead)->pRoot;

    if((*ppHead)->pNext == NULL)
    {
        free(*ppHead);
        *ppHead = NULL;

        return pDelRoot;
    }

    pTemp = *ppHead;
    *ppHead = (*ppHead)->pNext;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;

    return pDelRoot;
}