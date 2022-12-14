#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
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

    while(pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

void insertFirst(struct node ** ppHead, int iNo)
{
    struct node * pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}

void insertAtPosition(struct node **ppHead, int iPos, int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    int i = 0, iCount = 0;

    iCount = countNode(*ppHead);

    if(iPos < 1 || iPos > iCount + 1)
        return;

    if(iPos == 1)
    {   
        insertFirst(ppHead, iNo);
        return;
    }
    
    pTemp = *ppHead;
    pNewNode = (struct node*)malloc(sizeof(struct node));
    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    for(i = 1; i < iPos - 1; i++)
    {
        pTemp = pTemp->pNext;
    }
    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;
}

int main()
{
    struct node *pFirst = NULL;

    insertAtPosition(&pFirst, 1, 10);
    insertAtPosition(&pFirst, 2, 20);
    insertAtPosition(&pFirst, 3, 50);
    insertAtPosition(&pFirst, 2, 60);
    insertAtPosition(&pFirst, 3, 30);
    insertAtPosition(&pFirst, 4, 40);

    display(pFirst);

    return 0;
}