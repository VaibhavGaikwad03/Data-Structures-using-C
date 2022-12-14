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

void insertLast(struct node ** ppHead, int iNo)
{
    struct node * pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(*ppHead == NULL)
    {
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
    }
}

int deleteLast(struct node **ppHead)
{
    int iDel = 0;
    struct node *pTemp = NULL;

    if(*ppHead == NULL)
    {
        return -1;
    }

    if((*ppHead)->pNext == NULL)
    {
        iDel = (*ppHead)->iData;
        free(*ppHead);
        *ppHead = NULL;
    }
    else
    {
        pTemp = *ppHead;

        while(pTemp->pNext->pNext != NULL)
        {
            pTemp = pTemp->pNext;
        }
        iDel = pTemp->pNext->iData;
        free(pTemp->pNext);
        pTemp->pNext = NULL;
    }

    return iDel;
}

int main()
{
    int iRet = 0, iDel = 0;;
    struct node * pFirst = NULL;

    insertLast(&pFirst, 10);
    insertLast(&pFirst, 20);
    insertLast(&pFirst, 30);
    insertLast(&pFirst, 40);
    insertLast(&pFirst, 50);

    display(pFirst);
    iRet = countNode(pFirst);

    printf("Count of nodes is : %d\n", iRet);

    iDel = deleteLast(&pFirst);

    display(pFirst);
    iRet = countNode(pFirst);

    printf("Deleted data is : %d\n", iDel);
    printf("Count of nodes is : %d\n", iRet);

    return 0;
}