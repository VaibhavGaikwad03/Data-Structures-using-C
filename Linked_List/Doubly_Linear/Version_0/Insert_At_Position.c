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

void insertFirst(struct node ** ppHead, int iNo)
{
    struct node * pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pPrev = NULL;

    pNewNode->pNext = *ppHead;
    if(*ppHead != NULL)
        (*ppHead)->pPrev = pNewNode;
    *ppHead = pNewNode;
}

void insertAtPosition(struct node **ppHead, int iPos, int iNo)
{
    int i = 0, iCount = 0;
    iCount = countNode(*ppHead);
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    if(iPos < 1 || iPos > iCount + 1)
    {
        return;
    }

    if(iPos == 1)
    {
        insertFirst(ppHead, iNo);
        return;
    }
    // else if(iPos == iCount + 1)
    // {

    // }
    // else
    // {
    //     pTemp = *ppHead;

    //     pNewNode = malloc(sizeof(struct node));

    //     for(i = 1; i < iPos - 1; i++)
    //     {
    //         pTemp = pTemp->pNext;
    //     }
    //     pNewNode->pNext = pTemp->pNext;
    //     pTemp->pNext = pNewNode;
    //     pNewNode->pNext->pPrev = pNewNode;
    //     pNewNode->pPrev = pTemp;
    // }   
    pTemp = *ppHead;

    pNewNode = malloc(sizeof(struct node));
    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;
    pNewNode->pPrev = NULL;

    for(i = 1; i < iPos - 1; i++)
    {
        pTemp = pTemp->pNext;
    }
    
    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;
    if(pNewNode->pNext != NULL)
        pNewNode->pNext->pPrev = pNewNode;
    pNewNode->pPrev = pTemp;
}

int main()
{
    struct node *pFirst = NULL;

    insertFirst(&pFirst, 10);
    insertFirst(&pFirst, 20);
    insertFirst(&pFirst, 30);
    insertFirst(&pFirst, 40);
    insertFirst(&pFirst, 50);
    
    display(pFirst);

    insertAtPosition(&pFirst, 6, 90);

    display(pFirst);

    printf("%d", countNode(pFirst));

    return 0;
}