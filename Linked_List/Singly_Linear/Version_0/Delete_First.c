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

int deleteFirst(struct node **ppHead)
{
    int iDel = 0;
    struct node *pTemp = NULL;

    if(*ppHead == NULL)
    {
        return -1;
    }

    pTemp = *ppHead;
    *ppHead = (*ppHead)->pNext;
    iDel = pTemp->iData;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;

    return iDel;
}

int main()
{
    int iRet = 0, iDel = 0;
    struct node * pFirst = NULL;

    insertFirst(&pFirst, 10);
    insertFirst(&pFirst, 20);
    insertFirst(&pFirst, 30);
    insertFirst(&pFirst, 40);
    insertFirst(&pFirst, 50);

    display(pFirst);
    iRet = countNode(pFirst);

    printf("Count of nodes is : %d\n", iRet);

    iDel = deleteFirst(&pFirst);

    display(pFirst);
    iRet = countNode(pFirst);

    printf("Deleted data is : %d\n", iDel);
    printf("Count of nodes is : %d\n", iRet);

    return 0;
}