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
    printf("Data from the Queue : \n");
    while(pHead != NULL)
    {
        printf("|%d|<-", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

BOOL isQueueFull(struct node *pHead)
{
    if(countNodes(pHead) == MAX)
        return TRUE;
    return FALSE;
}

BOOL isQueueEmpty(struct node *pHead)
{
    if(countNodes(pHead) == 0)
        return TRUE;
    return FALSE;
}

void enQueue(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));
    pNewNode->iData = iNo;
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

int deQueue(struct node **ppHead)
{
    int iDelData = 0;
    struct node *pTemp = NULL;

    if(isQueueEmpty(*ppHead))
    {
        printf("Queue is empty.\n");
        return -1;
    }

    iDelData = (*ppHead)->iData;

    if((*ppHead)->pNext == NULL)
    {
        free(*ppHead);
        *ppHead = NULL;

        return iDelData;
    }

    pTemp = *ppHead;
    *ppHead = (*ppHead)->pNext;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;

    return iDelData;
}

int main()
{
    struct node *pQueue = NULL;

    enQueue(&pQueue, 10);
    enQueue(&pQueue, 20);
    enQueue(&pQueue, 30);
    enQueue(&pQueue, 40);
    enQueue(&pQueue, 50);

    display(pQueue);

    printf("%d\n", deQueue(&pQueue));

    display(pQueue);

    return 0;
}