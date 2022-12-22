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

int deleteFirst(struct node **ppHead)
{
    int iDelData = 0;
    struct node *pTemp = NULL;

    if(*ppHead == NULL)
    {
        return -1;
    }

    // if((*ppHead)->pNext == NULL)
    // {
    //     iDelData = (*ppHead)->iData;
    //     free(*ppHead);
    //     *ppHead = NULL;
    // }
    // else
    // {
    //     pTemp = *ppHead;
    //     iDelData = pTemp->iData;
    //     *ppHead = (*ppHead)->pNext;
    //     (*ppHead)->pPrev = NULL;
    //     pTemp->pNext = NULL;
    //     free(pTemp);
    //     pTemp = NULL;
    // }

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

int main()
{
    struct node * pFirst = NULL;

    insertLast(&pFirst, 10);
    insertLast(&pFirst, 20);
    insertLast(&pFirst, 30);
    insertLast(&pFirst, 40);
    insertLast(&pFirst, 50); 

    display(pFirst);

    printf("%d\n", deleteFirst(&pFirst));

    display(pFirst);

    return 0;
}