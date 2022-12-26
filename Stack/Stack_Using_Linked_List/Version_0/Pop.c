#include<stdio.h>
#include<malloc.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

#define MAX 10

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

BOOL isFull(struct node *pHead)
{
    if(MAX == countNodes(pHead))
        return TRUE;
    return FALSE;
}

BOOL isEmpty(struct node *pHead)
{
    if(pHead == NULL)
        return TRUE;
    return FALSE;
}

void display(struct node *pHead)
{
    if(isEmpty(pHead))
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Data from the stack : \n");

    while(pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
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

int pop(struct node **ppHead)
{
    int iDelData = 0;
    struct node *pTemp = NULL;

    if(isEmpty(*ppHead))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    
    iDelData = (*ppHead)->iData;

    pTemp = *ppHead;
    *ppHead = (*ppHead)->pNext;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;

    return iDelData;
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

    printf("%d\n", pop(&pStack));

    display(pStack);

    return 0;
}