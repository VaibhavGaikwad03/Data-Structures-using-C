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

void insertFirst(struct node ** ppHead, int iNo)
{
    struct node * pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pPrev = NULL;

    // if(*ppHead == NULL)
    // {
    //     pNewNode->pNext = NULL;
    //     *ppHead = pNewNode;
    // }
    // else
    // {
    //     pNewNode->pNext = *ppHead;
    //     if(*ppHead != NULL)
    //         (*ppHead)->pPrev = pNewNode;
    //     *ppHead = pNewNode;
    // }

    pNewNode->pNext = *ppHead;
    if(*ppHead != NULL)
        (*ppHead)->pPrev = pNewNode;
    *ppHead = pNewNode;
}

int main()
{
    struct node * pFirst = NULL;

    insertFirst(&pFirst, 10);
    insertFirst(&pFirst, 20);
    insertFirst(&pFirst, 30);
    insertFirst(&pFirst, 40);
    insertFirst(&pFirst, 50);

    display(pFirst);

    return 0;
}