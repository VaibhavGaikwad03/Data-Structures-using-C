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

void concatList(struct node **ppHead1, struct node **ppHead2)
{
    struct node *pTemp = NULL;

    if(*ppHead2 == NULL)
    {
        return;
    }
    if(*ppHead1 == NULL)
    {
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;

        return;
    }
    
    pTemp = *ppHead1;

    while(pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp;
    *ppHead2 = NULL;
}

void concatAtPosition(struct node **ppHead1, struct node **ppHead2, int iPos)
{
    int iCount = 0, i = 0;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = countNode(*ppHead1);

    if(iPos < 1 || iPos > iCount + 1)
        return;

    if(*ppHead2 == NULL)
        return;

    if(iPos == 1)
    {
        concatList(ppHead2, ppHead1);
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;

        return;
    }
    // if(iPos == iCount + 1)
    // {
    //     concatList(ppHead1, ppHead2);
    //     return;
    // }

    pTemp1 = *ppHead1;

    for(i = 1; i < iPos - 1; i++)
    {
        pTemp1 = pTemp1->pNext;
    }

    pTemp2 = *ppHead2;

    while(pTemp2->pNext != NULL)
    {
        pTemp2 = pTemp2->pNext;
    }

    pTemp2->pNext = pTemp1->pNext;
    if(pTemp1->pNext != NULL)
        pTemp1->pNext->pPrev = pTemp2;
    pTemp1->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp1; 

    *ppHead2 = pTemp1 = pTemp2 = NULL;
}

int main()
{

    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    insertLast(&pFirst, 10);
    insertLast(&pFirst, 20);
    insertLast(&pFirst, 25);
    insertLast(&pFirst, 26);
    insertLast(&pFirst, 27);
    insertLast(&pSecond, 30);
    insertLast(&pSecond, 40);
    insertLast(&pSecond, 50); 

    concatAtPosition(&pFirst, &pSecond, 6);

    display(pFirst);

    return 0;
}