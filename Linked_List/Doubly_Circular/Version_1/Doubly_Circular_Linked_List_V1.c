#include<stdio.h>
#include<stdlib.h>

struct node
{
    int iData;
    struct node *pNext;
    struct node *pPrev;
};

int countNodes(struct node *pHead, struct node *pTail)
{
    int iCount = 0;

    if(pHead == NULL)
    {
        return iCount;
    }

    do
    {
        iCount++;
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

    return iCount;
}

void display(struct node *pHead, struct node *pTail)
{
    if(pHead == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Data from the linked list : \n");
    do
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);
    printf("\n");
}

void insertFirst(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
        return;

    pNewNode->iData = iNo;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;             
        *ppTail = pNewNode;           
    }
    else
    {
        pNewNode->pNext = *ppHead;      
        (*ppHead)->pPrev = pNewNode;   
        *ppHead = pNewNode;
    }       
    (*ppHead)->pPrev = *ppTail;        
    (*ppTail)->pNext = *ppHead;        
}

void insertLast(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
        return;

    pNewNode->iData = iNo;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;             
        *ppTail = pNewNode;           
    }
    else
    {
        pNewNode->pPrev = *ppTail;
        (*ppTail)->pNext = pNewNode;
        *ppTail = pNewNode;
    }
    (*ppHead)->pPrev = *ppTail;        
    (*ppTail)->pNext = *ppHead;
}

void insertAtPosition(struct node **ppHead, struct node **ppTail, int iNo, int iPos)
{
    int iCount = 0, i = 0;
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    iCount = countNodes(*ppHead, *ppTail);

    if(iPos < 1 || iPos > iCount + 1)
        return;

    if(iPos == 1)
        insertFirst(ppHead, ppTail, iNo);
    else if(iPos == iCount + 1)
        insertLast(ppHead, ppTail, iNo);
    else
    {
        pTemp = *ppHead;
        pNewNode = (struct node*)malloc(sizeof(struct node));
        pNewNode->iData = iNo;

        for(i = 1; i < iPos - 1; i++)
        {
            pTemp = pTemp->pNext;
        }
        pNewNode->pNext = pTemp->pNext;
        pTemp->pNext->pPrev = pNewNode;
        pTemp->pNext = pNewNode;
        pNewNode->pPrev = pTemp;
    }
}

int deleteFirst(struct node **ppHead, struct node **ppTail)
{
    int iDelData = 0;

    if(*ppHead == NULL)
        return -1;

    iDelData = (*ppHead)->iData;

    if(*ppHead == *ppTail)
    {
        free(*ppHead);
        *ppHead = *ppTail = NULL;
    }
    else
    {
        *ppHead = (*ppHead)->pNext;
        free((*ppTail)->pNext);

        (*ppHead)->pPrev = *ppTail;
        (*ppTail)->pNext = *ppHead;
    }
    return iDelData;
}

int deleteLast(struct node **ppHead, struct node **ppTail)
{
    int iDelData = 0;

    if(*ppHead == NULL)
        return -1;

    if(*ppHead == *ppTail)
    {
        iDelData = (*ppTail)->iData;
        free(*ppTail);
        *ppHead = *ppTail = NULL;
    }
    else
    {
        *ppTail = (*ppTail)->pPrev;
        iDelData = (*ppTail)->pNext->iData;
        free((*ppTail)->pNext);
        (*ppHead)->pPrev = *ppTail;
        (*ppTail)->pNext = *ppHead;
    }
    return iDelData;
}

int deleteAtPosition(struct node **ppHead, struct node **ppTail, int iPos)
{
    int iCount = 0, i = 0, iDelData = 0;
    struct node *pTemp = NULL;

    iCount = countNodes(*ppHead, *ppTail);

    if(iPos < 1 || iPos > iCount)
        return -1;

    if(iPos == 1)
        return deleteFirst(ppHead, ppTail);

    else if(iPos == iCount)
        return deleteLast(ppHead, ppTail);

    else
    {
        pTemp = *ppHead;

        for(i = 1; i < iPos; i++)
        {
            pTemp = pTemp->pNext;
        }

        iDelData = pTemp->iData;
        pTemp->pPrev->pNext = pTemp->pNext;
        pTemp->pNext->pPrev = pTemp->pPrev;

        pTemp->pNext = NULL;
        pTemp->pPrev = NULL;
        free(pTemp);
        pTemp = NULL;

        return iDelData;
    }
}

int searchFirstOccurrence(struct node *pHead, struct node *pTail, int iKey)
{
    int iCountPos = 0;

    if(pHead == NULL)
    {
        return iCountPos;
    }

    do
    {
        iCountPos++;
        if(pHead->iData == iKey)
            break;
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);  

    if(pHead == pTail->pNext)
        iCountPos = 0;
    
    return iCountPos;
}

int searchLastOccurrence(struct node *pHead, struct node *pTail, int iKey)
{
    int iCountPos = 0, iRetPos = 0;

    if(pHead == NULL)
        return iRetPos;

    do
    {   
        iCountPos++;
        if(pHead->iData == iKey)
            iRetPos = iCountPos;
        
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

    return iRetPos;
}

int searchAllOccurrences(struct node *pHead, struct node *pTail, int iKey)
{
    int iCountOcc = 0;

    if(pHead == NULL)
        return iCountOcc;
    
    do
    {
        if(pHead->iData == iKey)
            iCountOcc++;

        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

    return iCountOcc;
}

void concatList(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2)
{
    if(*ppHead2 == NULL)
        return;

    if(*ppHead1 == NULL)
    {
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;

        *ppHead2 = *ppTail2 = NULL;

        return;
    }

    (*ppTail1)->pNext = *ppHead2;
    (*ppHead2)->pPrev = *ppTail1;
    *ppTail1 = *ppTail2;
    (*ppHead1)->pPrev = *ppTail1;
    (*ppTail1)->pNext = *ppHead1;

    *ppHead2 = *ppTail2 = NULL;
}

void concatAtPosition(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2, int iPos)
{
    int iCount = 0, i = 0;
    struct node *pTemp = NULL;

    iCount = countNodes(*ppHead1, *ppTail1);

    if(iPos < 1 || iPos > iCount + 1)
    {
        printf("Position is invalid\n");
        return;
    }

    if(ppHead2 == NULL)
        return;

    if(iPos == 1)
    {
        concatList(ppHead2, ppTail2, ppHead1, ppTail1);
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;

        *ppHead2 = *ppTail2 = NULL;

        return;
    }

    if(iPos == iCount + 1)
    {
        concatList(ppHead1, ppTail1, ppHead2, ppTail2);
        return;
    }

    pTemp = *ppHead1;

    for(i = 1; i < iPos - 1; i++)
    {
        pTemp = pTemp->pNext;
    }

    (*ppTail2)->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = *ppTail2;
    pTemp->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp;

    *ppHead2 = *ppTail2 = NULL;
}

void physicalReverse(struct node **ppHead, struct node **ppTail)
{
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;

    if(*ppHead == NULL)
        return;

    do
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pCurrent->pPrev;
        pCurrent->pPrev = pNext;
        pCurrent = pNext;
    }while(pCurrent != *ppHead);

    *ppHead = *ppTail;
    *ppTail = pCurrent;
}

void reverseDisplay(struct node *pHead, struct node *pTail)
{
    if(pHead == NULL)
    {
        printf("List is empty\n");
        return;
    }

    do
    {
        printf("|%d|->", pTail->iData);
        pTail = pTail->pPrev;
    }while(pTail != pHead->pPrev);
    printf("\n");
}

void deleteAll(struct node **ppHead, struct node **ppTail)
{
    struct node *pTemp = NULL;
    pTemp = *ppHead;
    (*ppTail)->pNext = NULL;

    while(pTemp != NULL)
    {
        *ppHead = pTemp->pNext;
        pTemp->pNext = NULL;
        pTemp->pPrev = NULL;
        free(pTemp);
        pTemp = *ppHead;
    }
}

int main()
{
    int iResult = 0;
    struct node *pFirst = NULL;
    struct node *pLast = NULL;

    struct node *pFirst1 = NULL;
    struct node *pLast1 = NULL;

    display(pFirst, pLast);
    
    insertFirst(&pFirst, &pLast, 30);
    insertFirst(&pFirst, &pLast, 20);
    insertFirst(&pFirst, &pLast, 10);

    display(pFirst, pLast);

    insertLast(&pFirst, &pLast, 40);
    insertLast(&pFirst, &pLast, 30);
    insertLast(&pFirst, &pLast, 60);

    display(pFirst, pLast);

    insertAtPosition(&pFirst, &pLast, 70, 4);           

    display(pFirst, pLast);

    iResult = deleteFirst(&pFirst, &pLast);
    if(iResult != -1)
    {
        printf("Deleted data is %d\n", iResult);
    }

    display(pFirst, pLast);

    iResult = deleteLast(&pFirst, &pLast);
    if(iResult != -1)
    {
        printf("Deleted data is %d\n", iResult);
    }

    display(pFirst, pLast);

    iResult = deleteAtPosition(&pFirst, &pLast, 3);
    if(iResult != -1)
    {
        printf("Deleted data is %d\n", iResult);
    }

    display(pFirst, pLast);

    iResult = searchFirstOccurrence (pFirst, pLast, 30);
    if(iResult != 0)
    {
        printf("First occurrence of %d is at position %d\n", 30, iResult);
    }

    iResult = searchLastOccurrence(pFirst, pLast, 30);
    if(iResult != 0)
    {
        printf("Last occurrence of %d is at position %d\n", 30, iResult);
    }

    iResult = searchAllOccurrences(pFirst, pLast, 30);
    printf("%d found %d times\n", 30, iResult);

    iResult = countNodes(pFirst, pLast);
    printf("Total count is %d\n", iResult);

    display(pFirst, pLast);

    reverseDisplay(pFirst, pLast);
    display(pFirst, pLast);

    physicalReverse(&pFirst, &pLast);
    display(pFirst, pLast);

    physicalReverse(&pFirst, &pLast);
    display(pFirst, pLast);

    insertLast(&pFirst1, &pLast1, 100);
    insertLast(&pFirst1, &pLast1, 200);
    insertLast(&pFirst1, &pLast1, 300);

    display(pFirst1, pLast1);

    concatList(&pFirst, &pLast, &pFirst1, &pLast1);

    display(pFirst, pLast);
    display(pFirst1, pLast1);

    insertLast(&pFirst1, &pLast1, 400);
    insertLast(&pFirst1, &pLast1, 500);
    insertLast(&pFirst1, &pLast1, 600);

    display(pFirst1, pLast1);

    concatAtPosition(&pFirst, &pLast, &pFirst1, &pLast1, 3);

    display(pFirst, pLast);

    display(pFirst1, pLast1);

    if(pFirst != NULL)
    {
        deleteAll(&pFirst, &pLast);
        pFirst = NULL;
    }

    if(pFirst1 != NULL)
    {
        deleteAll(&pFirst1, &pLast1);
        pFirst1 = NULL;
    }

    display(pFirst, pLast);
    display(pFirst1, pLast1);

    return 0;
}