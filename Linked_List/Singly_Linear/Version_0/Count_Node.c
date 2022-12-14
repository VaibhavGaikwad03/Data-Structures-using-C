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

void insertFirst(struct node ** ppHead, int iNo)
{
    struct node * pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}

int main()
{
    int iRet = 0;
    struct node * pFirst = NULL;

    insertFirst(&pFirst, 10);
    insertFirst(&pFirst, 20);
    insertFirst(&pFirst, 30);
    insertFirst(&pFirst, 40);
    insertFirst(&pFirst, 50);

    iRet = countNode(pFirst);

    printf("Count of nodes is : %d\n", iRet);

    return 0;
}