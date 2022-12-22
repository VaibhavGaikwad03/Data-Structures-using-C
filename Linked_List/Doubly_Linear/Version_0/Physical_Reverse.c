#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
    struct node *pPrev;
};

void display(struct node *pHead)
{
    if(pHead == NULL)
    {
        printf("Linked List is empty !!\n");
        return;
    }

    printf("Data from the linked list : \n");

    printf("NULL<->");
    while(pHead != NULL)
    {
        printf("|%d|<->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

void insertLast(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(*ppHead == NULL)
    {
        pNewNode->pPrev = NULL;
        *ppHead = pNewNode;
    }
    else
    {
        pTemp = *ppHead;

        while(pTemp->pNext != NULL)
        { 
            pTemp = pTemp->pNext;
        }
        pTemp->pNext = pNewNode;
        pNewNode->pPrev = pTemp;
    }
}

void physicalReverse(struct node **ppHead)
{
    struct node *pCurrent = *ppHead;
    struct node *pTemp = NULL;

    if((*ppHead)->pNext == NULL)
        return;
    
    while(pCurrent != NULL)
    {
        pTemp = pCurrent->pPrev;
        pCurrent->pPrev = pCurrent->pNext;
        pCurrent->pNext = pTemp;
        pCurrent = pCurrent->pPrev;
    }

    *ppHead = pTemp->pPrev;
}

int main()
{
    struct node *pFirst = NULL;

    insertLast(&pFirst, 10);
    insertLast(&pFirst, 20);
    insertLast(&pFirst, 30);
    insertLast(&pFirst, 40);
    insertLast(&pFirst, 50); 

    display(pFirst);

    physicalReverse(&pFirst);

    display(pFirst);

    return 0;
}