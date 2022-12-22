#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
    struct node *pPrev;
};

int countNode(struct node *pHead)
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

int deleteFirst(struct node **ppHead)
{
    int iDelData = 0;
    struct node *pTemp = NULL;

    if(*ppHead == NULL)
    {
        return -1;
    }

    pTemp = *ppHead;
    iDelData = pTemp->iData;
    *ppHead = (*ppHead)->pNext;
    if(pTemp->pNext != NULL)
        (*ppHead)->pPrev = NULL;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;

    return iDelData;
}

int deleteAtPosition(struct node **ppHead, int iPos)
{
    int i = 0, iCount = 0, iDelData = 0;
    iCount = countNode(*ppHead);
    struct node *pTemp = NULL;

    if(iPos < 1 || iPos > iCount)
    {
        return -1;
    }

    if(iPos == 1)
    {
        return deleteFirst(ppHead);
    }
    // else if(iPos == iCount)
    // {

    // }
    // else
    // {
    //     pTemp = *ppHead;

    //     for(i = 1; i < iPos; i++)
    //     {
    //         pTemp = pTemp->pNext;
    //     }
    //     iDelData = pTemp->iData;
    //     pTemp->pPrev->pNext = pTemp->pNext;
    //     pTemp->pNext->pPrev = pTemp->pPrev;
    //     pTemp->pNext = NULL;
    //     pTemp->pPrev = NULL;
    //     free(pTemp);
    //     pTemp = NULL;

    //     return iDelData;
    // }

    pTemp = *ppHead;

    for(i = 1; i < iPos; i++)
    {
        pTemp = pTemp->pNext;
    }
    iDelData = pTemp->iData;
    pTemp->pPrev->pNext = pTemp->pNext;
    if(pTemp->pNext != NULL)
        pTemp->pNext->pPrev = pTemp->pPrev;
    pTemp->pNext = NULL;
    pTemp->pPrev = NULL;
    free(pTemp);
    pTemp = NULL;

    return iDelData;
}

int main()
{
    struct node * pFirst = NULL;

    insertLast(&pFirst, 10);
    insertLast(&pFirst, 20);
    insertLast(&pFirst, 30);
    insertLast(&pFirst, 40);
    insertLast(&pFirst, 50); 

    display(pFirst);

    printf("%d\n", deleteAtPosition(&pFirst, 1));

    display(pFirst);

    return 0;
}